// MiWriteDemandZeroPte 
 
int __fastcall MiWriteDemandZeroPte(_DWORD *a1)
{
  unsigned int *v2; // r4
  int v3; // r7
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r1
  int v9; // r0

  v2 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52A7E0();
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
        v8 = __ldrex(v2);
      while ( v8 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  MiMakeSystemAddressValid(a1, 0);
  if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
  {
    *a1 = 128;
  }
  else
  {
    __dmb(0xBu);
    *a1 = 128;
    if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
    {
      v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v9, v9 + 4 * ((unsigned __int16)a1 & 0xFFF), 128);
    }
  }
  return MiUnlockWorkingSetExclusive(v2, v3);
}
