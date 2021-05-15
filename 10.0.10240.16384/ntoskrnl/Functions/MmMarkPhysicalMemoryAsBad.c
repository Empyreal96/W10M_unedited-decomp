// MmMarkPhysicalMemoryAsBad 
 
int __fastcall MmMarkPhysicalMemoryAsBad(__int64 *a1, __int64 *a2)
{
  int v3; // r5
  unsigned int v4; // r6
  int v5; // r3
  unsigned int v6; // r8
  int v7; // r4
  unsigned int *v8; // r7
  int v9; // r5
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  unsigned __int8 *v12; // r1
  unsigned int v13; // r3
  unsigned int v14; // r2
  __int16 *v15; // r9
  unsigned int v16; // r1
  int v17; // r2
  unsigned int v18; // r1
  int v19; // r8
  int v20; // lr
  unsigned __int8 *v21; // r1
  unsigned int v22; // r2
  unsigned __int8 *v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  int v28; // r1
  int v29; // r2
  int v30; // r3
  unsigned int v31; // r1
  int v32; // r4
  unsigned int *v33; // r2
  unsigned int v34; // r0
  int v35; // r1
  int v36; // r2
  int v37; // r3
  int v39; // [sp+Ch] [bp-44h]
  int v40; // [sp+18h] [bp-38h]
  unsigned int v41; // [sp+1Ch] [bp-34h]
  int v42; // [sp+20h] [bp-30h]
  int v43; // [sp+28h] [bp-28h]
  unsigned int v44[9]; // [sp+2Ch] [bp-24h] BYREF

  if ( !dword_634C9C )
    return -1073741822;
  v4 = *a1 >> 12;
  v5 = *a2 >> 12;
  v6 = v5 + v4;
  v41 = v5 + v4;
  v43 = v5;
  if ( v4 >= v5 + v4 )
    return -1073741585;
  v40 = 203423744;
  if ( (*(_DWORD *)a1 & 1) == 0 )
    v40 = 471859200;
  v42 = 0;
  v7 = MmPfnDatabase + 24 * v4;
  v8 = (unsigned int *)(v7 + 12);
  while ( !MI_IS_PFN(v4) )
  {
    v3 = -1073741584;
LABEL_54:
    ++v4;
    v7 += 24;
    v8 += 6;
    if ( v4 >= v6 )
    {
      v32 = 0;
      goto LABEL_59;
    }
  }
  v9 = KfRaiseIrql(2);
  v10 = (unsigned __int8 *)(v7 + 15);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
  {
    v12 = (unsigned __int8 *)v8 + 3;
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v13 = *v8;
        __dmb(0xBu);
      }
      while ( (v13 & 0x80000000) != 0 );
      do
        v14 = __ldrex(v12);
      while ( __strex(v14 | 0x80, v12) );
      __dmb(0xBu);
    }
    while ( v14 >> 7 );
  }
  v15 = (__int16 *)MiReferencePagePartition();
  if ( !v15 )
  {
    __dmb(0xBu);
    do
      v16 = __ldrex(v8);
    while ( __strex(v16 & 0x7FFFFFFF, v8) );
    KfLowerIrql(v9);
    v3 = -1073741558;
    goto LABEL_54;
  }
  if ( (v40 & 0x10000000) != 0 )
  {
    v17 = *(unsigned __int8 *)(v7 + 19);
    if ( (v17 & 0xFFFFFF80) == 0 )
      *(_BYTE *)(v7 + 19) = v17 | 0x80;
  }
  if ( (*(_BYTE *)(v7 + 19) & 0x40) == 0 )
    *(_BYTE *)(v7 + 19) |= 0x40u;
  __dmb(0xBu);
  do
    v18 = __ldrex(v8);
  while ( __strex(v18 & 0x7FFFFFFF, v8) );
  KfLowerIrql(v9);
  v19 = MiFindContiguousPages(v15, v4, v4, 0, 1u, 1, 0x80000000, v39, v40, v44);
  v3 = 0;
  v20 = KfRaiseIrql(2);
  v21 = (unsigned __int8 *)(v7 + 15);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 | 0x80, v21) );
  __dmb(0xBu);
  if ( v22 >> 7 )
  {
    v23 = (unsigned __int8 *)v8 + 3;
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v24 = *v8;
        __dmb(0xBu);
      }
      while ( (v24 & 0x80000000) != 0 );
      do
        v22 = __ldrex(v23);
      while ( __strex(v22 | 0x80, v23) );
      __dmb(0xBu);
    }
    while ( v22 >> 7 );
  }
  if ( v19 >= 0 )
  {
    if ( (*(_BYTE *)(v7 + 19) & 0x40) == 0 )
    {
      __dmb(0xBu);
      do
        v27 = __ldrex(v8);
      while ( __strex(v27 & 0x7FFFFFFF, v8) );
      KfLowerIrql(v20);
      MiFreeContiguousPages((int)v15, v4, 1);
      goto LABEL_53;
    }
    *(_WORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) &= 0xFFF00000;
    MiInsertPageInList(v7, 32, v22);
    __dmb(0xBu);
    do
      v25 = __ldrex(v8);
    while ( __strex(v25 & 0x7FFFFFFF, v8) );
    v26 = v20;
LABEL_52:
    KfLowerIrql(v26);
LABEL_53:
    MiDereferencePartition((int)v15, v28, v29, v30);
    v6 = v41;
    goto LABEL_54;
  }
  if ( (*(_BYTE *)(v7 + 19) & 0x40) != 0 )
  {
    if ( (*(_DWORD *)(v7 + 4) | 0x80000000) != -4 || (*(_BYTE *)(v7 + 18) & 7) != 5 )
    {
      byte_634428 = 1;
      v42 = 1;
      v3 = 259;
    }
    goto LABEL_49;
  }
  if ( v19 != -1073741523 && v19 != -1073741670 )
  {
LABEL_49:
    __dmb(0xBu);
    do
      v31 = __ldrex(v8);
    while ( __strex(v31 & 0x7FFFFFFF, v8) );
    v26 = v20;
    goto LABEL_52;
  }
  __dmb(0xBu);
  v33 = (unsigned int *)(v7 + 12);
  do
    v34 = __ldrex(v33);
  while ( __strex(v34 & 0x7FFFFFFF, v33) );
  KfLowerIrql(v20);
  MiDereferencePartition((int)v15, v35, v36, v37);
  v3 = v19;
  v32 = v19;
  v6 = v41;
LABEL_59:
  if ( v42 == 1 )
    ZwUpdateWnfStateData();
  if ( v43 != 1 )
    v3 = v32;
  *a2 = (unsigned __int64)(v43 - v6 + v4) << 12;
  return v3;
}
