// MiDeleteSessionPoolRange 
 
int __fastcall MiDeleteSessionPoolRange(int a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  unsigned int *v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r6
  int v7; // r9
  unsigned int i; // r6
  int v9; // r2
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r0
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  unsigned int v21; // [sp+Ch] [bp-24h]

  v4 = (unsigned int *)(a1 + 3248);
  v5 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v6 = v5 + 4 * (a3 >> 12);
  v21 = v6;
  v7 = KfRaiseIrql(2);
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
  if ( v5 < v6 )
  {
    for ( i = v5 + 1070596096; ; i += 4 )
    {
      v9 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 0xC02) != 0 || (v9 & 0x3E0) != 0 )
        break;
      if ( v9 )
      {
        if ( i + 3145728 <= 0x3FFFFF )
          goto LABEL_23;
LABEL_35:
        *(_DWORD *)v5 = 0;
      }
LABEL_36:
      v5 += 4;
      if ( v5 >= v21 )
        return MiUnlockWorkingSetExclusive((int)v4, v7);
    }
    MiUnlockWorkingSetExclusive((int)v4, v7);
    MiDeleteSystemPagableVm((int *)v4, 0, v5, 1, 0, a4);
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
    }
    else
    {
      v15 = (unsigned __int8 *)v4 + 3;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v4);
      while ( 1 )
      {
        v17 = *v4;
        if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v4);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v4) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( i + 3145728 <= 0x3FFFFF )
    {
LABEL_23:
      __dmb(0xBu);
      *(_DWORD *)v5 = 0;
      if ( i <= 0xFFF )
      {
        v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v14, (_DWORD *)(v14 + 4 * (v5 & 0xFFF)), 0);
      }
      goto LABEL_36;
    }
    goto LABEL_35;
  }
  return MiUnlockWorkingSetExclusive((int)v4, v7);
}
