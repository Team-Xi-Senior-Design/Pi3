#ifndef SERIAL_DRIVER_H_
#define SERIAL_DRIVER_H_

int set_interface_attribs(int fd, int speed, int parity);
void set_blocking(int fd, int should_block);


#endif