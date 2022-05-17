/*
 * utn.h
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */

#ifndef UTN_H_
#define UTN_H_


/// @brief Solicita un número al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita un número flotante al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos);

/// @brief Solicita una letra al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pCaracterIngresado Puntero al resultado alli se dejara el caracter ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getCaracter(char * pCaracterIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);


/// @brief  Solicita un texto al usuario, lo valida, verifica y devuelve el resultado
///
/// @param stringAIngresar -> puntero al resultado, alli se dejara la frase ingresada por el usuario
/// @param mensaje -> Es el mensaje a ser mostrado
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @param maximoReintentos -> Cantidad de reintentos en caso de error
/// @param lenMinima -> longitud minima requerida de caracteres
/// @param lenMaxima -> longitud maxima requerida de caracteres
/// @return En caso de exito (0), en caso de error (-1)
int utn_getString(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima);



/// @brief Solicita al usuario un telefono (formato string), lo valida, verifica y devuelve resultado
///
/// @param telefonoAIngresar -> puntero al resultado, alli se dejará el telefono ingresado por el usuario
/// @param mensaje -> es el mensaje a ser mostrado
/// @param mensajeError -> es el mensaje a ser mostrado en caso de error
/// @param maximoReintentos -> cantidad de reintentos en caso de error
/// @param len -> longitud maxima del telefono
/// @return -> En caso de exito (0), en caso de error (-1)
int utn_getTelefono(char * telefonoAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int len);



/// @brief Solicita al usuario un numero de documento, lo valida, verifica y devuelve un resultado
///
/// @param numeroDocumento -> puntero al resultado, alli se dejara el el documento ingresado por el usuario
/// @param mensaje -> es el mensaje en el ingreso de datos
/// @param mensajeError -> es el mensaje en caso de error
/// @param maximoReintentos -> cantidad de reintenttos en caso de error
/// @param len -> longitud maxima del documento
/// @return -> En caso de exito (0), en caso de error (-1)
int utn_getDocumento(int * numeroDocumento, char * mensaje, char * mensajeError, int maximoReintentos);



int utn_getMail(char * mailAIngresar, char * mensaje, char * mensajeError, int maximoReintentos);


/// @brief Solicita usuario y contraseña,lo valida, verifica y devuelve un resultado
///
/// @param pIsLogged Puntero al resultado alli se dejará TRUE o FALSE si fue logeado o no
/// @param intentosMaximos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_loguear(int * pIsLogged, int intentosMaximos);



/// @brief Hace un n% descuento, lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param descuento -> porcentaje a descontar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejará el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_hacerDescuento(float monto, int descuento, float * pValorFinal);



/// @brief Agrega un n% de interes, lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param interes -> porcentaje a agregar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejará el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_sumarInteres(float monto, int interes, float * pValorFinal);


/// @brief calcula el costo del pasaje en Bitcoin, verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace la conversion de divisas
/// @param precioBitcoin -> precio del bitcoin actual
/// @param pValorFinal -> putenro al resultado, alli se dejara la conversion final de divisas
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularAPrecioBitcoin(float monto, float precioBitcoin, float * pValorFinal);


/// @brief calcula el precio unitario del km, verifica y valida, devuelve un resultado
///
/// @param kilometro -> kilometros ingresados
/// @param precio -> precio total del vuelo
/// @param pValorFinal -> puntero al resultado, alli se dejara el precio unitario
int utn_calcularPrecioPorKilometro(int kilometro, float precio, float * pValorFinal);


/// @brief Verifica si la respuesta recibida es exitosa (0) o erratica(1)
///
/// @param respuesta -> respuesta 0 exitosa o 1 invalida
/// @param pHayError -> puntero al resultado, alli se dejara 1 si la respuesta es erratica o 0 si es exitosa
/// @return no retorna nada
void utn_verificarSiHayError(int respuesta, int * pHayError);


/// @brief Verifica si la respuesta es exitosa o no y en base a ello imprime un mensaje
///
/// @param hayError -> respuesta para verificacion (0) es exito y (-1) error
/// @param mensaje -> Es el mensaje a ser mostrado en caso de exito
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @return no retorna nada
void utn_imprimirMensajes(int hayError, char * mensaje, char * mensajeError);


/// @brief Cuenta la cantidad de enteros positivos
///
/// @param arr[] -> array de enteros previamente creado
/// @param cantidadPositivos -> puntero a mostrar el resultado de la cantidad de positivos
/// @param longitudArray -> longitud del array para iterar
/// @return En caso de exito (0), en caso de error (-1)
int utn_contarPositivos(int arr[], int * cantidadPositivos, int longitudArray);


/// @brief Cuenta la cantidad de enteros negativos
///
/// @param arr[] -> array de enteros previamente creado
/// @param cantidadNegativos -> puntero a mostrar el resultado de la cantidad de negativos
/// @param longitudArray -> longitud del array para iterar
/// @return En caso de exito (0), en caso de error (-1)
int utn_contarNegativos(int arr[], int * cantidadNegativos, int longitudArray);


