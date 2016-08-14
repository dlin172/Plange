#This file will download and build mpir source for MSVC++ build
include(vsyasm_install)

function(get_msvc_short_ver OUTPUT_VARIABLE)
	set(MSVC_VERSION_TABLE "1600:10;1700:11;1800:12;1900:14;")	
	string(REGEX MATCH "${MSVC_VERSION}:[0-9]+;" ENTRY "${MSVC_VERSION_TABLE}")
	string(LENGTH ${MSVC_VERSION} L)
	string(SUBSTRING "${ENTRY}" ${L} -1 RESULT)
	string(SUBSTRING "${RESULT}" 1 -1 RESULT)
	string(LENGTH "${RESULT}" L)
	string(SUBSTRING "${RESULT}" 0 ${L} RESULT)
	set(${OUTPUT_VARIABLE} ${RESULT} PARENT_SCOPE)
endfunction()

function(msvc_fetch_mpir)
	if(${MSVC})
		set(DOWNLOADS_DIR "${PROJECT_BINARY_DIR}\\Downloads")
		file(MAKE_DIRECTORY "${DOWNLOADS_DIR}")
		set(MPIR_VERSION "2.7.2")
		set(MPIR_INSTALL_DIR "${PROJECT_BINARY_DIR}\\mpir")
		set(MPIR_INC_OUT "${MPIR_INSTALL_DIR}\\gmp.h")
		set(MPIR_LIB_OUT "${MPIR_INSTALL_DIR}\\mpir.lib")
		set(GMP_INCLUDE_DIRS "${MPIR_INSTALL_DIR}")
		set(MPIR_LIBRARY "${MPIR_INSTALL_DIR}\\mpir.lib")
		if(NOT EXISTS "${MPIR_INC_OUT}" OR NOT EXISTS "${MPIR_LIB_OUT}")
			set(MPIR_DL_BASENAME "mpir-${MPIR_VERSION}")
			set(MPIR_DL_FILENAME "${MPIR_DL_BASENAME}.tar.bz2")
			set(MPIR_DL_LOCATION "${DOWNLOADS_DIR}\\${MPIR_DL_FILENAME}")
			set(MPIR_DL_SERVER "http://mpir.org")
			set(MPIR_DL_URI "${MPIR_DL_SERVER}/${MPIR_DL_FILENAME}")
			if(NOT EXISTS "${MPIR_DL_LOCATION}")
				message(STATUS "Downloading ${MPIR_DL_URI} to ${MPIR_DL_LOCATION}")
				file(DOWNLOAD "${MPIR_DL_URI}" "${MPIR_DL_LOCATION}")				
			endif()
			set(MPIR_SOURCE_DIR "${DOWNLOADS_DIR}\\${MPIR_DL_BASENAME}")
			if(NOT IS_DIRECTORY "${MPIR_SOURCE_DIR}")
				message(STATUS "Unpacking ${MPIR_DL_LOCATION}")
				execute_process(COMMAND "${CMAKE_COMMAND}" "-E" tar xf "${MPIR_DL_LOCATION}" WORKING_DIRECTORY "${DOWNLOADS_DIR}")
			endif()
			get_msvc_short_ver(MSVC_SHORT_VER)
			set(MPIR_SLN_DIR "${MPIR_SOURCE_DIR}\\build.vc${MSVC_SHORT_VER}")
			set(MPIR_SLN_OUT_DIR "${MPIR_SOURCE_DIR}\\lib\\win32\\Debug")
			set(MPIR_SLN_LIB "${MPIR_SLN_OUT_DIR}\\mpir.lib")
			set(MPIR_SLN_INC "${MPIR_SLN_OUT_DIR}\\gmp.h")
			if (NOT EXISTS "${MPIR_SLN_INC}")
				message(STATUS "Building mpir")
				execute_process(COMMAND "${MPIR_SLN_DIR}\\msbuild.bat" gc LIB win32 Debug WORKING_DIRECTORY "${MPIR_SLN_DIR}")
			endif()

			
			#copy files to MPIR_INSTALL_DIR
			file(COPY "${MPIR_SLN_INC}" DESTINATION "${MPIR_INSTALL_DIR}")
			file(COPY "${MPIR_SLN_LIB}" DESTINATION "${MPIR_INSTALL_DIR}")
			file(COPY "${MPIR_SLN_OUT_DIR}\\mpir.pdb" "${MPIR_INSTALL_DIR}")
			
		endif()
		set(GMP_INCLUDE_DIRS "${GMP_INCLUDE_DIRS}" PARENT_SCOPE)
		set(GMP_LIBRARIES "${MPIR_LIBRARY}" PARENT_SCOPE)
	endif()
endfunction()

msvc_fetch_mpir()