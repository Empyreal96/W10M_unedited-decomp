// MiRecheckVaVm 
 
int __fastcall MiRecheckVaVm(int a1, unsigned int a2)
{
  int v2; // r5
  int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r0
  unsigned int v12; // r1
  bool v13; // zf

  v2 = 1;
  if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
  {
    if ( a2 < dword_63389C )
      return v2;
    return 0;
  }
  if ( a2 < dword_63389C )
    return 0;
  if ( (dword_682604 & 0x210000) == 0 )
  {
    v6 = dword_6342C0 & 0x7FFFFFFF;
    v7 = (dword_6342C0 & 0x7FFFFFFF) + 1;
    do
      v8 = __ldrex((unsigned int *)&dword_6342C0);
    while ( v8 == v6 && __strex(v7, (unsigned int *)&dword_6342C0) );
    __dmb(0xBu);
    if ( v8 != v6 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
    v9 = *((unsigned __int8 *)&MiState[2423]
         + ((int)(((a2 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    v10 = *(_BYTE *)(a1 + 112) & 7;
    switch ( v10 )
    {
      case 1:
        if ( v9 != 1 )
        {
          v13 = v9 == 11;
          goto LABEL_25;
        }
        break;
      case 2:
        v13 = v9 == 8;
        goto LABEL_25;
      case 3:
        if ( v9 == 6 )
          break;
        v13 = v9 == 14;
LABEL_25:
        if ( !v13 )
          v2 = 0;
        break;
      case 4:
        v13 = v9 == 9;
        goto LABEL_25;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v11 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v12 - 1, (unsigned int *)&dword_6342C0) );
    }
    return v2;
  }
  return sub_54F0D0();
}
