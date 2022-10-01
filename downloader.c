
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pthread.h>

#define say_exit(STR)                                                          \
    do {                                                                       \
        printf(STR "\n");                                                      \
        exit(0);                                                               \
    } while (0)

char *make_datetime (void) 
{
    time_t now      = time(NULL);
    struct tm *tms  = localtime(&now);
    int size        = 0;
    char *date      = NULL;
    char day[5], mon[5], year[5], hour[5], min[5], sec[5];

    size = sizeof(char) * 100;
    date = (char *) malloc(size);
    if (!date)
        return NULL;

    memset(date, '\0', size);
    memset(day,  '\0', 5);
    memset(mon,  '\0', 5);
    memset(year, '\0', 5);
    memset(hour, '\0', 5);
    memset(min,  '\0', 5);
    memset(sec,  '\0', 5);

    sprintf(day,  "%d", tms->tm_mday);
    sprintf(mon,  "%d", (tms->tm_mon + 1));
    sprintf(year, "%d", (1900 + tms->tm_year));
    sprintf(hour, "%d", tms->tm_hour);
    sprintf(min,  "%d", tms->tm_min);
    sprintf(sec,  "%d", tms->tm_sec);

    if (strlen(day) == 1)
        sprintf(day, "0%d",  tms->tm_mday);
    if (strlen(mon) == 1)
        sprintf(mon, "0%d",  (tms->tm_mon + 1));
    if (strlen(hour) == 1)
        sprintf(hour, "0%d", tms->tm_hour);
    if (strlen(min) == 1)
        sprintf(min, "0%d",  tms->tm_min);
    if (strlen(sec) == 1)
        sprintf(sec, "0%d",  tms->tm_sec);

    sprintf(date, "%s-%s-%s %s:%s:%s", 
                day, mon, year, hour, min, sec);

    return date;
}

int open_application (void)
{
    int   fd_limit;
    pid_t pid;

    pid = fork();

    if (pid < 0)
        printf("error open fork() 1.");    
    if (pid > 0)
       return 0;

    if (setsid() < 0)
        printf("error setsid.");       

    pid = fork();

    if (pid < 0)
        say_exit("error open fork() 2.");
    if (pid > 0) 
        say_exit("fork() 2 - exit.");

    // Close all file descriptors.
    fd_limit = (int) sysconf(_SC_OPEN_MAX);

    for (int fd = STDERR_FILENO + 1; fd < fd_limit; fd++) 
        close(fd);

    stdin  = fopen("/dev/null", "r" );
    stderr = fopen("/dev/null", "w+");
    stdout = fopen("/dev/null", "w+");

    // Ignore child and tty signals.
    signal(SIGCHLD, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);

    system("./links.sh &");
    sleep(3);
    exit(0);
}

void * start_th (void *_param)
{
    printf("Thread started!\n");
    open_application();
}

int start_app (void)
{
    pthread_t tid;
    
    if (pthread_create(&tid, NULL, start_th, NULL) != 0)
        return 0;

    return 1;
}

void start_app_force (void)
{
    printf("Open script...\n");

    while (1) {
        if (start_app())
            break;
        sleep(1);
    }
}

int main (int argc, char *argv[])
{
    char *date = NULL, *last = NULL;
    int counter = 0;

    while (1) {
        system("killall wget");
        sleep(2);
        start_app_force();
        last = make_datetime();

        if (last) {
            for (int a=0; a<(60 * 3); a++) {
                system("clear");

                date = make_datetime();
                if (date) {
                    printf("%d - [%s, %s] -> Sleeping...\n", counter, last, date);
                    free(date);
                }

                system("ls -la | grep 'zip\\|pdf'");
                sleep(1);
            }

            free(last);
        }

        counter++;
    }

    return 0;
}


