
#ifndef JACE_PROXY_JAVA_IO_FILENAMEFILTER_H
#include "jace/proxy/java/io/FilenameFilter.h"
#endif

/**
 * Standard Jace headers needed to implement this class.
 *
 */
#ifndef JACE_JARGUMENTS_H
#include "jace/JArguments.h"
#endif
using jace::JArguments;

#ifndef JACE_JMETHOD_H
#include "jace/JMethod.h"
#endif
using jace::JMethod;

#ifndef JACE_JFIELD_H
#include "jace/JField.h"
#endif
using jace::JField;

#ifndef JACE_JCLASS_IMPL_H
#include "jace/JClassImpl.h"
#endif
using jace::JClassImpl;


/**
 * Headers for the classes that this class uses.
 *
 */
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif
#ifndef JACE_PROXY_JAVA_IO_FILE_H
#include "jace/proxy/java/io/File.h"
#endif
#ifndef JACE_PROXY_JAVA_LANG_STRING_H
#include "jace/proxy/java/lang/String.h"
#endif

BEGIN_NAMESPACE_4( jace, proxy, java, io )

/**
 * The Jace C++ proxy class source for java/io/FilenameFilter.
 * Please do not edit this source, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
#ifndef VIRTUAL_INHERITANCE_IS_BROKEN
  #define FilenameFilter_INITIALIZER : ::jace::proxy::java::lang::Object( NO_OP )
#else
  #define FilenameFilter_INITIALIZER
#endif

::jace::proxy::types::JBoolean FilenameFilter::accept( ::jace::proxy::java::io::File p0, ::jace::proxy::java::lang::String p1 ) {
  ::jace::JArguments arguments;
  arguments << p0 << p1;
  return ::jace::JMethod< ::jace::proxy::types::JBoolean >( "accept" ).invoke( *this, arguments );
}

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
FilenameFilter::FilenameFilter() : Object( NO_OP ) { 
}

FilenameFilter::FilenameFilter( jvalue value ) FilenameFilter_INITIALIZER {
  setJavaJniValue( value );
}

FilenameFilter::FilenameFilter( jobject object ) FilenameFilter_INITIALIZER {
  setJavaJniObject( object );
}

FilenameFilter::FilenameFilter( const FilenameFilter& object ) FilenameFilter_INITIALIZER {
  setJavaJniObject( object.getJavaJniObject() );
}

FilenameFilter::FilenameFilter( const NoOp& noOp ) FilenameFilter_INITIALIZER {
}

const JClass* FilenameFilter::staticGetJavaJniClass() throw ( JNIException ) {
  static JClassImpl javaClass( "java/io/FilenameFilter" );
  return &javaClass;
}

const JClass* FilenameFilter::getJavaJniClass() const throw ( JNIException ) {
  return FilenameFilter::staticGetJavaJniClass();
}

JEnlister< FilenameFilter> FilenameFilter::enlister;

END_NAMESPACE_4( jace, proxy, java, io )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> inline ElementProxy< ::jace::proxy::java::io::FilenameFilter>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::java::io::FilenameFilter( element ), Object( NO_OP ), mIndex( index ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::java::io::FilenameFilter>::ElementProxy( const jace::ElementProxy< ::jace::proxy::java::io::FilenameFilter>& proxy ) : 
    ::jace::proxy::java::io::FilenameFilter( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex ) {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif
#ifndef PUT_TSDS_IN_HEADER
  template <> inline JFieldProxy< ::jace::proxy::java::io::FilenameFilter>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::java::io::FilenameFilter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ ) {
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    }
    else {
      parent = parent_;
    }

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FilenameFilter>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::java::io::FilenameFilter( value ), Object( NO_OP ), fieldID( fieldID_ ) {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::java::io::FilenameFilter>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::java::io::FilenameFilter>& object ) : 
    ::jace::proxy::java::io::FilenameFilter( object.getJavaJniValue() ), Object( NO_OP ) {

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

