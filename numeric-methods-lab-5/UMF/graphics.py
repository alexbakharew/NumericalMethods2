import matplotlib.pyplot as plt
import math
from numpy import *
def func(x, t):
    return math.sin(t) * math.cos(x)

def main():

    COUNT = 3 # Amount of graphics
    with open("res.txt") as input:
        N, K = input.readline().strip("\n").split(" ")
        l, T = input.readline().strip("\n").split(" ")
        lines = input.readlines()
        line_count = 1
        vec = []
        lines.reverse()
        for line in lines:
            if line_count % int((int(K) / COUNT)) == 0:
                vec.append(line)
            line_count += 1
    h = float(l) / int(N)
    
    x_values = []
    y_values = []


    for i in range(int(N)):
        x_values.append(h * i)
        y_values.append(func(h * i, int(T)))

    plt.plot(x_values, y_values)

    for line in vec:
        y_values.clear()
        for val in line.strip("\n").split(" "):
            try:
                y_values.append(float(val))
            except ValueError:
                continue
        print(y_values)
        plt.plot(x_values, y_values)

    plt.show()
if __name__ == "__main__":
    main()