#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// function used to read from file
// will save data in the board array and count the tile in tilesCount
bool readFile(string fileName, int* board, int boardSize, int &tilesCount) 
{
  tilesCount = 0;
  string line;
  ifstream infile (fileName);
  if (infile.is_open())
  {
    while ( !infile.eof())
    {
      int row = 0;
      int col = 0;
      char letter = 'X';

      infile >> row >> col >> letter;

      // check if we reached end with 0 0 X
      if(row == 0 && col == 0 && letter == 'X') 
      {
        break; //stop everything and exit this loop
      }

      // check if read a letter
      if(!((letter>='a' && letter<='z') || (letter>='A' && letter<='Z')))
      {
        cerr << "ERROR:  REJECTED CELL " << row << " " << col << " " << letter << " NOT A LETTER\n";
        return false;
      }
      // check if row is valid
      if(row < 1 || row > boardSize) 
      {
        cerr << "ERROR:  REJECTED CELL " << row << " " << col << " " << letter << " BAD ROW\n";
        return false;  
      }
      // check if col is valid
      if(col < 1 || col > boardSize) 
      {
        cerr << "ERROR:  REJECTED CELL " << row << " " << col << " " << letter << " BAD COL\n";
        return false;  
      }
      // decrease row and col as we start from 0-based index 
      --row;
      --col;
      // check cell is not already occupied
      if(board[row*boardSize+col] != 0)
      {
        cerr << "ERROR:  REJECTED CELL " << row << " " << col << " " << letter << " CELL MARKED\n";
        return false;  
      }

      // everything ok..save the value on board and increase tilesCount
      board[row*boardSize+col] = letter;
      tilesCount++;            
    }
    infile.close();
    return true;
  }
  else
  {
    cerr << "Unable to open file"; 
    return false;
  }
}

// print tiles information
void printTiles(int* board, int boardSize, int tilesCount)
{
  cout << tilesCount << " TILES on Scrabble Board\n\n";

  //print header
  cout << "ROW COL LETTER\n";
  cout << "=== === ======\n";

  //print tiles
  for(int i=0;i<boardSize;i++) 
  {
    for(int j=0;j<boardSize;++j)
    {
      if(board[i*boardSize+j]!= 0) 
      {
        cout << " " << i+1 << "   " << j+1 << "    " << (char)board[i*boardSize+j] << "\n";
      }
    }
  } 

  //print tail
  cout << "=== === ======\n\n";
}

void printScrabbleBoard(int* board, int boardSize) 
{
  // print header
  cout << boardSize << " x " << boardSize << " SCRABBLE BOARD\n\n";
              
  // print top line
  cout << "\t         "; 
  for(int i=0;i<boardSize;++i)
  {
    cout << i+1 << " ";
  }            
  cout << "\n\t       + "; 
  for(int i=0;i<boardSize;++i)
  {
    cout << "- ";
  }    
  cout << "+\n";
  //print each row
  for(int i=0;i<boardSize;++i)
  {
    cout << "\trow"<<i+1<<"=> | ";
    for(int j=0;j<boardSize;++j)
    {
      cout << (board[i*boardSize+j] == 0 ? ' ' : (char)board[i*boardSize+j]) << " ";
    }
    cout << "|\n";
  }
  // print bottom line
  cout << "\t       + "; 
  for(int i=0;i<boardSize;++i)
  {
    cout << "- ";
  }    
  cout << "+\n";
  cout << "\t         "; 
  for(int i=0;i<boardSize;++i)
  {
    cout << i+1 << " ";
  }      
  cout << "\n";                  
}


// check for workds on board
void scrabbleWords(int* board, int boardSize)
{
  // will save the words in vectors
  vector<string> horiz;
  vector<string> vert;

  //first for horizontal....we go each row and see if there are words with lenght > 1
  for(int i=0;i<boardSize;++i) 
  {
    string word = "";
    for(int j=0;j<boardSize;++j)
    {
      if(board[i*boardSize+j] == 0) 
      {
        if(word.size() > 1) //is there any word there already?
        {
          horiz.push_back(word);
        }
        //reset word
        word = "";
      }
      else 
      {
        word.append(1, (char)board[i*boardSize+j]);
      }
    }
    //see if there is any word at the end of line
    if(word.size() > 1) 
    {
      horiz.push_back(word);
    }
  }

  //then check the columns
  for(int j=0;j<boardSize;++j) 
  {
    string word = "";
    for(int i=0;i<boardSize;++i)
    {
      if(board[i*boardSize+j] == 0) 
      {
        if(word.size() > 1) //is there any word there already?
        {
          vert.push_back(word);
        }
        //reset word
        word = "";
      }
      else 
      {
        word.append(1, (char)board[i*boardSize+j]);
      }
    }
    //see if there is any word at the end of line
    if(word.size() > 1) 
    {
      vert.push_back(word);
    }
  }

  if(horiz.size() + vert.size() > 0) //is there any word? if yes print them
  {
    cout << "ScrabbleWords ===>\n\n";
    cout << "\tWORDS ON " << boardSize << " x " << boardSize << " SCRABBLE BOARD\n";
    //print horizontal
    cout << "\tHORIZONTAL:";
    for(string word : horiz) 
    {
      cout << " " << word;
    }
    cout << " " << horiz.size() << " WORDS\n";
    //print vertical words
    cout << "\tWERTICAL:";
    for(string word : vert) 
    {
      cout << " " << word;
    }
    cout << " " << vert.size() << " WORDS\n";

    // print total
    cout << "\t" << horiz.size() + vert.size() << " SCRABBLE WORDS\n\n";
  }
}


int main (int argc, char* argv[]) 
{
  string fileName;
  int boardSize;

  cout << "Input data (filename board_size):";
  cin >> fileName >> boardSize;

  // allocate an array to represent the board
  int* board = new int[boardSize*boardSize];
  for(int i=0;i<boardSize;i++) 
  {
    for(int j=0;j<boardSize;j++)
    {
      board[i*boardSize+j] = 0;
    }
  }
  int tilesCount;
  if(readFile(fileName, board, boardSize, tilesCount))
  {
      printTiles(board, boardSize, tilesCount);
      printScrabbleBoard(board, boardSize);
      scrabbleWords(board, boardSize);
  }

  delete[] board;

  return 0;
}