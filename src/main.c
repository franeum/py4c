#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>

const char* p = "python3.7";

int main(int argc, char* argv[])
{
    // wchar_t* program = Py_DecodeLocale("python3", NULL);
    Py_SetPath(Py_DecodeLocale(
        "/home/neum/anaconda3/lib/python37.zip:/home/neum/anaconda3/lib/python3.7:/home/neum/anaconda3/lib/python3.7/lib-dynload:/home/neum/.local/lib/python3.7/site-packages:/home/neum/anaconda3/lib/python3.7/site-packages", NULL));
    /*
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    */
    // Py_SetProgramName((wchar_t*)program); /* optional but recommended */
    printf("PATH: %s", Py_EncodeLocale(Py_GetPath(), NULL));
    printf("python: %s\n", Py_EncodeLocale(Py_GetProgramName(), NULL));
    printf("version: %s\n", Py_GetVersion());

    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");
    PyRun_SimpleString("import sys\n"
                       "print(sys.version)\n");
    PyRun_SimpleString("print(help('modules'))\n");
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    // PyMem_RawFree(program);
    return 0;
}