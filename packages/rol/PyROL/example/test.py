from PyROL.PyROL import ROL
from PyROL.vectors.npVector import npVector as vector_type

class norm2Obj(ROL.Objective_double_t):
    def __init__(self, H, g, c=0):
        self.H = H
        self.g = g
        self.c = c
        super().__init__()
    def value(self, x, tol):
        tmp = x.clone()
        self.H.apply(tmp, x, tol)
        tmp.scale(0.5)
        tmp.plus(self.g)
        return x.apply(tmp) + self.c
    def gradient(self, g, x, tol):
        self.H.apply(g, x, tol)
        g.plus(self.g)
    def hessVec(self, hv, v, x, tol):
        self.H.apply(hv, v, tol)
    def invHessVec(self, hv, v, x, tol):
        self.H.applyInverse(hv, v, tol)

# Matrix from rol/example/quadratic/example_01.cpp
class matrix(ROL.LinearOperator_double_t):
    def __init__(self, dim):
        self.dim = dim
        super().__init__()
    def apply(self, Hv, v, tol):
        for i in range(0, self.dim):
            Hv[i] = 2.*v[i]
            if i > 0:
                Hv[i] -= v[i-1]
            if i < self.dim - 1:
                Hv[i] -= v[i+1]

op = matrix(10)
g = vector_type(10, 1.)
x = vector_type(10, 0.)
obj = norm2Obj(op, g)
c = ROL.Constraint_double_t()
a = vector_type(10, 1.)
b = vector_type(10, 1.)
a.scale(2.)
print(a.norm())
a.zero()
print(a.norm())

a.axpy(1., b)
print(a.norm())
print(a.dot(b))

b.setScalar(2.)
a = b
print(a.apply(b))
print(b.norm())
print(b[0])
b[0:2]=[-1., 3.]
print(b[0:3])

print(obj.value(a, 1e-8))

op.apply(b,a,1e-8)
print(b[0:3])
g = vector_type(10, 1.)

params = ROL.getParametersFromXmlFile("input.xml")

problem = ROL.Problem_double_t(obj, x)
#solver = ROL.Solver_double_t(problem, params)

#print(params)

obj_q = ROL.QuadraticObjective_double_t(op, g)
step = ROL.TrustRegionStep_double_t(params)
status = ROL.StatusTest_double_t(params)
algo = ROL.Algorithm_double_t(step,status,False)

algo.run_void(x=x, obj=obj_q)