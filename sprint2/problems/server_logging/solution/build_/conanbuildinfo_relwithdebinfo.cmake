
#################
###  BOOST
#################
set(CONAN_BOOST_ROOT_RELWITHDEBINFO "C:/.conan/cfe78e/1")
set(CONAN_INCLUDE_DIRS_BOOST_RELWITHDEBINFO "C:/.conan/cfe78e/1/include")
set(CONAN_LIB_DIRS_BOOST_RELWITHDEBINFO "C:/.conan/cfe78e/1/lib")
set(CONAN_BIN_DIRS_BOOST_RELWITHDEBINFO )
set(CONAN_RES_DIRS_BOOST_RELWITHDEBINFO )
set(CONAN_SRC_DIRS_BOOST_RELWITHDEBINFO )
set(CONAN_BUILD_DIRS_BOOST_RELWITHDEBINFO )
set(CONAN_FRAMEWORK_DIRS_BOOST_RELWITHDEBINFO )
set(CONAN_LIBS_BOOST_RELWITHDEBINFO libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization)
set(CONAN_PKG_LIBS_BOOST_RELWITHDEBINFO libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization)
set(CONAN_SYSTEM_LIBS_BOOST_RELWITHDEBINFO ole32 dbgeng bcrypt)
set(CONAN_FRAMEWORKS_BOOST_RELWITHDEBINFO )
set(CONAN_FRAMEWORKS_FOUND_BOOST_RELWITHDEBINFO "")  # Will be filled later
set(CONAN_DEFINES_BOOST_RELWITHDEBINFO "-DBOOST_STACKTRACE_USE_NOOP"
			"-DBOOST_STACKTRACE_USE_WINDBG"
			"-DBOOST_STACKTRACE_USE_WINDBG_CACHED"
			"-DBOOST_ALL_NO_LIB")
set(CONAN_BUILD_MODULES_PATHS_BOOST_RELWITHDEBINFO )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_BOOST_RELWITHDEBINFO "BOOST_STACKTRACE_USE_NOOP"
			"BOOST_STACKTRACE_USE_WINDBG"
			"BOOST_STACKTRACE_USE_WINDBG_CACHED"
			"BOOST_ALL_NO_LIB")

set(CONAN_C_FLAGS_BOOST_RELWITHDEBINFO "")
set(CONAN_CXX_FLAGS_BOOST_RELWITHDEBINFO "")
set(CONAN_SHARED_LINKER_FLAGS_BOOST_RELWITHDEBINFO "")
set(CONAN_EXE_LINKER_FLAGS_BOOST_RELWITHDEBINFO "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_BOOST_RELWITHDEBINFO_LIST "")
set(CONAN_CXX_FLAGS_BOOST_RELWITHDEBINFO_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_BOOST_RELWITHDEBINFO_LIST "")
set(CONAN_EXE_LINKER_FLAGS_BOOST_RELWITHDEBINFO_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_BOOST_RELWITHDEBINFO "${CONAN_FRAMEWORKS_BOOST_RELWITHDEBINFO}" "_BOOST" "_RELWITHDEBINFO")
# Append to aggregated values variable
set(CONAN_LIBS_BOOST_RELWITHDEBINFO ${CONAN_PKG_LIBS_BOOST_RELWITHDEBINFO} ${CONAN_SYSTEM_LIBS_BOOST_RELWITHDEBINFO} ${CONAN_FRAMEWORKS_FOUND_BOOST_RELWITHDEBINFO})


#################
###  ZLIB
#################
set(CONAN_ZLIB_ROOT_RELWITHDEBINFO "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d")
set(CONAN_INCLUDE_DIRS_ZLIB_RELWITHDEBINFO "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/include")
set(CONAN_LIB_DIRS_ZLIB_RELWITHDEBINFO "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/lib")
set(CONAN_BIN_DIRS_ZLIB_RELWITHDEBINFO )
set(CONAN_RES_DIRS_ZLIB_RELWITHDEBINFO )
set(CONAN_SRC_DIRS_ZLIB_RELWITHDEBINFO )
set(CONAN_BUILD_DIRS_ZLIB_RELWITHDEBINFO "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/")
set(CONAN_FRAMEWORK_DIRS_ZLIB_RELWITHDEBINFO )
set(CONAN_LIBS_ZLIB_RELWITHDEBINFO zlib)
set(CONAN_PKG_LIBS_ZLIB_RELWITHDEBINFO zlib)
set(CONAN_SYSTEM_LIBS_ZLIB_RELWITHDEBINFO )
set(CONAN_FRAMEWORKS_ZLIB_RELWITHDEBINFO )
set(CONAN_FRAMEWORKS_FOUND_ZLIB_RELWITHDEBINFO "")  # Will be filled later
set(CONAN_DEFINES_ZLIB_RELWITHDEBINFO )
set(CONAN_BUILD_MODULES_PATHS_ZLIB_RELWITHDEBINFO )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_ZLIB_RELWITHDEBINFO )

