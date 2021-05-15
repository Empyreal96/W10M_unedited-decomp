// ExpResizeBigPageTable 
 
int __fastcall ExpResizeBigPageTable(char a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r9
  unsigned int v4; // r4
  unsigned int v5; // r10
  unsigned int v6; // r3
  unsigned int v7; // r8
  _BYTE *v8; // r0
  __int64 v9; // r6
  _DWORD *v10; // r3
  _DWORD *v11; // r5
  unsigned int v12; // lr
  _DWORD *v13; // r8
  int v14; // r2
  _DWORD *v15; // r4
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int i; // r3
  int v22; // r2
  int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r0
  unsigned int v26; // r0
  unsigned int v27; // r1
  int *v28; // r3
  int v29; // r5
  int v30; // r2
  int v31; // r0
  int v32; // r4
  int v33; // r1
  _DWORD *v34; // r5
  int v35; // r3
  unsigned int *v36; // r2
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int result; // r0
  int v41; // r3
  int v42; // r3
  int v43; // [sp+8h] [bp-40h]
  int *v44; // [sp+10h] [bp-38h]
  int v45; // [sp+10h] [bp-38h]
  unsigned int v46; // [sp+14h] [bp-34h]
  int v47; // [sp+14h] [bp-34h]
  int v48; // [sp+18h] [bp-30h]
  int v49; // [sp+18h] [bp-30h]
  char v51[40]; // [sp+20h] [bp-28h] BYREF

  *a3 = 0;
  v48 = a1 & 0x20;
  if ( (a1 & 0x20) != 0 )
  {
    v4 = *(_DWORD *)(MmSessionSpace + 8384);
    v44 = (int *)(MmSessionSpace + 8304);
    v3 = *(_DWORD **)(MmSessionSpace + 8380);
    if ( !PoolBigPageTableSize )
      return 0;
  }
  else
  {
    v3 = (_DWORD *)PoolBigPageTable;
    v4 = PoolBigPageTableSize;
    v44 = &ExpPoolBigEntriesInUse;
  }
  if ( v4 )
  {
    v5 = 2 * v4;
    if ( 2 * v4 <= v4 || v5 > 0xFFFFFFF )
      return 0;
    v6 = 32 * v4;
  }
  else
  {
    v5 = 512;
    v6 = 0x2000;
  }
  if ( v6 >= v6 + 4095 )
    return 0;
  v7 = (v6 + 4095) & 0xFFFFF000;
  v46 = v7;
  v8 = (_BYTE *)MiAllocatePoolPages(512, v7, 512, v6);
  LODWORD(v9) = v8;
  if ( !v8 )
    return 0;
  memset(v8, 0, v7);
  v10 = (_DWORD *)v9;
  do
  {
    *v10 = 1;
    v10 += 4;
  }
  while ( v10 != (_DWORD *)(v9 + 16 * v5) );
  v11 = v3;
  v12 = v5 - 1;
  if ( v3 != &v3[4 * v4] )
  {
    v13 = &v3[4 * v4];
    do
    {
      if ( (*v11 & 1) == 0 )
      {
        v14 = v12 & ((162172
                    * ((*v11 >> 12 >> 16) ^ (4 * ((unsigned __int8)(*v11 >> 20) ^ (4 * (unsigned __int8)(*v11 >> 12)))))) >> 2);
        while ( (*(_DWORD *)(16 * v14 + v9) & 1) == 0 )
        {
          if ( ++v14 > v12 )
            v14 = 0;
        }
        v15 = (_DWORD *)(v9 + 16 * v14);
        v16 = v11[1];
        v17 = v11[2];
        v18 = v11[3];
        *v15 = *v11;
        v15[1] = v16;
        v15[2] = v17;
        v15[3] = v18;
      }
      v11 += 4;
    }
    while ( v11 != v13 );
    v7 = v46;
  }
  if ( v44 == &ExpPoolBigEntriesInUse )
  {
    v19 = v9;
  }
  else
  {
    if ( ExpPoolBigEntriesInUse == PoolBigPageTableSize )
      return sub_550BA4(1, 40543);
    v12 = PoolBigPageTableSize - 1;
    v19 = PoolBigPageTable;
  }
  v20 = v12 & ((int)(162172
                   * (((unsigned int)v9 >> 12 >> 16) ^ (4
                                                      * ((unsigned __int8)((unsigned int)v9 >> 20) ^ (4 * (unsigned __int8)((unsigned int)v9 >> 12)))))) >> 2);
  for ( i = 16 * v20; (*(_DWORD *)(i + v19) & 1) == 0; i = 16 * v20 )
  {
    if ( ++v20 > v12 )
      v20 = 0;
  }
  HIDWORD(v9) = 1819242320;
  v22 = v19 + 16 * v20;
  *(_QWORD *)v22 = v9;
  *(_BYTE *)(v22 + 8) = 0;
  v23 = *(_DWORD *)(v22 + 8);
  *(_DWORD *)(v22 + 12) = v7;
  *(_DWORD *)(v22 + 8) = (unsigned __int8)v23 | 0x20000;
  do
    v24 = __ldrex((unsigned int *)&ExpPoolBigEntriesInUse);
  while ( __strex(v24 + 1, (unsigned int *)&ExpPoolBigEntriesInUse) );
  do
    v25 = __ldrex(dword_643D88);
  while ( __strex(v25 + (v7 >> 12), dword_643D88) );
  do
    v26 = __ldrex(dword_643D90);
  while ( __strex(v26 + v7, dword_643D90) );
  do
    v27 = __ldrex((unsigned int *)&dword_643D80);
  while ( __strex(v27 + 1, (unsigned int *)&dword_643D80) );
  if ( v48 )
  {
    v42 = MmSessionSpace;
    *(_DWORD *)(MmSessionSpace + 8380) = v9;
    v28 = (int *)(v42 + 8384);
  }
  else
  {
    PoolBigPageTable = v9;
    v28 = &PoolBigPageTableSize;
  }
  *v28 = v5;
  if ( PoolHitTag == 1819242320 )
    __debugbreak();
  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, 512, 1819242320, v9, v7);
  v29 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
  v43 = v29;
  v30 = PoolTrackTableMask;
  v49 = PoolTrackTableMask;
  v31 = PoolTrackTableSize;
  v45 = PoolTrackTableSize;
  v32 = PoolTrackTableMask & 0x2F53638;
  v33 = PoolTrackTableMask & 0x2F53638;
  v47 = PoolTrackTableMask & 0x2F53638;
  while ( 1 )
  {
    v34 = (_DWORD *)(v29 + 28 * v32);
    if ( *v34 == 1819242320 )
      break;
    if ( *v34 )
    {
LABEL_36:
      v35 = v32 + 1;
      v32 = (v32 + 1) & v30;
      v29 = v43;
      if ( v32 == v33 )
      {
        ExpInsertPoolTrackerExpansion(1819242320, v7, 512, v35);
        goto LABEL_44;
      }
    }
    else
    {
      v41 = *(_DWORD *)(PoolTrackTable + 28 * v32);
      if ( v41 )
      {
        *v34 = v41;
      }
      else
      {
        if ( v32 == v31 - 1 )
          goto LABEL_36;
        KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v51);
        if ( !*(_DWORD *)(PoolTrackTable + 28 * v32) )
        {
          *(_DWORD *)(PoolTrackTable + 28 * v32) = 1819242320;
          *v34 = 1819242320;
        }
        KeReleaseInStackQueuedSpinLock((int)v51);
        v33 = v47;
        v30 = v49;
        v31 = v45;
      }
      v29 = v43;
    }
  }
  v36 = v34 + 1;
  do
    v37 = __ldrex(v36);
  while ( __strex(v37 + 1, v36) );
  v38 = v34 + 3;
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 + v7, v38) );
LABEL_44:
  if ( v3 )
    *v3 = 0;
  else
    v3 = 0;
  result = 1;
  *a3 = v3;
  return result;
}
