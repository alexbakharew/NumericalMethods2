import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import math

def func(a, x, t):
    return math.exp( - a * t) * math.cos(x)

colors = ["b", "g", "r", "c", "y"]
def main():
    color_count = 0
    COUNT = 3 # Amount of graphics
    vec = []
    with open("res.txt") as input:
        N, K = input.readline().strip("\n").split(" ")
        l, T, a = input.readline().strip("\n").split(" ")
        curr_str = input.readline()
        str_count = 0
        while len(curr_str) != 0:
            if str_count % (int(int(K) / COUNT)) == 0:
                vec.append(curr_str)
            curr_str = input.readline()
            str_count += 1

    h = float(l) / float(N)
    x = []
    y = []
    handles = []
    for i in range(int(N)):
        x.append(h * i)
        y.append(func(float(a), h * i, int(T)))
    plt.plot(x, y, color=colors[color_count])
    plot_label = mpatches.Patch(color=colors[color_count], label='Analytic')
    color_count += 1
    handles.append(plot_label)

    for i in range(COUNT):
        y.clear()
        for val in vec[i].strip("\n").split(" "):
            if val != "":
                y.append(float(val))
        plt.plot(x, y, color = colors[color_count])
        plot_label = mpatches.Patch(color=colors[color_count], label='Numeric' + str(i))
        color_count += 1
        handles.append(plot_label)
        
    plt.ylabel('value')
    plt.xlabel('length')
    plt.legend(handles=handles)
    plt.show()
    

if __name__ == "__main__":
    main()