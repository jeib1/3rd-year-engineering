#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char* file = argv[1];
    char num[5];
    char pos[7];
    char lin[17];
    char per[12];
    char out[11];
    lin[16] = '\0';
    out[10] = '\0';
    pos[6] = '\0';
    int min = 9999;
    int m = 0;

    FILE *f = fopen(file,"r+");

    if(f == NULL) {
      perror("Error: ");
      return(-1);
    }
    
    fread(num, 4, 1, f);
    int n = atoi(num);
    if(n == 0){
      fprintf(stderr, "error: cola.txt esta vacia\n");
      return(-1);
    }
    fseek(f, 0, SEEK_SET);

    for(int i=0; i<=n-1; i++){
        fseek(f, 5+(17*i)+10, SEEK_SET);
        fread(pos, 6, 1 ,f);
        int cur = atoi(pos);
        if(cur < min){
            min = cur;
            m = i;
        }
        fseek(f, 0, SEEK_SET);
    }

    fseek(f, 5+17*m, SEEK_SET);
    fread(out, 10, 1, f);
    printf("%s\n", out);

    fseek(f, 0, SEEK_SET);
    fseek(f, 5+17*(n-1), SEEK_SET);
    fread(lin, 16, 1 ,f);

    fseek(f, 0, SEEK_SET);
    fseek(f, 5+17*m, SEEK_SET);
    fputs(lin, f);

    fseek(f, 0, SEEK_SET);
    sprintf(per,"%-4d", n-1);
    fputs(per, f);
    fclose(f);
    return 0;
}

