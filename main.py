import slausolve
import timeit
import slau_clear_python

def test():
    a = slausolve.solve(1,0.17,-0.25,0.54,0.47,1,0.67,-0.32,-0.11,0.35,1,-0.74,0.55,0.43,0.36,1,0.3,0.5,0.7,0.9)
    return a

def test1():
    a = slausolve.solve(1,0.17,-0.25,0.54,0.47,1,0.67,-0.32,-0.11,0.35,1,-0.74,0.55,0.43,0.36,1,0.3,0.5,0.7,0.9)
    b = slausolve.solve(4.33,-1.12,-1.08,1.14,-1.12,4.33,0.24,-1.22,-1.08,0.24,7.21,-3.22,1.14,-1.22,-3.22,5.43,0.3,0.5,0.7,0.9)
    c = slausolve.solve(1,0.42,0.54,0.66,0.42,1,0.32,0.44,0.54,0.32,1,0.22,0.66,0.44,0.22,1,0.3,0.5,0.7,0.9)
    return [a,b,c]

def test_clear():
    slau_clear_python.clear_python_solve()

print("Return of function from module slausolve")
print(test())


time1 = timeit.timeit("test()", setup="from __main__ import test", number=100000)
time2 = timeit.timeit("test_clear()", setup="from __main__ import test_clear", number=100000)


print("Function from module slausolve running time")
print(time1)
print("Function with clear python running time")
print(time2)
print("Function life ratio")
print(time2 / time1)
print("Example of function returns with different arguments")
print(test1())

