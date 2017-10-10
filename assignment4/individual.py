import random

class individual(object):
	"""docstring for individual"""
	def __init__(self, chromSize):
		self.chromSize = chromSize
		self.fitness = 0
		self.chrom = []
		#self.seed = randomSeed

	def initRandom(self, inlist):
		# create a new chromosome with a 
		for i in range(self.chromSize):
			self.chrom.append(inlist[i])

		random.shuffle(self.chrom)
		