"""from tslearn import metrics


path, sim = metrics.dtw_path(ts1, ts2)
print(path)
print(sim)
"""
import matplotlib
matplotlib.use("TkAgg")
import numpy as np
from scipy.spatial.distance import cdist
from tslearn import metrics
import matplotlib.pyplot as plt

def compute_DTW(ts1, ts2):
    n, m = len(ts1), len(ts2)
    DTW_matrix = np.zeros((n+1, m+1))
    for i in range(n+1):
        for j in range(m+1):
            DTW_matrix[i, j] = np.inf

    DTW_matrix[0, 0] = 0 # Initializing step
    for i in range(1, n+1):
        for j in range(1, m+1):
            cost = abs(ts1[i-1] - ts2[j-1])
            last_min = np.min([DTW_matrix[i-1, j], DTW_matrix[i, j-1], DTW_matrix[i-1, j-1]])
            DTW_matrix[i, j] = cost + last_min

    print("DTW Distance Matrix")
    return DTW_matrix

def plot_matrix(cdist_matrix, path):
    plt.plot([j for (i, j) in path], [i for (i, j) in path], "w-",linewidth=3.)
    plt.imshow(cdist_matrix)
    plt.show()





#ts1 = [1,3,1,2,1,1,1]
#ts2 = [1,1,3,1,2,1,1]

ts1 = [1, 3, 4, 9, 8, 2, 1, 5, 7, 3]
ts2 = [1, 6, 2, 3, 0, 9, 4, 3, 6, 3]
a = compute_DTW(ts1, ts2)

path, sim = metrics.dtw_path(ts1, ts2)
#arr = metrics.cdist_dtw(ts1, ts2)
print("Using tslearn library")
print(f"Path : {path}")
print(f"Similarity Score: {sim}")
#print(np.shape(arr))
#cdist_matrix = cdist([ts1], [ts2])
#print(cdist_matrix)
plot_matrix(a, path)

