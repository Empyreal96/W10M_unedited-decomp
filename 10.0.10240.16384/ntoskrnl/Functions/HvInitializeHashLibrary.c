// HvInitializeHashLibrary 
 
int HvInitializeHashLibrary()
{
  int v0; // r0
  int result; // r0
  int v2[2]; // [sp+0h] [bp-8h] BYREF

  v0 = SymCryptInit();
  v2[0] = 2051954117;
  v2[1] = -2098246264;
  if ( SymCryptMarvin32ExpandSeed(v0, v2) )
    result = -1073741823;
  else
    result = 0;
  return result;
}
