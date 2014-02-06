#ifndef RSCLASSMAPPER_H
#define RSCLASSMAPPER_H
#include "jace/os_dep.h"
#include "jni.h"

#include <QObject>
#include <QMap>
#include <QFile>

class RSClassMapper : public QObject {
    Q_OBJECT
  private:
    static QString defaultDataFile;
    static RSClassMapper* classmapper;

    QString source;
    QMap<QString, QString> classMap;                // semanticClassName => realClassName
    QMap<QString, QMap<QString, QString>> fieldMap; // semanticClassName => ( semanticFieldName => realFieldName )
    QMap<QString, QMap<QString, int>> modifiers;    // semanticClassName => ( semanticFieldName => modifier value )

  public:
    JACE_API static RSClassMapper* DefaultInstance();

    JACE_API explicit RSClassMapper(QString dataFile);
    JACE_API virtual ~RSClassMapper();

    JACE_API QMap<QString, QString> getFieldMap(QString className) const ;

    JACE_API QString dataFile() const { return source; }
    JACE_API QString getRealName(QString semanticName) const;

    JACE_API void parseData(jbyteArray data);
};

#endif // RSCLASSMAPPER_H
