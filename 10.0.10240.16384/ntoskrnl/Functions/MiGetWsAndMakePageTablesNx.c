// MiGetWsAndMakePageTablesNx 
 
int MiGetWsAndMakePageTablesNx()
{
  unsigned int *v0; // r4
  int v1; // r7
  unsigned __int8 *v3; // r3
  unsigned int v4; // r1
  unsigned int v5; // r0
  char v6; // r3
  int v7; // r5
  int v8; // r2
  int v9; // r0
  unsigned int v10; // r1

  v0 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_555034();
  v3 = (unsigned __int8 *)v0 + 3;
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v0);
  while ( 1 )
  {
    v5 = *v0;
    if ( (*v0 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v5 & 0x40000000) == 0 )
    {
      do
        v10 = __ldrex(v0);
      while ( v10 == v5 && __strex(v5 | 0x40000000, v0) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v6 = MEMORY[0xC0300C00];
  v7 = 0;
  v8 = MEMORY[0xC0300C00] | 1;
  __dmb(0xBu);
  MEMORY[0xC0300C00] = v8;
  if ( (v6 & 2) == 0 && (v8 & 2) != 0 )
    v7 = 1;
  v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
  MiArmWriteConvertedHardwarePde(v9, (_DWORD *)(v9 + 12288), v8);
  if ( v7 == 1 )
  {
    __dsb(0xFu);
    __isb(0xFu);
  }
  MiUnlockWorkingSetExclusive((int)v0, v1);
  return KeFlushTb(1, 0);
}
