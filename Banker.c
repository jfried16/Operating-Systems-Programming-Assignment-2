#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    
    // Opens the data file, 
    // with read permission
    FILE *data;
    
    data = fopen("Data.txt", "r");
    
    // Ensures that the data file is open
    if(data == NULL){
        printf ("failed to open file\n");
        return (0);
    }

    // Initialize the number of processes
    // and resources, which is constant
    const int processes = 5;
    const int resources = 3;

    // boolean that determines whether
    // or not the system is in a safe state
    bool safe = true;

    // Initialize the allocation matrix
    int allocated[processes][resources]; 

    // Assign values to the 
    // allocation matrix
    for (int x = 0; x < processes; x++){
        for (int y = 0; y < resources; y++){
            fscanf(data, "%d", &allocated[x][y]);
        }
    }

    // Initiatlize the max matrix
    int max[processes][resources];

    // Assign values to the max matrix
    for (int x = 0; x < processes; x++){
        for (int y = 0; y < resources; y++){
            fscanf(data, "%d", &max[x][y]);
        }
    }

    // Initialize the available array
    int available[3];

    // Assign values to the available array
    for (int x = 0; x < resources; x++){
        fscanf(data, "%d", &available[x]);
    }

    // Close the file
    fclose(data);

    // Initialize an array to tell 
    // which proccesses are finished
    int finish[processes];

    // Set all values in the finish array
    // to 0, to indicate they are not finished
    for (int x = 0; x < processes; x++){
        finish[x] = 0; 
    }

    // Initialize an array to store the
    // safe sequence
    int safeSequence[processes]; 
    
    // Initialize an index to be used for
    // the safe sequence array later
    int index = 0;

    // Initialize the need matrix
    int need[processes][resources];

    // Initialize the values in each spot
    // of the need matrix by taking max - allocated
    // from the same respective spots
    for (int x = 0; x < processes; x++){
        for(int y = 0; y < resources; y++){
            need[x][y] = max[x][y] - allocated[x][y];
        }
    }

    // Initialize a loop
    for(int x = 0; x < resources; x++){
        for(int y = 0; y < processes; y++){
            
            // If a process is not yet finished
            if (finish[y] == 0) {

                // set the safe state to true 
                safe = true;

                // A loop that checks all resources
                // present in a loop
                for(int z = 0; z < resources; z++){
                     
                     // If need is greater that available
                     // it would not be safe to add, so safe
                     // state would be false
                     if (need[y][z] > available[z]){
                         safe = false;
                         break;
                     }
                }
                
                // If all relevant numbers of need
                // are greater than the relevant available
                if (safe == true){

                    // Assign which resource is to be added
                    // then increment the index
                    safeSequence[index++] = y;
                    
                    // Increase the available resources
                    for(int i = 0; i < resources; i++){
                        available[i] += allocated[y][i];
                    }
                    // Indicate that this resource is finished
                    finish[y] = 1;
                }
            }
        }
    }
        // If the loop ended without adding the last
        // element to the safe sequence
        if (safe == false){
            
            // Tell the user about the unsafe state
            printf("System is not in a Safe State.\n");
            
            // Exit 
            exit(1);
        }
    
        // If it passed the check the system is in
        // a safe state
        printf("The system is in a safe state.\nThe following is the safe sequence:\n");
        
        // For loop to print all but last 
        // process in safe sequence
        for(int i = 0; i < processes-1; i++){
            printf(" P%d ->", safeSequence[i]);     
        }
        // Print the last process, 
        // but without an arrow 
        printf(" P%d\n", safeSequence[processes-1]);

        // Return
        return(0);
}