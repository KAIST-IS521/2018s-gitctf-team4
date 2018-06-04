/*
 * @author dhuertas
 * @email huertas.dani@gmail.com
 */
#ifndef __UTIL_H
#define __UTIL_H

void integer_to_ascii(int number, char **result);
void get_date(char *buffer, char *format);
int send_file(int thread_id, int sockfd, char *file_path);
int is_dir(char *path);
int is_file(char *path);
int directory_index_lookup(char *dir_path, char **file_path);
int resource_path(char *resource, char **path);
void paranoid_free_string(char *s);
int enc(unsigned char* output0, int len);

#endif