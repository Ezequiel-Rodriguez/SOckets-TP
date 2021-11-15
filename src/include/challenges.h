#ifndef __CHALLENGES_H__
#define __CHALLENGES_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef int (*PChallenge)(const char *ans, const char *investigation,
                          const char *message, FILE *stream);

typedef struct challenge {
  char *ans;
  char *investigation;
  char *message;
  PChallenge issue;
} Challenge;

#define MAX_ANSWER_LENGTH 256
#define CAPACITY 50

static char buf[MAX_ANSWER_LENGTH] = {0};

#define MAX_CHALLENGES 12
#define TITLE "------------- DESAFIO -------------"
#define Q_TITLE "----- PREGUNTA PARA INVESTIGAR -----"

#define QUESTION1                                                              \
  "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?"
#define QUESTION2                                                              \
  "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada " \
  "uno?"
#define QUESTION3                                                               \
  "¿El puerto que usaron para conectarse al server es el mismo que usan para " \
  "mandar las respuestas? ¿Por qué?"
#define QUESTION4                                                              \
  "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se " \
  "puede utilizar read(2) y write(2) para operar?"
#define QUESTION5                                                              \
  "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?"
#define QUESTION6                                                              \
  "Un servidor suele crear un nuevo proceso o thread para atender las "        \
  "conexiones entrantes. ¿Qué conviene más?"
#define QUESTION7                                                               \
  "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin " \
  "usar procesos ni threads?"
#define QUESTION8                                                              \
  "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?"
#define QUESTION9                                                              \
  "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y "  \
  "pipes?"
#define QUESTION10 "¿Cuáles son las características del protocolo SCTP?"
#define QUESTION11 "¿Qué es un RFC?"
#define QUESTION12 "¿Fue divertido?"

#define MESSAGE1                                                               \
  "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer "             \
  "acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron "     \
  "resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar " \
  "otras preguntas para responder durante la defensa.\nEl desafío final "     \
  "consiste en crear un programa que se comporte igual que yo, es decir, que " \
  "provea los mismos desafíos y que sea necesario hacer lo mismo para "       \
  "resolverlos. No basta con esperar la respuesta.\nAdemás, deberán "        \
  "implementar otro programa para comunicarse conmigo.\n\nDeberán estar "     \
  "atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el " \
  "formato correcto respondan a este desafío con la palabra 'entendido\\n'"
#define MESSAGE2 "The Wire S1E5\n5295 888 6288"
#define MESSAGE3 "https://ibb.co/tc0Hb6w"
#define MESSAGE4 "EBADF..."
#define MESSAGE5 "respuesta = strings:93"  // strings server | grep -n too_easy
#define MESSAGE6 ".text .fini .rodata ? .eh_frame_hdr .eh_frame .preinit_array"  // readelf -S server
#define MESSAGE7 "Filter error"
#define MESSAGE8 "¿?\n\n\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m"
#define MESSAGE9                                                               \
  "Latexme\n\nSi\n\\mathrm{d}y = "                                             \
  "u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\nentonces\ny ="
#define MESSAGE10 "quine.\n"
#define MESSAGE11 "b gdbme y encontrá el valor mágico\n\nENTER para reintentar."
#define MESSAGE12 "Me conoces"

#define ANSWER1 "entendido\n"
#define ANSWER2 "itba\n"
#define ANSWER3 "M4GFKZ289aku\n"
#define ANSWER4 "fk3wfLCm3QvS\n"
#define ANSWER5 "too_easy\n"
#define ANSWER6 ".RUN_ME\n"
#define ANSWER7 "K5n2UFfpFMUN\n"
#define ANSWER8 "BUmyYq5XxXGt\n"
#define ANSWER9 "u^v\n"
#define ANSWER10 "chin_chu_lan_cha\n"
#define ANSWER11 "gdb_rules\n"
#define ANSWER12 "normal\n"

#define SECRET_W                                                               \
  "................................La respuesta es fk3wfLCm3QvS\n"
#define SECRET_W_SIZE 62
#define SECRET_W_FD 13
#define QUINE_MSG                                                               \
  "¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que " \
  "corresponde."
#define COMPILE_QUINE "gcc quine.c -o quine"
#define ERROR_QUINE "ENTER para reintentar."
#define RUN_QUINE "./quine | diff - quine.c"
#define QUINE_SUCCESS "la respuesta es chin_chu_lan_cha"
#define QUINE_FOUND_DIF "diff encontró diferencias."
#define SECRET_PID 0x12345678
#define GDB_ANSWER "La respuesta es: gdb_rules"
#define ANS_7_LEN 100
#define RANDOMNES 10
#define MAX_CHARACTER '~'
#define MIN_CHARACTER ' '
#define NORMALIZED_COUNT 300

int basicChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream);
int quineChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream);
int filterChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream);
int gdbChallenge(const char *ans, const char *investigation,
                 const char *message, FILE *stream);
int writeChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream);
int normalChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream);

static Challenge challenges[MAX_CHALLENGES] = {
    {ANSWER1, QUESTION1, MESSAGE1, basicChallenge},
    {ANSWER2, QUESTION2, MESSAGE2, basicChallenge},
    {ANSWER3, QUESTION3, MESSAGE3, basicChallenge},
    {ANSWER4, QUESTION4, MESSAGE4, writeChallenge},
    {ANSWER5, QUESTION5, MESSAGE5, basicChallenge},
    {ANSWER6, QUESTION6, MESSAGE6, basicChallenge},
    {ANSWER7, QUESTION7, MESSAGE7, filterChallenge},
    {ANSWER8, QUESTION8, MESSAGE8, basicChallenge},
    {ANSWER9, QUESTION9, MESSAGE9, basicChallenge},
    {ANSWER10, QUESTION10, MESSAGE10, quineChallenge},
    {ANSWER11, QUESTION11, MESSAGE11, gdbChallenge},
    {ANSWER12, QUESTION12, MESSAGE12, normalChallenge}};

#endif