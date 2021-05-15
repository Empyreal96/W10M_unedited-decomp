// MiInsertAweInfo 
 
int __fastcall MiInsertAweInfo(int a1, int a2)
{
  unsigned int *v3; // r4
  int v5; // r8
  int v6; // r5
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1

  v3 = (unsigned int *)(a1 + 492);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3);
  }
  else
  {
    v8 = (unsigned __int8 *)v3 + 3;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v3);
    while ( 1 )
    {
      v10 = *v3;
      if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex(v3);
        while ( v11 == v10 && __strex(v10 | 0x40000000, v3) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v6 = *(_DWORD *)(a1 + 328);
  if ( !v6 )
    *(_DWORD *)(a1 + 328) = a2;
  MiUnlockWorkingSetExclusive((int)v3, v5);
  if ( v6 )
  {
    MiFreeAweInfo(a2);
    a2 = v6;
  }
  return a2;
}
