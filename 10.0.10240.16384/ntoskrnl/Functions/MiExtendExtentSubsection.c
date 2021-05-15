// MiExtendExtentSubsection 
 
int __fastcall MiExtendExtentSubsection(_DWORD *a1)
{
  unsigned int *v2; // r4
  int v3; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = (unsigned int *)(*a1 + 36);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
  }
  else
  {
    v4 = (unsigned __int8 *)v2 + 3;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v2);
    while ( 1 )
    {
      v6 = *v2;
      if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v6 & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex(v2);
        while ( v7 == v6 && __strex(v6 | 0x40000000, v2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiInitializeFileExtents(a1, v3);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  KfLowerIrql(v3);
  return 0;
}
