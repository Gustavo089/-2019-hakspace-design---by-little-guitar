#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (){


    FILE *arquivo;
    char comando[25], nomes[100], site[100];

    printf ("escreva o nome do novo executavel\n");


    gets(comando);

    printf("%s\n", comando);
    strcat(comando, ".bat");


    arquivo = fopen(comando, "w");

    if (arquivo == NULL){
        printf ("ERRO");
        return (1);
    }
    

    while (comando[0] != 'f') {
        gets (comando);
        switch (comando[0]){
        case 'c':
            printf("qual o nome que voce deseja por na pasta?\n");
            scanf(" %s[^\n]", nomes);
            fprintf(arquivo, "md %s\n", nomes);        
            break;
        case 'a':
            switch (comando[6]){
            case 'b':
                if (comando[7] == 'i'){
                    fprintf(arquivo, "start explorer\n");
                } else fprintf(arquivo, "start notepad\n"); 
                break;
            case 'c':
                if (comando[7] == 'm'){
                    fprintf(arquivo, "start cmd\n");
                } else fprintf(arquivo, "start calc\n");
                break;
            case 'p':
                if (comando[7] == 'a' && comando[10] == 't'){
                    fprintf(arquivo, "start mspaint\n");
                }else if (comando[7] == 'a' && comando[10] == 'l'){
                    fprintf(arquivo, "start control\n");
                } else fprintf(arquivo, "start powerpnt\n");
                break;
            case 'w':
                if(comando[10] == 'p'){
                    fprintf(arquivo, "start write\n");
                } else fprintf(arquivo, "start winword\n");
                break;
            case't':
                fprintf(arquivo, "start osk\n");
                break;
            case 'l':
                fprintf(arquivo, "start magnify\n");
                break;
            case 'm':
                fprintf(arquivo, "start wmplayer\n");
                break;
            case'e':
                fprintf(arquivo, "start iexplore\n");
                break;
            case's':
                printf ("digite qual site voce vai querer abrir:\n");
                scanf("%s[^\n]", site);
                fprintf(arquivo, "start %s\n", site);
            default:
                break;
            }  
        default:
            break;
        }
        
    }
    fclose(arquivo);    
    printf("criado\n");
    return (0);
}

