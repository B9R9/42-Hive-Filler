
NAME = briffard.filler

all: $(NAME)

$(NAME):
	@echo "Creation player: briffard"
	gcc -o myplayer/briffard.filler  src/*.c  -L libft/ -lft -I includes/ -I libft/includes/
	if [ -e "/home/chopper/workspace/Filler/myplayer/briffard.filler"]
		@echo "Player created"

./resources/filler_vm -p1 myplayer/briffard.filler -p2 myplayer/briffard.filler -f ./resources/maps/map00
