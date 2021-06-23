#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *port = "/dev/ttyUSB0";
    if (argc > 1)
        port = argv[1];

    printf("Opening %s\n", port);
    int fd = open(port, O_RDONLY | O_NOCTTY); // Abre a porta para leitura
    if (fd < 0) {
        printf("Error opening USB\n");
        return 1;
    }

    struct termios config;
    tcgetattr(fd, &config);          // Lê a configuração atual da porta
    cfsetispeed(&config, B9600);     // 9600 bauds
    cfsetospeed(&config, B9600);     // 9600 baud
    config.c_cflag &= ~PARENB;       // Sem paridade
    config.c_cflag &= ~CSIZE;        // Define tamanho da palavra
    config.c_cflag &= ~CSTOPB;       // Stop bit
    config.c_cflag |= CS8;           // 8 bits
    config.c_lflag |= ICANON;        // Modo canônico
    tcsetattr(fd, TCSANOW, &config); // Reconfigura a porta

    char buffer[100];
    int n, millis;
    while (1) {
        int size = read(fd, buffer, sizeof(buffer));
        buffer[size - 1] = '\0';
        sscanf(buffer, "%d %d", &n, &millis);
        printf("buffer: %s (%d bytes)\nN: %d millis: %d\n", buffer, size, n, millis);
    }
    close(fd);
}
