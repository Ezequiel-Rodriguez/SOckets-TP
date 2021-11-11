## ------------- DESAFIO -------------
Usando el comando lsof -i -P -n, podemos ver con detalle el PID y el puerto que esta usando el server. Una de las lineas devolvera algo como lo siguiente:

COMMAND   PID  USER            FD  TYPE  DEVICE  SIZE/OFF  NODE  NAME
server    4319 ezerodriguez    3u  IPv4  27365      0t0    TCP   *:8080 (LISTEN)

Una vez encontrado, basta con conectarse desde otra terminal usando una herramienta de  scaneo de puertos como Netcat, podremos conectarnos al mismo mediante el comando:

> Solución: Correr en la terminal `nc -v -n 0.0.0.0 8080` con el servidor corriendo.

## ------------- DESAFIO -------------
Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.

En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.
Además tendrán que investigar otras preguntas para responder durante la defensa.
El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.
Además, deberán implementar otro programa para comunicarse conmigo.

Deberán estar atentos a los easter eggs.

Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\n'


### ----- PREGUNTA PARA INVESTIGAR -----
¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?

> Respuesta: Desde esta nueva terminal, una vez conectada, podremos comunicarnos con el puerto por entrada estandar y la salida se vera en la terminal donde se ejecutó el server.

> Solución: `entendido`

---

## ------------- DESAFIO -------------
The Wire S1E5
5295 888 6288


### ----- PREGUNTA PARA INVESTIGAR -----
¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?

> Respuesta: TCP ports use the Transmission Control Protocol, the most commonly used protocol on the Internet and any TCP/IP network. TCP enables two hosts to establish a connection and exchange streams of data. TCP guarantees delivery of data and that packets will be delivered in the same order in which they were sent. Guaranteed communication/delivery is the key difference between TCP and UDP. UDP ports use the Datagram Protocol. Like TCP, UDP is used in combination with IP (the Internet Protocol) and facilitates the transmission of datagrams from one computer to applications on another computer, but unlike TCP, UDP is connectionless and does not guarantee reliable communication; it's up to the application that received the message to process any errors and verify correct delivery. UDP is often used with time-sensitive applications, such as audio/video streaming and realtime gaming, where dropping some packets is preferable to waiting for delayed data.

> Solución: `itba`

---

## ------------- DESAFIO -------------
https://ibb.co/tc0Hb6w


### ----- PREGUNTA PARA INVESTIGAR -----
¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?

> Respuesta: TODO!!!!

> Solución: `M4GFKZ289aku`

---

## ------------- DESAFIO -------------
EBADF...

write: Bad file descriptor

### ----- PREGUNTA PARA INVESTIGAR -----
¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?

> Respuesta: TODO!!!!

> Solución: `fk3wfLCm3QvS`

---

## ------------- DESAFIO -------------
respuesta = strings:277


### ----- PREGUNTA PARA INVESTIGAR -----
¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?

> Respuesta: TODO!!!!

> Solución: `too_easy`

--- 

## ------------- DESAFIO -------------
.data .bss .comment ? .shstrtab .symtab .strtab


### ----- PREGUNTA PARA INVESTIGAR -----
Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?

> Respuesta: TODO!!!!

> Solución: `.RUN_ME`

## ------------- DESAFIO -------------
Filter error

8VJ=RcfL5E[aQ ='9 l%O\:,\!p*)O|(eWZ_0NyAxPx67 3+Qr,(K_84.:J)el>Pr')As_`.bpym7v\zY)u2HjB}<iXN-:=' es|[-Gp}$l]|{tZ`n7o(7t%Dt|jaS] 8$+%#es-C8Br Z$^Qs(yj8_kV@>2&+uem6=,ucW[HJH<DS._pm!19K>y G{q&K55Gy+c(HspO5n0d2'y<$#J8yoU?Ffr_sPHPp'p^I&b.3F pb!:hI?i,=LM@$UUNMr3Fl N

### ----- PREGUNTA PARA INVESTIGAR -----
¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?

> Respuesta: TODO!!!!

> Solución: ``


<!-- Respuestas so far:
nc 0.0.0.0 8080

entendido
itba
M4GFKZ289aku
fk3wfLCm3QvS
too_easy
.RUN_ME

 -->