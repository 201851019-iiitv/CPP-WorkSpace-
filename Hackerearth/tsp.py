import numpy as np
import random
import operator
import pandas as pd

# To create the locations. Here the x and y are the latitude and longitude respectively, obtained using Google Maps.
class Location:
    def _init_(self, x, y, name):
        self.x = x
        self.y = y
        self.name = name
    
    def distance(self, location):
        xDis = abs(self.x - location.x)
        yDis = abs(self.y - location.y)
        distance = np.sqrt((xDis * 2) + (yDis * 2))
        return distance
    
    def _repr_(self):
        return "(" + str(self.x) + "," + str(self.y) + ")"

# Fitness is inverse of route distanse. We have to minimize route distance, therefore we will maximizing fitness. This function we tell how good each route is.
class Fitness:
    def _init_(self, route):
        self.route = route
        self.distance = 0
        self.fitness= 0.0
    
    def routeDistance(self):
        if self.distance ==0:
            pathDistance = 0
            for i in range(0, len(self.route)):
                fromL = self.route[i]
                toL = None
                if i + 1 < len(self.route):
                    toL = self.route[i + 1]
                else:
                    toL = self.route[0]
                pathDistance += fromL.distance(toL)
            self.distance = pathDistance
        return self.distance
    
    def routeFitness(self):
        if self.fitness == 0:
            self.fitness = 1 / float(self.routeDistance())
        return self.fitness

# Produces routes randomly.
def createRoute(locationList):
    route = random.sample(locationList, len(locationList))
    return route

# Produces a population
def initialPopulation(popSize, locationList):
    population = []

    for i in range(0, popSize):
        population.append(createRoute(locationList))
    return population

# This function returns a list with route ids and their respective fitness scores
def rankRoutes(population):
    fitnessResults = {}
    for i in range(0,len(population)):
        fitnessResults[i] = Fitness(population[i]).routeFitness()
    return sorted(fitnessResults.items(), key = operator.itemgetter(1), reverse = True)

# This function returns a list of route ids, which we use to create the mating pool
def selection(popRanked, eliteSize):
    selectionResults = []
    df = pd.DataFrame(np.array(popRanked), columns=["Index","Fitness"])
    df['cum_sum'] = df.Fitness.cumsum()
    df['cum_perc'] = 100*df.cum_sum/df.Fitness.sum()
    
    for i in range(0, eliteSize):
        selectionResults.append(popRanked[i][0])
    for i in range(0, len(popRanked) - eliteSize):
        pick = 100*random.random()
        for i in range(0, len(popRanked)):
            if pick <= df.iat[i,3]:
                selectionResults.append(popRanked[i][0])
                break
    return selectionResults

# To create the mating pool, we are simply extracting the selected individuals from our population
def matingPool(population, selectionResults):
    matingpool = []
    for i in range(0, len(selectionResults)):
        index = selectionResults[i]
        matingpool.append(population[index])
    return matingpool

# Creating the next generation (Crossover)
def breed(parent1, parent2):
    child = []
    childP1 = []
    childP2 = []
    
    geneA = int(random.random() * len(parent1))
    geneB = int(random.random() * len(parent1))
    
    startGene = min(geneA, geneB)
    endGene = max(geneA, geneB)

    for i in range(startGene, endGene):
        childP1.append(parent1[i])
        
    childP2 = [item for item in parent2 if item not in childP1]

    child = childP1 + childP2
    return child

# Creates offspring population
def breedPopulation(matingpool, eliteSize):
    children = []
    length = len(matingpool) - eliteSize
    pool = random.sample(matingpool, len(matingpool))

    for i in range(0,eliteSize):
        children.append(matingpool[i])
    
    for i in range(0, length):
        child = breed(pool[i], pool[len(matingpool)-i-1])
        children.append(child)
    return children

# We use swap mutation i.e. with specified low probability, two cities will swap places in our route
def mutate(individual, mutationRate):
    for swapped in range(len(individual)):
        if(random.random() < mutationRate):
            swapWith = int(random.random() * len(individual))
            
            city1 = individual[swapped]
            city2 = individual[swapWith]
            
            individual[swapped] = city2
            individual[swapWith] = city1
    return individual

# Creating a mutated population
def mutatePopulation(population, mutationRate):
    mutatedPop = []
    
    for ind in range(0, len(population)):
        mutatedInd = mutate(population[ind], mutationRate)
        mutatedPop.append(mutatedInd)
    return mutatedPop


