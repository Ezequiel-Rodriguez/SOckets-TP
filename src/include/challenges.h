#ifndef __CHALLENGES_H__
#define __CHALLENGES_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*PChallenge)(const char *ans, const char *investigation, const char *message,
                          FILE *stream);

typedef struct challenge {
  char *ans;
  char *investigation;
  char *message;
  PChallenge issue;
} Challenge;

#define MAX_ANSWER_LENGTH 256

static char buf[MAX_ANSWER_LENGTH] = {0};

#define MAX_CHALLENGES 12
#define TITLE "------------- DESAFIO -------------"
#define Q_TITLE "----- PREGUNTA PARA INVESTIGAR -----"

#define QUESTION1 ""
#define QUESTION2 ""
#define QUESTION3 ""
#define QUESTION4 ""
#define QUESTION5 ""
#define QUESTION6 ""
#define QUESTION7 ""
#define QUESTION8 ""
#define QUESTION9 ""
#define QUESTION10 ""
#define QUESTION11 ""
#define QUESTION12 ""

#define MESSAGE1 ""
#define MESSAGE2 ""
#define MESSAGE3 ""
#define MESSAGE4 ""
#define MESSAGE5 ""
#define MESSAGE6 ""
#define MESSAGE7 ""
#define MESSAGE8 ""
#define MESSAGE9 ""
#define MESSAGE10 ""
#define MESSAGE11 ""
#define MESSAGE12 ""

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

int basicChallenge(const char *ans, const char *investigation, const char *message, FILE *stream);
int quineChallenge(const char *ans, const char *investigation, const char *message, FILE *stream);
int filterChallenge(const char *ans, const char *investigation, const char *message,
                    FILE *stream);
int gdbChallenge(const char *ans, const char *investigation, const char *message, FILE *stream);
int writeChallenge(const char *ans, const char *investigation, const char *message, FILE *stream);
int normalChallenge(const char *ans, const char *investigation, const char *message, FILE *stream);

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
    {ANSWER11, QUESTION10, MESSAGE10, gdbChallenge},
    {ANSWER12, QUESTION11, MESSAGE11, normalChallenge}};

#endif