// MiMakeProtoLeafValid 
 
_DWORD *__fastcall MiMakeProtoLeafValid(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r10
  _DWORD *v5; // r4
  int v6; // r5
  unsigned int *v7; // r5
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v13; // [sp+10h] [bp-28h]
  int varg_r2; // [sp+48h] [bp+10h]

  varg_r2 = a3;
  v4 = a3;
  v5 = a1;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v13 = v6;
  while ( (*v5 & 2) == 0 )
  {
    MiUnlockWorkingSetExclusive(v6 + 492, v4);
    v7 = (unsigned int *)(v6 + 492);
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
    }
    else
    {
      v8 = (unsigned __int8 *)v7 + 3;
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 | 0x80, v8) );
      __dmb(0xBu);
      if ( v9 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v7);
      while ( 1 )
      {
        v10 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v10 & 0x40000000) == 0 )
        {
          do
            v11 = __ldrex(v7);
          while ( v11 == v10 && __strex(v10 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    MiMakeSystemAddressValid(v5, 0);
    v6 = v13;
  }
  return v5;
}
