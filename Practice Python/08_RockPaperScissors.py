# https://www.practicepython.org/exercise/2014/03/26/08-rock-paper-scissors.html

# Remember the rules:
#  - Rock beats scissors
#  - Scissors beats paper
#  - Paper beats rock

def askForPlay(player_name):
  play = None
  while play != "rock" and play != "paper" and play != "scissors":
    play = input(f"{player_name}: Enter your play (rock/paper/scissors): ").lower()

  return play 

def is_first_player_won(player1, player2):
  if player1 == "rock" and player2 == "scissors":
    return True
  if player1 == "scissors" and player2 == "paper":
    return True
  if player1 == "paper" and player2 == "rock":
    return True

  return False

while True:
  print("Starting Rock-Paper-Scissors game...")

  player1 = askForPlay("Player 1")
  player2 = askForPlay("Player 2")

  if player1 == player2:
    print("No one won! You should play one more time.")
  elif is_first_player_won(player1, player2):
    print("First player won!")
  else:
    print("Second player won!")  

  game_continue = input("Do you want to play another game (yes/no): ")
  if game_continue.lower() == "no":
    break

print("Thanks for playing!")
