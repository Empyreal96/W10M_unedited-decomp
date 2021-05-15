// ViAvlReleaseTableLockFromDpcLevel 
 
unsigned int *__fastcall ViAvlReleaseTableLockFromDpcLevel(unsigned int *result, int a2)
{
  char v3; // r3
  unsigned int v4; // r1
  unsigned int v5; // r2

  if ( (*(_BYTE *)(a2 + 5) & 4) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
      return (unsigned int *)sub_518B34();
    __dmb(0xBu);
    result[32] = 0;
  }
  else
  {
    result += 32;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = (unsigned int *)ExpReleaseSpinLockSharedFromDpcLevelInstrumented(result);
    }
    else
    {
      __dmb(0xBu);
      do
        v4 = __ldrex(result);
      while ( __strex(v4 & 0xBFFFFFFF, result) );
      __dmb(0xBu);
      do
        v5 = __ldrex(result);
      while ( __strex(v5 - 1, result) );
    }
  }
  v3 = *(_BYTE *)(a2 + 5);
  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 5) = v3 & 0xFD;
  return result;
}
