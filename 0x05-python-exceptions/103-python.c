#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints basic info about Python lists.
 * @p: A PyObject list object.
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, alloc, i;
    const char *type;
    PyListObject *list = (PyListObject *)p;
    PyVarObject *var = (PyVarObject *)p;

    size = var->ob_size;
    alloc = list->allocated;

    setbuf(stdout, NULL);

    printf("[*] Python list info\n");
    if (strcmp(p->ob_type->tp_name, "list") != 0)
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", alloc);

    for (i = 0; i < size; i++)
    {
        type = list->ob_item[i]->ob_type->tp_name;
        printf("Element %ld: %s\n", i, type);
    }
}

/**
 * print_python_bytes - Prints basic info about Python bytes.
 * @p: A PyObject bytes object.
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;
    unsigned char byte;
    PyObject *repr;

    setbuf(stdout, NULL);

    printf("[.] bytes object info\n");
    if (strcmp(p->ob_type->tp_name, "bytes") != 0)
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    printf("  first 10 bytes: ");
    for (i = 0; i < size && i < 10; i++)
    {
        byte = *(str + i);
        printf("%02x ", byte);
    }
    printf("\n");
}

/**
 * print_python_float - Prints basic info about Python floats.
 * @p: A PyObject float object.
 */
void print_python_float(PyObject *p)
{
    double value;

    setbuf(stdout, NULL);

    printf("[.] float object info\n");
    if (strcmp(p->ob_type->tp_name, "float") != 0)
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = PyFloat_AsDouble(p);
    printf("  value: %f\n", value);
}
