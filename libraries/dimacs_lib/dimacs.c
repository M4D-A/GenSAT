#include "dimacs.h"
#include "memory.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> //isdigit()
#include <sys/types.h>
#include <regex.h>

#define NO_FILE_FOUND 1
#define HEADER_CORRUPTED 2
#define DATA_CORRUPTED 3


int file_check(char* filename){ //TODO: LOGICAL CHECK - check variables' and clauses' numbers
    // ++++ READ FILE VARIABLES ++++ //
    FILE* dimacs_file;
    char* line = NULL;
    size_t len = 0;
    size_t read;

    // ++++ REGEX VARIABLES ++++ //
    regex_t exp; 
    regmatch_t match;

    int linenum = 0;

    // ++++ READING FILE AND CREATING DATA STRUCTURE ++++ //
    dimacs_file = fopen(filename,"r");
    if (dimacs_file == NULL)
        return NO_FILE_FOUND;

    // ++++ CHECK COMMENTARY LINES ++++ //
    regcomp(&exp, "^c.*\n", REG_EXTENDED);
    while ((read = getline(&line, &len, dimacs_file)) != -1) { // ommit commentary
        if(regexec(&exp, line, 1, &match, 0) == 0){
            ++linenum;
            continue;
        }
        else
            break;
    }
    regfree(&exp);


    // ++++ CHECK HEADER ++++ // 
    regcomp(&exp, "^p cnf [0-9]+ [0-9]+\n", REG_EXTENDED);
    if(regexec(&exp, line, 1, &match, 0) != 0){
        return HEADER_CORRUPTED; //
    }
    regfree(&exp);


    // ++++ CHECK DATA  ++++ //
    regcomp(&exp, "^(-?[0-9]+ )+0\n", REG_EXTENDED);
    while ((read = getline(&line, &len, dimacs_file)) != -1){
        if(regexec(&exp, line, 1, &match, 0) != 0){
            return DATA_CORRUPTED;
        }
    }
    regfree(&exp);


    fclose(dimacs_file);
    free(line);
    return 0;
}

int** file_read(char* filename){
    // ++++ READ FILE VARIABLES ++++ //
    FILE* dimacs_file;
    char* line = NULL;
    size_t len = 0;
    size_t read;
    int clauses_number = 0;
    int variables_number = 0;
    int** cnf;

    // ++++ READING FILE AND CREATING DATA STRUCTURE ++++ //
    dimacs_file = fopen(filename,"r");
    if (dimacs_file == NULL)
        return NULL;
    
    while ((read = getline(&line, &len, dimacs_file)) != -1) { // ommit commentary
        if(line[0] == 'c')
            continue;
        else
            break;
    }

    char* temp = line;
    while(temp){ // get number of variables from cnf header
        if(isdigit(*temp)){
            variables_number = strtol(temp, &temp, 10);
            break;
        }
        else
            temp++;
    }

    while(temp){ // get number of clauses from cnf header
        if(isdigit(*temp)){
            clauses_number = strtol(temp, &temp, 10);
            break;
        }
        else temp++;
    }

    cnf = (int**)malloc(sizeof(int*) * (clauses_number + 1) ); // allocate clause arrays + header array

    cnf[0] = (int*)malloc(sizeof(int) * 2); // header allocation
    cnf[0][1] = clauses_number; // defining header
    cnf[0][0] = variables_number; 

    int i = 1;
    int j = 1;

    while ((read = getline(&line, &len, dimacs_file)) != -1) { // load clauses to clauses data structure
        int number_of_literals = 0; // number of literals in given clause
        temp = line;
        while(*temp != '\0'){ // count literals in given clause due to " " termination
            if(*temp == ' ') number_of_literals++;
            temp++;
        }
        cnf[i] = (int*)malloc(sizeof(int) * (number_of_literals + 1) ); // allocate memory for i clause 
        cnf[i][0] = number_of_literals; // save number of variables in each clause
        temp = line;
        j = 1;
        while (*temp){ // find literals in clause, save them to structure
            if (  isdigit(*temp) || ( *temp=='-' && isdigit(*(temp+1)) )  ){
                int literal = strtol(temp, &temp, 10);
                if(literal) cnf[i][j++] = literal;
            }
                
            else 
                temp++;
        }
        i++;
    }

    fclose(dimacs_file); // Finishing file usage

    if (line)
        free(line);
    
    return cnf;
}

int** file_save_to(char* filename){
}

void print_formula(int** formula, int transposed){
    int i,j;
    printf("##################\n");
    printf("v: %d, c: %d\n",formula[0][0],formula[0][1]);
    printf("******************\n");
    int length = (transposed) ? formula[0][0] : formula[0][1];
    for(i = 1; i <= length; i++){
        if(formula[i]){
            printf("%3d(%3d): ", i, formula[i][0]);
            for(j = 1; j<= formula[i][0]; j++){
                printf("%3d, ", formula[i][j]);
            }
            printf("\n");
        }
        else{
            printf("%3d(SAT):\n", i);
        }

    }
}
