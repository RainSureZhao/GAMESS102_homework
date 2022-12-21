//
// Created by 赵润朔 on 2022/12/20.
//
#pragma once

#include <vector>

#ifdef MINGW
// MinGW will complain that there is no 'hypot', including "math.h" can fix it (but including "cmath" cannot)
#include <math.h>
#endif

#include <math.h>
#define PY_SSIZE_T_CLEAN
#ifdef _DEBUG
#undef _DEBUG
#include "Python/include/Python.h"
#define _DEBUG
#else
#include "Python/include/Python.h"
#endif

#include "Eigen/Dense"

class RbfNetWork {
public:
    bool Initialize();
    void Finalize();

    std::vector<Eigen::Vector2f>
    Train(const std::vector<Eigen::Vector2f> &in_pos, int num_middle, int epochs, float l, float r, float step);
private:
    PyObject *py_module = nullptr;
    PyObject *py_func_train = nullptr;
    
};