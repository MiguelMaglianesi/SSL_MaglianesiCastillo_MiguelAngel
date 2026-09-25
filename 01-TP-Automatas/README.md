
# Parte 1 del TP 
"Dada una cadena que contenga varios números que pueden ser decimales,octales o hexadecimales, con o sin signo para el caso de los decimales, separados por el carácter ‘@’ , reconocer los tres grupos de constantes enteras, indicando si hubo un error léxico , en caso de ser correcto contar la cantidad de cada grupo."
Como nos piden disinguir cuantos numeros hay en fomato decimal, que puede estar signado o no, octal o hexadecimal lo más sencillo para empezar es distinguir en que categoria entra cada numero.
Primero,empezaremos distigiendo a los decimales que sus cifras solo varian entre los numeros del 0 al 9 y pueden tener signo o no.
Segundo trataremos a los octales la caracteristica de estos tipos de numeros es que sus cifras varian entre los numeros del 0 al 7 para distinguilos tendremos que empezar por el 0 seguido de una "o" en minússcula.
Tercero trataremos de ditinguir a los hexadecimales que si o si empiezan por la cadena de caracteres 0 seguido de una x minuscula o mayuscula y despues de esto sus cifras podran variar entre los numeros del 0 al 9 como las letras de la a hasta la f en minuscula o mayuscula.
Por utimo tenemos el caracter se parador el "@" que indicaria el termino de un numero de cada formato , debido a esto una cadena no puede empezar por el caracter "@" y al mismo tiempo no este caracter separador no puede estar concatendo directamente con otro caracter separador.
La ultima caracteristica sera el estado del error lexico el cual se compondra de cualquier cadena de los caracteres ya mencionados que no sea valida por ejemplo la concatenacion de dos o más caracteres de signado "+" o "-" como por el inicio de dos o más caracteres separadores o si ya la cadena establecio el formato del numero cualquier caracter que no este permitido dentro de ese formato.
El automata que implementaremos tiene que ir desde el estado inicial a tres posibles estados validos: que serian los correspondientes a que si el el cararcter consumido es cualquier numero del 1 al 9 , si el caracter consumido es el signo del numero o si el caracter consumido es el numero 0.
En el primer caso te enviaria a que el numero escrito pertenece al formato decimal sindo este un estdo de aceptacion.
En el segundo caso tendra que seguirle un numero en formato decimal este como tal no es un estado de aceptacion.
En el tercer caso 