// RtlpSparseBitmapCtxLockExclusive 
 
int __fastcall RtlpSparseBitmapCtxLockExclusive(int a1, unsigned int *a2)
{
  int v4; // r6
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r1

  if ( (*(_DWORD *)(a1 + 48) & 4) != 0 )
    return 1;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2);
  }
  else
  {
    v5 = (unsigned __int8 *)a2 + 3;
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a2);
    while ( 1 )
    {
      v7 = *a2;
      if ( (*a2 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v7 & 0x40000000) == 0 )
      {
        do
          v8 = __ldrex(a2);
        while ( v8 == v7 && __strex(v7 | 0x40000000, a2) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  return v4;
}
