import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from mpl_toolkits import mplot3d
import math
import os
import sys
import numpy as np

def ParabolicAnalyticFunction(a, x, t):
    return math.exp( - a * t) * math.cos(x)

def HyperbolicAnalyticFunction(x, t):
    return math.cos(x) * math.sin(2 * t)

def ElepticalAnalyticFunction(x,y):
    return np.cos(x) * np.cos(y)

def print_usage():
    print("usage:")
    print("N PlotName")

result_file = "res.txt"
max_x = math.pi / 2
max_y = math.pi / 2

def f1():
    handles = []
    ax1 = plt.axes(projection='3d')
    Z1 = ElepticalAnalyticFunction(X, Y)
    ax1.contour3D(X, Y, Z1, 50)
    
    plot_label = mpatches.Patch(color="blue", label='Analytic')
    handles.append(plot_label)
    plt.show()
def f2():

    ax = plt.axes(projection='3d')


    Z2 = []
    with open(result_file) as result:
        line = result.readline()
        while len(line) != 0:
            curr = [float(x) for x in line.split()]
            Z2.append(curr)
            line = result.readline()
    
    Z2 = np.array(Z2)
    ax.contour3D(X, Y, Z2, 50)

    plot_label = mpatches.Patch(color="red", label='Numeric')
    plt.show()

def main():
    if len(sys.argv) != 3:
        print_usage()
        exit(-1)
    N = int(sys.argv[1])
    plot_name = sys.argv[2]

    h = N / max_x
    x = np.linspace(0, max_x, N) 
    y = np.linspace(0, max_y, N)
    global X
    global Y
    X, Y = np.meshgrid(x,y)

    f1()
    f2()

    
    

    #fig = plt.figure()
    # ax.legend(handles=handles)
    # ax.set_xlabel('x')
    # ax.set_ylabel('y')
    # ax.set_zlabel('z')
    # plt.title(plot_name)
    # plt.show()
if __name__ == "__main__":
    main()