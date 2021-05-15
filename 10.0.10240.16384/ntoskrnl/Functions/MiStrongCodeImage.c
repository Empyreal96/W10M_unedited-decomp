// MiStrongCodeImage 
 
__int64 __fastcall MiStrongCodeImage(int a1, unsigned int a2)
{
  unsigned int *v3; // r4
  int v5; // r9
  unsigned int v6; // r2
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r1
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = (unsigned int *)(a1 + 36);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3);
  }
  else
  {
    v7 = (unsigned __int8 *)v3 + 3;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v3);
    while ( 1 )
    {
      v9 = *v3;
      if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v9 & 0x40000000) == 0 )
      {
        do
          v10 = __ldrex(v3);
        while ( v10 == v9 && __strex(v9 | 0x40000000, v3) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v6 = *(_DWORD *)(a1 + 52);
  if ( ((v6 >> 26) & 3) < a2 )
    *(_DWORD *)(a1 + 52) = (v6 ^ (a2 << 26)) & 0xC000000 ^ v6;
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
