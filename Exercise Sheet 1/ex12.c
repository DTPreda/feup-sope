#include <stdio.h>
#include <stdlib.h>

void skipLine(FILE* fp, int c){
    while((char)c != '\n'){
        c = fgetc(fp);
        if(feof(fp)){
            return;
        }
    }
}

void skipWord(FILE* fp, int* c){
    while(1){
        *c = fgetc(fp);
        if(feof(fp)){
            return;
        }
        if((char)*c == ' '){
            while((char)*c == ' '){
                *c = fgetc(fp);
                if(feof(fp)){
                    return;
                }    
            }
            return;
        }
    }
}

void skipWords(FILE* fp, int* c, int n){
    while(n != 0){
        skipWord(fp, c);
        n -= 1;
    }
}

int getRegular(char* filename1, char* filename2){
    FILE* files;
    files = fopen(filename1, "r");
    if(files == NULL){
        fprintf(stderr, "Could not read content of directory.\n");
        return 1;
    }

    FILE* ret;
    ret = fopen(filename2, "w+");
    if(ret == NULL){
        fprintf(stderr, "Could not open file to write.\n");
        return 1;
    }

    int c;
    while(1){
        if(feof(files)){
            break;
        }
        c = fgetc(files);
        if((char)c != '-'){
            skipLine(files, c);
        } else {
            skipWords(files, &c, 4);
            while(!feof(files) && (char)c != ' '){
                fprintf(ret, "%c", c);
                c = fgetc(files);
            }
            fprintf(ret, " ");
            skipWords(files, &c, 3);
            while(!feof(files) && (char)c != '\n'){
                fprintf(ret, "%c", c);
                c = fgetc(files);
            }
            fprintf(ret, "\n");
        }
    }

    fclose(files);
    fclose(ret);

    return 0;
}

void getNumberOfFiles(char* filename){
    FILE* temp;
    temp = fopen(filename, "r");

    int c;

    fprintf(stdout, "Total number of regular files in requested directory: ");

    skipWords(temp, &c, 1);
    while(!feof(temp) && (char)c != ' '){
        fprintf(stdout, "%c", c);
        c = fgetc(temp);
    }
    fprintf(stdout, "\n");

    fclose(temp);
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    char command [100];

    sprintf(command, "ls -l %s > temp", argv[1]);
    system(command);

    if(getRegular("temp", "ret") != 0){
        fprintf(stdout, "Unable to fecth regular files.\n");
        return 1;
    }

    sprintf(command, "cat ret");
    system(command);

    sprintf(command, "wc ret > temp");
    system(command);

    getNumberOfFiles("temp");
    
    sprintf(command, "rm -f ret");
    system(command);

    sprintf(command, "rm -f temp");
    system(command);
    return 0;
}