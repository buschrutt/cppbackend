
#################
###  BOOST
#################
set(CONAN_BOOST_ROOT_MINSIZEREL "C:/.conan/036733/1")
set(CONAN_INCLUDE_DIRS_BOOST_MINSIZEREL "C:/.conan/036733/1/include")
set(CONAN_LIB_DIRS_BOOST_MINSIZEREL "C:/.conan/036733/1/lib")
set(CONAN_BIN_DIRS_BOOST_MINSIZEREL )
set(CONAN_RES_DIRS_BOOST_MINSIZEREL )
set(CONAN_SRC_DIRS_BOOST_MINSIZEREL )
set(CONAN_BUILD_DIRS_BOOST_MINSIZEREL )
set(CONAN_FRAMEWORK_DIRS_BOOST_MINSIZEREL )
set(CONAN_LIBS_BOOST_MINSIZEREL libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization)
set(CONAN_PKG_LIBS_BOOST_MINSIZEREL libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization)
set(CONAN_SYSTEM_LIBS_BOOST_MINSIZEREL ole32 dbgeng bcrypt)
set(CONAN_FRAMEWORKS_BOOST_MINSIZEREL )
set(CONAN_FRAMEWORKS_FOUND_BOOST_MINSIZEREL "")  # Will be filled later
set(CONAN_DEFINES_BOOST_MINSIZEREL "-DBOOST_STACKTRACE_USE_NOOP"
			"-DBOOST_STACKTRACE_USE_WINDBG"
			"-DBOOST_STACKTRACE_USE_WINDBG_CACHED"
			"-DBOOST_ALL_NO_LIB")
set(CONAN_BUILD_MODULES_PATHS_BOOST_MINSIZEREL )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_BOOST_MINSIZEREL "BOOST_STACKTRACE_USE_NOOP"
			"BOOST_STACKTRACE_USE_WINDBG"
			"BOOST_STACKTRACE_USE_WINDBG_CACHED"
			"BOOST_ALL_NO_LIB")

set(CONAN_C_FLAGS_BOOST_MINSIZEREL "")
set(CONAN_CXX_FLAGS_BOOST_MINSIZEREL "")
set(CONAN_SHARED_LINKER_FLAGS_BOOST_MINSIZEREL "")
set(CONAN_EXE_LINKER_FLAGS_BOOST_MINSIZEREL "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_BOOST_MINSIZEREL_LIST "")
set(CONAN_CXX_FLAGS_BOOST_MINSIZEREL_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_BOOST_MINSIZEREL_LIST "")
set(CONAN_EXE_LINKER_FLAGS_BOOST_MINSIZEREL_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_BOOST_MINSIZEREL "${CONAN_FRAMEWORKS_BOOST_MINSIZEREL}" "_BOOST" "_MINSIZEREL")
# Append to aggregated values variable
set(CONAN_LIBS_BOOST_MINSIZEREL ${CONAN_PKG_LIBS_BOOST_MINSIZEREL} ${CONAN_SYSTEM_LIBS_BOOST_MINSIZEREL} ${CONAN_FRAMEWORKS_FOUND_BOOST_MINSIZEREL})


#################
###  ZLIB
#################
set(CONAN_ZLIB_ROOT_MINSIZEREL "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba")
set(CONAN_INCLUDE_DIRS_ZLIB_MINSIZEREL "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/include")
set(CONAN_LIB_DIRS_ZLIB_MINSIZEREL "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/lib")
set(CONAN_BIN_DIRS_ZLIB_MINSIZEREL )
set(CONAN_RES_DIRS_ZLIB_MINSIZEREL )
set(CONAN_SRC_DIRS_ZLIB_MINSIZEREL )
set(CONAN_BUILD_DIRS_ZLIB_MINSIZEREL "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/")
set(CONAN_FRAMEWORK_DIRS_ZLIB_MINSIZEREL )
set(CONAN_LIBS_ZLIB_MINSIZEREL zlib)
set(CONAN_PKG_LIBS_ZLIB_MINSIZEREL zlib)
set(CONAN_SYSTEM_LIBS_ZLIB_MINSIZEREL )
set(CONAN_FRAMEWORKS_ZLIB_MINSIZEREL )
set(CONAN_FRAMEWORKS_FOUND_ZLIB_MINSIZEREL "")  # Will be filled later
set(CONAN_DEFINES_ZLIB_MINSIZEREL )
set(CONAN_BUILD_MODULES_PATHS_ZLIB_MINSIZEREL )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_ZLIB_MINSIZEREL )

