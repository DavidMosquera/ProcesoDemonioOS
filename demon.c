#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

#define DAEMON_NAME "vdaemon"



void *hiloLadron (void *arg ) {
    int ret;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,124,"%d-%m-%y-%H:%M:%S", tlocal);
    char con1[128] = "usr/local/etc/";
    char con2[128] = ".txt";
    strcat(con1,output);
    strcat(con1,con2);
    printf(con1);
    ret = rename("/usr/src/HistorialChat/file.txt",con1);
    FILE*file;
    file = fopen (con1,"a");
    char con3[128] = "El archivo se obtuvo en la siguiente fecha por el demonio malvado :\n";
    strcat(con3,con1);
    fprintf (file, con3);
    fclose(file);
    return NULL;
}

void *hiloDeMofa (void *arg ) {
    FILE*file;
    file = fopen("/usr/src/HistorialChat/fileDESTRUIDO.txt","a");
    for (int x = 0; x<160; x++){
         fprintf(file,"pqwoeqeQWUOEQWNSAKNAKSNAPSIDJASPODJASPODAMASKCÑANSÑKCASJDAISPDPAISUDQWPEUQ)""!ASD)ASDOPAJSDPOASJDPOASDJPOASDJAPSODJASPODJASPDOAJSOPDJASPODJASPDOJASDPOASJDPOASSAPODJASPODJSAPODJASDPOASJDZXCKLZXCZKXCNZKXC");
    }
    return NULL;
}

void process(){
    // escribir los datos en un archivo.txt
    FILE*file;
    file = fopen("/usr/src/HistorialChat/file.txt","rb");
    if(file==NULL)
	{

	}
	else{
        fclose(file);
	    pthread_t  h1;
        pthread_t  h2;
        char *hola = "Hola ";
        char *mundo = "mundo";
        pthread_create (&h1, NULL , hiloLadron, (void *) hola);
        pthread_create (&h2, NULL , hiloDeMofa, (void *) mundo);
        pthread_join(h1, NULL);
        pthread_join(h2, NULL);
	}

}

int main(int argc, char *argv[]) {
    //Set our Logging Mask and open the Log
    setlogmask(LOG_UPTO(LOG_NOTICE));
    openlog(DAEMON_NAME, LOG_CONS | LOG_NDELAY | LOG_PERROR | LOG_PID, LOG_USER);

    syslog(LOG_INFO, "Entering Daemon");

    pid_t pid, sid;

   //Fork the Parent Process
    pid = fork();

    if (pid < 0) { exit(EXIT_FAILURE); }

    //We got a good pid, Close the Parent Process
    if (pid > 0) { exit(EXIT_SUCCESS); }

    //Change File Mask
    umask(0);

    //Create a new Signature Id for our child
    sid = setsid();
    if (sid < 0) { exit(EXIT_FAILURE); }

    //Change Directory
    //If we cant find the directory we exit with failure.
    if ((chdir("/")) < 0) { exit(EXIT_FAILURE); }

    //Close Standard File Descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //----------------
    //Main Process
    //----------------
    while(1==1){
        process();    //Run our Process
        sleep(10);    //Sleep for 60 seconds
    }

    //Close the log
    closelog ();
}
