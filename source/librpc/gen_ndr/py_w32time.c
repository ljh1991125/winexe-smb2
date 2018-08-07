
/* Python wrapper functions auto-generated by pidl */
#define PY_SSIZE_T_CLEAN 1 /* We use Py_ssize_t for PyArg_ParseTupleAndKeywords */
#include <Python.h>
#include "python/py3compat.h"
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "bin/default/librpc/gen_ndr/ndr_w32time.h"
#include "bin/default/librpc/gen_ndr/ndr_w32time_c.h"

/*
 * These functions are here to ensure they can be optimized out by
 * the compiler based on the constant input values
 */

static inline unsigned long long ndr_sizeof2uintmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return UINT64_MAX;
	case 4:
		return UINT32_MAX;
	case 2:
		return UINT16_MAX;
	case 1:
		return UINT8_MAX;
	}

	return 0;
}

static inline long long ndr_sizeof2intmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return INT64_MAX;
	case 4:
		return INT32_MAX;
	case 2:
		return INT16_MAX;
	case 1:
		return INT8_MAX;
	}

	return 0;
}

static inline PyObject *ndr_PyLong_FromLongLong(long long v)
{
	if (v > LONG_MAX || v < LONG_MIN) {
		return PyLong_FromLongLong(v);
	} else {
		return PyInt_FromLong(v);
	}
}

static inline PyObject *ndr_PyLong_FromUnsignedLongLong(unsigned long long v)
{
	if (v > LONG_MAX) {
		return PyLong_FromUnsignedLongLong(v);
	} else {
		return PyInt_FromLong(v);
	}
}

static PyTypeObject w32time_InterfaceType;

static PyTypeObject *ClientConnection_Type;
static PyTypeObject *ndr_syntax_id_Type;

const struct PyNdrRpcMethodDef py_ndr_w32time_methods[] = {
	{ NULL }
};

static PyObject *interface_w32time_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_w32time);
}

#define PY_DOC_W32TIME "Win32 Time Server"
static PyTypeObject w32time_InterfaceType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "w32time.w32time",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "w32time(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_W32TIME,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_w32time_new,
};

static PyObject *syntax_w32time_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_syntax_init_helper(type, args, kwargs, &ndr_table_w32time.syntax_id);
}

#define PY_DOC_W32TIME_SYNTAX "Win32 Time Server"
static PyTypeObject w32time_SyntaxType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "w32time.w32time_abstract_syntax",
	.tp_doc = "w32time_abstract_syntax()\n"PY_DOC_W32TIME_SYNTAX,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = syntax_w32time_new,
};

static PyMethodDef w32time_methods[] = {
	{ NULL, NULL, 0, NULL }
};

static struct PyModuleDef moduledef = {
	PyModuleDef_HEAD_INIT,
	.m_name = "w32time",
	.m_doc = "w32time DCE/RPC",
	.m_size = -1,
	.m_methods = w32time_methods,
};
MODULE_INIT_FUNC(w32time)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;
	PyObject *dep_samba_dcerpc_misc;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return NULL;

	dep_samba_dcerpc_misc = PyImport_ImportModule("samba.dcerpc.misc");
	if (dep_samba_dcerpc_misc == NULL)
		return NULL;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return NULL;

	ndr_syntax_id_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_misc, "ndr_syntax_id");
	if (ndr_syntax_id_Type == NULL)
		return NULL;

	w32time_InterfaceType.tp_base = ClientConnection_Type;

	w32time_SyntaxType.tp_base = ndr_syntax_id_Type;
	w32time_SyntaxType.tp_basicsize = pytalloc_BaseObject_size();

	if (PyType_Ready(&w32time_InterfaceType) < 0)
		return NULL;
	if (PyType_Ready(&w32time_SyntaxType) < 0)
		return NULL;
	if (!PyInterface_AddNdrRpcMethods(&w32time_InterfaceType, py_ndr_w32time_methods))
		return NULL;

#ifdef PY_W32TIME_PATCH
	PY_W32TIME_PATCH(&w32time_InterfaceType);
#endif
#ifdef PY_W32TIME_ABSTRACT_SYNTAX_PATCH
	PY_W32TIME_ABSTRACT_SYNTAX_PATCH(&w32time_SyntaxType);
#endif
#ifdef PY_ABSTRACT_SYNTAX_PATCH
	PY_ABSTRACT_SYNTAX_PATCH(&w32time_SyntaxType);
#endif

	m = PyModule_Create(&moduledef);
	if (m == NULL)
		return NULL;

	Py_INCREF((PyObject *)(void *)&w32time_InterfaceType);
	PyModule_AddObject(m, "w32time", (PyObject *)(void *)&w32time_InterfaceType);
	Py_INCREF((PyObject *)(void *)&w32time_SyntaxType);
	PyModule_AddObject(m, "w32time_abstract_syntax", (PyObject *)(void *)&w32time_SyntaxType);
	Py_INCREF((PyObject *)(void *)&w32time_SyntaxType);
	PyModule_AddObject(m, "abstract_syntax", (PyObject *)(void *)&w32time_SyntaxType);
#ifdef PY_MOD_W32TIME_PATCH
	PY_MOD_W32TIME_PATCH(m);
#endif
	return m;

}