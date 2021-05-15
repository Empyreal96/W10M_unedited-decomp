// MiPopulateWorkingSetFreeList 
 
int __fastcall MiPopulateWorkingSetFreeList(int a1, unsigned int a2, unsigned int a3)
{
  int v6; // r10
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r4
  unsigned int *v11; // r4
  unsigned int v12; // r5
  unsigned int v13; // r1

  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50BBE8();
  v8 = (unsigned __int8 *)(a1 + 3);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
  while ( 1 )
  {
    v10 = *(_DWORD *)a1;
    if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex((unsigned int *)a1);
      while ( v13 == v10 && __strex(v10 | 0x40000000, (unsigned int *)a1) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  for ( **(_DWORD **)(a1 + 92) = 0xFFFFF; a3 >= a2; --a3 )
  {
    v11 = *(unsigned int **)(a1 + 92);
    v12 = *v11;
    if ( *v11 != 0xFFFFF )
    {
      if ( v12 < v11[1] || v12 > v11[4] )
        KeBugCheckEx(26, 20484, *(_DWORD *)(a1 + 92));
      *(_DWORD *)(v11[9] * v12 + v11[63]) ^= (*(_DWORD *)(v11[9] * v12 + v11[63]) ^ (2 * a3)) & 0xFFE;
    }
    *(_DWORD *)(v11[9] * a3 + v11[63]) = (v12 << 12) | 0xFFE;
    *v11 = a3;
  }
  return MiUnlockWorkingSetExclusive(a1, v6);
}
