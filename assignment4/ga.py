import random
import math
import sys
from individual import individual

POPSIZE = 10
CHROMSIZE = 10
LAMBDA = POPSIZE
GENERATIONS = 5

Px = 0.8
Pm = 0.01

def initPop(cityList):
	population = []
	for i in range(POPSIZE):
		ind = individual(CHROMSIZE)
		ind.initRandom(cityList)
		population.append(ind)
	return population

def evaluate(population):
	# get the fitness of each individual in the population
	# random for now because I don't have the function
	for individual in population:
		totalDist = 0
		for i in range(CHROMSIZE-1):
			totalDist += math.sqrt(math.pow((individual.chrom[i+1][1]-individual.chrom[i][1]),2) + math.pow((individual.chrom[i+1][2]-individual.chrom[i][2]),2))
		individual.fitness = totalDist

def crossover(parent1, parent2):
	# copy the parents into the children
	child1 = [0] * len(parent1)
	child2 = [0] * len(parent2)

	#if doWithProb returns true, perform pmx crossover
	if doWithProb(Px):
		return child1, child2
		#select portion of string to copy over
		index1 = random.randint(0,CHROMSIZE-1)
		index2 = index1 + int(CHROMSIZE/5) + random.randint(0,5) # doesn't matter if its larger than end of list, won't run over

		# copy swatch that was selected
		child1[index1:index2] = parent1[index1:index2]
		child2[index1:index2] = parent2[index1:index2]

		# do the stuff

		# copy the rest of the values to the children
		for i in range(len(parent1)):
			if child1[i] == 0:
				child1[i] = parent2[i]
			if child2[i] == 0:
				child2[i] = parent1[i]

		# chance of mutation then return the children
		if doWithProb(Pm):
			mutate(child1)
		if doWithProb(Pm):
			mutate(child2)

		return child1, child2

	#else just return the two children no edits
	else:
		# chance for children with no crossover to mutate too
		if doWithProb(Pm):
			mutate(child1)
		if doWithProb(Pm):
			mutate(child2)

		return child1, child2

def mutate(chrom):
	# swap two random cities
	# might swap the same one but thats alright
	index1 = random.randint(0,CHROMSIZE-1)
	index2 = random.randint(0,CHROMSIZE-1)
	tempCity = chrom[index1]

	chrom[index1] = chrom[index2]
	chrom[index2] = tempCity
	

def doWithProb(prob):
	# random.random returns a number between 0 and 1, returns true if generated # is < input probability
	if random.random() < prob:
		return True
	else:
		return False

def getRandomIndividual(population):
	ind = random.randint(0, POPSIZE-1)
	return population[ind]

def openFile(file):
	#  open given file and return list of cities inside it
	file = open(file, 'r')
	cities = []
	for line in file:
		cities.append(line.split())

	# remove all elements that aren't the cities and their coordinates
	coordStart = cities.index(['NODE_COORD_SECTION'])
	coordEnd = cities.index(['EOF'])
	cities = cities[coordStart+1:coordEnd]

	# change elements into not strings
	for c in cities:
		c[0] = int(c[0])
		c[1] = float(c[1])
		c[2] = float(c[2])

	# print cities
	return cities

def avgFitness(population):
	totalFit = 0.0
	for individual in population:
		totalFit += individual.fitness

	return totalFit/float(POPSIZE)

def maxFitness(population):
	currentMax = 0
	for individual in population:
		if individual.fitness > currentMax:
			currentMax = individual.fitness

	return currentMax

def minFitness(population):
	currentMin = 0
	for individual in population:
		if currentMin == 0:
			currentMin = individual.fitness
		else:
			if individual.fitness < currentMin:
				currentMin = individual.fitness

	return currentMin

def main():
	global CHROMSIZE

	filename = sys.argv[1]
	seed = sys.argv[2]

	#cityList = openFile('tsps/burma14.tsp')
	cityList = openFile(filename)
	CHROMSIZE = len(cityList)
	
	random.seed(seed)

	# create initial population with random strings
	pop = initPop(cityList)

	# get fitnesses for population
	evaluate(pop)

	# test print
	# for ind in pop:
	# 	print ind.fitness

	# reproduce, double population via random selection and etc, for each generation
	for i in range(GENERATIONS):
		#crossover double pop
		for j in range(LAMBDA/2):
			parent1 = getRandomIndividual(pop)
			parent2 = getRandomIndividual(pop)
			child1 = individual(CHROMSIZE)
			child2 = individual(CHROMSIZE)
			child1.chrom, child2.chrom = crossover(parent1.chrom, parent2.chrom)

			# add new children to population
			pop.append(child1)
			pop.append(child2)

		# eval new members of population
		evaluate(pop)

		# sort pop in place based on lowest distance (counts as highest fitness)
		pop.sort(key=lambda individual:individual.fitness)

		# print "more before cull"
		# for ind in pop:
		# 	print ind.fitness

		# remove excess population
		pop[POPSIZE:] = []
		# print "aftercull"
		# for ind in pop:
		# 	print ind.fitness
	for ind in pop:
		print ind.fitness

if __name__ == '__main__':
	main()