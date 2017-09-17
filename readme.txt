Assignment ID:  PROG2

Program Names:  PROG2  Scrabble.cpp

Givens (in OP): key-Scrabble.run
                

DESCRIPTION:   Design and write a program that processes an input file 
               containing a sequence of triples:

                  <row> <col> <character> <row><col><character> ... 0 0 X

               The square "board" can contain up to 9 rows and 9 columns.

               Keyboard inputs:
                   (1) name of the input file;
                   (2) board size.

 
                       +-----------------+
                       |                 |
      string filename  |                 |
      ---------------->|    program      |   
                       |                 |
      int boardsize    |                 |          Board Row*
      ---------------->|    Scrabble     |-------------------->
                       |                 |
           int row*    |                 |
           ----------->|                 |    Error Message(s) 
                       |                 |-------------------->
                       |                 |
           int col*    |                 |
           ----------->|                 |  word*
                       |                 |-------------------->
       char symbol*    |                 |
       --------------->|                 |  #words
                       |                 |-------------------->
                       +-----------------+

        ------
        Note:  * means multiple values read/displayed during program execution.


                    .
Example 1:      Input:  
                     keyboard ==> thisfile  4
                     thisfile ==> 1 1 A 2 2 B 3 3 C 0 0 X

                Output: 

                     3 TILES on Scrabble Board
                     
                     ROW COL LETTER
                     === === ======
                      1   1    A
                      2   2    B
                      3   3    C
                     === === ======
                     
                     
                     4 x 4 SCRABBLE BOARD 
                     
                     
                                   1 2 3 4
                                 + - - - - +
                          row1=> | A       |
                          row2=> |   B     |
                          row3=> |     C   |
                          row4=> |         |
                                 + - - - - +
                                   1 2 3 4
                     
                     `

Example 2:      Input:  
                     keyboard    ==> nothinghere 5
                     nothinghere ==> 

                Output: 

                    0 TILES on Scrabble Board
                    
                    ROW COL LETTER
                    === === ======
                    === === ======
                    
                    
                    5 x 5 SCRABBLE BOARD 


                              1 2 3 4 5
                            + - - - - - +
                     row1=> |           |
                     row2=> |           |
                     row3=> |           |
                     row4=> |           |
                     row5=> |           |
                            + - - - - - +
                              1 2 3 4 5
`

Example 3:
                Input:  
                     keyboard    ==> stuff 5
                     stuff ==> 1 3 G 2 3 O 2 4 F 2 5 F 3 2 O 3 4 A
                               4 2 F 4 3 A 4 4 T 5 2 T 0 0 X


                Output: 

                10 TILES on Scrabble Board
              
                ROW COL LETTER
                === === ======
                 1   3    G
                 2   3    O
                 2   4    F
                 2   5    F
                 3   2    O
                 3   4    A
                 4   2    F
                 4   3    A
                 4   4    T
                 5   2    T
                === === ======


                5 x 5 SCRABBLE BOARD
              
              
                              1 2 3 4 5
                            + - - - - - +
                     row1=> |     G     |
                     row2=> |     O F F |
                     row3=> |   O   A   |
                     row4=> |   F A T   |
                     row5=> |   T       |
                            + - - - - - +
                              1 2 3 4 5

ScrabbleWords ===>
              
                WORDS ON 5 x 5 SCRABBLE BOARD
                HORIZONTAL: OFF FAT 2 WORDS
                VERTICAL:   OFT GO FAT 3 WORDS
                5 SCRABBLE WORDS


DESIGN CONSTRAINTS:
        
        (1) Store all board characters into array

              char Board[9][9];   // Capacity is 9x9 = 81.


           RULE: A board cell can contain at most one value;
                 Display error message when:
                    - the cell already contains a mark
                    - the mark is not a letter
                    - the row is outside the range [1,boardsize]
                    - the col is outside the range [1,boardsize]

                     ERROR:  REJECTED CELL <row> <col> <symbol> CELL MARKED
                     ERROR:  REJECTED CELL <row> <col> <symbol> NOT A LETTER
                     ERROR:  REJECTED CELL <row> <col> <symbol> BAD ROW
                     ERROR:  REJECTED CELL <row> <col> <symbol> BAD COL


        (2) After the input file has been read, display the Board array.


        (3) Display the words on the scrable board (illustration only):

             HORIZONTAL: xxxx yyyyyyy zzzzz 3 WORDS
             VERTICAL:   aaa bbb ccc ddd  4 WORDS
             7 SCRABBLE WORDS


