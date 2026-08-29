cmake_minimum_required(VERSION 3.20)

project("hxttp"
	VERSION 0.0.1 
	SPDX_LICENSE "GPLv3"
	DESCRIPTION "Postman, but made using the most bleeding edge, and native apis the three OSes have to offer."
	HOMEPAGE_URL "https://github.com/hexd4-software/hxttp"
	LANGUAGES CXX
	)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE)
set_target_properties(${PROJECT_NAME} 
	PROPERTIES 
	CMAKE_CXX_STANDARD 23
	CMAKE_CXX_STANDARD_REQUIRED YES
)

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cc)


if(WIN32)

	target_sources(${PROJECT_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/src/win/win.hh)
elseif (APPLE)

	target_sources(${PROJECT_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/src/darwin/darwin.hh)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_sources(${PROJECT_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/src/linux/linux.hh)

endif()
