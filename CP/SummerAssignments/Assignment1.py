# 1st line number of cars 
# 2nd line transmission range  
# starting from the 3rd  line, each line represents the x and y coordinates of the cars

# Nodes are cars
# Edges are set if the cars are within transmission range of the cars
# Graph is undirected
# The weight is the distance between 2 cars 
# The graph is represented as an adjacency list

import math
import heapq

class EdgeForHeap:
    def __init__(self, key1, key2, key3):
        self.key1 = key1
        self.key2 = key2
        self.key3 = key3  # This is the cost
    
    def __lt__(self, other):
        return self.key3 < other.key3



numberofcars: int = None
transmissionrange: float = None

class queue(list):
    def dequeue(self):
        if self.isEmpty():
            print("queue is empty")
            return 
        
        return self.pop(0)
    
    def enqueue(self, x):
        self.append(x)

    def peek(self):
        return self[0]
    
    def isEmpty(self):
        return len(self) == 0


class graph: 
    def __init__(self):
        self.cars = [] # list of [id, x, y] id is also the index since it won't change
        self.adjcency_list = {}  # key = node its a list [carID, x, y] , value = list of tuples (carID, weight)


    @staticmethod
    def CountWeight(x1, x2, y1, y2):
        return math.sqrt( (x1 - x2)**2 + (y1 - y2)**2)      
    
    def AddCar(self, id, x, y):
        # edge is there if distance < transmission range 
        # sort according to distance (weight)
    
        if id in self.adjcency_list:
            print("Car already exists")
            return
        
        self.adjcency_list[id] = []

        for key, value in self.adjcency_list.items():
            if key == id: continue

            distance = self.CountWeight(self.cars[key][1] ,x, self.cars[key][2],y)
            if distance <= transmissionrange: 
                self.adjcency_list[id].append( [key ,distance] ) # append in new car
                value.append( [id, distance] ) # append in car whose close
                value.sort(key = lambda x : x[1] )

        self.adjcency_list[id].sort(key = lambda x : x[1] ) 

 
    def __str__(self):
        finalstr = ""
        for key, value in self.adjcency_list.items():
            if len(value) == 0:
                finalstr += f"{key} is isolated \n"
            for val in value: 
                finalstr += f"( {key}, {val[0]}, {val[1]})\n" 
        return finalstr 


    def DisplayAdj(self,id):
        adj = list(map(lambda x: x[1],self.adjcency_list[id]))
        str = ""
        for i in adj :
            str+=f'{i},'
        print(f"The adjacent cars are : {str}")


    def MoveVehicle(self, id, newx, newy):
        if self.adjcency_list[id] == None: 
            print("Car doesn't exist")
            return 

        self.cars[id][1] = newx
        self.cars[id][2] = newy 

        self.adjcency_list[id] = []
        for key, value in self.adjcency_list.items():
            if key == id: continue

            distance = self.CountWeight(self.cars[key][1] ,newx, self.cars[key][2],newy)
            results = [element for element in value if element[0] == id] # check if car already in the connections

            if distance <= transmissionrange: 
                if len(results) != 0: 
                    results[0][1] = distance # Update distance 
                else: 
                    value.append( [id, distance] ) # append the car 
                self.adjcency_list[id].append( [key ,distance] ) # append in new car
            else:
                if len(results) != 0:
                    value.remove(results[0])
                
            value.sort(key = lambda x : x[1] ) 
        self.adjcency_list[id].sort(key = lambda x : x[1] ) 


    def DFS(self, start, visited=None):
        if visited is None:
            visited = set()
        visited.add(start)

        print(start, end=" ")

        for neighbor in self.adjcency_list[start]:
            if neighbor[0] not in visited:
                self.DFS(neighbor[0], visited)
        return visited


    def BFS(self, start):
        visited = set()   
        myqueue = queue()
        myqueue.enqueue(start)
        while not myqueue.isEmpty():
            node = myqueue.dequeue()  

            if node not in visited:
                print(node, end=" ")    
                visited.add(node)

                for neighbor in self.adjcency_list[node]:
                    if neighbor[0] not in visited:
                        myqueue.append(neighbor[0])  


    def MinimumSpanningTree(self, start):
        visited = set([start])
        mst = []
        heap = [ EdgeForHeap(start, connex[0], connex[1]) for connex in self.adjcency_list[start]]
        heapq.heapify(heap) 

        while len(heap) != 0:
            elem = heapq.heappop(heap)
            frm, to, cost = elem.key1, elem.key2, elem.key3
            if to not in visited: 
                visited.add(to)
                mst.append( (frm, to, cost) )

                for val in self.adjcency_list[to]:
                    if val[0] not in visited:
                        heapq.heappush(heap, EdgeForHeap(to, val[0], val[1]) )

        return " ".join([str(i) for i in mst])        


    def GetShortestPath(self, start, destination):
        min_heap = [EdgeForHeap(start, start, 0)]  # (from, to, cost)
        distances = {node: float('infinity') for node in self.adjcency_list}
        distances[start] = 0
        previous_nodes = {node: None for node in self.adjcency_list}
        visited = set()
        
        while min_heap:
            edge = heapq.heappop(min_heap)
            current_distance = edge.key3
            current_node = edge.key2
            
            if current_node in visited:
                continue
            
            visited.add(current_node)
            
            if current_node == destination:
                break
            
            for neighbor, weight in self.adjcency_list[current_node]:
                if neighbor in visited:
                    continue
                
                distance = current_distance + weight
                
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous_nodes[neighbor] = current_node
                    heapq.heappush(min_heap, EdgeForHeap(current_node, neighbor, distance))
        
        path = []
        node = destination
        while previous_nodes[node] is not None:
            path.append((previous_nodes[node], node, distances[node]))
            node = previous_nodes[node]
        
        path.reverse()
        
        if distances[destination] == float('infinity'):
            print("There is no path between the start and destination.")
        else:
            print("Shortest path:")
            for edge in path:
                print(f"Edge from {edge[0]} to {edge[1]}")
            print(f"Total minimum distance: {distances[destination]}")



