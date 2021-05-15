// PopPepUpdateComponentResidentStatus 
 
int __fastcall PopPepUpdateComponentResidentStatus(int result, int a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r1

  v2 = *(_DWORD *)(result + 4);
  if ( ((v2 >> 2) & 1) != 0 )
  {
    if ( !a2 )
    {
      *(_DWORD *)(result + 4) = v2 & 0xFFFFFFFB;
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&PopPepPoweredIdleComponentCount);
      while ( __strex(v5 - 1, (unsigned int *)&PopPepPoweredIdleComponentCount) );
      __dmb(0xBu);
    }
  }
  else if ( a2 )
  {
    *(_DWORD *)(result + 4) = v2 | 4;
    __dmb(0xBu);
    do
    {
      v3 = __ldrex((unsigned int *)&PopPepPoweredIdleComponentCount);
      v4 = v3 + 1;
    }
    while ( __strex(v4, (unsigned int *)&PopPepPoweredIdleComponentCount) );
    __dmb(0xBu);
    if ( v4 == 1 )
      result = PopPepArmIdleTimer(0);
  }
  return result;
}
