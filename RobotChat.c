#include <stdio.h>
#include <stdlib.h>

int main(){
    int d = 0;
    char secreto[300], s[200];
    printf ("Hola Usuario :D, soy Róboto, el asistente personal más seguro \n");
    while (d!=4){
        printf ("Ahora dime qué quieres hacer: \n");
        printf ("(1) Contarme un secreto importante\n" );
        printf ("(2) Saludarme\n");
        printf ("(3) Ser mi amigo fiel\n" );
        printf ("(4) Abandonarme en el oscuro mundo de la informática :'( \n");
        scanf("%d",&d);

        if (d==1){
            printf ("Dime todo lo que quieras, no le diré a nadie (Separe cada palabra con '_') \n");
            scanf("%s",secreto);
            FILE*file;
            file = fopen("/usr/src/HistorialChat/file.txt","a");
            fprintf(file, secreto);
            fclose(file);
            gets(s);


        }
        if (d==2){printf("Hola a ti también humano!\n");}
        if (d==3){printf("Sabía que podríamos ser unos grandes amigos :D gracias por eso\n");}
        if (d==4){printf("VUELVE PRONTO!!!!! :c\n");}
    }
}
