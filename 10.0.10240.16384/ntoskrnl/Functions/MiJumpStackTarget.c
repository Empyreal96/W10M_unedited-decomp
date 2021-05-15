// MiJumpStackTarget 
 
int __fastcall MiJumpStackTarget(int **a1)
{
  int **v1; // r6
  int *v2; // r4
  unsigned int *v3; // r1
  int v4; // r8
  int v5; // r10
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int v8; // r5
  int v9; // r0
  unsigned int *v10; // r1
  int v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r3
  int result; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r6
  int v21; // r10
  unsigned int v22; // r1
  int v23; // r5
  unsigned __int8 *v24; // r0
  unsigned int v25; // r2
  int v26; // r1
  int v27; // r2
  unsigned int v28; // r3
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int v31; // r4
  unsigned int v32; // r0
  int v33; // r3
  int v34; // r0
  int *v35; // [sp+0h] [bp-38h]
  int v36; // [sp+4h] [bp-34h]
  int v37; // [sp+8h] [bp-30h]
  int v38; // [sp+Ch] [bp-2Ch]

  v1 = a1;
  v2 = *a1;
  v3 = (unsigned int *)a1[2];
  v4 = (*a1)[5];
  v5 = 0;
  v35 = *a1;
  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v3);
    v7 = v6 - 1;
  }
  while ( __strex(v7, v3) );
  __dmb(0xBu);
  v8 = ~v7 & 0x80000000;
  if ( (v7 & 0x7FFFFFFF) != 0 )
  {
    while ( (*v3 & 0x80000000) != v8 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v19 = v3[1] | v8;
    __dmb(0xBu);
    *v3 = v19;
    if ( !v2[4] )
    {
      v20 = MmPfnDatabase + 24 * *v2;
      v36 = MmPfnDatabase;
      v37 = 3 * v2[1];
      if ( v2[6] )
        v21 = 2;
      else
        v21 = 1;
      v38 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_550A40();
      do
        v22 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
      while ( __strex(v22 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
      __dmb(0xBu);
      if ( v22 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
      while ( 1 )
      {
        v23 = dword_634F00;
        if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_634F00 & 0x40000000) == 0 )
        {
          do
            v32 = __ldrex((unsigned int *)&dword_634F00);
          while ( v32 == v23 && __strex(v23 | 0x40000000, (unsigned int *)&dword_634F00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v24 = (unsigned __int8 *)(v20 + 15);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 | 0x80, v24) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v25 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v33 = *(_DWORD *)(v20 + 12);
          __dmb(0xBu);
        }
        while ( (v33 & 0x80000000) != 0 );
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 | 0x80, v24) );
      }
      if ( MiCanStealKernelStack(v20, v21)
        && *(_DWORD *)v20 != -5
        && (*(_DWORD *)v20 & 1) != 0
        && v35[5] == *(_DWORD *)(v20 + 4) << 10 )
      {
        if ( v35[6] )
          MiRemoveLockedPageChargeAndDecRef(v20);
        MiCopyKstack(v36 + 8 * v37, v20, v35[2]);
        KeFlushSingleCurrentTb(v35[5], v26, v27, v28);
        MiSwitchKstackPages(v36 + 8 * v37, (int *)v20);
        *(_DWORD *)(v20 + 20) &= 0xF7FFFFFF;
        *(_BYTE *)(v20 + 18) &= 0xC7u;
        *(_BYTE *)(v20 + 19) &= 0xDFu;
        v5 = v35[5];
        v35[4] = 0;
      }
      else
      {
        v5 = 0;
        v35[4] = -1073740748;
      }
      __dmb(0xBu);
      v29 = (unsigned int *)(v20 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      v31 = v35[2];
      if ( v31 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v31 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v31 = 0;
        if ( v31 >= 0xC0300000 && v31 <= 0xC0300FFF )
        {
          v34 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v34, (_DWORD *)(v34 + 4 * (v31 & 0xFFF)), 0);
        }
      }
      MiUnlockWorkingSetExclusive((int)&dword_634F00, v38);
      v1 = a1;
    }
  }
  v9 = KfRaiseIrql(13);
  v10 = (unsigned int *)v1[2];
  v11 = v9;
  __dmb(0xBu);
  do
  {
    v12 = __ldrex(v10);
    v13 = v12 - 1;
  }
  while ( __strex(v13, v10) );
  __dmb(0xBu);
  v14 = ~v13 & 0x80000000;
  if ( (v13 & 0x7FFFFFFF) != 0 )
  {
    while ( 1 )
    {
      v15 = *v10 & 0x80000000;
      if ( v15 == v14 )
        break;
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v15 = v10[1] | v14;
    __dmb(0xBu);
    *v10 = v15;
  }
  if ( !v5 )
    KeFlushSingleCurrentTb(v4, (int)v10, v13, v15);
  result = KfLowerIrql(v11);
  v17 = (unsigned int *)v1[1];
  __dmb(0xBu);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  __dmb(0xBu);
  return result;
}
