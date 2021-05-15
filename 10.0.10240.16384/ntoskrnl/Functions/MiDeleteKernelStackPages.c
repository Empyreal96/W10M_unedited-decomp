// MiDeleteKernelStackPages 
 
int __fastcall MiDeleteKernelStackPages(unsigned int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r7
  int *v6; // lr
  unsigned int v7; // r0
  int v8; // r5
  unsigned int v9; // r5
  int v10; // r6
  unsigned __int8 *v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r5
  int v14; // r3
  int v15; // r1
  int v16; // r5
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r2
  int v20; // r5
  unsigned __int8 *v21; // r1
  unsigned int v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r0
  unsigned __int8 *v27; // r1
  int v28; // r3
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // r0
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  int v37; // [sp+Ch] [bp-24h]

  v3 = a1;
  v4 = a1 + 4 * a2;
  __mrc(15, 0, 13, 0, 3);
  v37 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53D864();
  v6 = MiState;
  do
    v7 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
  __dmb(0xBu);
  if ( v7 >> 7 )
  {
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
    v6 = MiState;
  }
  while ( 1 )
  {
    v8 = v6[2336];
    if ( (v8 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v8 & 0x40000000) == 0 )
    {
      v25 = (unsigned int *)(v6 + 2336);
      do
        v26 = __ldrex(v25);
      while ( v26 == v8 && __strex(v8 | 0x40000000, v25) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( v3 < v4 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)v3;
      if ( (*(_DWORD *)v3 & 2) != 0 )
      {
        v10 = MmPfnDatabase + 24 * (v9 >> 12);
        v11 = (unsigned __int8 *)(v10 + 15);
        do
          v12 = __ldrex(v11);
        while ( __strex(v12 | 0x80, v11) );
        __dmb(0xBu);
        if ( v12 >> 7 )
        {
          v27 = (unsigned __int8 *)(v10 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v28 = *(_DWORD *)(v10 + 12);
              __dmb(0xBu);
            }
            while ( (v28 & 0x80000000) != 0 );
            do
              v29 = __ldrex(v27);
            while ( __strex(v29 | 0x80, v27) );
            __dmb(0xBu);
          }
          while ( v29 >> 7 );
        }
        if ( v9 != *(_DWORD *)v3 )
        {
          __dmb(0xBu);
          v30 = (unsigned int *)(v10 + 12);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 & 0x7FFFFFFF, v30) );
          goto LABEL_11;
        }
        if ( v3 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v3 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v3 = 0;
          if ( v3 >= 0xC0300000 && v3 <= 0xC0300FFF )
          {
            v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v32, (_DWORD *)(v32 + 4 * (v3 & 0xFFF)), 0);
          }
        }
        v13 = *(_DWORD *)(v10 + 20) & 0xF8FFFFFF;
        v14 = *(_DWORD *)(v10 + 12);
        v15 = *(_BYTE *)(v10 + 18) & 7;
        *(_DWORD *)(v10 + 20) = v13;
        *(_DWORD *)(v10 + 12) = v14 | 0x40000000;
        v16 = v13 & 0xFFFFF;
        if ( v15 != 6 )
          KeBugCheckEx(78, 153, (v10 - MmPfnDatabase) / 24);
        if ( !MiUpdateShareCount(v10, -1) && MiPfnShareCountIsZero(v10, 0) == 3 )
          ++a3[1];
        __dmb(0xBu);
        v17 = (unsigned int *)(v10 + 12);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & 0x7FFFFFFF, v17) );
        v19 = a3[3] + 1;
        ++*a3;
        a3[3] = v19;
        v20 = MmPfnDatabase + 24 * v16;
        v21 = (unsigned __int8 *)(v20 + 15);
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 | 0x80, v21) );
        __dmb(0xBu);
        if ( v22 >> 7 )
        {
          v33 = (unsigned __int8 *)(v20 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v34 = *(_DWORD *)(v20 + 12);
              __dmb(0xBu);
            }
            while ( (v34 & 0x80000000) != 0 );
            do
              v35 = __ldrex(v33);
            while ( __strex(v35 | 0x80, v33) );
            __dmb(0xBu);
          }
          while ( v35 >> 7 );
        }
        if ( (*(_BYTE *)(v20 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v20 - MmPfnDatabase) / 24);
        if ( !MiUpdateShareCount(v20, -1) )
          MiPfnShareCountIsZero(v20, 0);
        __dmb(0xBu);
        v23 = (unsigned int *)(v20 + 12);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 & 0x7FFFFFFF, v23) );
      }
      v3 += 4;
LABEL_11:
      if ( v3 >= v4 )
      {
        v6 = MiState;
        return MiUnlockWorkingSetExclusive(v6 + 2336, v37);
      }
    }
  }
  return MiUnlockWorkingSetExclusive(v6 + 2336, v37);
}
