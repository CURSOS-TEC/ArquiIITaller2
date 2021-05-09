import matplotlib.pyplot as plt

X, Y = [], []
for line in open('./data.dat', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[3])

fig,dataPlot = plt.subplots()
dataPlot.set_xlabel("n (factorial)")
dataPlot.set_ylabel("error")
plt.xscale('log')
dataPlot.plot(X, Y)
plt.show()