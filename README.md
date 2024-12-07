# Make Your Own Adventure
 > Authors: Angel Franco(https://github.com/ImmortalWave), Alex Totah(https://github.com/nander100), Isaias Villanueva(https://github.com/mindisaias), Lynvy Chang(https://github.com/noodlespad)

## Project Description
 > Make Your Own Adventure is a program that allows users to create a text choice-based interactive story (just like the classic Choose Your Own Adventure genre of books and games). There are two types of people that would use this program. The creators, the ones who make the stories, and the users/players, the ones who play and go through these stories made by the creators. This project is important to us because we belive in allowing people to make use of their creativity to bring their ideas and stories to fruition. We intend to implement this program using C++ and the SQLite3 API.
> 
 > There are two possible inputs for this program, one from the creator, and one from the player. The creator will input the info they want to include their game, this includes things such as dialogue and text, the possible choices they want the user to make, and the pool of items we provide to include in their story. The input from the player is the path they decide to take for any given story.
> 
 > Given two possible inputs, we also have two possible outputs for the program. For the creator, upon completion of the story they make, they will get a text file which our program can use to run the story. For the player, the output will also be a text file which goes over their entire path of the story.
> 
 > Our program will include features such as the following:
 >  * Choosing between options given a prompt
 >  * Randomly decided choices without user input
 >  * Items to allow/prevent user from making a choice
 >  * User inventory
 >  * Base set of items to include in a story 
 >  * Save work in progress game (For creators)
 >  * Save a game in progress (For users)
 >  * Undo Action (For users)
 >  * Printed overview of story upon completion
 >
### Navigation Diagram
> <img width="584" alt="image" src="https://github.com/user-attachments/assets/41fec473-e33d-4b86-a791-051161e73727">

> Our navigation diagram shows all possible paths/routes the user can take through the program.

### Screen Layouts
<img width="682" alt="image" src="https://github.com/user-attachments/assets/d752b103-c3ff-44cf-8182-a16cb348c12d">

> Create Account: This allows the user to either sign in or create an account which allows them to access our game creation feature and game play feature.
> Run Program: This layout shows the very first display the user will get upon opening the program.
> Sign-In: This layout allows the user to sign into an already made account with a welcome message, and outputs an error message upon an invalid account being inputted.
> Edit Scene: This is the display that the user sees when they go to edit any scene for a game being made.
> Main Menu: Upon signing in, the user will see this display to decide what they want to do.
> Select a Game: Upon deciding play a game in the main menu, the user will get a display of games they can choose from to play.
> Scene Title: This is the display that the user will see when they are playing a story and they get to choose any of the provided choices.
 

## Class Diagram
<img width="600" alt="image" src= "https://github.com/user-attachments/assets/e3e35838-1b4c-4a36-a376-e4e3d9f22936">


> This diagram illustrates the seven classes we will be using to implement our project. The program class will hold the objects of all the other classes and runs our entire program through the run function, everything happens inside of here. The user class exists for the user to sign in and access the rest of our program, such as game play and game creation. Playing a game is done through the GameRunner class, and game creation is done through the GameCreator class. For our game class, it has basic identifying features and the core element of the game class is the vector of scenes. Each scene is essentially a page of the story which can be accessed through the choices class. The identifying features of the game, the users, and the scenes are all stored in a database and are crossreferenced with a unique id.

 ## SOLID Principles
 > We added a scene editor class to follow the SOLID single responsibility principle. We did this because the game creator class was handling to many features. The game creator class was responsible for adding scenes, creating scenes, creating games, changing games, and adding games. So we split these features into two different classes. One called GameCreator and the other SceneEditor, now the responsibilities are evenly distributed among the two classes. It helped us write better code because now each class can focus on a single feature and we can change each of the objects separately and avoid cluttering one single class.
> We originally added a database class to abstract sqlite3's database, and after implementation realized that the class was becoming too big and doing too much. We followed SOLID's single responsibility principle again here by making 3 separate classes for each of the things we want our database to do. One class abstract's the database to allow it to exist in our program, and we have two other classes, a DatabaseEditor and a DatabaseSelector to allow for acting on the existing database through the database class. This allows for us to easier understand the implementation of each class and makes our code more readable, accessible, and editable.
 
 > ## Final deliverable

 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
 
 ## Screenshots
 this is the opening screen:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/1cea170d-7b67-4490-8762-7ca49b3b5ba0">

>The account "ngel" is created:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/74d7a449-c305-4207-83ca-66585765e6ac">
>

>We type in 1 to add a scene:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/04226f32-adb0-48fe-be0d-d5fb545eea72">

>We are adding a scene called "We went to the pet shelter":
><img width="200" alt="image" src="https://github.com/user-attachments/assets/d80c2a34-bc4b-43f4-8ac2-302375b9c0f4">

>We are printing scene names:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/1b8f8727-607e-4818-8200-ff90f54d4472">

>This shows what games that have been created:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/48fc3a9e-13e5-48f4-b558-f9870230587f">

>We are now saving the game:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/d17df6eb-066d-4cd3-a802-b858b17d2574">

>We are quitting the game:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/248f71e7-ded7-47b8-9f35-3c52a172712c">

>This now takes us to the start screen:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/84455e3b-36f5-4d73-bdf0-ca8b9916ad3a">

>We are selecting to play a user created game:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/83d00fab-08dd-47ad-a50d-65d6e405e0e9">

>We are choosing a game to play:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/f7c1eb1b-81df-4d54-860b-344b9005fa71">

>This shows the scene in game 1:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/1b74ac30-9112-4a70-bf13-b78df7b72918">

 ## Installation/Usage
On first install:
> 1. Type cmake .
> 2. Type make
> 3. Type ./bin/choose-your-own-adventure
> 4. Type in a number to choose an option and press enter
 ## Testing
 We created test cases in our test class for each function. It tested the functionality and whether it passed or failed. We made sure each test file had multiple test cases to check other potential errors.
 
