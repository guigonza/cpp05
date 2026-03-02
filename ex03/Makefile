# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Guille <Guille@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 07:53:27 by Guille            #+#    #+#              #
#    Updated: 2026/03/02 23:23:12 by Guille           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
DEPFLAGS = -MMD -MP
SRCS = 	main.cpp	Bureaucrat.cpp	\
		AForm.cpp	ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp	PresidentialPardonForm.cpp Intern.cpp

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(NAME): $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@
-include $(DEPS)
clean:
	rm -rf $(OBJDIR) *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
