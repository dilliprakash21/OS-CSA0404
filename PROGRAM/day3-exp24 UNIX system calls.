#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open or create a new file
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    const char *content = "Hello, World!\n";
    if (write(fd, content, strlen(content)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    

    close(fd);
    
   
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    
    
    close(fd);
    
    
    if (unlink("example.txt") == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