# Creates a new generation by combining all the above function. We first rank the routes using rankRoutes, then determine our potential parents which allows us to create mating pool. Then to create new generstion we  use breed population and apply then mutate it.
def nextGeneration(currentGen, eliteSize, mutationRate):
    popRanked = rankRoutes(currentGen)
    selectionResults = selection(popRanked, eliteSize)
    matingpool = matingPool(currentGen, selectionResults)
    children = breedPopulation(matingpool, eliteSize)
    nextGeneration = mutatePopulation(children, mutationRate)
    return nextGeneration

# The final Genetic ALgorithm function
def geneticAlgorithm(population, popSize, eliteSize, mutationRate, generations):
    pop = initialPopulation(popSize, population)
    print("Initial Route:-")
    for i in range(len(pop[0])):
        print((pop[0])[i].name,end = " -> ")
    print((pop[0])[0].name)
    print("Initial distance: " + str(1 / rankRoutes(pop)[0][1]))
    
    for i in range(0, generations):
        pop = nextGeneration(pop, eliteSize, mutationRate)
    print("Final Route (Shortest Path):-")
    print("Final distance: " + str(1 / rankRoutes(pop)[0][1]))
    bestRouteIndex = rankRoutes(pop)[0][0]
    bestRoute = pop[bestRouteIndex]
    return bestRoute



if __name__ == "_main_":
    placesList = []

    CityPalace = Location(25.702503034283787, 73.58152248534205, "City Palace")
    placesList.append(CityPalace)
    
    AmberPalace = Location(27.665607356096267, 76.13035074255151, "Amber Palace")
    placesList.append(AmberPalace)
    
    HawaMahal = Location(27.89888431960082, 75.07566318784414, "Hawa Mahal")
    placesList.append(HawaMahal)
    
    ChittorgarhFort = Location(26.49179507068974, 74.28464752181362, "Chittorgarh Fort")
    placesList.append(ChittorgarhFort)
    
    DhebarLake = Location(24.267605308786163, 74.00025745250876, "Dhebar Lake")
    placesList.append(DhebarLake)
    
    KumbhalgarhFort = Location(27.19755931967608, 73.58152248534205, "Kumbhalgarh Fort")
    placesList.append(KumbhalgarhFort)
    
    RanthamboreNationalPark = Location(27.821180947322215, 76.21824137211046, "Ranthambore National Park")
    placesList.append(RanthamboreNationalPark)
    
    BhangarhFort = Location(29.287913803748992, 76.13035074255151, "Bhangarh Fort")
    placesList.append(BhangarhFort)
    
    SariskaTigerReserve = Location(28.90391780739106, 77.09714766769993, "Sariska Tiger Reserve")
    placesList.append(SariskaTigerReserve)
    
    TheTharHeritageMuseum = Location(29.134487314536173, 70.24167856210207, "The Thar Heritage Museum")
    placesList.append(TheTharHeritageMuseum)
    
    JalMahal = Location(28.74991940396533, 76.04246011299257, "Jal Mahal")
    placesList.append(JalMahal)
    
    DilwaraTemples = Location(25.860786617456906, 72.43894430107575, "Dilwara Temples")
    placesList.append(DilwaraTemples)
    
    JaswantThada = Location(27.74342192499812, 73.22995996710627, "Jaswant Thada")
    placesList.append(JaswantThada)
    
    RanthamboreFort = Location(27.197559319676053, 76.39402263122835, "Ranthambore Fort")
    placesList.append(RanthamboreFort)
    
    JaigarhFort = Location(28.59569358526302, 76.56980389034625, "Jaigarh Fort")
    placesList.append(JaigarhFort)
    
    AlbertHallMuseum = Location(26.911833790980342, 75.8194553111577, "Albert Hall Museum")
    placesList.append(AlbertHallMuseum)
    
    BirlaTemple = Location(26.89245423532142, 75.81553157254318, "Birla Temple Jaipur")
    placesList.append(BirlaTemple)
    
    JantarMantar = Location(26.924991563302612, 75.82452781115796, "Jantar Mantar Jaipur")
    placesList.append(JantarMantar)
    
    SajjangarhMonsoonPalace = Location(24.59349746222666, 73.63965924180238, "Sajjangarh Monsoon Palace")
    placesList.append(SajjangarhMonsoonPalace)
    
    MaharanaPratapMemorial  = Location(24.5976062757075, 73.67966285529258, "Maharana Pratap Memorial ")
    placesList.append(MaharanaPratapMemorial )
    
    
    # Here we loop through 500 generations
    bestRoute = geneticAlgorithm(population=placesList, popSize=100, eliteSize=20, mutationRate=0.01, generations=100)
    
    for i in range(len(bestRoute)):
        print((bestRoute[i]).name , end=" -> ")

    print((bestRoute[0]).name)