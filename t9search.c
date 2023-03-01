#include <stdio.h>
#include <string.h>

//edited array of names ; namesCh contains numbers that represent the characters of the name
char namesCh[100]; 

//KB - KeyBoard
char KB[10][5] = { 
        "+",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
};

//checking the length of the string
//returns 1 or 0
// 1 - OK, 0 - Error
char checkTheLengthOfTheString(char * string){
    for (int i = 0; i < 101; i++){

        if (string[i] == '\0'){
            return 1;
        }
    }
    return 0;
}

//the function removes the line feed character
void deleteSpaces(char *names, char *numbers){

    names[strcspn(names, "\r\n")] = '\0';
    numbers[strcspn(numbers, "\r\n")] = '\0';

    return;
}

//Change the case of uppercase letters
void editReg(char *names) {
    for (int i = 0; names[i] != '\0'; i++)
        if (names[i] >= 'A' && names[i] <= 'Z') {
            names[i] += 32;
        }
    return;
}

//this is where our name comes in
void namesToChar(char *names) 
{
    int len = (int) strlen(names);

    editReg(names);

   for (int i = 0; i < len; i++)
   {
       for (int j = 0; j < 10; j++)
       {
           if (names[i] == ' ') // gap check 
           {
               namesCh[i] = ' '; // found - writes a space character in the modified array
               break;
           }
           if (strchr(KB[j], names[i]) != NULL) //strchr - finding a character in the string
           {
               namesCh[i] = j + '0'; //store one number at a time in an array
               break;
           }
       }
   }
    //printf("%s\n", namesCh); // namesCh - array of numbers
    return;
}

void compareName(char *numbers, char *num, char *names, int *flag){
    if (strstr(namesCh, num)){
        printf("%s, %s\n", names, numbers);
        *flag = 1;
    }
    return;
}


//comparing the numbers from seznam.txt to the argument
// pass the number and the entered argument - a fragment of the number
void compareNum(char *numbers, char *num, char *names, int * flag){

    if(strstr(numbers, num)){

        printf("%s, %s\n", names, numbers);
        *flag = 1;
    }

    return;
}

int main(int argc, char **argv){  //argv[1] - "315"

    char names[103]; //buffer array for the string of the name from the file
    char numbers[103]; //buffer array for the string of the phone number from the file

    int check = 1; //to check if the length of a string is correct

    if (argc == 2) { //if two arguments are entered - the name of the file with contacts and a fragment of the number

        int flag = 0; //in case we did not find a name or a number

        while (fgets(names, sizeof(names), stdin) != NULL) {
            fgets(numbers, sizeof(numbers), stdin);

            deleteSpaces(names, numbers);

            check = checkTheLengthOfTheString(names);
            check = checkTheLengthOfTheString(numbers);

            if (check == 0)
            {
                printf("Error!\nThe contact is too long\n");
                return 117; //the string is too long, program is stopped
            }

            compareNum(numbers, argv[1], names, &flag);

            namesToChar(names);
            compareName(numbers, argv[1], names, &flag);
        }

        // printf("\n%d", flag); //check if any number is found

        if (flag == 0){
            printf("Not found");
        }
    }
    else if (argc > 2){
        printf("Too many arguments");
    }
    else {
        while (fgets(names, sizeof(names), stdin) != NULL) {
            fgets(numbers, sizeof(numbers), stdin);

            deleteSpaces(names, numbers);

            printf("%s, %s\n", names, numbers);
        }
    }

    return 0;
}
