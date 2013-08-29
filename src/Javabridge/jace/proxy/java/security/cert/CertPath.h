
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H
#define JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JENLISTER_H
#include "jace/JEnlister.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * The interfaces implemented by this class.
 *
 */
#ifndef JACE_PROXY_JAVA_IO_SERIALIZABLE_H
#include "jace/proxy/java/io/Serializable.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class Iterator;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, java, security, cert )
class CertificateEncodingException;
END_NAMESPACE_5( jace, proxy, java, security, cert )

BEGIN_NAMESPACE_4( jace, proxy, java, util )
class List;
END_NAMESPACE_4( jace, proxy, java, util )

BEGIN_NAMESPACE_5( jace, proxy, java, security, cert )

/**
 * The Jace C++ proxy class for java/security/cert/CertPath.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class CertPath : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable {

public: 

/**
 * getType
 *
 */
::jace::proxy::java::lang::String getType();

/**
 * getEncodings
 *
 */
::jace::proxy::java::util::Iterator getEncodings();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * getEncoded
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > getEncoded();

/**
 * getEncoded
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > getEncoded( ::jace::proxy::java::lang::String p0 );

/**
 * getCertificates
 *
 */
::jace::proxy::java::util::List getCertificates();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CertPath( jvalue value );
CertPath( jobject object );
CertPath( const CertPath& object );
CertPath( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< CertPath> enlister;
};

END_NAMESPACE_5( jace, proxy, java, security, cert )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::cert::CertPath>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::cert::CertPath( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::cert::CertPath>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::cert::CertPath>& proxy ) : 
    ::jace::proxy::java::security::cert::CertPath( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::cert::CertPath>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::cert::CertPath( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::cert::CertPath( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::cert::CertPath>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::cert::CertPath>& object ) : 
    ::jace::proxy::java::security::cert::CertPath( object.getJavaJniValue() ), Object( NO_OP ) {

    fieldID = object.fieldID; 

    if ( object.parent ) {
      JNIEnv* env = ::jace::helper::attach();
      parent = ::jace::helper::newGlobalRef( env, object.parent );
    }
    else {
      parent = 0;
    }

    if ( object.parentClass ) {
      JNIEnv* env = ::jace::helper::attach();
      parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
    }
    else {
      parentClass = 0;
    }
  }
#endif

END_NAMESPACE( jace )

#endif // #ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTPATH_H

