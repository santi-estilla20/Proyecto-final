#include <stdio.h>

int main() 
{
    char *tituloscanciones[10] = {"Hielo","La Célula Que Explota","Trátame Suavemente","En La Ciudad De La Furia","Azul","Viento","Lamento Boliviano","La Mentira","Persiana Americana","EoO"};
    int votosdeparticipantes[100][3] , v1 , v2 , v3 , i ;
    int totaldeparticipantes = 0;
    
    printf("CONCURSO\n");
    printf("CANCIONES DISPONIBLES:\n");
    for(i = 0; i < 10; i++) 
    {
        printf("Numero %d: %s\n", i + 1, tituloscanciones[i]);
    }

    while(totaldeparticipantes < 100) 
    {
        printf("Dame la posición de tus 3 canciones, o un -1 si ya no hay más participantes:\n");
        
        do
        {
            printf("  1er lugar (3 pts): ");
            scanf("%d", &v1);
            if (( v1<1 || v1>10 ) && v1 != -1)
            {
                printf("Dato no válido\n");
            }
        }
        while(( v1<1 || v1>10 ) && v1 != -1);
        
        if(v1 == -1) 
        {
            printf("Total de participantes: %d\n", totaldeparticipantes);
            break;
        }
                
        do
        {
            printf("  2do lugar (2 pts): ");
            scanf("%d", &v2);
            if ( v2<1 || v2>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v2<1 || v2>10 );
        
        do
        {
            printf("  3er lugar (1 pt) : ");
            scanf("%d", &v3);
            if ( v3<1 || v3>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v3<1 || v3>10 );

        votosdeparticipantes[totaldeparticipantes][0] = v1;
        votosdeparticipantes[totaldeparticipantes][1] = v2;
        votosdeparticipantes[totaldeparticipantes][2] = v3;

        totaldeparticipantes++;
    }
    
    int numvot[10]={0,0,0,0,0,0,0,0,0,0};
        
    for( i=0 ; i<totaldeparticipantes ; i++ )
    {
        int au=votosdeparticipantes[i][0] - 1,ad=votosdeparticipantes[i][1] - 1,at=votosdeparticipantes[i][2] - 1 ;
        numvot[au]++;
        numvot[ad]++;
        numvot[at]++;
    }
    printf("Votos totales:\n");
        
    for( i=0 ; i<10 ; i++ )
    {
        printf("%s = %d votos totales\n", tituloscanciones[i], numvot[i]);
    }
    
    int puntosCanciones[10] = {0};
    for (int i = 0; i < totaldeparticipantes; i++)
    {
        int cancion1 = votosdeparticipantes[i][0];
        int cancion2 = votosdeparticipantes[i][1];
        int cancion3 = votosdeparticipantes[i][2];
        
        puntosCanciones[cancion1] = puntosCanciones [cancion1] + 3;
        puntosCanciones[cancion2] = puntosCanciones [cancion2] + 2;
        puntosCanciones[cancion3] = puntosCanciones [cancion3] + 1;
        
    }
    int lugar1 = -1;
    int lugar2 = -1; 
    int numcancion1 = 0;
    int numcancion2 = 0;
    
    for ( int i = 0; i < 10; i++)
    {
        if (puntosCanciones [i] > lugar1)
        {
            lugar2 = lugar1;
            numcancion2 = numcancion1;
            
            lugar1 = puntosCanciones [i];
            numcancion1 = i;
            
        }
        else if (puntosCanciones [i] > lugar2)
        {
            lugar2 = puntosCanciones [i];
            numcancion2 = i;
        }
    }
    printf ("La primera canción más votada es la cancion: %d\n", numcancion1 );
    printf ("La segunda canción más votada es la cancion: %d\n", numcancion2 );
    return 0;
}
