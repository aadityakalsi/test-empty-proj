
#ifndef test_lib_export_h
#define test_lib_export_h

#if defined(TEST_LIB_BUILD)
  #ifdef _WIN32
  #define TEST_LIB_EXPORT __declspec(dllexport)
  #else
  #define TEST_LIB_EXPORT __attribute__((__visibility__("default")))
  #endif
#else
  #ifdef _WIN32
  #define TEST_LIB_EXPORT __declspec(dllimport)
  #else
  #define TEST_LIB_EXPORT 
  #endif
#endif

TEST_LIB_EXPORT
int test_lib_func(void);

#endif//test_lib_export_h
