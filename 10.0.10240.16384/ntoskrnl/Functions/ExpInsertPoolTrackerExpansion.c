// ExpInsertPoolTrackerExpansion 
 
int __fastcall ExpInsertPoolTrackerExpansion(int a1, int a2, int a3)
{
  int v3; // r7
  char v4; // r6
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r1
  int v9; // r9
  int v10; // r3
  unsigned int v11; // r2
  int *v12; // r0
  int v13; // r3
  int v14; // t1
  _DWORD *v15; // r2
  int result; // r0
  unsigned int *v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int *v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r7
  int v24; // r2
  unsigned int v25; // r3
  int v26; // r8
  int v27; // r0
  unsigned int v28; // r6
  int v29; // r3
  int v30; // r3
  int v31; // r0
  int v32; // r2
  int v33; // r5
  int v34; // r1
  _DWORD *v35; // r4
  int v36; // r3
  unsigned int *v37; // r2
  unsigned int v38; // r1
  unsigned int *v39; // r2
  unsigned int v40; // r0
  int v41; // r3
  int v42; // r6
  int v43; // r4
  int v44; // r2
  int v45; // r5
  _DWORD *v46; // r1
  int v47; // r3
  int v48; // r3
  unsigned int *v49; // r4
  unsigned int v50; // r5
  int v51; // r6
  unsigned int *v52; // r4
  unsigned int v53; // r7
  unsigned int *v54; // r4
  unsigned int *v55; // r2
  unsigned int v56; // r1
  unsigned int *v57; // r2
  unsigned int v58; // r1
  unsigned int *v59; // r2
  int v60; // [sp+8h] [bp-58h]
  int v61; // [sp+8h] [bp-58h]
  int v63; // [sp+10h] [bp-50h]
  int v64; // [sp+10h] [bp-50h]
  int v65; // [sp+14h] [bp-4Ch]
  int v66; // [sp+18h] [bp-48h]
  unsigned int v67; // [sp+1Ch] [bp-44h]
  char v69[16]; // [sp+28h] [bp-38h] BYREF
  char v70[40]; // [sp+38h] [bp-28h] BYREF

  v3 = a1;
  v4 = a3;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v69);
  v63 = v4 & 0x20;
  if ( (v4 & 0x20) != 0 )
  {
    v6 = ExpSessionPoolTrackTable;
    v7 = ExpSessionPoolTrackTableSize;
    v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v9 = *(_DWORD *)(v10 + 8372);
    v8 = *(_DWORD *)(v10 + 8376);
  }
  else
  {
    v6 = PoolTrackTable;
    v7 = PoolTrackTableSize;
    v8 = PoolTrackTableExpansionSize;
    v9 = PoolTrackTableExpansion;
  }
  v11 = 0;
  if ( v8 )
  {
    v12 = (int *)v9;
    do
    {
      v14 = *v12;
      v12 += 7;
      v13 = v14;
      if ( v14 == v3 )
        break;
      if ( !v13 )
      {
        *(_DWORD *)(v9 + 28 * v11) = v3;
        break;
      }
      ++v11;
    }
    while ( v11 < v8 );
  }
  if ( v11 != v8 )
  {
    v15 = (_DWORD *)(v9 + 28 * v11);
    if ( (v4 & 1) != 0 )
    {
      ++v15[4];
      v15[6] += a2;
    }
    else
    {
      ++v15[1];
      v15[3] += a2;
    }
    return KeReleaseInStackQueuedSpinLock((int)v69);
  }
  if ( *(_DWORD *)(v6 + 28 * v7 - 28) )
  {
    KeReleaseInStackQueuedSpinLock((int)v69);
    v17 = (unsigned int *)(v6 + 28 * (v7 - 1));
    if ( (v4 & 1) != 0 )
    {
      v21 = v17 + 4;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 + 1, v21) );
      v20 = v17 + 6;
    }
    else
    {
      v18 = v17 + 1;
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 + 1, v18) );
      v20 = v17 + 3;
    }
    goto LABEL_72;
  }
  v60 = 28 * v8;
  v23 = (28 * v8 + 4095) & 0xFFFFF000;
  v24 = (613566757 * (unsigned __int64)(v23 + 4096)) >> 32;
  v67 = v23;
  v25 = v24 + ((v23 + 4096 - v24) >> 1);
  v26 = v25 >> 4;
  v27 = MiAllocatePoolPages(512, v23 + 4096, v24, v25);
  v28 = v27;
  if ( !v27 )
  {
    v54 = (unsigned int *)(v6 + 28 * (v7 - 1));
    *v54 = 1818654287;
    KeReleaseInStackQueuedSpinLock((int)v69);
    if ( (a3 & 1) != 0 )
    {
      v57 = v54 + 4;
      do
        v58 = __ldrex(v57);
      while ( __strex(v58 + 1, v57) );
      v59 = v54 + 6;
      do
        result = __ldrex(v59);
      while ( __strex(result + a2, v59) );
      return result;
    }
    v55 = v54 + 1;
    do
      v56 = __ldrex(v55);
    while ( __strex(v56 + 1, v55) );
    v20 = v54 + 3;
    do
LABEL_72:
      result = __ldrex(v20);
    while ( __strex(result + a2, v20) );
    return result;
  }
  if ( v9 )
    memmove(v27, v9, v23);
  memset((_BYTE *)(v60 + v28), 0, 4096);
  if ( v63 )
  {
    v29 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    *(_DWORD *)(v29 + 8372) = v28;
    *(_DWORD *)(v29 + 8376) = v26;
  }
  else
  {
    PoolTrackTableExpansion = v28;
    PoolTrackTableExpansionSize = v26;
  }
  if ( PoolHitTag == 1819242320 )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, 512, 1819242320, v28, v23 + 4096);
  v30 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
  v31 = PoolTrackTableSize;
  v32 = PoolTrackTableMask;
  v61 = v30;
  v66 = PoolTrackTableSize;
  v33 = PoolTrackTableMask & 0x2F53638;
  v34 = PoolTrackTableMask & 0x2F53638;
  v64 = PoolTrackTableMask;
  v65 = PoolTrackTableMask & 0x2F53638;
  while ( 1 )
  {
    v35 = (_DWORD *)(v30 + 28 * v33);
    if ( *v35 == 1819242320 )
      break;
    if ( *v35 )
    {
LABEL_43:
      v33 = (v33 + 1) & v32;
      v30 = v61;
      if ( v33 == v34 )
      {
        ExpInsertPoolTrackerExpansion(1819242320, v23 + 4096, 512, v61);
        goto LABEL_49;
      }
    }
    else
    {
      v36 = *(_DWORD *)(PoolTrackTable + 28 * v33);
      if ( v36 )
      {
        *v35 = v36;
        v30 = v61;
      }
      else
      {
        if ( v33 == v31 - 1 )
          goto LABEL_43;
        KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v70);
        if ( !*(_DWORD *)(PoolTrackTable + 28 * v33) )
        {
          *(_DWORD *)(PoolTrackTable + 28 * v33) = 1819242320;
          *v35 = 1819242320;
        }
        KeReleaseInStackQueuedSpinLock((int)v70);
        v32 = v64;
        v34 = v65;
        v31 = v66;
        v30 = v61;
      }
    }
  }
  v37 = v35 + 1;
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 + 1, v37) );
  v39 = v35 + 3;
  do
    v40 = __ldrex(v39);
  while ( __strex(v40 + v23 + 4096, v39) );
