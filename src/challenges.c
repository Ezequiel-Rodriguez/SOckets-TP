// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <challenges.h>

// https://rosettacode.org/wiki/Random_numbers#C

static double drand() /* uniform distribution, (0..1] */
{
  return (rand() + 1.0) / (RAND_MAX + 1.0);
}

static double randNormDist() /* normal distribution, centered on 0, std dev 1 */
{
  return sqrt(-2 * log(drand())) * cos(2 * M_PI * drand());
}

int basicChallenge(const char *ans, const char *investigation,
                   const const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    return -1;
  }

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
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

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
}

int filterChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);

  char aux[ANS_7_LEN] = "La respuesta es: ";
  strcat(aux, ans);

  int i = 0;

  srand(time(NULL));

  while (aux[i]) {
    if (rand() % RANDOMNES == 1) {
      write(STDOUT_FILENO, aux + i++, 1);
    } else {
      char c = (rand() % (MAX_CHARACTER - MIN_CHARACTER)) + MIN_CHARACTER;
      write(STDERR_FILENO, &c, 1);
    }
  }

  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL)
    return -1;

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
}

void gdbme(void) {
  if (getpid() == SECRET_PID) {
    printf("%s\n\n", GDB_ANSWER);
  }
}

int gdbChallenge(const char *ans, const char *investigation,
                 const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  gdbme();

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    return -1;
  }

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
}

int writeChallenge(const char *ans, const char *investigation,
                   const char *message, FILE *stream) {
  printf("\n%s\n%s\n\n", TITLE, message);
  if (write(SECRET_W_FD, SECRET_W, SECRET_W_SIZE) == -1) {
    perror("write");
  }
  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    return -1;
  }

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
}

int normalChallenge(const char *ans, const char *investigation,
                    const char *message, FILE *stream) {
  printf("\n%s\n%s\n", TITLE, message);

  int i = 0;

  srand(time(NULL));

  while (i < NORMALIZED_COUNT) {
    printf("%.6f ", randNormDist());
    i++;
  }

  printf("\n%s\n%s\n\n", Q_TITLE, investigation);

  if (fgets(buf, MAX_ANSWER_LENGTH, stream) == NULL) {
    return -1;
  }

  int answer = !strcmp(ans, buf);

  if (answer == 0) {
    printf("La respuesta incorrecta: %s\n", buf);
  }

  return answer;
}
