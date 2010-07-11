include_directories (
	#${QCodeEdit_SOURCE_DIR}
	#${QCodeEdit_SOURCE_DIR}
	#${QCodeEdit_SOURCE_DIR}
	${QCodeEdit_SOURCE_DIR}/document
	${Minerva_SOURCE_DIR}/src
	${Minerva_BINARY_DIR}/src
	${QCodeEdit_SOURCE_DIR})
set ( Minerva_HDRS
	minervatabwidget.h
	)

set ( Minerva_SRCS
	main.cpp
	minervawindow.cpp
	minervadocument.cpp
	minervatabwidget.cpp
	minervasettings.cpp
	minervaapplication.cpp
	)

set ( Minerva_UIS
	minervawindow.ui
	)
QT4_WRAP_UI(UIS ${Minerva_UIS})
set ( EXECUTABLE_OUTPUT_PATH ${Minerva_BINARY_DIR} )
set ( Minerva_MOCS
	minervawindow.h
	minervadocument.h
	minervasettings.h
	minervaapplication.h
	)
QT4_WRAP_CPP(MOCS ${Minerva_MOCS})

link_directories (${QCodeEdit_BINARY_DIR}) 

configure_file (
  "${Minerva_SOURCE_DIR}/minervaconfig.h.in"
  "${Minerva_BINARY_DIR}/minervaconfig.h"
  )


add_executable ( minerva ${Minerva_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( minerva qcodeedit  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} )

install ( TARGETS minerva DESTINATION bin )
