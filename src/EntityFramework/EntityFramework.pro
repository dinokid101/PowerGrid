#------------------------------------------------------------------------
# Copyright 2014 Patrick Kramer, Vincent Wassenaar
#
# This file is part of PowerGrid.
#
# PowerGrid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PowerGrid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
#
# Note that the files contained in this project do NOT fall under the
# terms of the GNU General Public License, but instead fall under a
# different license as mentioned below. This .pro file does fall under the
# GNU General Public License.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# .pro file for the Entity Framework
#------------------------------------------------------------------------

QT       = core concurrent

TARGET   = EntityFramework
TEMPLATE = lib
CONFIG  += staticlib thread c++11

HEADERS += \
    entity/component.h \
    entity/entity.h \
    entity/world.h \
    component/position.h \
    component/size.h \
    component/id.h \
    component/name.h \
    component/speed.h \
    component/interaction.h \
    component/action.h \
    entity/matcher.h \
    component/transportation.h \
    entity/mapper.h \
    entity/classifier.h \
    entity/task.h \
    entity/taskmanager.h \
    entity/taskcontext.h \
    entity/tasknotifier.h \
    entity/taskfactory.h

SOURCES += \
    entity/component.cpp \
    entity/entity.cpp \
    entity/world.cpp \
    component/position.cpp \
    component/size.cpp \
    component/id.cpp \
    component/name.cpp \
    component/speed.cpp \
    component/interaction.cpp \
    component/action.cpp \
    entity/matcher.cpp \
    component/transportation.cpp \
    entity/mapper.cpp \
    entity/classifier.cpp \
    entity/task.cpp \
    entity/taskmanager.cpp \
    entity/taskcontext.cpp \
    entity/tasknotifier.cpp \
    entity/taskfactory.cpp

# Dependency for the Bridge subproject
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Bridge/release/ -lBridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Bridge/debug/ -lBridge
else:unix: LIBS += -L$$OUT_PWD/../Bridge/ -lBridge

INCLUDEPATH += $$PWD/../Bridge
DEPENDPATH += $$PWD/../Bridge

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/libBridge.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/libBridge.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/release/Bridge.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Bridge/debug/Bridge.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Bridge/libBridge.a
