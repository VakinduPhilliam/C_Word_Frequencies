 #include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>

using namespace std;

const int MAX_CHARS = 60 ;
const int MAX_WORDS = 30000 ;



int sequential_search ( int data [], int from, int to, int search_value )
{
    // pre-condition
    assert(0 <= from && 0 <= to) ;

    if ( from > to )
        return to + 1 ;
    int position = from ;
    while ( position <= to && data [ position ] != search_value )
        position++ ;
    return position ;
}

bool open_text_file ( ifstream& infile )
{
    // pre-conditions
    assert( !infile.is_open ()) ;

    // post-condition
    // Result is true only if the file is opened

    cout << "Please enter a file name here: " ;
    char filename [80] ;
    cin.getline( filename, 80, '\n') ;
    infile.open( filename ) ;
    return infile.is_open () ;

}

bool read_word (ifstream& infile, char word [MAX_CHARS])
{
    // pre-conditions
    assert(infile.is_open () ) ;

    // post-condition
    // Result is true only if word has been filled with the next word from infile

    infile >> word ;
    return infile ;

}

bool tally_word ( char word [MAX_CHARS], char words [MAX_WORDS][MAX_CHARS], int freqs [MAX_WORDS], int& no )
{
    // pre-conditions
    assert( no >= 0 && no < MAX_WORDS ) ;

    int pos = sequential_search ( words, 0, no, word ) ;
    if ( pos < no )
    {
        freqs [pos]++ ;
        return true ;
    }
    else if ( pos < MAX_WORDS )
    {
        strcpy ( words [pos], word ) ;
        freqs [pos] = 1 ;
        no++ ;
        return true ;
    }
    return false ;

}

int count_words ( ifstream& infile, char words [MAX_WORDS][MAX_CHARS], int freqs [MAX_WORDS] )
{
    // pre-conditions
    assert( infile.is_open ()) ;

    // post-condition
    // Result is the number of counted words stored in words and freqs

    int no = 0 ;
    char next [MAX_CHARS] ;
    while ( read_word ( infile, next ) && tally_word ( next, words, freqs, no ) && no < MAX_WORDS ) ;
    return no ;
}




void display_frequencies ( char words [MAX_WORDS][MAX_CHARS], int freqs [MAX_WORDS], int no )
{
    // pre-conditions
    assert( no >= 0 && no < MAX_WORDS ) ;

    // Post-condition
    // All words and their frequencies have been printed

    for ( int i = 0 ; i < no ; i++ )
    {
        cout << words [i] << '\t'
             << freqs [i] << '\n' ;
    }
}




int main ()
{
    ifstream file ;
    if ( open_text_file ( file ) )
    {
        char words [MAX_WORDS][MAX_CHARS] ;
        int freqs [MAX_WORDS] ;
        int nr = count_words( file, words, freqs ) ;
        display_frequencies( words, freqs, nr ) ;
        file.close () ;
        return 0 ;
    }
    else return 1 ;
}