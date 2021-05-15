// MiWriteLargePde 
 
int __fastcall MiWriteLargePde(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int *v4; // r5
  int v6; // r7
  int v7; // r2
  int v8; // r6
  int v9; // r3
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  _DWORD *varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r1 = a2;
  v4 = (unsigned int *)(a1 + 492);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v10 = (unsigned __int8 *)v4 + 3;
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v12 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(v4);
        while ( v13 == v12 && __strex(v12 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
  {
    *a2 = a3;
  }
  else
  {
    v7 = *a2;
    v8 = 0;
    __dmb(0xBu);
    *a2 = a3;
    if ( (v7 & 2) == 0 && (a3 & 2) != 0 )
      v8 = 1;
    if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
    {
      v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      MiArmWriteConvertedHardwarePde(
        *(_DWORD *)(v9 + 32),
        (_DWORD *)(*(_DWORD *)(v9 + 32) + 4 * ((unsigned __int16)a2 & 0xFFF)),
        a3);
    }
    if ( v8 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return MiUnlockWorkingSetExclusive((int)v4, v6);
}
