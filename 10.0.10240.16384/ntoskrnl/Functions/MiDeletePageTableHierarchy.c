// MiDeletePageTableHierarchy 
 
int __fastcall MiDeletePageTableHierarchy(int *a1, unsigned int a2)
{
  int *v3; // r6
  int v4; // r8
  int v5; // r5
  int v6; // r9
  unsigned int v7; // r7
  unsigned int *v8; // r4
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r4
  BOOL v12; // r7
  unsigned __int8 *v13; // r1
  int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r6
  int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned __int8 *v20; // r2
  unsigned int v21; // r1
  unsigned int *v22; // r2
  int result; // r0
  unsigned __int8 *v24; // r1
  int v25; // r3
  unsigned int v26; // r2
  unsigned __int8 *v27; // r1
  int v28; // r3
  unsigned int v29; // r2
  _DWORD v30[4]; // [sp+18h] [bp-D8h] BYREF
  int v31[4]; // [sp+28h] [bp-C8h] BYREF
  int v32; // [sp+38h] [bp-B8h] BYREF
  char v33; // [sp+3Ch] [bp-B4h]
  char v34; // [sp+3Dh] [bp-B3h]
  int v35; // [sp+40h] [bp-B0h]
  int v36; // [sp+44h] [bp-ACh]
  int v37; // [sp+48h] [bp-A8h]
  int v38; // [sp+4Ch] [bp-A4h]

  v3 = a1;
  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( !a1 )
  {
    v32 = 1;
    v3 = &v32;
    v33 = 0;
    v35 = 33;
    v36 = 0;
    v34 = 0;
    v37 = 0;
    v38 = 0;
  }
  while ( 1 )
  {
    v7 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
    v8 = (unsigned int *)(MmPfnDatabase + 24 * (*(_DWORD *)v7 >> 12));
    if ( !v5 )
      v5 = MmPfnDatabase + 24 * (*(_DWORD *)v7 >> 12);
    MiTerminateWsle(a2, (_DWORD *)(v6 + 492), *v8);
    if ( (v8[1] | 0x80000000) != v7 )
      KeBugCheckEx(26, 1025, v7);
    __dmb(0xBu);
    *(_DWORD *)v7 = 0;
    if ( ((a2 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
    {
      v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v9, (_DWORD *)(v9 + 4 * ((a2 >> 10) & 0xFFC)), 0);
    }
    ++v4;
    MiInsertTbFlushEntry(v3, a2 & 0xFFFFF000, 1);
    if ( v7 >= 0xC0300000 && v7 <= 0xC0300FFF )
      break;
    MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((a2 >> 22) - 534769440)), 1);
    if ( *(_WORD *)(2 * ((a2 >> 22) - 534769440)) )
      break;
    a2 = v7 & 0xFFFFF000;
  }
  MiFlushTbList(v3);
  v10 = (unsigned int *)(v6 + 276);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - v4, v10) );
  v12 = (dword_682604 & 1) != 0;
  do
  {
    v13 = (unsigned __int8 *)(v5 + 15);
    v14 = MmPfnDatabase + 24 * (*(_DWORD *)(v5 + 20) & 0xFFFFF);
    do
      v15 = __ldrex(v13);
    while ( __strex(v15 | 0x80, v13) );
    __dmb(0xBu);
    if ( v15 >> 7 )
    {
      v24 = (unsigned __int8 *)(v5 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v25 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v25 & 0x80000000) != 0 );
        do
          v26 = __ldrex(v24);
        while ( __strex(v26 | 0x80, v24) );
        __dmb(0xBu);
      }
      while ( v26 >> 7 );
    }
    *(_DWORD *)(v5 + 12) |= 0x40000000u;
    if ( v12 )
    {
      v30[0] = 0;
      v30[1] = 0;
      v30[2] = 0;
      v30[3] = 0;
      MiIdentifyPfn(v5, v30);
    }
    v16 = *(_DWORD *)(v5 + 12) & 0x3FFFFFFF;
    v17 = *(_BYTE *)(v5 + 18) & 7;
    if ( v16 >= 0x10000 )
    {
      if ( v17 != 6 )
        KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
      if ( !MiUpdateShareCount(v5, -1) )
        MiPfnShareCountIsZero(v5, 0);
LABEL_48:
      MiChargeCommit((int)MiSystemPartition, 1u, 4);
      goto LABEL_22;
    }
    if ( v17 != 6 )
      KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
    if ( !MiUpdateShareCount(v5, -1) && MiPfnShareCountIsZero(v5, 0) == 3 )
      goto LABEL_48;
LABEL_22:
    if ( v16 != 1 )
      *(_DWORD *)v5 = 0;
    __dmb(0xBu);
    v18 = (unsigned int *)(v5 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    v20 = (unsigned __int8 *)(v14 + 15);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 | 0x80, v20) );
    __dmb(0xBu);
    if ( v21 >> 7 )
    {
      v27 = (unsigned __int8 *)(v14 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v28 = *(_DWORD *)(v14 + 12);
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
    if ( (*(_BYTE *)(v14 + 18) & 7) != 6 )
      KeBugCheckEx(78, 153, (v14 - MmPfnDatabase) / 24);
    if ( !MiUpdateShareCount(v14, -1) )
      MiPfnShareCountIsZero(v14, 0);
    __dmb(0xBu);
    v22 = (unsigned int *)(v14 + 12);
    do
      result = __ldrex(v22);
    while ( __strex(result & 0x7FFFFFFF, v22) );
    v5 = v14;
    --v4;
    if ( v12 )
    {
      v31[0] = (int)v30;
      v31[1] = 0;
      v31[2] = 16;
      v31[3] = 0;
      result = EtwTraceKernelEvent(v31, 1, 536870913, 631, 289413890);
    }
  }
  while ( v4 );
  return result;
}
