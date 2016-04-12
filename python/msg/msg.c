
#include "Python.h"


static PyObject * string_s_asterisk(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	Py_buffer msg;
	int i;


	if (PyArg_ParseTuple(args, "s*", &msg)) //no arguements
	{
		printf("Hello %s, %ld bytes.\n", (char *)msg.buf, msg.len);
		char *p = (char *)msg.buf;

		for(i = 0; i < msg.len; ++i)
		{
			printf("0x%02x ", p[i]);
			if (!(i + 1) % 8)
			{
				printf("\n");
			}
		}
		printf("\n");

		ref_obj = Py_BuildValue("is", 0, "success");
	}

	return ref_obj;

}

static PyObject * string_y_asterisk(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	Py_buffer msg;
	int i;

	if (PyArg_ParseTuple(args, "y*", &msg)) //no arguements
	{
		printf("%ld bytes.\n", msg.len);
		unsigned char *p = (unsigned char *)msg.buf;

		for(i = 0; i < msg.len; ++i)
		{
			printf("0x%02x ", p[i]);
			if (!(i + 1) % 8)
			{
				printf("\n");
			}
		}
		printf("\n");

		ref_obj = Py_BuildValue("is", 0, "success");
	}

	return ref_obj;

}


static PyMethodDef msg_methonds[] = {
		{"string_s_asterisk", string_s_asterisk, METH_VARARGS, "strings and buffers: s*"},
		{"string_y_asterisk", string_y_asterisk, METH_VARARGS, "strings and buffers: y*"},

		{NULL, NULL, 0, NULL}
};


static struct PyModuleDef msgmodule = {
		PyModuleDef_HEAD_INIT,
		"msg",
		"python extension samples",
		-1,
		msg_methonds
};

PyMODINIT_FUNC
PyInit_libmsg()
{
	return PyModule_Create(&msgmodule);
}


