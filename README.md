# 42_project-lem-in
In this project, an anthill has to go through a graph-like maze, from a given start room to the end one, using the fastest way and with only one ant in a room at any given time (except the start and end room). My project uses a breath first search algorithm to find the fastest way from start to end.


The program takes in an input formatted as such :  
100            //number of ants   
##start      //indicates that the following room description is the start room   
start 1 3    //room_name x y (for the visualizer bonus, not used in my project)   
##end   
end 3 5   
start-end    //link between rooms   

To try the game, clone the repository and type the following commands :   
make   
./lem-in < maps/1.map    

Other examples of graphs are in the maps folder
