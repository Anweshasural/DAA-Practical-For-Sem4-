#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define V 4
bool graph[V][V] = {
   {0, 1, 1, 1},
   {1, 0, 1, 0},
   {1, 1, 0, 1},
   {1, 0, 1, 0}
};
void showColors(int color[]) {
   printf("Assigned Colors are:\n");
   for (int i = 0; i < V; i++)
      printf("%d ", color[i]);
   printf("\n");
}
//check whether putting a color valid for v
bool isValid(int v, int color[], int c) {
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}
bool graphColoring(int colors, int color[], int vertex) {
   //when all vertices are considered      
   if (vertex == V)
      return true;
   for (int col = 1; col <= colors; col++) {
      //check whether color is valid or not 
      if (isValid(vertex, color, col)) {
         color[vertex] = col;
         // go for additional vertices
         if (graphColoring(colors, color, vertex + 1))
            return true;
         color[vertex] = 0;
      }
   }
   //when no colors can be assigned
   return false;
}
bool checkSolution(int m) {
   //make color matrix for each vertex   
   int *color = (int *)malloc(V * sizeof(int)); 
   for (int i = 0; i < V; i++)
      //initially set to 0
      color[i] = 0;
   //for vertex 0 check graph coloring      
   if (graphColoring(m, color, 0) == false) {
      printf("Solution does not exist.\n");
      free(color); 
      return false;
   }
   showColors(color);
   free(color); 
   return true;
}

int main() {
   // Number of colors    
   int colors = 3;
   checkSolution(colors);
   return 0;
}