import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print("Usage: Python dna.py database.csv sequences.txt")

    # TODO: Read database file into a variable
    STR = []
    DNAS = []
    db = sys.argv[1]
    file = open(db, "r")
    reader = csv.DictReader(file)
    for row in reader:
        STR = list(row.keys())
        for value in row:
            row[value] = row[value]
        DNAS.append(row)
    STR.remove('name')

    # TODO: Read DNA sequence file into a variable
    seq = sys.argv[2]
    with open(seq, "r") as txtfile:
        txtreader = txtfile.read()

    # TODO: Find longest match of each STR in DNA sequence
    sequences = {}
    for i in range(len(STR)):
        longRun = longest_match(txtreader, STR[i])
        sequences[STR[i]] = str(longRun)

    # TODO: Check database for matching profiles
    for i in range(len(DNAS)):
        if sequences.items() <= DNAS[i].items():
            print(DNAS[i]["name"])
            return
    print("No match")


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
