
TEXT    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
INDICE: 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
KEY     Q  W  E  R  T  Y  U  I  O  P  A  S  D  F  G  H  J  K  L  Z  X  C  V  B  N  M 
ASCII   81 87 69 82 84 89 85 73 79 80 65 83 68 70 71 72 74 75 76 90 88 67 86 66 78 77

                                M  O  N  O  P  A  T  I  N

ASCII   65 65 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90
TEXT    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
INDICE: 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

char cifrado[26];                       //Creamos una variable para almacenar el texto cifrado
for(int i = 0; i < longitud; i++){
    int index = texto[i] - 'A';        // Guardamos en index el indice del caracter del textoplano
    cifrado[i] = argv[1][index];       //usamos index como posicion para acceder a la letra en llave y
}                                      // en cifrado[i] almacenamos esa letra y asi todo el bucle

//El valor de I representa la posicion alfabetica de cada letra en el abecedario
//RESTANDO cualquier letra a 'A' me da su posicion en el indice del abecedario 
//(A - A = 0), (B - A = 1), (C - A = 2)


