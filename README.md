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
<img width="583" alt="image" src="https://github.com/user-attachments/assets/e339dd9b-dcc2-4e4f-a740-de71b8d99b0f" />

> Our navigation diagram shows all possible paths/routes the user can take through the program.

### Screen Layouts
<img width="683" alt="image" src="https://github.com/user-attachments/assets/213092d8-819e-45ab-9dfa-8af27e89a1d0" />


> Create Account: This allows the user to either sign in or create an account which allows them to access our game creation feature and game play feature.
> Run Program: This layout shows the very first display the user will get upon opening the program.
> Sign-In: This layout allows the user to sign into an already made account with a welcome message, and outputs an error message upon an invalid account being inputted.
> Edit Scene: This is the display that the user sees when they go to edit any scene for a game being made.
> Main Menu: Upon signing in, the user will see this display to decide what they want to do.
> Select a Game: Upon deciding play a game in the main menu, the user will get a display of games they can choose from to play.
> Scene Title: This is the display that the user will see when they are playing a story and they get to choose any of the provided choices.
 

## Class Diagram
<img width="598" alt="image" src="https://github.com/user-attachments/assets/d8d99455-f925-4e40-aeee-0060c0d91f10" />



> This diagram illustrates the seven classes we will be using to implement our project. The program class will hold the objects of all the other classes and runs our entire program through the run function, everything happens inside of here. The user class exists for the user to sign in and access the rest of our program, such as game play and game creation. Playing a game is done through the GameRunner class, and game creation is done through the GameCreator class. For our game class, it has basic identifying features and the core element of the game class is the vector of scenes. Each scene is essentially a page of the story which can be accessed through the choices class. The identifying features of the game, the users, and the scenes are all stored in a database and are crossreferenced with a unique id.

 ## SOLID Principles
 > We added a scene editor class to follow the SOLID single responsibility principle. We did this because the game creator class was handling to many features. The game creator class was responsible for adding scenes, creating scenes, creating games, changing games, and adding games. So we split these features into two different classes. One called GameCreator and the other SceneEditor, now the responsibilities are evenly distributed among the two classes. It helped us write better code because now each class can focus on a single feature and we can change each of the objects separately and avoid cluttering one single class.
> We originally added a database class to abstract sqlite3's database, and after implementation realized that the class was becoming too big and doing too much. We followed SOLID's single responsibility principle again here by making 3 separate classes for each of the things we want our database to do. One class abstract's the database to allow it to exist in our program, and we have two other classes, a DatabaseEditor and a DatabaseSelector to allow for acting on the existing database through the database class. This allows for us to easier understand the implementation of each class and makes our code more readable, accessible, and editable.

 ## Screenshots
 this is the opening screen:
><img width="306" alt="image" src="https://github.com/user-attachments/assets/4ef7f36f-5db7-46a0-940c-ea0e4e7e23b1" />


>The account "ngel" is created:
><img width="309" alt="image" src="https://github.com/user-attachments/assets/df5ac8f2-1941-4036-abd7-4141dd7635be" />
>

>We type in 1 to add a scene:
><img width="307" alt="image" src="https://github.com/user-attachments/assets/c0075d9a-4f50-428a-be8c-e4c84547f177" />


>We are adding a scene called "We went to the pet shelter":
><img width="307" alt="image" src="https://github.com/user-attachments/assets/959f2b54-2c08-4806-bd51-f9485adb87f1" />


>We are printing scene names:
><img width="306" alt="image" src="https://github.com/user-attachments/assets/cf1ae6c9-28ba-4979-984b-5b19d2bd0b2b" />


>This shows what games that have been created:
><img width="200" alt="image" src="https://github.com/user-attachments/assets/48fc3a9e-13e5-48f4-b558-f9870230587f">

>We are now saving the game:
><img width="270" alt="image" src="https://github.com/user-attachments/assets/c45311aa-2358-4774-bae2-0112ed16c0a6" />


>We are quitting the game:
><img width="275" alt="image" src="https://github.com/user-attachments/assets/29f90b30-068c-4c76-9485-1371e5707ce3" />


>This now takes us to the start screen:
><img width="269" alt="image" src="https://github.com/user-attachments/assets/c1f0429e-c9db-43ee-a91b-5049d67681d1" />


>We are selecting to play a user created game:
><img width="273" alt="image" src="https://github.com/user-attachments/assets/ad1f97b7-bdfe-42c1-b28c-df9d37ef83a5" />


>We are choosing a game to play:
><img width="272" alt="image" src="https://github.com/user-attachments/assets/c54d33c0-f1a9-4bc4-ba29-dd3383ce4822" />

>This shows the scene in game 1:
><img width="270" alt="image" src="https://github.com/user-attachments/assets/8ae4e460-01aa-4f4b-8c2a-d60cf34d0edc" />

 ## Installation/Usage
On first install:
> 1. Type cmake .
> 2. Type make
> 3. Type ./bin/choose-your-own-adventure
> 4. Type in a number to choose an option and press enter
 ## Testing
 We created test cases in our test class for each function. It tested the functionality and whether it passed or failed. We made sure each test file had multiple test cases to check other potential errors.
 
