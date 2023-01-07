#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256

int substring_norder(char s[],char sub[]){
    int i=0;
    int j=0;
    while(sub[i]!='\0'){
        if(sub[i]==s[j]){
            i++;
            j++;
        }
        else{
            j++;
            if(s[j]=='\0'){
                return 0;
            }
        }   
    }
    return 1;
}


void search_text(char s[], char* text, int option) {
   if (option == 1) {
        // Print all lines in the text that contain the string
        char* line = strtok(text, "\n"); // split the text into lines
        while (line != NULL) {
            if (strstr(line, s) != NULL) { // check if the string appears in the line
                printf("%s\n", line);
            }
            line = strtok(NULL, "\n"); // get the next line
        }
    } else if (option == 2) {
        // Print all words in the text that contain the string
        char* word = strtok(text, " \n"); // split the text into words
        while (word != NULL) {
            if (substring_norder(word, s)) {
                if(strlen(s)+1 == strlen(word) || strlen(s) == strlen(word) )
                { // check if the string is a substring of the word
                printf("%s\n", word);
                }
            }
            word = strtok(NULL, " \n"); // get the next word
        }
    } else {
        printf("Invalid option\n");
    }
} 

// void search_text(char s[], char* text, int option) {
//     if (option == 1) {
//         // Print all lines in the text that contain the string
//         char* line = strtok(text, "\n"); // split the text into lines
//         while (line != NULL) {
//             if (strstr(line, s) != NULL) { // check if the string appears in the line
//                 printf("%s\n", line);
//             }
//             line = strtok(NULL, "\n"); // get the next line
//         }
//     } else if (option == 2) {
//         // Print all words in the text that contain the string
//         char* word = strtok(text, " "); // split the text into words
//         while (word != NULL) {

//             if (strstr(word, s) != NULL )  { 
//             // check if the string appears in the word
            
//             if (strstr(word, "\n") != NULL) {

//                 // word contains a newline character, remove it before printing
//                 word[strcspn(word, "\n")] = '\0';
//                 printf("%s\n", word);
//             }
          
           
//             else{
//                 printf("%s\n", word);
//             }   
//         }
//             word = strtok(NULL, " "); // get the next word
//         }
//     } else {
//         printf("Invalid option\n");
//     }
// }

int main(void) {
    char s[LINE]; // string to search for
    char filename[LINE]; // name of the file to search in

    printf("Enter a string: ");
    fgets(s, LINE, stdin);
    s[strcspn(s, "\n")] = '\0'; // remove the newline character from the string

    printf("Enter the name of the file to search in: ");
    fgets(filename, LINE, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove the newline character from the filename

    printf("Choose an option:\n");
    printf("1. Print all lines in the text that contain the string\n");
    printf("2. Print all words in the text that contain the string\n");
    int option;
    scanf("%d", &option);

    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Read the contents of the file into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    // Search the text
    search_text(s, buffer, option);

    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}
