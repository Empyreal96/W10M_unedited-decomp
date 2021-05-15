// MiCleanWorkingSet 
 
int __fastcall MiCleanWorkingSet(int a1)
{
  unsigned int *v2; // r5
  int v3; // r7
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  int v8; // r0
  int v9; // r3
  int v10; // r4
  unsigned int v11; // r1

  v2 = (unsigned int *)(a1 + 492);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51A158();
  v5 = (unsigned __int8 *)v2 + 3;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v7 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v7 & 0x40000000) == 0 )
    {
      do
        v11 = __ldrex(v2);
      while ( v11 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  *(_BYTE *)(a1 + 607) |= 1u;
  MiRemoveWorkingSetPages(v2);
  v8 = *(_DWORD *)(a1 + 500);
  *(_DWORD *)(a1 + 276) -= 3;
  if ( v8 )
  {
    MiEmptyPageAccessLog();
    *(_DWORD *)(a1 + 500) = 0;
  }
  v9 = *(_DWORD *)(a1 + 540);
  v10 = v9 - 4;
  MiChargeWsles(v2, 4 - v9, 1);
  MiUnlockWorkingSetExclusive(v2, v3);
  return v10;
}
