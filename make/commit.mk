OBJS = $(patsubst %.c,%.o,$(SOURCES))
CPPFLAGS = $(OPTCPPFLAGS)
CFLAGS = -g -O2 $(INCLUDE) $(OPTFLAGS) -Wall -Werror
LIBS = $(OPTLIBS) -lm

$(OBJS): $(SOURCES)
