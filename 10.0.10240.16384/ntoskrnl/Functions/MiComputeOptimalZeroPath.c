// MiComputeOptimalZeroPath 
 
int MiComputeOptimalZeroPath()
{
  unsigned int v0; // r4
  int result; // r0
  int v2; // r1
  int v3; // r0
  unsigned int v4; // r3
  unsigned int v5; // r6
  unsigned __int64 v6; // r8
  int v7; // r10
  __int64 v8; // r0
  __int64 v9; // r4
  int v10; // r3
  __int64 v11; // r0
  int v12; // r0
  int v13; // r1
  int v14; // r9
  int v15; // r10
  __int64 v16; // r0
  __int64 v17; // r4
  int v18; // r3
  __int64 v19; // r0
  unsigned __int64 v20; // r2
  unsigned __int64 v21; // r0
  unsigned __int64 v22; // r4
  unsigned int v23; // r1
  int v24; // kr00_4
  int *v25; // r3
  unsigned int i; // r4
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // r5
  int v30; // r9
  unsigned __int8 *v31; // r3
  unsigned int v32; // r1
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  int v36; // r5
  int v37; // r7
  unsigned __int8 *v38; // r3
  unsigned int v39; // r1
  unsigned __int8 *v40; // r1
  int v41; // r3
  unsigned int v42; // r2
  unsigned int *v43; // r2
  unsigned int v44; // r0
  unsigned int v45; // [sp+0h] [bp-58h]
  int v46; // [sp+4h] [bp-54h]
  int v47; // [sp+8h] [bp-50h]
  unsigned __int64 v48; // [sp+Ch] [bp-4Ch]
  int v49; // [sp+18h] [bp-40h]
  int v50; // [sp+1Ch] [bp-3Ch]
  int v51[14]; // [sp+20h] [bp-38h] BYREF

  v51[0] = 0;
  v0 = 0;
  v51[1] = 2;
  do
  {
    result = MiGetPage((int)MiSystemPartition, v0, 0);
    v51[v0 + 2] = result;
    if ( result == -1 )
    {
      for ( ; v0; result = KfLowerIrql(v37) )
      {
        v36 = v51[--v0 + 4];
        v37 = KfRaiseIrql(2);
        v38 = (unsigned __int8 *)(v36 + 15);
        do
          v39 = __ldrex(v38);
        while ( __strex(v39 | 0x80, v38) );
        __dmb(0xBu);
        if ( v39 >> 7 )
        {
          v40 = (unsigned __int8 *)(v36 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v41 = *(_DWORD *)(v36 + 12);
              __dmb(0xBu);
            }
            while ( (v41 & 0x80000000) != 0 );
            do
              v42 = __ldrex(v40);
            while ( __strex(v42 | 0x80, v40) );
            __dmb(0xBu);
          }
          while ( v42 >> 7 );
        }
        MiInsertPageInFreeOrZeroedList(v51[v0 + 2], 2);
        __dmb(0xBu);
        v43 = (unsigned int *)(v36 + 12);
        do
          v44 = __ldrex(v43);
        while ( __strex(v44 & 0x7FFFFFFF, v43) );
      }
      return result;
    }
    v2 = v51[v0];
    v3 = MmPfnDatabase + 24 * result;
    v4 = *(unsigned __int8 *)(v3 + 18);
    v51[v0 + 4] = v3;
    if ( v4 >> 6 != v2 )
      MiChangePageAttribute(v3, v2, 0);
    ++v0;
  }
  while ( v0 < 2 );
  v5 = 0;
  v45 = 0;
  do
  {
    v6 = 0i64;
    v46 = v51[v5];
    v7 = 3;
    v47 = v51[v5 + 2];
    do
    {
      LODWORD(v8) = ReadTimeStampCounter();
      v9 = v8;
      __dmb(0xFu);
      MiZeroPhysicalPage(v47, 3, v46, v10);
      __dmb(0xFu);
      LODWORD(v11) = ReadTimeStampCounter();
      v6 += v11 - v9;
      --v7;
    }
    while ( v7 );
    v12 = _rt_udiv64(3i64, v6);
    v49 = v13;
    v50 = v12;
    v48 = 0i64;
    v14 = v51[v45 + 4];
    v15 = 3;
    do
    {
      LODWORD(v16) = ReadTimeStampCounter();
      v17 = v16;
      __dmb(0xFu);
      MiChangePageAttribute(v14, 1, 0);
      MiZeroPhysicalPage(v47, 3, v46, v18);
      MiChangePageAttribute(v14, v46, 0);
      __dmb(0xFu);
      LODWORD(v19) = ReadTimeStampCounter();
      v20 = v48 + v19 - v17;
      v48 = v20;
      --v15;
    }
    while ( v15 );
    LODWORD(v21) = _rt_udiv64(3i64, v20);
    v22 = v21;
    v24 = _rt_udiv64(10i64, __PAIR64__(v49, v50));
    if ( v22 < 9 * __PAIR64__(v23, v24) )
      return sub_969F34(9 * v24);
    v25 = &MiState[4 * v45];
    v5 = v45 + 1;
    v25[876] = v50;
    v25[877] = v49;
    *((_QWORD *)v25 + 439) = v22;
    v45 = v5;
  }
  while ( v5 < 2 );
  for ( i = 0; i < 2; ++i )
  {
    v29 = v51[i + 4];
    v30 = KfRaiseIrql(2);
    v31 = (unsigned __int8 *)(v29 + 15);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 | 0x80, v31) );
    __dmb(0xBu);
    if ( v32 >> 7 )
    {
      v33 = (unsigned __int8 *)(v29 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v34 = *(_DWORD *)(v29 + 12);
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
    MiInsertPageInFreeOrZeroedList(v51[i + 2], 2);
    __dmb(0xBu);
    v27 = (unsigned int *)(v29 + 12);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    result = KfLowerIrql(v30);
  }
  return result;
}
