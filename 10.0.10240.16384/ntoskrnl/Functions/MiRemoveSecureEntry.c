// MiRemoveSecureEntry 
 
int __fastcall MiRemoveSecureEntry(int a1, _DWORD *a2)
{
  unsigned int v2; // r5
  int v3; // r10
  _DWORD *v6; // r9
  unsigned int *v7; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  _DWORD *i; // r2
  unsigned int v13; // r1
  int v14; // [sp+0h] [bp-20h]

  v2 = 0;
  v3 = 0;
  v6 = (_DWORD *)(a1 + 36);
  v7 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_546D1C();
  v9 = (unsigned __int8 *)v7 + 3;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v7);
  while ( 1 )
  {
    v11 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v11 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v7);
      while ( v13 == v11 && __strex(v11 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  for ( i = *(_DWORD **)(a1 + 36); i; i = (_DWORD *)*i )
  {
    if ( i[1] == 2 && v2 <= 1 )
      ++v2;
    if ( i == a2 )
    {
      v3 = 1;
      *v6 = *i;
    }
    if ( v2 > 1 && v3 == 1 )
      break;
    v6 = i;
  }
  MiUnlockWorkingSetExclusive((int)v7, v14);
  if ( (a2[2] & 0x10) != 0 )
    MiUnsecureVirtualMemoryAgainstWrites(a1);
  if ( v2 == 1 )
    *(_DWORD *)(a1 + 28) &= 0xFFFFBFFF;
  return ExFreePoolWithTag(a2, 0);
}
