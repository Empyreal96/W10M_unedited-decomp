// KiInitializeNxSupportDiscard 
 
int KiInitializeNxSupportDiscard()
{
  int result; // r0
  char v1; // r1

  MEMORY[0xFFFF92D5] = MEMORY[0xFFFF92D5] & 0xFC | 1;
  result = KiIsNXSupported();
  if ( result )
    MEMORY[0xFFFF9280] = v1;
  return result;
}
