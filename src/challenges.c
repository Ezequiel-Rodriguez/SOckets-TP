#include <challenges.h>

int basicChallenge(const char *ans, const char *investigation,
                   const const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
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

  char aux[ANS_7_LEN] = "La respuesta es: ";
  strcat(aux, ans);
  ans = aux;

  srand(time(NULL));

  while (ans) {
    if (rand() % RANDOMNES) {
      write(STDOUT_FILENO, ans++, 1);
    } else {
      char c = (rand() % (MAX_CHARACTER - MIN_CHARACTER)) + MIN_CHARACTER;
      write(STDERR_FILENO, &c, 1);
    }
  }

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
    return -1;
  }

  return !strcmp(ans, buf);
}

int writeChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (write(SECRET_W_FD, SECRET_W, SECRET_W_SIZE) == -1) {
    return -1;
  }

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
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
    return -1;
  }

  return !strcmp(ans, buf);
}
