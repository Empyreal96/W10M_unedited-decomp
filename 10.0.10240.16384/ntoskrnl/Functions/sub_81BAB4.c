// sub_81BAB4 
 
void sub_81BAB4()
{
  int v0; // r6

  while ( 1 )
  {
    v0 = MEMORY[0xFFFF9324];
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v0 == MEMORY[0xFFFF9328] )
      break;
    __dmb(0xAu);
    __yield();
  }
  JUMPOUT(0x7BBBE0);
}
