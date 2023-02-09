PROG:=main
SRCS:=ppt2.cc main.cc

CXX:= g++

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

clean:
	@rm -f $(PROG) $(OBJS) core *.s

rational.o: ppt2.cc ppt2.h
main.o: main.cc ppt2.h
main.s: main.cc ppt2.h
