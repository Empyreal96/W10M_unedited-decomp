// MiGetZeroedPages 
 
int __fastcall MiGetZeroedPages(int a1, int a2, int a3, unsigned int a4, char a5, unsigned int *a6)
{
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r4
  _WORD *v10; // r10
  unsigned int v11; // r3
  int v12; // r2
  int v14; // r5
  unsigned int v15; // r6
  int v16; // r8
  unsigned int *v17; // r7
  char v18; // r2
  int v19; // r9
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r4
  int v24; // r3
  unsigned int *v25; // lr
  int v26; // r1
  unsigned int v27; // r7
  unsigned int *v28; // lr
  int v29; // r0
  int v30; // r8
  unsigned int v31; // r7
  int v32; // r0
  char v33; // r3
  unsigned int *v34; // lr
  int v35; // r9
  int v36; // r0
  unsigned int v37; // r7
  int v38; // r2
  char v39; // r3
  unsigned int v40; // r3
  unsigned int v41; // r0
  unsigned int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r1
  unsigned int v45; // r0
  unsigned int v46; // r1
  int v47; // [sp+0h] [bp-38h]
  int v48; // [sp+4h] [bp-34h]
  _WORD *v50; // [sp+Ch] [bp-2Ch]
  int v51; // [sp+10h] [bp-28h]
  int v53; // [sp+18h] [bp-20h]

  if ( a3 )
  {
    v7 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v8 = (unsigned __int16)((a3 + 0xFFFF) << byte_6337F5);
  }
  else
  {
    v7 = (unsigned int)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C));
    v8 = (unsigned __int16)*(_DWORD *)(v7 + 2732);
  }
  v51 = v8;
  v9 = (unsigned __int16)((1 << byte_6337FC) - 1);
  v53 = v9;
  if ( a2 && (*(_BYTE *)(a2 + 112) & 7u) < 2 )
    v10 = (_WORD *)(a2 + 96);
  else
    v10 = (_WORD *)(v7 + 2724);
  v11 = a4 >> 3;
  v12 = 1;
  v50 = v10;
  if ( a4 >> 3 == 3 && (a4 & 7) != 0 )
  {
    v12 = 2;
  }
  else if ( v11 == 1 )
  {
    return sub_537620();
  }
  v14 = 0;
  v15 = 0;
  v16 = 0xFFFFF;
  v47 = MiPlatformCacheAttributes[v12];
  v48 = 0;
  v17 = a6;
  if ( !*a6 )
    return 0;
  v18 = a5;
  v19 = v47;
  while ( 1 )
  {
    v20 = (unsigned __int16)(*v10 + 1);
    *v10 = v20;
    v21 = (v18 & 2) != 0 ? 2 : 0;
    v22 = MiGetPage(a1, v20 & v9 | v8, v21);
    v23 = v22;
    if ( v22 == -1 )
      break;
    v14 = MmPfnDatabase + 24 * v22;
    if ( *(_DWORD *)(v14 + 8) && (a5 & 0x40) != 0 )
    {
      MiZeroPhysicalPage(v22, 1, v19);
      *(_DWORD *)(v14 + 8) = 0;
      __dmb(0xFu);
      v33 = KiTbFlushTimeStamp;
      __dmb(0xBu);
      v34 = (unsigned int *)(v14 + 12);
      v35 = v33 & 0xF;
      v36 = *(_DWORD *)(v14 + 12);
      do
        v37 = __ldrex(v34);
      while ( v37 == v36 && __strex(v36 & 0xFF0FFFFF | (v35 << 20), v34) );
      if ( v36 != v37 )
      {
        do
        {
          v41 = v37;
          do
            v42 = __ldrex(v34);
          while ( v42 == v37 && __strex(v37 & 0xFF0FFFFF | (v35 << 20), v34) );
          v37 = v42;
        }
        while ( v41 != v42 );
        v10 = v50;
      }
      v19 = v47;
    }
    v24 = *(unsigned __int8 *)(v14 + 18) >> 6;
    if ( v24 != v19 )
    {
      if ( v19 != 1
        || v24 != 3
        && (v38 = (*(_DWORD *)(v14 + 12) >> 20) & 0xF,
            __dmb(0xFu),
            v39 = KiTbFlushTimeStamp,
            __dmb(0xBu),
            v40 = (v39 - (_BYTE)v38) & 0xF,
            v40 <= 2)
        && ((v38 & 1) != 0 || v40 < 2) )
      {
        v32 = v48;
        v48 = v14;
        *(_DWORD *)(v14 + 8) = v32;
        goto LABEL_20;
      }
      MiChangePageAttribute(v14, 1, 4);
    }
    v25 = (unsigned int *)(v14 + 12);
    v26 = *(_DWORD *)(v14 + 12);
    do
      v27 = __ldrex(v25);
    while ( v27 == v26 && __strex(v26 & 0xFF0FFFFF, v25) );
    if ( v26 != v27 )
    {
      do
      {
        v43 = v27;
        do
          v44 = __ldrex(v25);
        while ( v44 == v27 && __strex(v27 & 0xFF0FFFFF, v25) );
        v27 = v44;
      }
      while ( v43 != v44 );
      v19 = v47;
    }
LABEL_20:
    v28 = (unsigned int *)(v14 + 12);
    v29 = *(_DWORD *)(v14 + 12);
    v30 = v16 & 0xFFFFF;
    do
      v31 = __ldrex(v28);
    while ( v31 == v29 && __strex(v29 & 0xFFF00000 | v30, v28) );
    if ( v29 != v31 )
    {
      do
      {
        v45 = v31;
        do
          v46 = __ldrex(v28);
        while ( v46 == v31 && __strex(v31 & 0xFFF00000 | v30, v28) );
        v31 = v46;
      }
      while ( v45 != v46 );
    }
    ++v15;
    v16 = v23;
    if ( (v15 & 0xF) == 0 && ExSpinLockIsContended(a2) || KeShouldYieldProcessor() )
    {
      *a6 = v15;
      goto LABEL_27;
    }
    v17 = a6;
    v18 = a5;
    v8 = v51;
    v9 = v53;
    if ( v15 >= *a6 )
      goto LABEL_27;
  }
  *v17 = v15;
LABEL_27:
  if ( v48 )
    MiChangePageAttributeBatch(v48, v19, 0);
  return v14;
}