network = graph()



menu = {} 
def registercommand(func):
    menu[func.__name__.lower()] = func
    def wrapper(*args, **kwargs):
        ret = func(*args, **kwargs)
        return ret 
    return wrapper


@registercommand
def help(command=None, *args):
    """ 
        Returns a list of commands or details about a specified command
        Example: help displayalledges
    """
    retstr = ""

    if not command is None and command.lower() in menu:
        return f"{command} : {menu[command.lower()].__doc__}\n"

    for key, value in menu.items():
        retstr += f"{key} : {value.__doc__} \n"

    return retstr


@registercommand
def DisplayAllEdges(*args):
    """
        Display All Edges
        o in the format (1, 2, 5) [Third parameter is the distance between two cars]
    """
    return str(network)


@registercommand
def DisplayAdjacentVehicles(Car, *args):
    """
        Given a provided ID prints all connected cars
        Example: displayadjacentvehicles 0
    """
    network.DisplayAdj(int(Car))
    return ""


@registercommand
def Movecar(Car, x, y, *args):
    """ 
        Given a car ID move it to the new coordinates    
        Example: movecar 0 5.2 48.2
    """
    network.MoveVehicle(int(Car), float(x), float(y))
    return "Car sucessfully moved"


@registercommand 
def DepthFirstSearch(Car, *args):
    """
        Given a car ID, perform a DFS traversal
        Example: fepthfirstsearch 0
    """
    network.DFS(int(Car))
    return ""


@registercommand
def BreadthFirstSearch(Car, *args):
    """
        Given a car ID, perform a BFS traversal
        Example: breadthfirstsearch 0
    """
    network.BFS(int(Car))
    return ""


@registercommand
def MinimumSpanningTree(Car, *args):
    """
        Given a car ID, generate a Minimum Spanning Tree
        Example: minimumspanningtree 0
    """
    return network.MinimumSpanningTree(int(Car))


@registercommand
def GetShortestPath(Car1, Car2, *args):
    """
        Given two car IDs, find the shortest path between them
        Example: getshortestpath 0 1
    """
    network.GetShortestPath(int(Car1), int(Car2))
    return "" 



def takeinput():
    global numberofcars
    global transmissionrange 

    numberofcars = int(input())
    transmissionrange = float(input())
    for i in range(numberofcars):
        cords = map(float, input().split(" "))
        network.cars.append( [i, *cords] )


enabled = True
if enabled:
    print("Insert the data:")
    takeinput()
    for car in network.cars: 
        network.AddCar(*car)

    print("=====================================================================================")
    print("""
 __          __  _                          
 \ \        / / | |                         
  \ \  /\  / /__| | ___ ___  _ __ ___   ___ 
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \\
    \  /\  /  __/ | (_| (_) | | | | | |  __/
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|
                                            
                                               """)
    print("=====================================================================================")
    print("System is made by Othmane AZOUBI and Mohammed Ayman BOURICH")
    print("Type help for a list of commands")
    print("=====================================================================================")


    while True:
        command = input()
        if command.lower() == "quit":
            break
        command = command.strip().split(" ")
        if command[0].lower() in menu:
            print("=====================================")
            print(menu[command[0].lower()](*command[1:]))
        else:
            print("Invalid command")

        print("\n=====================================================================================\n")


    
 
    