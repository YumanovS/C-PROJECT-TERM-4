#include <stdio.h>
#include <Python.h>

static PyObject *solve(PyObject *self,PyObject *args){
	double a[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    double f[4][1] = {{0.3},{0.5},{0.7},{0.9}};
    double x[4][1] = {{0},{0},{0},{0}};
    double t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,f1,f2,f3,f4;
    if(!PyArg_ParseTuple(args,"dddddddddddddddddddd", &t1,&t2,&t3,&t4,&t5,&t6,&t7,&t8,&t9,&t10,&t11,&t12,&t13,&t14,&t15,&t16,&f1,&f2,&f3,&f4))
    	return NULL;
    double tt[4][4];
    f[0][0] = f1;f[1][0] = f2;f[2][0] = f3;f[3][0] = f4;
    tt[0][0] = t1;tt[0][1] = t2;tt[0][2] = t3;tt[0][3] = t4;tt[1][0] = t5;tt[1][1] = t6;tt[1][2] = t7;tt[1][3] = t8;tt[2][0] = t9;tt[2][1] = t10;tt[2][2] = t11;tt[2][3] = t12;tt[3][0] = t13;tt[3][1] = t14;tt[3][2] = t15;tt[3][3] = t16;
    for (int i = 0; i <= 3;i++){
        for (int j = 0; j <= 3; j++) {
            a[i][j] = tt[i][j];
        }
    }
    for (int i = 0;i<=3;i++) {
        for (int j = 0; j <= 3; j++) {
            if (i != j){
                a[i][j] = a[i][j] / ((-1)*a[i][i]);
            }

        }

    }
    for (int i = 0; i <= 3; i++){
        x[i][0] = f[i][0] / a[i][i];

    }

    for (int i = 0; i <= 3; i++){
        f[i][0] = f[i][0] / a[i][i];

    }
    for (int i = 0; i <= 3; i++){
        a[i][i] = 0;
    }
    float t = 0;
    for (int k = 0;k <= 16;k++){
        for (int i = 0;i<=3;i++) {
            for (int j = 0; j <= 3; j++) {
                t += (a[i][j] * x[j][0]);
            }

            x[i][0] = t + f[i][0];
            t = 0;
        }
    }

    return Py_BuildValue("dddd",x[0][0],x[1][0],x[2][0],x[3][0]);
}

static PyMethodDef ownmod_methods[] = {
{ 
    "solve",          
     solve,        
     METH_VARARGS, 
     "slau solve function" 
},
{ NULL, NULL, 0, NULL } 

};

static PyModuleDef slausolve = {    
    PyModuleDef_HEAD_INIT,   
    "solve",               
    "that function sole the slau", 
    -1,
    ownmod_methods          
};



PyMODINIT_FUNC PyInit_slausolve(void) {
      PyObject* m;

      m = PyModule_Create(&slausolve);

      if (m == NULL)
          return NULL;
      return m;
}
