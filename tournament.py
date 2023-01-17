# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    csvFile = open(sys.argv[1], 'r')
    reader = csv.DictReader(csvFile)
    # read each row of the csv file and insert as a list of dictionary
    for row in reader:
        teams.append(row)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        # this will return name of winner each tournament
        winner = simulate_tournament(teams)
        # check if the NAME is already exist
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1
    print(counts)

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    csvFile.close()

# ---------------------------------------------------


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = int(team1["rating"])
    rating2 = int(team2["rating"])
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))

    # this will return bool type
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = simulate_round(teams)
    size = int(len(teams)**0.5 - 1)
    for i in range(size):
        winners = simulate_round(winners)
    # THIS ONLY NEED TO RETURN THE NAME OF WINNER TEAM -not as list dictionary
    return winners[0]["team"]


if __name__ == "__main__":
    main()
