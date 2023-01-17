import csv
import sys
import os


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect number of command-line arguments.")
        return

    # TODO: Read database file into a variable
    # open csv file
    baseFile = open(sys.argv[1], 'r')
    # create reader object
    readBase = csv.DictReader(baseFile)

    # store each reder object's output (dictionary) in a list
    groupBase = []
    for row in readBase:
        groupBase.append(row)

    # TODO: Read DNA sequence file into a variable
    # open .txt file
    refFile = open(sys.argv[2], 'r')
    # copy the text into a variable
    groupRef = refFile.read()

    # TODO: Find longest match of each STR in DNA sequence
    # getting all the key in the dictionary for method input and store in refResult dictionary
    # REMARKS: need to store as dictionary only in order to compare with another dictionary
    refResult = {}
    for j in groupBase[0]:
        if j != "name":
            end = str(longest_match(groupRef, j))
            # linked each key with the output value of longest_match method
            refResult[j] = end

    # TODO: Check database for matching profiles
    for baseUnit in groupBase:
        count = 0
        j = -1
        for key in baseUnit:
            if key != "name":
                if baseUnit[key] == refResult[key]:
                    count += 1
                else:
                    count == 0
                j += 1
        # if all key are match then print the name of the person
        if count == len(refResult):
            print(baseUnit["name"])
            return

    print("No match")

    baseFile.close()
    refFile.close()

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
