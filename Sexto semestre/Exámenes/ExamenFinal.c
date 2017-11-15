#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

extern int errno;

#define KEY 1234

sem_t* sem1;
sem_t* sem2;

int shmid;

void limpiar() {

    sem_close(sem2);
        sem_unlink("sem2");
}

typedef struct bufers {
    int cantidad;
} bufers;

void * metodoP0(int num, bufers b){
    b.cantidad = num;
    sem_post(sem1);

}

void * metodoP1(bufers b0, bufers b1){
  sem_wait(sem1);
    if(b0.cantidad % 2 != 0){
      if(b0.cantidad == 1001){
	b1.cantidad = 0;
	sem_post(sem1);
	sem_close(sem1);
	sem_unlink("sem1");
      }else{
	b1.cantidad = b0.cantidad;
	sem_post(sem1);
      }
      sem_post(sem2);
    }
}


void * metodoP2(bufers b1){
  sem_wait(sem2);
  if(b1.cantidad ==0){
    sem_post(sem2);
    sem_close(sem2);
    sem_unlink("sem2");
  }else{
    if(b1.cantidad % 3 != 0){
    printf("%d\n",b1.cantidad);
    sem_post(sem2);
    }
  }
}

int main(){
  if (( shmid = shmget(KEY, sizeof(bufers), IPC_CREAT | S_IRWXU)) < 0 ) {
    perror("Error en creacion al shmget");
    exit(0);
  }

  pid_t ptid;
  limpiar();
  sem1 = sem_open("sem1", O_CREAT,S_IRWXU,1);
  sem2 = sem_open("sem2", O_CREAT,S_IRWXU,1);

  bufers buf[2];
  if(fork() == 0){
    for(int i = 1;  i <= 1001; i++){
      //nuestro 1001 es el 0
      sem_wait(sem1);
      metodoP0(i,buf[0]);
    }

    int status;
    wait(&status);
    wait(&status);
  }else{
    if(fork() ==0){

	sem_wait(sem2);
	metodoP1(buf[0],buf[1]);

      exit(0);
    }else{

      metodoP2(buf[1]);

      exit(0);
    }
  }

  return 0;
}
