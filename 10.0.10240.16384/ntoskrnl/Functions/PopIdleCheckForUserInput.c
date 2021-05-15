// PopIdleCheckForUserInput 
 
int PopIdleCheckForUserInput()
{
  if ( MEMORY[0xFFFF92E4] == dword_61E810 )
    return 0;
  dword_61E810 = MEMORY[0xFFFF92E4];
  PopResetIdleTime(1);
  return 1;
}
