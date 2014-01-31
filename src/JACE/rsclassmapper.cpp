#include "rsclassmapper.h"
#include "mappingunavailableexception.h"
#include <stdexcept>
#include <QDebug>
#include <QXmlStreamReader>

#include "jace/JNIException.h"
#include "jace/JNIHelper.h"
using namespace jace;

QString RSClassMapper::defaultDataFile ("cache/updater.dat");
RSClassMapper* RSClassMapper::classmapper = nullptr;

RSClassMapper* RSClassMapper::DefaultInstance() {
    if (! RSClassMapper::classmapper) {
        RSClassMapper::classmapper = new RSClassMapper(defaultDataFile);
    }
    return RSClassMapper::classmapper;
}

RSClassMapper::RSClassMapper(QString dataFile) : source (dataFile) {}

RSClassMapper::~RSClassMapper() {}

QMap<QString, QString> RSClassMapper::getFieldMap(QString className) const {
    QMap<QString, QMap<QString, QString>>::const_iterator it = fieldMap.find(className);
    if (it == fieldMap.end()) {
        throw MappingUnavailableException(className.toStdString());
    }
    return it.value();
}

QString RSClassMapper::getRealName(QString semanticName) const {
    QMap<QString, QString>::const_iterator it = classMap.find(semanticName);
    if (it == classMap.end()) {
        throw MappingUnavailableException(semanticName.toStdString());
    }
    return it.value();
}

void RSClassMapper::parseData(jbyteArray data) {
    if (data == NULL) {
        throw JNIException("Received NULL jbyteArray as map data");
    }
    if (classMap.isEmpty()) {
        JNIEnv* env = helper::attach();
        // sizeof(jbyte) == sizeof(char), and QByteArray can be initialized using a const char*
        char* bytes = static_cast<char*>(env->GetDirectBufferAddress(data));
        jlong length = env->GetDirectBufferCapacity(data);
        QByteArray byteArray (const_cast<const char*>(bytes), length);
        QXmlStreamReader reader (byteArray);
        reader.setNamespaceProcessing(false);

        QString currentClass;
        QString fieldName;
        bool readModifier = false;
        bool stop = true;
        while (!stop && !reader.atEnd()) {
            reader.readNext();
            // Switches in while loop, still annoying
            switch (reader.tokenType()) {
            case QXmlStreamReader::NoToken:
            case QXmlStreamReader::Invalid:
                stop = true; // Switches in while loop, still annoying...
                break;
            case QXmlStreamReader::StartElement:
                if (reader.name() == "modifier") {
                    readModifier = true;
                } else if (currentClass.isEmpty()) {
                    classMap.insert(reader.name().toString(),
                                    reader.attributes().value("className").toString());
                    currentClass = reader.name().toString();
                } else {
                    // TODO read name() as field name and store as fieldName
                }
                break;
            case QXmlStreamReader::EndElement:
                if (readModifier) {
                    readModifier = false;
                } else if (fieldName.isEmpty()) {
                    currentClass.clear();
                } else {
                    fieldName.clear();
                }
                break;
            case QXmlStreamReader::Characters:
                if (readModifier) {
                    // TODO read name() as modifier value.
                } else {
                    // TODO read name() as obfuscated field name and store as
                }
                break;
            default:
                break;
            }
        }
        if (reader.hasError()) {
            throw JNIException("Error parsing XML file: " + reader.errorString());
        }
    }
}
