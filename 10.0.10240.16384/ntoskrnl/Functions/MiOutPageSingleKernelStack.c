// MiOutPageSingleKernelStack 
 
int __fastcall MiOutPageSingleKernelStack(int a1, _DWORD *a2, int a3)
{
  unsigned int v5; // r1
  unsigned int v7; // r1
  int v8; // r4
  unsigned int v9; // r7
  int v10; // r8
  int v11; // r9
  int v12; // r6
  int v13; // r10
  int v14; // r8
  unsigned int v15; // r2
  unsigned int v16; // r5
  unsigned int v17; // r8
  unsigned int v18; // r0
  int v19; // r4
  int v20; // r7
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r6
  unsigned int *v25; // r2
  unsigned int v26; // r0
  unsigned __int8 *v27; // r3
  unsigned int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r6
  unsigned int v35; // r0
  int v36; // r0
  unsigned __int8 *v37; // r1
  int v38; // r3
  unsigned int v39; // r2
  unsigned int v40; // r2
  int v41; // r0
  int v42; // r0
  unsigned __int8 *v43; // r1
  int v44; // r3
  unsigned int v45; // r2
  unsigned int v46; // [sp+8h] [bp-40h]
  int v47; // [sp+Ch] [bp-3Ch]
  unsigned int v48; // [sp+10h] [bp-38h]
  int v49; // [sp+14h] [bp-34h]
  unsigned int v50; // [sp+1Ch] [bp-2Ch]
  unsigned int v51; // [sp+20h] [bp-28h]
  int v53; // [sp+28h] [bp-20h]

  v50 = (((unsigned int)(*a2 - 4096) >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = (((unsigned int)(a2[2] - 4) >> 10) & 0x3FFFFC) - 0x40000000;
  v48 = v5 << 10;
  v51 = v5;
  v49 = ((a2[1] >> 10) & 0x3FFFFC) - 1073741828;
  v46 = v5;
  v47 = ((int)(v50 - v5) >> 2) + 1;
  __mrc(15, 0, 13, 0, 3);
  v53 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53E270();
  do
    v7 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
  while ( 1 )
  {
    v8 = dword_634F00;
    if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634F00 & 0x40000000) == 0 )
    {
      v31 = dword_634F00 | 0x40000000;
      do
        v32 = __ldrex((unsigned int *)&dword_634F00);
      while ( v32 == v8 && __strex(v31, (unsigned int *)&dword_634F00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v9 = v46;
  *(_DWORD *)(a2[2] - 4) = a1;
  v10 = *(_DWORD *)(a1 + 336);
  v11 = 0;
  if ( *(_DWORD *)(v10 + 612) > 2u )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_63F990);
    }
    else
    {
      do
        v33 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
      while ( __strex(v33 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
      __dmb(0xBu);
      if ( v33 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
      while ( 1 )
      {
        v34 = dword_63F990;
        if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_63F990 & 0x40000000) == 0 )
        {
          do
            v35 = __ldrex((unsigned int *)&dword_63F990);
          while ( v35 == v34 && __strex(v34 | 0x40000000, (unsigned int *)&dword_63F990) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v9 = v46;
    }
    if ( *(_DWORD *)(v10 + 612) <= 2u )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F990);
      }
      else
      {
        __dmb(0xBu);
        dword_63F990 = 0;
      }
    }
    else
    {
      v11 = *(_DWORD *)(v10 + 612);
    }
  }
  do
  {
    v12 = *(_DWORD *)v9;
    v13 = MmPfnDatabase;
    v14 = 3 * (*(_DWORD *)v9 >> 12);
    if ( v11 )
      MiOutSwapKernelStackPage(v11, v9);
    v15 = v12 & 0xFFFFFBFC | 0xBE0;
    if ( v9 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v9 = v15;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v9 = v15;
      if ( v9 >= 0xC0300000 && v9 <= 0xC0300FFF )
      {
        v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * (v9 & 0xFFF)), v15);
      }
    }
    MiLockAndDecrementShareCount(v13 + 8 * v14, 0);
    v9 += 4;
  }
  while ( v9 <= v50 );
  if ( v11 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F990);
    }
    else
    {
      __dmb(0xBu);
      dword_63F990 = 0;
    }
  }
  v16 = v51 - 4;
  if ( v51 - 4 != v49 )
  {
    v17 = v51 + 1070596092;
    do
    {
      v18 = *(_DWORD *)v16;
      if ( (*(_DWORD *)v16 & 2) == 0 )
        break;
      v19 = MmPfnDatabase + 24 * (v18 >> 12);
      v20 = MmPfnDatabase + 24 * (*(_DWORD *)(v19 + 20) & 0xFFFFF);
      v21 = (unsigned __int8 *)(v19 + 15);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      __dmb(0xBu);
      if ( v22 >> 7 )
      {
        v37 = (unsigned __int8 *)(v19 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v38 = *(_DWORD *)(v19 + 12);
            __dmb(0xBu);
          }
          while ( (v38 & 0x80000000) != 0 );
          do
            v39 = __ldrex(v37);
          while ( __strex(v39 | 0x80, v37) );
          __dmb(0xBu);
        }
        while ( v39 >> 7 );
      }
      if ( *(_WORD *)(v19 + 16) == 1 )
      {
        if ( v17 + 3145728 > 0x3FFFFF )
        {
          *(_DWORD *)v16 = 992;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v16 = 992;
          if ( v16 >= 0xC0300000 && v16 <= 0xC0300FFF )
          {
            v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v42, (_DWORD *)(v42 + 4 * (v16 & 0xFFF)), 992);
          }
        }
        v23 = *(_DWORD *)(v19 + 20);
        *(_DWORD *)(v19 + 12) |= 0x40000000u;
        *(_DWORD *)(v19 + 20) = v23 & 0xF8FFFFFF;
        if ( (*(_BYTE *)(v19 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v19 - MmPfnDatabase) / 24);
      }
      else
      {
        v40 = v18 & 0xFFFFFBFC | 0xBE0;
        if ( v17 + 3145728 > 0x3FFFFF )
        {
          *(_DWORD *)v16 = v40;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v16 = v40;
          if ( v17 <= 0xFFF )
          {
            v41 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v41, (_DWORD *)(v41 + 4 * (v16 & 0xFFF)), v40);
          }
        }
        if ( (*(_BYTE *)(v19 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v19 - MmPfnDatabase) / 24);
      }
      if ( MiUpdateShareCount(v19, -1) )
        v24 = 2;
      else
        v24 = MiPfnShareCountIsZero(v19, 0);
      __dmb(0xBu);
      v25 = (unsigned int *)(v19 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
      if ( v24 != 3 )
      {
        v27 = (unsigned __int8 *)(v20 + 15);
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 | 0x80, v27) );
        __dmb(0xBu);
        if ( v28 >> 7 )
        {
          v43 = (unsigned __int8 *)(v20 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v44 = *(_DWORD *)(v20 + 12);
              __dmb(0xBu);
            }
            while ( (v44 & 0x80000000) != 0 );
            do
              v45 = __ldrex(v43);
            while ( __strex(v45 | 0x80, v43) );
            __dmb(0xBu);
          }
          while ( v45 >> 7 );
        }
        if ( (*(_BYTE *)(v20 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v20 - MmPfnDatabase) / 24);
        if ( !MiUpdateShareCount(v20, -1) )
          MiPfnShareCountIsZero(v20, 0);
        __dmb(0xBu);
        v29 = (unsigned int *)(v20 + 12);
        do
          v30 = __ldrex(v29);
        while ( __strex(v30 & 0x7FFFFFFF, v29) );
      }
      v16 -= 4;
      v17 -= 4;
      ++v47;
      v48 -= 4096;
    }
    while ( v16 != v49 );
  }
  MiInsertTbFlushEntry(a3, v48, v47);
  return MiUnlockWorkingSetExclusive(&dword_634F00, v53);
}
