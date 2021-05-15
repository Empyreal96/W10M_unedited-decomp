// MiScrubLargeMappedPage 
 
int __fastcall MiScrubLargeMappedPage(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r8
  unsigned int v6; // r6
  unsigned int *v7; // r4
  unsigned int v8; // r10
  int v9; // r8
  unsigned int v10; // r5
  unsigned int v11; // r9
  int v12; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // r1
  unsigned int v18; // r5
  unsigned int *v19; // r7
  unsigned int v20; // r9
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned __int8 *v24; // r1
  unsigned int v25; // r3
  unsigned int v26; // r1
  int v27; // r2
  unsigned int v28; // r3
  int v29; // r5
  int v30; // r0
  int v31; // r5
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned int v34; // r0
  unsigned int v35; // r1
  int v37; // [sp+0h] [bp-E0h]
  int v38; // [sp+4h] [bp-DCh]
  unsigned int v39; // [sp+8h] [bp-D8h]
  unsigned int *v42; // [sp+1Ch] [bp-C4h]
  unsigned int v43; // [sp+20h] [bp-C0h]
  unsigned int v44; // [sp+24h] [bp-BCh]
  int v45; // [sp+28h] [bp-B8h] BYREF
  char v46; // [sp+2Ch] [bp-B4h]
  char v47; // [sp+2Dh] [bp-B3h]
  int v48; // [sp+30h] [bp-B0h]
  int v49; // [sp+34h] [bp-ACh]
  int v50; // [sp+38h] [bp-A8h]
  int v51; // [sp+3Ch] [bp-A4h]

  v49 = 0;
  v45 = 1;
  v46 = 0;
  v47 = 0;
  v50 = 0;
  v4 = *(_DWORD *)(a1 + 12);
  v48 = 33;
  v51 = 0;
  v39 = v4 << 12;
  v5 = ((*(_DWORD *)(a1 + 16) >> 8) & 0xFFC) - 1070596096;
  v6 = (((unsigned int)(v4 << 12) >> 20) & 0xFFC) - 1070596096;
  v7 = (unsigned int *)(a3 + 492);
  v42 = (unsigned int *)(a3 + 492);
  v43 = v5;
  v37 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
  }
  else
  {
    v13 = (unsigned __int8 *)v7 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v7);
    while ( 1 )
    {
      v15 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v7);
        while ( v16 == v15 && __strex(v15 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v6 > v5 )
  {
LABEL_62:
    v9 = 1;
  }
  else
  {
    v8 = v6 + 1070596096;
    v9 = 0;
    while ( 1 )
    {
      v10 = *(_DWORD *)v6;
      v11 = v8 + 3145728;
      v44 = *(_DWORD *)v6;
      if ( v8 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v6 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v6 = 0;
        if ( v8 <= 0xFFF )
        {
          v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * (v6 & 0xFFF)), 0);
        }
      }
      MiInsertTbFlushEntry((int)&v45, v39, 1, 1);
      MiFlushTbList((unsigned int)&v45, v17);
      v39 += 0x400000;
      v18 = MmPfnDatabase + 24 * (v10 >> 12);
      if ( v18 < v18 + 24576 )
      {
        v19 = (unsigned int *)(v18 + 12);
        v20 = v18 + 24576;
        do
        {
          if ( *(_WORD *)(v18 + 16) == 2 && MiScrubPage(a2, *(_DWORD *)(a2 + 16), v18) < 0 )
          {
            v38 = KfRaiseIrql(2);
            v21 = (unsigned __int8 *)(v18 + 15);
            do
            {
              v22 = __ldrex(v21);
              v23 = __strex(v22 | 0x80, v21);
            }
            while ( v23 );
            __dmb(0xBu);
            if ( v22 >> 7 )
            {
              v24 = (unsigned __int8 *)v19 + 3;
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v25 = *v19;
                  __dmb(0xBu);
                }
                while ( (v25 & 0x80000000) != 0 );
                do
                  v23 = __ldrex(v24);
                while ( __strex(v23 | 0x80, v24) );
                __dmb(0xBu);
              }
              while ( v23 >> 7 );
            }
            MiMakePageBad(v18, 0, (unsigned int *)v23);
            __dmb(0xBu);
            do
              v26 = __ldrex(v19);
            while ( __strex(v26 & 0x7FFFFFFF, v19) );
            KfLowerIrql(v38);
          }
          v18 += 24;
          v19 += 6;
        }
        while ( v18 < v20 );
        v7 = v42;
        v11 = v8 + 3145728;
      }
      v27 = v44 | 0x10;
      if ( v11 > 0x3FFFFF )
      {
        *(_DWORD *)v6 = v27;
      }
      else
      {
        v28 = *(_DWORD *)v6;
        v29 = 0;
        __dmb(0xBu);
        *(_DWORD *)v6 = v27;
        if ( (v28 & 2) == 0 && (v27 & 2) != 0 )
          v29 = 1;
        if ( v8 <= 0xFFF )
        {
          v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v30, (_DWORD *)(v30 + 4 * (v6 & 0xFFF)), v27);
        }
        if ( v29 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v6 += 4;
      v8 += 4;
      if ( *(_DWORD *)(a4 + 4) )
        break;
      if ( ExSpinLockIsContended(v7) || KeShouldYieldProcessor() )
      {
        MiUnlockWorkingSetExclusive((int)v7, v37);
        v31 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
        }
        else
        {
          v32 = (unsigned __int8 *)v7 + 3;
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 | 0x80, v32) );
          __dmb(0xBu);
          if ( v33 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v7);
          while ( 1 )
          {
            v34 = *v7;
            if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v34 & 0x40000000) == 0 )
            {
              do
                v35 = __ldrex(v7);
              while ( v35 == v34 && __strex(v34 | 0x40000000, v7) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
          v9 = 0;
        }
        v37 = v31;
      }
      if ( v6 > v43 )
        goto LABEL_62;
    }
  }
  MiUnlockWorkingSetExclusive((int)v7, v37);
  return v9;
}
