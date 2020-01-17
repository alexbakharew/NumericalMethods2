import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from mpl_toolkits import mplot3d
import math
import os
import sys
def ParabolicAnalyticFunction(a, x, t):
    return math.exp( - a * t) * math.cos(x)

def HyperbolicAnalyticFunction(x, t):
    return math.cos(x) * math.sin(2 * t)

def ElepticalAnalyticFunction(x,y):
    return math.cos(x) * math.cos(y)

def print_usage():
    print("usage:")
    print("N PlotName")

colors = ["b", "g", "r", "c", "y", "black"]
config_file = "res.txt"
max_x = math.pi / 2
max_y = math.pi / 2

def main():
    if len(sys.argv) != 3:
        print_usage()
        exit(-1)
    N = int(sys.argv[1])
    plot_name = sys.argv[2]
    h = N / max_x
    X = []
    Y = []
    Z = []

    for i in range(N):
        X.append(i * h)
        for j in range(N):
            Y.append(j * h)
            Z.append(ElepticalAnalyticFunction(i * h, j * h))
    
    fig = plt.figure()
    ax = plt.axes(projection='3d')
    ax.contour3D(X, Y, Z, color="red")
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z');

if __name__ == "__main__":
    main()