set(CONAN_C_FLAGS_ZLIB_MINSIZEREL "")
set(CONAN_CXX_FLAGS_ZLIB_MINSIZEREL "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_MINSIZEREL "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_MINSIZEREL "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_ZLIB_MINSIZEREL_LIST "")
set(CONAN_CXX_FLAGS_ZLIB_MINSIZEREL_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_MINSIZEREL_LIST "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_MINSIZEREL_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_ZLIB_MINSIZEREL "${CONAN_FRAMEWORKS_ZLIB_MINSIZEREL}" "_ZLIB" "_MINSIZEREL")
# Append to aggregated values variable
set(CONAN_LIBS_ZLIB_MINSIZEREL ${CONAN_PKG_LIBS_ZLIB_MINSIZEREL} ${CONAN_SYSTEM_LIBS_ZLIB_MINSIZEREL} ${CONAN_FRAMEWORKS_FOUND_ZLIB_MINSIZEREL})


#################
###  BZIP2
#################
set(CONAN_BZIP2_ROOT_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b")
set(CONAN_INCLUDE_DIRS_BZIP2_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/include")
set(CONAN_LIB_DIRS_BZIP2_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/lib")
set(CONAN_BIN_DIRS_BZIP2_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/bin")
set(CONAN_RES_DIRS_BZIP2_MINSIZEREL )
set(CONAN_SRC_DIRS_BZIP2_MINSIZEREL )
set(CONAN_BUILD_DIRS_BZIP2_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/")
set(CONAN_FRAMEWORK_DIRS_BZIP2_MINSIZEREL )
set(CONAN_LIBS_BZIP2_MINSIZEREL bz2)
set(CONAN_PKG_LIBS_BZIP2_MINSIZEREL bz2)
set(CONAN_SYSTEM_LIBS_BZIP2_MINSIZEREL )
set(CONAN_FRAMEWORKS_BZIP2_MINSIZEREL )
set(CONAN_FRAMEWORKS_FOUND_BZIP2_MINSIZEREL "")  # Will be filled later
set(CONAN_DEFINES_BZIP2_MINSIZEREL )
set(CONAN_BUILD_MODULES_PATHS_BZIP2_MINSIZEREL )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_BZIP2_MINSIZEREL )

set(CONAN_C_FLAGS_BZIP2_MINSIZEREL "")
set(CONAN_CXX_FLAGS_BZIP2_MINSIZEREL "")
set(CONAN_SHARED_LINKER_FLAGS_BZIP2_MINSIZEREL "")
set(CONAN_EXE_LINKER_FLAGS_BZIP2_MINSIZEREL "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_BZIP2_MINSIZEREL_LIST "")
set(CONAN_CXX_FLAGS_BZIP2_MINSIZEREL_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_BZIP2_MINSIZEREL_LIST "")
set(CONAN_EXE_LINKER_FLAGS_BZIP2_MINSIZEREL_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_BZIP2_MINSIZEREL "${CONAN_FRAMEWORKS_BZIP2_MINSIZEREL}" "_BZIP2" "_MINSIZEREL")
# Append to aggregated values variable
set(CONAN_LIBS_BZIP2_MINSIZEREL ${CONAN_PKG_LIBS_BZIP2_MINSIZEREL} ${CONAN_SYSTEM_LIBS_BZIP2_MINSIZEREL} ${CONAN_FRAMEWORKS_FOUND_BZIP2_MINSIZEREL})


### Definition of global aggregated variables ###

set(CONAN_DEPENDENCIES_MINSIZEREL boost zlib bzip2)

set(CONAN_INCLUDE_DIRS_MINSIZEREL "C:/.conan/036733/1/include"
			"C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/include"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/include" ${CONAN_INCLUDE_DIRS_MINSIZEREL})
set(CONAN_LIB_DIRS_MINSIZEREL "C:/.conan/036733/1/lib"
			"C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/lib"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/lib" ${CONAN_LIB_DIRS_MINSIZEREL})
set(CONAN_BIN_DIRS_MINSIZEREL "C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/bin" ${CONAN_BIN_DIRS_MINSIZEREL})
set(CONAN_RES_DIRS_MINSIZEREL  ${CONAN_RES_DIRS_MINSIZEREL})
set(CONAN_FRAMEWORK_DIRS_MINSIZEREL  ${CONAN_FRAMEWORK_DIRS_MINSIZEREL})
set(CONAN_LIBS_MINSIZEREL libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization zlib bz2 ${CONAN_LIBS_MINSIZEREL})
set(CONAN_PKG_LIBS_MINSIZEREL libboost_contract libboost_coroutine libboost_fiber_numa libboost_fiber libboost_context libboost_graph libboost_iostreams libboost_json libboost_locale libboost_log_setup libboost_log libboost_math_c99 libboost_math_c99f libboost_math_c99l libboost_math_tr1 libboost_math_tr1f libboost_math_tr1l libboost_nowide libboost_program_options libboost_random libboost_regex libboost_stacktrace_noop libboost_stacktrace_windbg libboost_stacktrace_windbg_cached libboost_timer libboost_type_erasure libboost_thread libboost_chrono libboost_container libboost_date_time libboost_unit_test_framework libboost_prg_exec_monitor libboost_test_exec_monitor libboost_exception libboost_wave libboost_filesystem libboost_atomic libboost_wserialization libboost_serialization zlib bz2 ${CONAN_PKG_LIBS_MINSIZEREL})
set(CONAN_SYSTEM_LIBS_MINSIZEREL ole32 dbgeng bcrypt ${CONAN_SYSTEM_LIBS_MINSIZEREL})
set(CONAN_FRAMEWORKS_MINSIZEREL  ${CONAN_FRAMEWORKS_MINSIZEREL})
set(CONAN_FRAMEWORKS_FOUND_MINSIZEREL "")  # Will be filled later
set(CONAN_DEFINES_MINSIZEREL "-DBOOST_STACKTRACE_USE_NOOP"
			"-DBOOST_STACKTRACE_USE_WINDBG"
			"-DBOOST_STACKTRACE_USE_WINDBG_CACHED"
			"-DBOOST_ALL_NO_LIB" ${CONAN_DEFINES_MINSIZEREL})
set(CONAN_BUILD_MODULES_PATHS_MINSIZEREL  ${CONAN_BUILD_MODULES_PATHS_MINSIZEREL})
set(CONAN_CMAKE_MODULE_PATH_MINSIZEREL "C:/Users/busch/.conan/data/zlib/1.2.13/_/_/package/be0e5d3ab5a73525c14355a25a6db952cf38d5ba/"
			"C:/Users/busch/.conan/data/bzip2/1.0.8/_/_/package/90210a0d432a6abf77bf30c6c9c43fae68c72a0b/" ${CONAN_CMAKE_MODULE_PATH_MINSIZEREL})

set(CONAN_CXX_FLAGS_MINSIZEREL " ${CONAN_CXX_FLAGS_MINSIZEREL}")
set(CONAN_SHARED_LINKER_FLAGS_MINSIZEREL " ${CONAN_SHARED_LINKER_FLAGS_MINSIZEREL}")
set(CONAN_EXE_LINKER_FLAGS_MINSIZEREL " ${CONAN_EXE_LINKER_FLAGS_MINSIZEREL}")
set(CONAN_C_FLAGS_MINSIZEREL " ${CONAN_C_FLAGS_MINSIZEREL}")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_MINSIZEREL "${CONAN_FRAMEWORKS_MINSIZEREL}" "" "_MINSIZEREL")
# Append to aggregated values variable: Use CONAN_LIBS instead of CONAN_PKG_LIBS to include user appended vars
set(CONAN_LIBS_MINSIZEREL ${CONAN_LIBS_MINSIZEREL} ${CONAN_SYSTEM_LIBS_MINSIZEREL} ${CONAN_FRAMEWORKS_FOUND_MINSIZEREL})
