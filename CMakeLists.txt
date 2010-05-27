cmake_minimum_required( VERSION 2.6 )
project(Minerva)
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR}
	)
add_subdirectory( qcodeedit )
add_subdirectory( src )

set ( MINERVA_FILES qxs/cpp.qxf
	qxs/css.qnfa
	qxs/xml.qxf
	qxs/css.qxf
	qxs/dox.qnfa
	qxs/dox.qxf
	qxs/marks.qxm
	qxs/qtscript.qxf
	qxs/python.qnfa
	qxs/snippet.qnfa
	qxs/php.qnfa
	qxs/qtscript.qnfa
	qxs/tex.qnfa
	qxs/tex.qxf
	qxs/formats.qxf
	qxs/python.qxf
	qxs/cpp.qnfa
	qxs/bibtex.qxf
	qxs/csharp.qxf
	qxs/bibtex.qnfa
	qxs/csharp.qnfa
	qxs/pro.qnfa
	qxs/xml.qnfa
	qxs/coldfusion.qnfa
	qxs/php.qxf
	qxs/pro.qxf)

install ( FILES ${MINERVA_FILES} DESTINATION share/minerva )