/// @brief Inicializa todos los valores del array en cada indice
///
/// @param arr -> array a ser inicializado
/// @param len -> longitud del array
/// @param valorInicial -> valor inicial por cada indice
/// @return En caso de exito (0), en caso de error (-1)
int utn_inicializarArrayDeEnteros(int arr[], int len, int valorInicial);


/// @brief Inicializa todos los valores del array en cada indice
///
/// @param arr -> array a ser inicializado
/// @param len -> longitud del array
/// @param valorInicial -> valor inicial por cada indice
/// @return En caso de exito (0), en caso de error (-1)
int utn_inicializarArrayDeFloats(float arr[], int len, float valorInicial);



/// @brief Suma los numeros pares del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> longitud del array
/// @param resultadoSuma -> puntero donde ira alojada la suma de los pares
/// @return En caso de exito (0), en caso de error (-1)
int utn_sumarEnterosParesDelArray(int arr[], int len, int * resultadoSuma);


/// @brief Calcular el numero impar mayor
///
/// @param arr -> Array que contiene numero enteros
/// @param len-> longitud del array
/// @param mayorImpar punteto donde ira alojado el mayor impar
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularEnteroMayorImpar(int arr[], int len, int * mayorImpar);


/// @brief Imprime todos los valores del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> Longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosArray(int arr[], int len);



/// @brief Imprime los valores pares del array
///
/// @param arr -> array que contiene numeros enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosParesArray(int arr[], int len);


/// @brief Imprime los valores de las posiciones impares del array
///
/// @param arr -> Array que contiene numeros enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirEnterosDePosicionesImparesArray(int arr[],int len);


/// @brief Carga valores enteros en indices aleatorios
///
/// @param arr -> Array inicializado que contendrá numeros enteros
/// @param len -> Longitud del array
/// @param valor -> Valor entero a cargar
/// @param indice -> indice indicado para cargar el dato
/// @return En caso de exito (0), en caso de error (-1)
int utn_cargarEnteroEnIndiceAleatorio(int arr[], int len, int valor, int indice);


/// @brief Carga valores enteros en indices aleatorios
///
/// @param arr -> Array inicializado que contendrá numeros enteros
/// @param len -> Longitud del array
/// @param valor -> Valor entero a cargar
/// @param indice -> indice indicado para cargar el dato
/// @return En caso de exito (0), en caso de error (-1)
int utn_cargarFlotanteEnIndiceAleatorio(float arr[], int len, float valor , int indice);



/// @brief  Calcula el menor de los numeros enteros dependiendo si se dessea que sea negativo, positivo o ambos
///
/// @param arr -> array de numeros enteros
/// @param len -> longitud del array
/// @param pMenor -> puntero donde se almacenara el resultado
/// @param tipo -> (+) calcula el menor positivo, (-) calcula el menor negativo negativo, (=) calcula el menor de ambos tipos
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularMenorEntero(int arr[], int len, int * pMenor, char tipo);


/// @brief  Calcula el mayor de los numeros enteros dependiendo si se dessea que sea negativo, positivo o ambos
///
/// @param arr -> array de numeros enteros
/// @param len -> longitud del array
/// @param pMayor -> puntero donde se almacenara el resultado
/// @param tipo -> (+) calcula el mayor positivo, (-) calcula el mayor negativo negativo, (=) calcula el mayor de ambos tipos
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularMayorEntero(int arr[], int len, int * pMayor, char tipo);


/// @brief ordena de menor a mayor los enteros
///
/// @param arr -> array de enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_ordenarArrayMenorAMayor(int arr[], int len);


/// @brief ordena de menor a mayor los enteros
///
/// @param arr -> array de enteros
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int utn_ordenarArrayMayorAMenor(int arr[], int len);


/// @brief imprime la string dada (array de chars)
///
/// @param arr -> array de chars
/// @return En caso de exito (0), en caso de error (-1)
int utn_imprimirString(char arr[]);


/// @brief devuelve TRUE (1) o FALSE(0) dependiendo si solo tiene letras
///
/// @param arr -> array de chars
/// @return En caso de tener solo letras TRUE (1), en caso de tener otro tipo de dato FALSE (0)
int utn_tieneSoloLetras(char arr[]);


/// @brief devuelve TRUE (1) o FALSE(0) dependiendo si solo tiene números
///
/// @param arr -> array de chars
/// @return En caso de tener solo números TRUE (1), en caso de tener otro tipo de dato FALSE (0)
int utn_esNumerico(char arr[]);



/// @brief Convierte la palabra a mayus
///
/// @param string -> palabra a convertir
/// return En caso de exito (0), en caso de error (-1)
int utn_convertirAMayuscula(char * string);


#endif /* UTN_H_ */
