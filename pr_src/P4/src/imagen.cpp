#include <imagen.h>
#include <iostream>

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
      byte bzero;
      apagar(bzero);
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
   bool exito = false;
   if(nfilas*ncolumnas < MAXPIXELS){
      if(tipo == IMG_PGM_BINARIO)
         exito = leerPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
      else if(tipo == IMG_PGM_TEXTO){
         exito = leerPGMTexto (nombreFichero, datos, nfilas, ncolumnas);
      }
   }
   return exito;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
   return (esBinario)?
      escribirPGMBinario (nombreFichero, datos, nfilas, ncolumnas):
      escribirPGMTexto (nombreFichero, datos, nfilas, ncolumnas);
}

Imagen Imagen::plano(int k) {
   Imagen nuevaImagen(nfilas, ncolumnas);
   int tam = nfilas*ncolumnas;
   for (int i = 0; i < tam; ++i) {
      byte pixel;
      apagar(pixel);
      if (getbit(getPos(i), k))
         on(pixel, 7);
      nuevaImagen.setPos(i, pixel);
   }
   return nuevaImagen;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
   bool success = maxlong > (ncolumnas + 1)*nfilas;
   int pos = 0,
      cardinal = strlen(grises);
   if(success){
      for(int i = 0; i < nfilas; i++){
         for(int j = 0; j < ncolumnas; j++){
            arteASCII[pos++] = grises[get(i,j)*cardinal/BITDEPTH];
         }
         arteASCII[pos++]='\n';
      }
   }
   arteASCII[pos] = '\0';
   return success;
}