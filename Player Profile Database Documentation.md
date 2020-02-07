| Ryan LaCombe |
|:---       |
| s198023 |
| Introduction to C++ |
|Player Profile Database Documentation |

## I. Requirements

1. Description of problem:
    - **Name:** Player Profile Database

    - **Problem Statement:** Creation of a game project using the C++ language using Visual Studio from a brief provided by the teacher.

    - **Problem Specifications:** The program must store the name and high-score information of the player, read the data file on launch and if it does not exist create a new file, player data must be loaded into a dynamic array, sort the player profiles alphabetically, search for and update an individual player profile, and include a test file with the program.

2. Input Information
    - The keyboard is used to type commands.

3. Output Information
    - The program displays a menu in which the User can navigate via console inputs.

## II. Design

1. _System Architecture_

    |
    |:--------------- |
    Main Game Loop:

        The program begins by looking for an existing file, and if none is found, creates a new file. The User is then prompted by a menu to navigate through its functions. The User can create a new profile in which they are prompted to enter a name and high score; the program then adds the new profile to the existing list (if applicable) and then sorts the list of profiles. The User can also search and update the high score of any individual profile. The User can also manually save or exit the program.

2. ### Object Information

    **File:** Container.h

        Description: Used to hold the functions of the main game loop.

        **Attributes:**

            Name: dataLength
                Description: Variable used to keep track of the length of the dynamic array
                Type: int

            Name: playerData
                Description: An array with length of "dataLength" that contains the information of the Player name and score.
                Type: Player*

    **File:** Player.h

        Description: Used to hold the information of the Player's name and score and gets the input for said information.

        **Attributes:**

            Name: playerName
                Description: Creates a string for holding the Player's name
                Type: char

            Name: playerScore:
                Description: Creates a interger to hold the Player's score
                Type: int
