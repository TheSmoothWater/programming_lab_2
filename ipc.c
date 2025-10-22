// TODO: add the appropriate header files here
#include <sys/mman.h>  // for shm_open
#include <fcntl.h>  // for O_Creat and the others
#include <sys/stat.h>  // for mode_t permission bit macros. Just good practice I suppose
#include <stddef.h>  // for NULL
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/**************************************************************
 *  ipc_create - creates a shared memory object called lab2 and
 *               returns a char pointer to the memory shared
 *               memory object.
 * 
 *  size - is the size of the memory object to create.
 *   
 ***************************************************************/
char* ipc_create(int size){
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char* ptr;

    // TODO: create the shared memory object called lab2
    // S_IRUSR is the read permission bit for the owner of the file
    // S_IWUSR is th write access permission bit for the owner
    fd = shm_open("/lab2", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    
    if(fd == -1){
        perror("shm_open failed");
        return NULL;
    }

    // TODO: configure the size of the shared memory object 
    if(ftruncate(fd, size) == 1){
        perror("ftruncate error");
        close(fd);
        return NULL;
    }
    // TODO: memory map the shared memory object */
    // Just look at documentation for MAP_SHARED, it's too much for a comment
    ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED){
        perror("Memory map has failed");
        close(fd);
        return NULL;
    }

    close(fd);

    return ptr;
}


/**************************************************************
 * ipc_close - closes the ipc communication channel that was
 *             created with ipc_create.
 * 
 **************************************************************/
void ipc_close(){
    shm_unlink("lab2");
}