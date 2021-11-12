#include <challenges.h>

#define SECRET_W                                                               \
  "................................La respuesta es fk3wfLCm3QvS\n"
#define SECRET_W_SIZE 62
#define SECRET_W_FD 420
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

int basicChallenge(const char *ans, const char *investigation,
                   const const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    // TODO: Error exit?
    return -1;
  }

  return !strcmp(ans, buf);
}

int quineChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);

  if (system(COMPILE_QUINE) == 0) {
    printf("%s\n", QUINE_MSG);
    if (system(RUN_QUINE) == 0) {
      printf("%s\n\n", QUINE_SUCCESS);
    } else {
      printf("\n%s\n%s\n", QUINE_FOUND_DIF, ERROR_QUINE);
    }
  } else {
    printf("\n%s\n", ERROR_QUINE);
  }

  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL)
    return -1;

  return !strcmp(ans, buf);
}

int filterChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);

  // TODO: It sends the answer to STDOUT but how 0x84, 0x70 does it do it.

  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL)
    return -1;

  return !strcmp(ans, buf);
}

int gdbChallenge(const char *ans, const char *investigation,
                 const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (getpid() == SECRET_PID) {
    printf("%s\n\n", GDB_ANSWER);
  }

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    // TODO: Error exit?
    return -1;
  }

  return !strcmp(ans, buf);
}

int writeChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (write(SECRET_W_FD, SECRET_W, SECRET_W_SIZE) == -1) {
    // TODO: Error exit?
    return -1; // TODO: Remove -1 magic number.
  }

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    // TODO: Error exit?
    return -1;
  }

  return !strcmp(ans, buf);
}

int normalChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  // TODO: Print normal dist.

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    // TODO: Error exit?
    return -1;
  }

  return !strcmp(ans, buf);
}
