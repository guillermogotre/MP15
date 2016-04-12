#include <cstring>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

Imagen::Imagen(){
   nfilas = 0;
   ncolumnas = 0;
}; 
   
Imagen::Imagen(int filas, int columnas){
   crear(filas, columnas);
}
   
void Imagen::crear(int filas, int columnas){
   if(filas*columnas < MAXPIXELS){
      nfilas = filas;
      ncolumnas = columnas;
      byte bzero = 0x00;
      for(int i=0; i < filas*columnas; i++)
            setPos(i,bzero);
   }
}
  
int Imagen::filas(){
   return nfilas;
} 

int Imagen::columnas(){
   return ncolumnas;
}
   
void Imagen::set(int y, int x, byte v){
   if(y<nfilas && x<ncolumnas)
      datos[ncolumnas*y + x] = v;
}

byte Imagen::get(int y, int x) {
   return datos[ncolumnas*y + x];
}

void Imagen::setPos(int i, byte v){
   datos[i] = v;
}

byte Imagen::getPos(int i){
   return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
   TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);
   return (tipo == IMG_PGM_BINARIO && nfilas*ncolumnas < MAXPIXELS)?
      leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas):
      false;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
   return (esBinario)?
      escribirPGMBinario (nombreFichero, datos, nfilas, ncolumnas):
      false; //De momento solo escribimos en binario
}

Imagen Imagen::plano(int k){
   Imagen nueva_imagen(nfilas, ncolumnas);
   for(int i=0; i<nfilas; i++){
      for(int j=0; j<ncolumnas; j++){
         byte pixel = get(i,j);
         bool is_one = getbit(pixel, k);
         apagar(pixel);
         if(is_one)
            on(pixel,7);
         nueva_imagen.set(i,j,pixel);
      }
   }
   return nueva_imagen;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
   bool success = maxlong > (ncolumnas*nfilas + nfilas);
   int pos = 0,
      length = strlen(grises);
   if(success){
      for(int i=0; i<nfilas; i++){
         for(int j=0; j<ncolumnas; j++){
            arteASCII[pos++] = grises[1*get(i,j)*length/BITDEPTH];
         }
         arteASCII[pos++]='\n';
      }
   }
   arteASCII[pos] = '\0';
   return success;
}