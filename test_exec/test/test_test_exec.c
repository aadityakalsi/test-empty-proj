#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <test-empty-proj/unittest/unittest.h>

#ifdef _WIN32
static char    S_PATH[MAX_PATH];
static HMODULE S_HMODULE;
static int     S_HAND_INIT = false;

void set_exe_parent_path(void) {
    if (!S_HAND_INIT) {
        S_HMODULE = GetModuleHandle(NULL);
        S_HAND_INIT = true;
    }
    GetModuleFileName(S_HMODULE, S_PATH, MAX_PATH);
    *(strrchr(S_PATH, '\\')) = '\0';
}

#endif

int exec_file(const char* name) {
    const char* srchName = NULL;

#ifdef _WIN32
    char newPath[MAX_PATH];
    set_exe_parent_path();
    sprintf(newPath, "%s/%s.exe", S_PATH, name);
    srchName = newPath;
#else
    srchName = name;
#endif

    FILE* f = fopen(srchName, "rb");
    if (f) {
        fclose(f);
        return system(srchName);
    } else {
        return -1;
    }
}

TEST_FUNC( exec ) {
    TEST_TRUE(
            (exec_file("./test_exec") == 0)
         || (exec_file("../test_exec") == 0)
         || (exec_file("../../test_exec") == 0)
    );
}

void SetupTests(void) {
    REG_TEST( exec );
}
