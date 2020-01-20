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

def main():
    if len(sys.argv) != 3:
        print_usage()
        exit(-1)
    N = int(sys.argv[1])
    plot_name = sys.argv[2]

    h = N / max_x
    x = np.linspace(0, max_x, N) 
    y = np.linspace(0, max_y, N)
    X, Y = np.meshgrid(x,y)

    ax1 = plt.axes(projection='3d')
    Z1 = ElepticalAnalyticFunction(X, Y)
    ax1.contour3D(X, Y, Z1, 50)
    
    plt.title("Eleptical_Analytic")
    plt.show()


    ax = plt.axes(projection='3d')

    Z2 = []
    with open(result_file) as result:
        line = result.readline()
        while len(line) != 0:
            curr = [float(x) for x in line.split()]
            Z2.append(curr)
            line = result.readline()
    
    Z2 = np.array(Z2)

    print("Max diff = {}".format(abs(np.max(Z1 - Z2))))
    print("Min diff = {}".format(abs(np.min(Z1 - Z2))))

    print("MSE = {}".format(np.sqrt(np.sum(Z1 - Z2) ** 2) / (N * N)))
    print("MAE = {}".format((np.sum(Z1 - Z2) ** 2) / (N * N)))
    ax.contour3D(X, Y, Z2, 50)

    plt.title("Eleptical_" + plot_name)
    plt.show()
if __name__ == "__main__":
    main()