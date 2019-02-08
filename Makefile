SRCFILES  = main.cpp \
	    ECIAS.cpp \
	    run.cpp \
	    close.cpp \
	    events.cpp \

SRCDIR   := src

OBJDIR   := obj

OUTDIR   := .

NAME     := ecias

CXXFLAGS += -Wextra -Wall -W

CPPFLAGS += -Iinclude

LDFLAGS  += -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window


OBJ       = $(addprefix $(OBJDIR)/, $(SRCFILES:.cpp=.o))
SRC       = $(addprefix $(SRCDIR)/, $(SRCFILES))
OUT       = $(OUTDIR)/$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(OUT) $(OBJ) $(LDFLAGS)
#	$(AR) rc $(OUT) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re
