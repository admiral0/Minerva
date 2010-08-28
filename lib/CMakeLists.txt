project(libminerva)
include_directories(${libminerva_SOURCE_DIR}
		    ${Minerva_SOURCE_DIR}/src 
		    ${Minerva_BINARY_DIR} 
		    ${QCodeEdit_SOURCE_DIR}/document
		    ${QCodeEdit_SOURCE_DIR})
set (	libminerva_HDRS 
	minervadocument.h 
	minervatabwidget.h )
set (	libminerva_SRCS 
	minervadocument.cpp 
	minervatabwidget.cpp )
QT4_WRAP_CPP ( libminerva_MOCS ${libminerva_HDRS})
add_library ( libminerva SHARED ${libminerva_SRCS} ${libminerva_MOCS})
target_link_libraries ( libminerva  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )
set_target_properties( libminerva PROPERTIES
			OUTPUT_NAME "minerva"
			VERSION ${MINERVA_VER_MAJOR}
			SOVERSION "${MINERVA_VER_MAJOR}.${MINERVA_VER_MINOR}" )