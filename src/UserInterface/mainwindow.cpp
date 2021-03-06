/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "versionInfo.h"

#include "rs/client.h"
#include "rs/keylistener.h"

#include "java/awt/event/keyevent.h"
using java::awt::event::KeyEvent;

#include "net/pgrid/loader/pgloader.h"

#include "monitorwindow.h"

Q_LOGGING_CATEGORY(guiLogger, "GUI")

/*!
 * \class MainWindow
 * \brief PowerGrid Control panel
 *
 * This class provides the PowerGrid control panel. It contains a variety
 * of slots to update the different properties this control panel displays.
 *
 * For example, there is a \c{setJVMVersion(QString)} slot that sets the version
 * of the running Java VM, as well as a slot to update the number of frames/second
 * the RS client is running (\c{updateFPS()}).
 *
 */

/*!
 * \brief Creates a new MainWindow instance
 * \param parent the parent, if any
 *
 * This constructor creates a new \c MainWindow object that can be displayed
 * on screen.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_mainWindow),
    timer(new QTimer) {
    ui->setupUi(this);
    ui->pgVersion->setText(PG_VERSION_STR);
    timer->setInterval(1000); // Update every second

    connect(ui->sendText,      SIGNAL(clicked()),
            this,              SLOT(sendText()));
    connect(ui->monitorButton, SIGNAL(clicked()),
            this,              SLOT(showMonitorWindow()));
    connect(timer,             SIGNAL(timeout()),
            this,              SLOT(updateFPS()));

    timer->start();
}

MainWindow::~MainWindow() {
    timer->stop();
    delete timer;
    delete ui;
}

/*!
 * \brief sets the JVM version displayed by this \c MainWindow
 * \param version the version to display
 */
void MainWindow::setJVMVersion(QString version) {
    ui->jvmVersion->setText(version);
}
/*!
 * \brief updates the number of frames per second (FPS)
 *
 * This slot automatically collects the required information from the
 * RS client, the FPS can be kept up-to-date if this is called
 * periodically.
 */
void MainWindow::updateFPS() {
    static bool thrown = false;
    try {
        JInt fpsValue = RS::Client::getFPS();
        ui->fps->setText(QString::number(fpsValue.getInt()));
    } catch (jace::MappingUnavailableException& e) {
        if (!thrown) {
            thrown = true;
            qCDebug(guiLogger) << "Error fetching FPS: Missing Field:" << e.what();
        }
        ui->fps->setText(tr("Missing binding for FPS field"));
    } catch (jace::JNIException& e) {
        if (!thrown) {
            thrown = true;
            qCDebug(guiLogger) << "Error fetching FPS:" << e.what();
        }
        ui->fps->setText(QStringLiteral("ERR: ") + e.what());
    }
}

void MainWindow::sendText() {
    try {
        RS::KeyListener keyboard = RS::Client::getKeyboard();
        java::awt::Component source = net::pgrid::loader::PGLoader::getApplet();
        QString text = ui->textToSend->text();
        for(int i=0;i<text.length();i++) {
            QDateTime time (QDateTime::currentDateTime());
            qint64 msec = time.toMSecsSinceEpoch();
            keyboard.dispatch(KeyEvent::createEvent(source,
                              KeyEvent::Typed, msec, 0, -1,
                              JChar(text.at(i).toLatin1())));
            qCDebug(guiLogger) << "Char" << text.at(i) << "sent.";
        }
    } catch (jace::JNIException& e) {
        qCDebug(guiLogger) << "Exception in sendText():" << e.what();
    }
}

void MainWindow::showMonitorWindow() {
    MonitorWindow* window = new MonitorWindow();
    window->show();
}
