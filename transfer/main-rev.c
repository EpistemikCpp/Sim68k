/*
 *  MAIN
 **************************************************************************/
int main( int argc, char* argv[] )
{
  char option ; // option chosen from the menu by the user
  char input[ memorySize ];
  char program_name[ memorySize ];
  
  // info on system data sizes
#if DEBUG > 1
  printf( "sizeof( char ) == %d\n", sizeof(char) );
  printf( "sizeof( short ) == %d\n", sizeof(short) );
  printf( "sizeof( int ) == %d\n", sizeof(int) );
  printf( "sizeof( long ) == %d\n", sizeof(long) );
  printf( "sizeof( bit ) == %d\n", sizeof(enum bit) );
  printf( "sizeof( rwbit ) == %d\n", sizeof(enum rwbit) );
  printf( "sizeof( dataSize ) == %d\n", sizeof(enum dataSize) );
  printf( "sizeof( numOperands ) == %d\n", sizeof(enum numOperands) );
  printf( "sizeof( boolean ) == %d\n", sizeof(boolean) );
  printf( "sizeof( string ) == %d\n", sizeof(string) );
  printf( "sizeof( byte ) == %d\n", sizeof(byte) );
  printf( "sizeof( word ) == %d\n", sizeof(word) );
#endif

  MnemoInit();
  fflush(stdout);
  // Menu 
  while( option != QUIT )
  {
    fflush(stdin);
    //if( ! isspace(option) )
      printf( "Your Option ('%c' to execute, '%c' to quit): ", EXECUTE, QUIT );
      fflush(stdout);
    
    gets( input );
    if( strchr(input, EXECUTE) )
      option = EXECUTE ;
    else
      if( strchr(input, QUIT) )
        option = QUIT ;
      else
          option = 'i' ;
    switch( option )
    {
      case EXECUTE :
                    // Execution on the simulator
                    puts( "Name of the 68k binary program ('.68b' will be added automatically): " );
                    gets( program_name );
                    if( Loader(strcat(program_name, ".68b")) )
                      Controller(); // Start the simulator
                    
                    break;
      
      case QUIT : puts( "Bye!" );
                  break;
                  
      default: printf( "Invalid Option. Please enter '%c' or '%c' \n", EXECUTE, QUIT );
    }
    
  }// while
  
  printf( "\tPROGRAM ENDED\n" );
  return 0 ;

}// main()
