// MiDeleteBootRange 
 
unsigned int __fastcall MiDeleteBootRange(unsigned int a1, int a2)
{
  unsigned int v2; // r6
  unsigned int v3; // r9
  unsigned int v4; // r10
  unsigned int result; // r0
  unsigned int v6; // r1
  int v7; // r7
  unsigned int v8; // lr
  unsigned int v9; // r7
  unsigned int *v10; // r9
  unsigned int v11; // t1
  int v12; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r9
  int v18; // r10
  unsigned int v19; // r1
  int v20; // r7
  int v21; // r9
  int v22; // r7
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r0
  __int16 v28; // r3
  unsigned int v29; // r0
  int v30; // r4
  int v31; // r3
  _DWORD *v32; // r3
  unsigned int v33; // r2
  bool v34; // zf
  int v35; // r1
  int *v36; // r2
  unsigned int v37; // r1
  int v38; // r10
  unsigned int v39; // r1
  int v40; // r7
  unsigned int v41; // r0
  unsigned __int8 *v42; // r1
  int v43; // r3
  unsigned int v44; // r2
  unsigned int v45; // r0
  unsigned __int8 *v46; // r1
  int v47; // r3
  unsigned int v48; // r2
  unsigned int v49; // r0
  int v51; // [sp+Ch] [bp-D4h]
  unsigned int v52; // [sp+Ch] [bp-D4h]
  unsigned int v54; // [sp+14h] [bp-CCh]
  int v55; // [sp+18h] [bp-C8h] BYREF
  int v56; // [sp+1Ch] [bp-C4h]
  int v57; // [sp+20h] [bp-C0h]
  int v58; // [sp+24h] [bp-BCh]
  int v59; // [sp+28h] [bp-B8h] BYREF
  char v60; // [sp+2Ch] [bp-B4h]
  char v61; // [sp+2Dh] [bp-B3h]
  int v62; // [sp+30h] [bp-B0h]
  int v63; // [sp+34h] [bp-ACh]
  int v64; // [sp+38h] [bp-A8h]
  int v65; // [sp+3Ch] [bp-A4h]

  v55 = 0;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v2 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = (((a1 + 4 * a2 - 4) >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = a1;
  v54 = v3;
  v51 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54D3A0(0x80000000);
  do
    v6 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
  while ( __strex(v6 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
  while ( 1 )
  {
    v7 = dword_634F00;
    if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634F00 & 0x40000000) == 0 )
    {
      do
        v41 = __ldrex((unsigned int *)&dword_634F00);
      while ( v41 == v7 && __strex(v7 | 0x40000000, (unsigned int *)&dword_634F00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v8 = 1;
  if ( v2 > v3 )
    v9 = 0;
  else
    v9 = (v3 - v2 + 4) >> 2;
  v10 = (unsigned int *)v2;
  if ( v9 )
  {
    do
    {
      v11 = *v10++;
      v12 = MmPfnDatabase + 24 * (v11 >> 12);
      v13 = (unsigned __int8 *)(v12 + 15);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 | 0x80, v13) );
      __dmb(0xBu);
      if ( v14 >> 7 )
      {
        v42 = (unsigned __int8 *)(v12 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v43 = *(_DWORD *)(v12 + 12);
            __dmb(0xBu);
          }
          while ( (v43 & 0x80000000) != 0 );
          do
            v44 = __ldrex(v42);
          while ( __strex(v44 | 0x80, v42) );
          __dmb(0xBu);
        }
        while ( v44 >> 7 );
      }
      *(_DWORD *)(v12 + 12) = *(_DWORD *)(v12 + 12) & 0xC0000000 | (*(_DWORD *)(v12 + 12) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v15 = (unsigned int *)(v12 + 12);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 & 0x7FFFFFFF, v15) );
      ++v8;
    }
    while ( v8 <= v9 );
    v4 = a1;
  }
  MiUnlockWorkingSetExclusive((int)&dword_634F00, v51);
  MiDeleteSystemPagableVm(&dword_634F00, 0, v4, a2, 1, &v55);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v52 = v17;
  --*(_WORD *)(v17 + 308);
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  v18 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634F00);
  }
  else
  {
    do
      v19 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
    while ( __strex(v19 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
    __dmb(0xBu);
    if ( v19 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
    while ( 1 )
    {
      v20 = dword_634F00;
      if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_634F00 & 0x40000000) == 0 )
      {
        do
          v45 = __ldrex((unsigned int *)&dword_634F00);
        while ( v45 == v20 && __strex(v20 | 0x40000000, (unsigned int *)&dword_634F00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v2 <= v54 )
  {
    v21 = v18;
    do
    {
      v22 = MmPfnDatabase + 24 * (*(_DWORD *)v2 >> 12);
      v23 = (unsigned __int8 *)(v22 + 15);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 | 0x80, v23) );
      __dmb(0xBu);
      if ( v24 >> 7 )
      {
        v46 = (unsigned __int8 *)(v22 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v47 = *(_DWORD *)(v22 + 12);
            __dmb(0xBu);
          }
          while ( (v47 & 0x80000000) != 0 );
          do
            v48 = __ldrex(v46);
          while ( __strex(v48 | 0x80, v46) );
          __dmb(0xBu);
        }
        while ( v48 >> 7 );
      }
      *(_DWORD *)(v22 + 12) = *(_DWORD *)(v22 + 12) & 0xC0000000 | (*(_DWORD *)(v22 + 12) - 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v25 = (unsigned int *)(v22 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
      if ( (*(_DWORD *)(v22 + 12) & 0x3FFFFFFF) == 1 )
      {
        v32 = (_DWORD *)(v2 << 10);
        v33 = (v2 << 10) + 4096;
        v34 = v2 << 10 == v33;
        if ( v2 << 10 < v33 )
        {
          do
          {
            if ( (*v32 & 0xC02) != 0 )
              break;
            v35 = (*v32 >> 5) & 0x1F;
            if ( v35 )
            {
              if ( v35 != 24 )
                break;
            }
            ++v32;
          }
          while ( (unsigned int)v32 < v33 );
          v34 = v32 == (_DWORD *)v33;
        }
        if ( v34 )
        {
          v36 = (int *)PsLoadedModuleList;
          while ( 1 )
          {
            v37 = v36[6];
            if ( v2 >= ((v37 >> 20) & 0xFFC) - 1070596096 && v2 <= (((v36[8] + v37 - 1) >> 20) & 0xFFC) - 1070596096 )
              break;
            v36 = (int *)*v36;
            if ( v36 == &PsLoadedModuleList )
              goto LABEL_47;
          }
          v36 = 0;
LABEL_47:
          if ( v36 )
          {
            MiUnlockWorkingSetExclusive((int)&dword_634F00, v21);
            v63 = 0;
            v64 = 0;
            v59 = 0;
            v60 = 0;
            v61 = 0;
            v62 = 33;
            v65 = 0;
            MiInsertTbFlushEntry((int)&v59, v2 << 20, 1024, 0);
            MiReturnSystemVa(v2 << 20, (v2 << 20) + 0x400000, 3, (unsigned int)&v59);
            v38 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634F00);
            }
            else
            {
              do
                v39 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
              while ( __strex(v39 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
              __dmb(0xBu);
              if ( v39 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
              while ( 1 )
              {
                v40 = dword_634F00;
                if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (dword_634F00 & 0x40000000) == 0 )
                {
                  do
                    v49 = __ldrex((unsigned int *)&dword_634F00);
                  while ( v49 == v40 && __strex(v40 | 0x40000000, (unsigned int *)&dword_634F00) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
            }
            v21 = v38;
          }
        }
      }
      v2 += 4;
    }
    while ( v2 <= v54 );
    v18 = v21;
    v17 = v52;
  }
  MiUnlockWorkingSetExclusive((int)&dword_634F00, v18);
  v27 = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v28 = *(_WORD *)(v17 + 308) + 1;
  *(_WORD *)(v17 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v27);
  MiReturnResidentAvailable(a2);
  do
    v29 = __ldrex(&dword_634A2C[63]);
  while ( __strex(v29 + a2, &dword_634A2C[63]) );
  v30 = a2 - v56;
  result = MiReturnCommit((int)MiSystemPartition, a2 - v56);
  v31 = dword_634D90 - v30;
  __dmb(0xBu);
  dword_634D90 = v31;
  return result;
}
