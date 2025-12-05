import requests
import json

launchesData = "https://api.spacexdata.com/v5/launches"
capsulesData = "https://api.spacexdata.com/v3/capsules"
rocketsData = "https://api.spacexdata.com/v3/rockets"
exitCode = "iWantToStopLearningAboutRocketsSaidNoOneEver"
categoryToLearn = ""

# "Enter a category to learn about:"
#    - Launches
#    - Capsules
#    - Rockets

print("Welcome to 'Explore SpaceX!' You'll have the option to explore a certain sector, then a particular launch/expedition from that sector. Press any key to continue!")
buffer = str(input())

def launchExplorer(launchToLearn):
    print("\n")
    for key, value in dictionaries.items():
        if key == "success":
            print("-Successful launch!")
        if key == "date_utc":
            print(f"-Launch date: {value}")
        if key == "name":
            print(f"-Launch Name: {value}")
        if key == "flight_number":
            print(f"-Flight number: {value}")
        if key == "details":
            if value != None:
                print("-Details: {value}")
            else:
                print("-No available details")
        if key == "links":
            for k,v in value.items():
                if k == "webcast":
                    print(f"-Stream: {v}")
    print("\n")
    buffer = str(input("Press any key to continue!"))
    print("\n\n")

def capsuleExplorer(capsule):
    print("\n")
    for key, value in capsule.items():
        match key:
            case "capsule_serial":
                print(f"-Serial: {value}")

            case "capsule_id":
                print(f"-ID: {value}")

            case "status":
                print(f"-Status: {value}")

            case "type":
                print(f"-Type: {value}")

            case "details":
                print(f"-Details: {value}")

            case _:
                1==1
    print("\n")
    buffer = str(input("Press any key to continue!"))
    print("\n\n")
    
def rocketExplorer(rocket):
    print("\n")
    for key, value in rocket.items():
        match key:
            case "rocket_id":
                print(f"-ID: {value}")

            case "rocket_name":
                print(f"-Name: {value}")

            case "wikipedia":
                print(f"-Wiki Link: {value}")

            case "active":
                if key:
                    print("-Status: Active")

            case "country":
                print(f"-Country: {value}")

            case "company":
                print(f"-Company: {value}")

            case "first_flight":
                print(f"-FIrst Flight Date: {value}")

            case "description":
                print(f"-Details: {value}")

            case _:
                1==1
    print("\n")
    buffer = str(input("Press any key to continue!"))
    print("\n\n")

while (categoryToLearn != exitCode):
    print("Categories:")
    print("    - Launches")
    print("    - Capsules")
    print("    - Rockets")

    categoryToLearn = str(input("Enter a category to explore ('exit' to quit): "))
    
    match categoryToLearn.lower():
        case "launches":
            launchRequest = requests.get(launchesData)
            launchJson = launchRequest.json()

            print("====================================")
            for dictionaries in launchJson:
                for key, value in dictionaries.items():
                    if key == "name":
                        print(f"{value}")
            
            launchToExplore = str(input("Enter a name from above to learn about: ")) 
            for dictionaries in launchJson:
                for key, value in dictionaries.items():
                    if key == "name" and value == launchToExplore:
                        print(f"\nYou've selected {launchToExplore}")
                        launchExplorer(dictionaries)
                                       
            
        case "capsules":
            capsuleRequest = requests.get(capsulesData)
            capsuleJson = capsuleRequest.json()
            print("====================================")
            for dictionaries in capsuleJson:
                for key, value in dictionaries.items():
                    if key == "capsule_serial":
                        print(f"{value}")

            capsuleToExplore = str(input("Enter a name from above to learn about: ")) 
            for dictionaries in capsuleJson:
                for key, value in dictionaries.items():
                    if key == "capsule_serial" and value == capsuleToExplore:
                        print(f"You've selected {capsuleToExplore}")
                        capsuleExplorer(dictionaries)
                      
        case "rockets":
            rocketsRequest = requests.get(rocketsData)
            rocketsJson = rocketsRequest.json()
            for dictionaries in rocketsJson:
                for key, value in dictionaries.items():
                    if key == "rocket_name":
                        print(f"{value}")

            rocketToExplore = str(input("Enter a name from above to learn about: "))
            for dictionaries in rocketsJson:
                for key, value in dictionaries.items():
                    if key == "rocket_name" and value == rocketToExplore:
                        rocketExplorer(dictionaries)
                    
        case "exit":
            categoryToLearn = exitCode
        case _:
            print("Invalid prompt. Please try again.")
    
