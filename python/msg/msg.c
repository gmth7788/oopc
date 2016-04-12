
#include "Python.h"

static PyObject * string_s(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char  *msg = NULL;

	if (PyArg_ParseTuple(args, "s", &msg)) //no arguements
	{
		printf("Hello %s, %ld bytes.\n", msg, strlen(msg));

		ref_obj = Py_BuildValue("is", 0, "success");
	}

	return ref_obj;
}

static PyObject * string_s_asterisk(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	Py_buffer msg;


	if (PyArg_ParseTuple(args, "s*", &msg)) //no arguements
	{
		printf("Hello %s, %ld bytes.\n", (char *)msg.buf, msg.len);

		ref_obj = Py_BuildValue("is", 0, "success");
	}

	return ref_obj;
}

static PyObject * string_s_well(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char  *msg = NULL;
	int len;

	if (PyArg_ParseTuple(args, "s#", &msg, &len)) //no arguements
	{
		printf("Hello %s, %d bytes.\n", msg, len);

		ref_obj = Py_BuildValue("is", 0, "success");
	}

	return ref_obj;
}

static PyObject * string_z(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char  *msg = NULL;

	if (PyArg_ParseTuple(args, "z", &msg)) //no arguements
	{
		if (NULL != msg)
		{
			printf("Hello %s, %ld bytes.\n", msg, strlen(msg));
			ref_obj = Py_BuildValue("is", 0, "success");
		}
		else
		{
			printf("arguments is NULL.\n");
			ref_obj = Py_BuildValue("is", -1, "failed");
		}
	}

	return ref_obj;
}

static PyObject * string_z_asterisk(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	Py_buffer msg;


	if (PyArg_ParseTuple(args, "z*", &msg)) //no arguements
	{
		if (NULL != msg.buf)
		{
			printf("Hello %s, %ld bytes.\n", (char *)msg.buf, msg.len);
			ref_obj = Py_BuildValue("is", 0, "success");
		}
		else
		{
			printf("arguments is NULL.\n");
			ref_obj = Py_BuildValue("is", -1, "failed");
		}
	}

	return ref_obj;
}

static PyObject * string_z_well(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char  *msg = NULL;
	int len;

	if (PyArg_ParseTuple(args, "z#", &msg, &len)) //no arguements
	{
		if (NULL != msg)
		{
			printf("Hello %s, %d bytes.\n", msg, len);
			ref_obj = Py_BuildValue("is", 0, "success");
		}
		else
		{
			printf("arguments is NULL.\n");
			ref_obj = Py_BuildValue("is", -1, "failed");
		}
	}

	return ref_obj;
}

static PyObject * string_y(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char * msg = NULL;
	int i, len;

	if (PyArg_ParseTuple(args, "y", &msg)) //no arguements
	{
		unsigned char *p = (unsigned char *)msg;
		len = strlen(msg);
		printf("%d bytes.\n", len);

		for(i = 0; i < len; ++i)
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

static PyObject * string_y_well(PyObject *self, PyObject *args)
{
	PyObject * ref_obj = NULL;
	const char * msg = NULL;
	int i, len;

	if (PyArg_ParseTuple(args, "y#", &msg, &len)) //no arguements
	{
		printf("%d bytes.\n", len);
		unsigned char *p = (unsigned char *)msg;

		for(i = 0; i < len; ++i)
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
		{"string_s", string_s, METH_VARARGS, "strings and buffers: s"},
		{"string_s_asterisk", string_s_asterisk, METH_VARARGS, "strings and buffers: s*"},
		{"string_s_well", string_s_well, METH_VARARGS, "strings and buffers: s#"},

		{"string_z", string_z, METH_VARARGS, "strings and buffers: z"},
		{"string_z_asterisk", string_z_asterisk, METH_VARARGS, "strings and buffers: z*"},
		{"string_z_well", string_z_well, METH_VARARGS, "strings and buffers: z#"},

		{"string_y", string_y, METH_VARARGS, "strings and buffers: y"},
		{"string_y_asterisk", string_y_asterisk, METH_VARARGS, "strings and buffers: y*"},
		{"string_y_well", string_y_well, METH_VARARGS, "strings and buffers: y#"},

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