set(CONAN_C_FLAGS_ZLIB_RELWITHDEBINFO "")
set(CONAN_CXX_FLAGS_ZLIB_RELWITHDEBINFO "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_RELWITHDEBINFO "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_RELWITHDEBINFO "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_ZLIB_RELWITHDEBINFO_LIST "")
set(CONAN_CXX_FLAGS_ZLIB_RELWITHDEBINFO_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_RELWITHDEBINFO_LIST "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_RELWITHDEBINFO_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_ZLIB_RELWITHDEBINFO "${CONAN_FRAMEWORKS_ZLIB_RELWITHDEBINFO}" "_ZLIB" "_RELWITHDEBINFO")
# Append to aggregated values variable
set(CONAN_LIBS_ZLIB_RELWITHDEBINFO ${CONAN_PKG_LIBS_ZLIB_RELWITHDEBINFO} ${CONAN_SYSTEM_LIBS_ZLIB_RELWITHDEBINFO} ${CONAN_FRAMEWORKS_FOUND_ZLIB_RELWITHDEBINFO})


#################
###  BZIP2
#################
set(CONAN_BZIP2_ROOT_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84")
set(CONAN_INCLUDE_DIRS_BZIP2_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/include")
set(CONAN_LIB_DIRS_BZIP2_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/lib")
set(CONAN_BIN_DIRS_BZIP2_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/bin")
set(CONAN_RES_DIRS_BZIP2_RELWITHDEBINFO )
set(CONAN_SRC_DIRS_BZIP2_RELWITHDEBINFO )
set(CONAN_BUILD_DIRS_BZIP2_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/")
set(CONAN_FRAMEWORK_DIRS_BZIP2_RELWITHDEBINFO )
set(CONAN_LIBS_BZIP2_RELWITHDEBINFO bz2)
set(CONAN_PKG_LIBS_BZIP2_RELWITHDEBINFO bz2)
set(CONAN_SYSTEM_LIBS_BZIP2_RELWITHDEBINFO )
set(CONAN_FRAMEWORKS_BZIP2_RELWITHDEBINFO )
set(CONAN_FRAMEWORKS_FOUND_BZIP2_RELWITHDEBINFO "")  # Will be filled later
set(CONAN_DEFINES_BZIP2_RELWITHDEBINFO )
set(CONAN_BUILD_MODULES_PATHS_BZIP2_RELWITHDEBINFO )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_BZIP2_RELWITHDEBINFO )

set(CONAN_C_FLAGS_BZIP2_RELWITHDEBINFO "")
set(CONAN_CXX_FLAGS_BZIP2_RELWITHDEBINFO "")
set(CONAN_SHARED_LINKER_FLAGS_BZIP2_RELWITHDEBINFO "")
set(CONAN_EXE_LINKER_FLAGS_BZIP2_RELWITHDEBINFO "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_BZIP2_RELWITHDEBINFO_LIST "")
set(CONAN_CXX_FLAGS_BZIP2_RELWITHDEBINFO_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_BZIP2_RELWITHDEBINFO_LIST "")
set(CONAN_EXE_LINKER_FLAGS_BZIP2_RELWITHDEBINFO_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_BZIP2_RELWITHDEBINFO "${CONAN_FRAMEWORKS_BZIP2_RELWITHDEBINFO}" "_BZIP2" "_RELWITHDEBINFO")
# Append to aggregated values variable
set(CONAN_LIBS_BZIP2_RELWITHDEBINFO ${CONAN_PKG_LIBS_BZIP2_RELWITHDEBINFO} ${CONAN_SYSTEM_LIBS_BZIP2_RELWITHDEBINFO} ${CONAN_FRAMEWORKS_FOUND_BZIP2_RELWITHDEBINFO})


### Definition of global aggregated variables ###

set(CONAN_DEPENDENCIES_RELWITHDEBINFO boost zlib bzip2)

set(CONAN_INCLUDE_DIRS_RELWITHDEBINFO "C:/.conan/cfe78e/1/include"
			"C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/include"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/include" ${CONAN_INCLUDE_DIRS_RELWITHDEBINFO})
set(CONAN_LIB_DIRS_RELWITHDEBINFO "C:/.conan/cfe78e/1/lib"
			"C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/lib"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/lib" ${CONAN_LIB_DIRS_RELWITHDEBINFO})
set(CONAN_BIN_DIRS_RELWITHDEBINFO "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/bin" ${CONAN_BIN_DIRS_RELWITHDEBINFO})
set(CONAN_RES_DIRS_RELWITHDEBINFO  ${CONAN_RES_DIRS_RELWITHDEBINFO})
set(CONAN_FRAMEWORK_DIRS_RELWITHDEBINFO  ${CONAN_FRAMEWORK_DIRS_RELWITHDEBINFO})
set(CONAN_LIBS_RELWITHDEBINFO libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization zlib bz2 ${CONAN_LIBS_RELWITHDEBINFO})
set(CONAN_PKG_LIBS_RELWITHDEBINFO libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization zlib bz2 ${CONAN_PKG_LIBS_RELWITHDEBINFO})
set(CONAN_SYSTEM_LIBS_RELWITHDEBINFO ole32 dbgeng bcrypt ${CONAN_SYSTEM_LIBS_RELWITHDEBINFO})
set(CONAN_FRAMEWORKS_RELWITHDEBINFO  ${CONAN_FRAMEWORKS_RELWITHDEBINFO})
set(CONAN_FRAMEWORKS_FOUND_RELWITHDEBINFO "")  # Will be filled later
set(CONAN_DEFINES_RELWITHDEBINFO "-DBOOST_STACKTRACE_USE_NOOP"
			"-DBOOST_STACKTRACE_USE_WINDBG"
			"-DBOOST_STACKTRACE_USE_WINDBG_CACHED"
			"-DBOOST_ALL_NO_LIB" ${CONAN_DEFINES_RELWITHDEBINFO})
set(CONAN_BUILD_MODULES_PATHS_RELWITHDEBINFO  ${CONAN_BUILD_MODULES_PATHS_RELWITHDEBINFO})
set(CONAN_CMAKE_MODULE_PATH_RELWITHDEBINFO "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/d51ab9483cc302aabcff00a35e5449c8e9bd7d3d/"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/566af12e4e1dd14ad86aa2dbb96d6ff6eadf2a84/" ${CONAN_CMAKE_MODULE_PATH_RELWITHDEBINFO})

set(CONAN_CXX_FLAGS_RELWITHDEBINFO " ${CONAN_CXX_FLAGS_RELWITHDEBINFO}")
set(CONAN_SHARED_LINKER_FLAGS_RELWITHDEBINFO " ${CONAN_SHARED_LINKER_FLAGS_RELWITHDEBINFO}")
set(CONAN_EXE_LINKER_FLAGS_RELWITHDEBINFO " ${CONAN_EXE_LINKER_FLAGS_RELWITHDEBINFO}")
set(CONAN_C_FLAGS_RELWITHDEBINFO " ${CONAN_C_FLAGS_RELWITHDEBINFO}")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_RELWITHDEBINFO "${CONAN_FRAMEWORKS_RELWITHDEBINFO}" "" "_RELWITHDEBINFO")
# Append to aggregated values variable: Use CONAN_LIBS instead of CONAN_PKG_LIBS to include user appended vars
set(CONAN_LIBS_RELWITHDEBINFO ${CONAN_LIBS_RELWITHDEBINFO} ${CONAN_SYSTEM_LIBS_RELWITHDEBINFO} ${CONAN_FRAMEWORKS_FOUND_RELWITHDEBINFO})
