CC=gcc
CFLAGS=-s -Wall
LIBS=-lpthread

SOURCES = src/config.c\
		 src/http.c\
		 src/mime.c\
		 src/request.c\
		 src/response.c\
		 src/util.c

all: bin bin/httpd

bin:
	@mkdir -p $@

bin/httpd: $(SOURCES)
	$(CC) $(CFLAGS) -o$@ $^ $(LIBS)

clean:
	@rm -rf bin/