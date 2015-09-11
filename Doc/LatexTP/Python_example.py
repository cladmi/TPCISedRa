import csv

def try_again():
    again = input("Do you want to look again? Yes or No").lower()
    if again == "yes":
        capital_cities()
    elif again == "no":
        print("Thanks for playing!")
    else:
        print("Sorry, try again")
        try_again()

def capital_cities():
    found = 0
    place = input("What do you want to look for?")
    with open('Data.csv','rt') as file:
        cap_cities = csv.reader(file)
        for row in cap_cities:
            if place in row:
                found += 1
                if place == row[0]:
                    print("The capital city is: " + row[1])
                else:
                    print("The country is: " + row[0])
        if found != 1:
            print("Not answers found, remember to use capital letters!")
    try_again()

capital_cities()
