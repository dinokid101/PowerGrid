
#ifndef JACE_PROXY_JAVA_SECURITY_CODESOURCE_H
#define JACE_PROXY_JAVA_SECURITY_CODESOURCE_H

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
#ifndef JACE_PROXY_JAVA_SECURITY_CERT_CERTIFICATE_H
#include "jace/proxy/java/security/cert/Certificate.h"
#endif
#ifndef JACE_PROXY_JAVA_SECURITY_CODESIGNER_H
#include "jace/proxy/java/security/CodeSigner.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, net )
class URL;
END_NAMESPACE_4( jace, proxy, java, net )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JBoolean;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, security )

/**
 * The Jace C++ proxy class for java/security/CodeSource.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class CodeSource : public virtual ::jace::proxy::java::lang::Object, public virtual ::jace::proxy::java::io::Serializable {

public: 

/**
 * CodeSource
 *
 */
CodeSource( ::jace::proxy::java::net::URL p0, ::jace::JArray< ::jace::proxy::java::security::cert::Certificate > p1 );

/**
 * CodeSource
 *
 */
CodeSource( ::jace::proxy::java::net::URL p0, ::jace::JArray< ::jace::proxy::java::security::CodeSigner > p1 );

/**
 * hashCode
 *
 */
::jace::proxy::types::JInt hashCode();

/**
 * equals
 *
 */
::jace::proxy::types::JBoolean equals( ::jace::proxy::java::lang::Object p0 );

/**
 * getLocation
 *
 */
::jace::proxy::java::net::URL getLocation();

/**
 * getCertificates
 *
 */
::jace::JArray< ::jace::proxy::java::security::cert::Certificate > getCertificates();

/**
 * getCodeSigners
 *
 */
::jace::JArray< ::jace::proxy::java::security::CodeSigner > getCodeSigners();

/**
 * implies
 *
 */
::jace::proxy::types::JBoolean implies( ::jace::proxy::java::security::CodeSource p0 );

/**
 * toString
 *
 */
::jace::proxy::java::lang::String toString();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
CodeSource( jvalue value );
CodeSource( jobject object );
CodeSource( const CodeSource& object );
CodeSource( const NoOp& noOp );
virtual const JClass* getJavaJniClass() const throw ( JNIException );
static const JClass* staticGetJavaJniClass() throw ( JNIException );
static JEnlister< CodeSource> enlister;
};

END_NAMESPACE_4( jace, proxy, java, security )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::CodeSource>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::security::CodeSource( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::security::CodeSource>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::security::CodeSource>& proxy ) : 
    ::jace::proxy::java::security::CodeSource( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::CodeSource>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::security::CodeSource( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::security::CodeSource( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::security::CodeSource>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::security::CodeSource>& object ) : 
    ::jace::proxy::java::security::CodeSource( object.getJavaJniValue() ), Object( NO_OP ) {

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

#endif // #ifndef JACE_PROXY_JAVA_SECURITY_CODESOURCE_H

