import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print("Please input FILENAME of STR count of individual(1st arg) and FILENAME of DNA sequence(2nd arg)")
        sys.exit(1)

    # TODO: Read database file into a variable
    databaseFilePath = sys.argv[1]
    with open(databaseFilePath) as databaseFile:
        databaseReader = csv.DictReader(databaseFile)
        sequenceList = databaseReader.fieldnames.copy()
        sequenceList.pop(0)
        personDNA_Count = {}
        # DNA_database = {}
        DNA_Database = []
        for row in databaseReader:
            # for seq in sequenceList:
            #     personDNA_Count[seq] = row[seq]
            DNA_Database.append(row)
            # name = f'{row["name"]}'
            # DNA_database[name] = personDNA_Count





    # TODO: Read DNA sequence file into a variable
    sequenceFilePath = sys.argv[2]
    with open(sequenceFilePath, 'r') as sequenceFile:
        sequenceReader = csv.reader(sequenceFile)
        for row in sequenceReader:
            print(row[0])

    # TODO: Find longest match of each STR in DNA sequence
    # for person in DNA_database:
    for seq in sequenceList:
        num = longest_match(row[0], seq)
        print(num)


    # TODO: Check database for matching profiles

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
