
# Parte 1 del TP 
"Dada una cadena que contenga varios números que pueden ser decimales,octales o hexadecimales, con o sin signo para el caso de los decimales, separados por el carácter ‘@’ , reconocer los tres grupos de constantes enteras, indicando si hubo un error léxico , en caso de ser correcto contar la cantidad de cada grupo."
Como nos piden disinguir cuantos numeros hay en fomato decimal, que puede estar signado o no, octal o hexadecimal lo más sencillo para empezar es distinguir en que categoria entra cada numero.
Primero,empezaremos distigiendo a los decimales que sus cifras solo varian entre los numeros del 0 al 9 y pueden tener signo o no.
Segundo trataremos a los octales la caracteristica de estos tipos de numeros es que sus cifras varian entre los numeros del 0 al 7 para distinguilos tendremos que empezar por el 0 seguido de una o en minucula o mayuscula.
Tercero trataremos de ditinguir a los hexadecimales que si o si empiezan por la cadena de caracteres 0 seguido de una x minuscula o mayuscula y despues de esto sus cifras podran variar entre los numeros del 0 al 9 como las letras de la a hasta la f en minuscula o mayuscula.
Por utimo tenemos el caracter se parador el "@" que indicaria el termino de un numero de cada formato.
