#include <iostream>

using namespace std;

int **p;

void crear2matrices();
void pedirDatos(int**,int,int);
void imprimirMatriz(int**,int,int);
void sumarMatrices(int**,int**,int,int);
void deleteMatriz(int**,int,int);
void imprimirConSuma(int,int,int**,int**);

int main(){

    int **p1,**p2,nF1,nC1;

    cout<<"Ingrese el numero de filas de las matrices: "; cin>>nF1;
    cout<<"Ingrese el numero de columnas de las matrices: "; cin>>nC1;

    p1 = new int*[nF1];
    p2 = new int*[nF1];
    for(int i=0;i<nF1;i++){
        p1[i] = new int[nC1];
        p2[i] = new int[nC1];
    }

    cout<<endl;

    cout<<"\t\t--------Ingrese datos para la primera matriz--------\n\n";
    pedirDatos(p1,nF1,nC1);
    imprimirMatriz(p1,nF1,nC1);

    cout<<endl;

    cout<<"\t\t--------Ingrese datos para la segunda matriz--------\n\n";
    pedirDatos(p2,nF1,nC1);
    imprimirMatriz(p2,nF1,nC1);

    cout<<endl;

    sumarMatrices(p1,p2,nF1,nC1);
    cout<<"\t\t--------El resultado de la suma de las matrices es:--------\n\n";

    imprimirConSuma(nF1,nC1,p1,p2);

    deleteMatriz(p1,nF1,nC1);
    deleteMatriz(p2,nF1,nC1);
    deleteMatriz(p,nF1,nC1);

    return 0;
}

void pedirDatos(int **matriz,int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<"Ingresar posicion ["<<i<<"]["<<j<<"]: ";
            cin>>*(*(matriz+i)+j);
        }
        cout<<endl;
    }
}

void imprimirMatriz(int **matriz,int filas ,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<*(*(matriz+i)+j)<<" ";
        }
        cout<<endl;
    }
}

void sumarMatrices(int **matriz1,int **matriz2,int nfilas1,int ncolumnas1){
    p = new int*[nfilas1];
    for(int i=0;i<nfilas1;i++){
        p[i] = new int[ncolumnas1];
    }
    for(int i=0;i<nfilas1;i++){
        for(int j=0;j<ncolumnas1;j++){
            *(*(p+i)+j) = *(*(matriz1+i)+j) + *(*(matriz2+i)+j);
        }
    }
}

void deleteMatriz(int **matriz,int nfilas,int ncolumnas){
    for(int i=0;i<nfilas;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

void imprimirConSuma(int nFilas,int var,int **matriz1,int **matriz2){

    int varMitad = var/2;
    char matriz[var][var];
    char matriz_2[var][var];

    for(int i=0;i<var;i++){
        for(int j=0;j<var;j++){
            matriz[i][j] = ' ';
            matriz_2[i][j] = ' ';
        }
    }


    matriz[varMitad][varMitad] = '+';

    matriz_2[varMitad][varMitad] = '=';

    for(int i=0;i<nFilas;i++){
        for(int j=0;j<var;j++){
            cout<<matriz1[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<var;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<var;j++){
            cout<<matriz2[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<var;j++){
            cout<<matriz_2[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<var;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}
