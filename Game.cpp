//
//  Game.cpp
//  Pic 10B HW1
//
//  Created by Michaella Baltazar on 10/15/19.
//  Copyright © 2019 Michaella Baltazar. All rights reserved.
//

#include "Game.hpp"
#include "Person.hpp"
#include <string>
#include <iostream>
using namespace std;

Game::Game()
{
    p1 = Person();
    p2 = Person();
}

std::string board[9] = {" "," "," "," "," "," "," "," "};

//drawing the grid
void Game::grid()
{
    //        cout << "01234567|1234567|1234567"<< endl;
    cout << "   1        2       3   "<< endl;
    cout << "        |       |       "<< endl;
    cout << "1   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   "<< endl;
    cout << " _______|_______|_______"<< endl;
    cout << "        |       |       "<< endl;
    cout << "2   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   "<< endl;
    cout << " _______|_______|_______"<< endl;
    cout << "        |       |       "<< endl;
    cout << "3   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   "<< endl;
    cout << "        |       |       "<< endl;
}

//create the players
Game::Game(string playerOne, string playerTwo)
{
    p1 = Person(playerOne);
    p2 = Person(playerTwo);
    //playMe(*p1, *p2);
}

int Game::conversion(int pos)
{
    switch (pos)
    {
        case 11:
            return 0;
            break;
        case 12:
            return 1;
            break;
        case 13:
            return 2;
            break;
        case 21:
            return 3;
            break;
        case 22:
            return 4;
            break;
        case 23:
            return 5;
            break;
        case 31:
            return 6;
            break;
        case 32:
            return 7;
            break;
        case 33:
            return 8;
            break;
    }
    return -1;
}

//takes the player's input and alters the grid
void Game::playerMove(Person& player)
{
    int coordinates;
    cout << player.playerName() << "'s turn. Please input coordinates: ";
    cin >> coordinates;
    if (!cin)
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    int pos = conversion(coordinates);
    if (board[pos].compare(" ") != 0)   //space not available
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    if (pos < 0)
    {
        cin.clear();
        cin.ignore(10000,'\n');
    }
    //if player 1, put X at position
    if (player.playerName().compare(p1.playerName())==0)
    {
        board[pos] = "X";
        moves++;
    }
    //if player 2, put O at position
    else
    {
        board[pos] = "O";
        moves++;
    }
    grid();
    checkGrid();
}


//checks if there is any wins or if all the available spaces are gone
void Game::checkGrid()
{
    if (board[0].compare(" ")!= 0)  // 1 1 is not vacant
    {
        if ((board[0].compare(board[1])==0) && (board[1].compare(board[2])==0))
        {
            // top horizontal match
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
        if ((board[0].compare(board[3])==0) && (board[3].compare(board[6])==0))
        {
            //first row vertical
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
        if ((board[0].compare(board[4])==0) && (board[4].compare(board[8])==0))
        {
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
    }
    
    if (board[4].compare(" ")!= 0)  // 1 1 is not vacant
    {
        if ((board[4].compare(board[3])==0) && (board[3].compare(board[5])==0))
        {
            // top horizontal match
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
        if ((board[4].compare(board[1])==0) && (board[1]).compare(board[7])==0)
        {
            //first row vertical
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
        if ((board[4].compare(board[2])==0) && (board[2].compare(board[6])==0))
        {
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
    }
    
    if (board[8].compare(" ")!= 0)  // 1 1 is not vacant
    {
        if ((board[8].compare(board[6])==0) && (board[6].compare(board[7])==0))
        {
            // top horizontal match
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
        if ((board[8].compare(board[2])==0) && (board[2].compare(board[5])==0))
        {
            //first row vertical
            if (board[0].compare("X")==0)
                p1.addWin();
            else
                p2.addWin();
        }
    }
}


void Game::play()
{
    for (int i = 0; i < 9; i++)
    {
        if ( (i==0) || (i%2 == 0))
        {
            playerMove(p1);
        }
        else
        {
            playerMove(p2);
        }
    }
}

//prints the score
void Game::showScore()
{
    cout << p1.playerName() << ": " << p1.playerScore() << endl;
    cout << p2.playerName() << ": " << p2.playerScore() << endl;
}

//
void Game::present()
{
    
}

//actually do the game
void Game::playMe(Person &p1, Person &p2)
{
    
}
