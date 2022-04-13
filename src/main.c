#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // wchar_t* program = Py_DecodeLocale("python3", NULL);
    Py_SetPath(Py_DecodeLocale(
        "/usr/local/lib/python39.zip:/usr/local/lib/python3.9:/usr/local/lib/python3.9/lib-dynload:/home/neum/Documenti/py4c/venv39/lib/python3.9/site-packages", NULL));
    //"/usr/local/lib/python39.zip:/usr/local/lib/python3.9:/usr/local/lib/python3.9/lib-dynload:/home/neum/Documenti/py4c/venv39/lib/python3.9/site-packages", NULL));
    /*
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    */
    // Py_SetProgramName((wchar_t*)program); /* optional but recommended */
    /*
    printf("PATH: %s", Py_EncodeLocale(Py_GetPath(), NULL));
    printf("python: %s\n", Py_EncodeLocale(Py_GetProgramName(), NULL));
    printf("version: %s\n", Py_GetVersion());
    */
    Py_SetProgramName(Py_DecodeLocale("python3.9", NULL));
    printf("PATH: %s", Py_EncodeLocale(Py_GetPath(), NULL));

    printf("version: %s\n", Py_GetVersion());
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");
    PyRun_SimpleString("import sys\n"
                       "print(sys.version)\n");
    PyRun_SimpleString("import numpy as np\n"
                       "print(np.array([1,3,5,7,9]))\n");
    // PyRun_SimpleString("import requests\n");

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    // PyMem_RawFree(program);
    return 0;
}