LABEL_49:
  KeReleaseInStackQueuedSpinLock((int)v69);
  if ( v9 )
  {
    if ( PoolHitTag == 1819242320 )
      __debugbreak();
    if ( (dword_682604 & 0x41) != 0 )
      EtwTracePool(3618, 512, 1819242320, v9, v23);
    v42 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v43 = PoolTrackTableMask;
    v44 = PoolTrackTableMask & 0x2F53638;
    v45 = PoolTrackTableMask & 0x2F53638;
    while ( 1 )
    {
      v46 = (_DWORD *)(v42 + 28 * v44);
      if ( *v46 == 1819242320 )
        break;
      if ( *v46 || (v47 = *(_DWORD *)(PoolTrackTable + 28 * v44)) == 0 )
      {
        v48 = v44 + 1;
        v44 = (v44 + 1) & v43;
        if ( v44 == v45 )
        {
          ExpRemovePoolTrackerExpansion(1819242320, v23, 512, v48);
          goto LABEL_66;
        }
      }
      else
      {
        *v46 = v47;
      }
    }
    v49 = v46 + 2;
    do
      v50 = __ldrex(v49);
    while ( __strex(v50 + 1, v49) );
    v51 = -v23;
    v52 = v46 + 3;
    do
      v53 = __ldrex(v52);
    while ( __strex(v53 + v51, v52) );
    v23 = v67;
LABEL_66:
    MiFreePoolPages(v9, v23);
  }
  return ExpInsertPoolTrackerExpansion(a1, a2, a3, v41);
}
