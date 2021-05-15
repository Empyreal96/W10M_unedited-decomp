// MiSetDeleteOnClose 
 
int __fastcall MiSetDeleteOnClose(_DWORD *a1, int a2)
{
  unsigned int *v3; // r4
  int v5; // r9
  __int64 v6; // r0
  int v7; // r3
  int v8; // r1
  unsigned __int8 *v9; // r3
  unsigned int v10; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = a1 + 9;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3);
  }
  else
  {
    v9 = (unsigned __int8 *)v3 + 3;
    do
      HIDWORD(v6) = __ldrex(v9);
    while ( __strex(BYTE4(v6) | 0x80, v9) );
    __dmb(0xBu);
    if ( HIDWORD(v6) >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v3);
    while ( 1 )
    {
      v10 = *v3;
      if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          HIDWORD(v6) = __ldrex(v3);
        while ( HIDWORD(v6) == v10 && __strex(v10 | 0x40000000, v3) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = a1[7];
  if ( (v7 & 0x40000) == 0 )
  {
    if ( (v7 & 0x8000000) != 0 )
    {
      LODWORD(v6) = a1;
      MiRemoveUnusedSegment(v6);
      a1[7] |= 0x40000u;
      MiInsertUnusedSegment(a1, v8);
    }
    else
    {
      a1[7] = v7 | 0x40000;
    }
  }
  if ( a2 == 1 )
    a1[7] |= 0x10u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v5);
}
