import random

player_choice = 'B'
bot_choice = 0
player_score = 0
bot_score = 0


class Obj:
    def __init__(self, name):
        self.name = name
        if name == 'Rock':
            self.defeat = ['Lizard', 'Scissors']
        if name == 'Paper':
            self.defeat = ['Spock', 'Rock']
        if name == 'Scissors':
            self.defeat = ['Paper', 'Lizard']
        if name == 'Lizard':
            self.defeat = ['Spock', 'Paper']
        if name == 'Spock':
            self.defeat = ['Scissors', 'Rock']

    def TryDefeat(self, obj):
        if obj.name == self.name: return False
        for i in range(len(self.defeat)):
            if obj.defeat[i] == self.name:
                return True
        return False


for turn in range(1, 5 + 1):
    print(f"Round: {turn}")
    player_choice = Obj(input("Enter choice (Rock, Paper, Scissors, Lizard, Spock): "))
    bot_choice = Obj(random.choice(['Rock', 'Paper', 'Scissors', 'Lizard', 'Spock']))
    if player_choice.name == bot_choice.name:
        print("Draw!")
    elif player_choice == '' and bot_choice == 'Paper' or not player_choice.TryDefeat(bot_choice):
        print("Bot win!")
        bot_score = 1
    elif player_choice.TryDefeat(bot_choice):
        print("You win!")
        player_score += 1
if player_score > bot_score:
    print("Player wins!")
elif bot_score > player_score:
    print("Bot wins!")
else:
    print("Draw!")
