// LdrpInitMuiCrits 
 
int LdrpInitMuiCrits()
{
  unsigned int v0; // r2
  int result; // r0

  while ( 1 )
  {
    __dmb(0xBu);
    do
      v0 = __ldrex((unsigned int *)&MuiLockInitCount);
    while ( !v0 && __strex(1u, (unsigned int *)&MuiLockInitCount) );
    __dmb(0xBu);
    if ( !v0 )
      break;
    if ( MuiLockInitCount == 1 )
      return sub_519420();
    if ( MuiLockInitCount == 2 )
      return result;
  }
  result = KiInitializeMutant((int)&MuiMutex, 0, 1);
  MuiLockInitCount = 2;
  return result;
}
