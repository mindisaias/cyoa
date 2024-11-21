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
<img width="600" alt="image" src="https://github.com/user-attachments/assets/18729d3f-a6d8-4474-b4ca-d4a551c12470">

> This diagram illustrates the seven classes we will be using to implement our project. The program class will hold the objects of all the other classes and runs our entire program through the run function, everything happens inside of here. The user class exists for the user to sign in and access the rest of our program, such as game play and game creation. Playing a game is done through the GameRunner class, and game creation is done through the GameCreator class. For our game class, it has basic identifying features and the core element of the game class is the vector of scenes. Each scene is essentially a page of the story which can be accessed through the choices class. The identifying features of the game, the users, and the scenes are all stored in a database and are crossreferenced with a unique id.

 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
