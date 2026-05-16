#include <stdio.h>

int registrarVotos (int votos [][3], char *tituloscanciones[]);
void calcularCancionesMasVotadas (int total, int votos [][3], char *tituloscanciones[], int *top1, int *top2);
void obtenerGanador (int total, int votos [][3], int cancionVotada1, int cancionVotada2);

int main() 
{
    char *tituloscanciones[10] = {"Algo Esta Cambiando","Hasta La Raiz","Teenage Dream","Bacalar","Nunca Es Suficiente","Blank Space","Deja Vu","Dulce Fantasia","Nettles","Monitor"};
    int votosdeparticipantes[100][3] , v1 , v2 , v3 , i ;
    int totaldeparticipantes = 0;
    int cancionVotada1 = 0;
    int cancionVotada2 = 0;
    
    //Leer y almacenar los votos de cada oyente
    totaldeparticipantes = registrarVotos (votosdeparticipantes, tituloscanciones);
    if (totaldeparticipantes == 0)
    {
        printf("No hay participantes.");
        return 0;
    }
    
    //Calcular votos de cada canción y obtener primer y segundo lugar
    calcularCancionesMasVotadas (totaldeparticipantes, votosdeparticipantes, tituloscanciones, &cancionVotada1, &cancionVotada2);
    
    //Asignar puntos a los oyentes y anunciar al ganador
    obtenerGanador (totaldeparticipantes, votosdeparticipantes, cancionVotada1, cancionVotada2);
    
    return 0;
}
    
int registrarVotos (int votos [][3], char *tituloscanciones[])
{
    int total = 0;
    int v1, v2, v3;
    
    printf("CONCURSO\n");
    printf("LISTA DE CANCIONES:\n");
    
    for(int i = 0; i < 10; i++) 
    {
        printf("Numero %d: %s\n", i + 1, tituloscanciones[i]);
    }

    while(total < 100) 
    {
        printf("Ingrese el número de sus 3 canciones favoritas de manera decreciente. Ingrese un -1 si ya no hay más participantes.\n", total + 1);
        
        do
        {
            printf("  1er. lugar: ");
            scanf("%d", &v1);
            if (( v1<1 || v1>10 ) && v1 != -1)
            {
                printf("Dato no válido\n");
            }
        }
        while(( v1<1 || v1>10 ) && v1 != -1);
        
        if(v1 == -1) 
        {
            printf("Total de participantes: %d\n", total);
            break;
        }
                
        do
        {
            printf("  2do. lugar: ");
            scanf("%d", &v2);
            if ( v2<1 || v2>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v2<1 || v2>10 );
        
        do
        {
            printf("  3er. lugar: ");
            scanf("%d", &v3);
            if ( v3<1 || v3>10 )
            {
                printf("Dato no válido\n");
            }
        }
        while( v3<1 || v3>10 );

        votos[total][0] = v1 - 1;
        votos[total][1] = v2 - 1;
        votos[total][2] = v3 - 1;

        total++;
    }
    return total;
}
void calcularCancionesMasVotadas(int total, int votos [][3], char *tituloscanciones[], int *top1, int *top2)
{
    
    int numvot[10]={0,0,0,0,0,0,0,0,0,0};
        
    for( int i=0 ; i<total ; i++ )
    {
        int au=votos[i][0],ad=votos[i][1],at=votos[i][2];
        numvot[au]++;
        numvot[ad]++;
        numvot[at]++;
    }
    printf("Votos totales:\n");
        
    for( int i=0 ; i<10 ; i++ )
    {
        printf("%s = %d votos \n", tituloscanciones[i], numvot[i]);
    }
    
    int puntosCanciones[10] = {0};
    for (int i = 0; i < total; i++)
    {
        int cancion1 = votos[i][0];
        int cancion2 = votos[i][1];
        int cancion3 = votos[i][2];
        
        puntosCanciones[cancion1] = puntosCanciones [cancion1] + 3;
        puntosCanciones[cancion2] = puntosCanciones [cancion2] + 2;
        puntosCanciones[cancion3] = puntosCanciones [cancion3] + 1;
        
    }
    int puntos1 = -1;
    int puntos2 = -1; 
    int cancionVotada1 = 0;
    int cancionVotada2 = 0;
    
    for ( int i = 0; i < 10; i++)
    {
        if (puntosCanciones [i] > puntos1)
        {
            puntos2 = puntos1;
            cancionVotada2 = cancionVotada1;
            
            puntos1 = puntosCanciones [i];
            cancionVotada1 = i;
            
        }
        else if (puntosCanciones [i] > puntos2)
        {
            puntos2 = puntosCanciones [i];
            cancionVotada2 = i;
        }
    }
    printf ("La primera canción más votada es la cancion: %d (%s) \n", cancionVotada1 + 1, tituloscanciones[cancionVotada1]);
    printf ("La segunda canción más votada es la cancion: %d (%s) \n", cancionVotada2 + 1, tituloscanciones[cancionVotada2]);
    
    *top1 = cancionVotada1;
    *top2 = cancionVotada2;
}
    
void obtenerGanador (int total, int votos [][3], int cancionVotada1, int cancionVotada2)
{

    int puntosmaximo = -1;
    int puntosOyente;
    int ganador = 0;
    
    for (int i= 0; i < total; i++)
    {
        puntosOyente = 0;
        int v1 = votos [i][0];
        int v2 = votos [i][1];
        int v3 = votos [i][2];
        
        if ((v1 == cancionVotada1 || v2 == cancionVotada1 || v3 == cancionVotada1) &&
            (v1 == cancionVotada2 || v2 == cancionVotada2 || v3 == cancionVotada2))
        {
            puntosOyente = 60;
        }
            
        else if (v1 == cancionVotada1 || v2 == cancionVotada1 || v3 == cancionVotada1)
        {
            puntosOyente = 30;
        }
        
        else if (v1 == cancionVotada2 || v2 == cancionVotada2 || v3 == cancionVotada2)
        {
            puntosOyente = 20;
        }
    
        printf ("Oyente %d: %d puntos\n", i + 1, puntosOyente);
        
        if (puntosOyente > puntosmaximo)
        {
            puntosmaximo = puntosOyente;
            ganador = i;
        }
    }
    printf ("El ganador es el oyento numero: %d\n FELICIDADES!", ganador + 1);
}
