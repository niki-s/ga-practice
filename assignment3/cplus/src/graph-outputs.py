import numpy as np
import matplotlib.pyplot as plt
import os
import sys

# open directory that contains a list of output files
# read output files to lists and then avg things and do math
# finally use matplotlib to plot graphs
def main():

	outputs = []

	if len(sys.argv) < 1:
		print "please specify path to output files directory"
	else:
		path = sys.argv[1]
	print path
	filelist = os.listdir(path)

	for file in filelist:
		if not file.endswith(".pheno"):	#ignore these
			outputs.append(np.loadtxt(path+file))
			#print path+file

	#print outputs[0]
	# maxY = outputs[1][:, 3]
	# avgY = outputs[1][:, 2]
	# minY = outputs[1][:, 1]
	
	gens = outputs[0][:, 0]
	maxY = []
	avgY = []
	minY = []
	maxYs = []
	avgYs = []
	minYs = []


	# rearrange data into plotable averages
	for gen in range(len(gens)):
		for run in range(len(outputs)):
			minYs.append(outputs[run][gen][1])
			avgYs.append(outputs[run][gen][2])
			maxYs.append(outputs[run][gen][3])

		minY.append(np.average(minYs))
		avgY.append(np.average(avgYs))
		maxY.append(np.average(maxYs))

	for run in range(len(outputs)):
		print outputs[run][0]

	plt.plot(gens, maxY, 'g', gens, avgY, 'b', gens, minY, 'r')
	plt.ylabel('fitness')
	plt.xlabel('generation')
	plt.show()

if __name__ == '__main__':
	main()