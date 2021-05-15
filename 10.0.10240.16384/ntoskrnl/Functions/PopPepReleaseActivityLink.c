// PopPepReleaseActivityLink 
 
int __fastcall PopPepReleaseActivityLink(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r4
  unsigned int v6; // r1
  _DWORD *v7; // r2
  unsigned int *v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2

  v5 = a1;
  if ( a3 == 1 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = *(_DWORD **)(a1 + 48);
      if ( v7 )
      {
        if ( *v7 )
          break;
      }
      ++v6;
      a1 += 4;
      if ( v6 >= 6 )
      {
        if ( *(_BYTE *)(v5 + 88) )
          *(_BYTE *)(v5 + 77) = 0;
        if ( (dword_682604 & 0x10000) != 0 )
          return sub_53F024(a1);
        goto LABEL_12;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
      return sub_53F024(a1);
LABEL_12:
    __dmb(0xBu);
    *(_DWORD *)(v5 + 44) = 0;
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a2);
    }
    else
    {
      __dmb(0xBu);
      *a2 = 0;
    }
    v9 = (unsigned int *)(v5 + 44);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v9);
    }
    else
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0xBFFFFFFF, v9) );
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 - 1, v9) );
    }
  }
  return KfLowerIrql(a4);
}
