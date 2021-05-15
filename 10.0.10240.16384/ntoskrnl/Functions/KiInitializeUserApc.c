// KiInitializeUserApc 
 
int __fastcall KiInitializeUserApc(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // r8
  _DWORD *v8; // r10
  unsigned int v9; // r6
  unsigned int v10; // r1
  unsigned int v11; // r6
  int v12; // r3
  int v13; // r1
  int result; // r0
  unsigned int v15; // r4
  int i; // r2
  unsigned int v17; // r1
  unsigned int v18; // r5
  unsigned int v19; // lr
  _QWORD *v20; // r0
  char *j; // r3
  int v22; // r4
  int v23; // r1
  char v24; // r5
  unsigned int v25; // r4
  unsigned int v26; // r6
  char v27; // r5
  int v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r6
  char v31; // r5
  int v32; // r0
  __int64 v33; // kr28_8
  int k; // r2
  unsigned int v35; // r4
  unsigned __int64 v36; // r0
  __int64 v37; // r2
  int v39; // [sp+8h] [bp-98h]
  unsigned int v41; // [sp+10h] [bp-90h]
  unsigned int v43; // [sp+18h] [bp-88h]
  _QWORD *v44; // [sp+18h] [bp-88h]

  v7 = (_DWORD *)((*(_DWORD *)(a2 + 116) - 16) & 0xFFFFFFF8);
  v8 = (_DWORD *)((unsigned int)(v7 - 104) & 0xFFFFFFF8);
  v9 = (unsigned int)(v8 - 4) & 0xFFFFFFF8;
  v10 = (unsigned int)v7 - v9 + 8;
  if ( (_DWORD *)((char *)v7 - v9) == (_DWORD *)-8 || v10 >= 0x1000 )
  {
    ProbeForWrite((unsigned int)(v8 - 4) & 0xFFFFFFF8, v10, 8);
  }
  else
  {
    if ( v9 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)v9 = *(_BYTE *)v9;
    if ( v10 > 8 )
      *(_BYTE *)((((unsigned int)v7 - v9 + 7) & 0xFFFFFFF8) + v9) = *(_BYTE *)((((unsigned int)v7 - v9 + 7) & 0xFFFFFFF8)
                                                                             + v9);
  }
  *v8 = 2097167;
  KeContextFromKframes(a2, a1);
  *v7 = v8[14];
  v7[1] = v8[16];
  *(_DWORD *)(v9 + 4) = a4;
  *(_DWORD *)(v9 + 8) = a5;
  *(_DWORD *)(v9 + 12) = a6;
  *(_DWORD *)v9 = a3;
  *(_DWORD *)(a2 + 116) = v9;
  *(_DWORD *)(a2 + 128) = KeUserApcDispatcher;
  v11 = 32;
  v39 = 32;
  v12 = *(_DWORD *)(a2 + 132) | 0x20;
  *(_DWORD *)(a2 + 132) = v12;
  *(_DWORD *)(a2 + 132) = v12 & 0xF9FF03FF;
  if ( *(_BYTE *)(a2 + 16) != 2 )
  {
    v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 160);
    if ( v13 )
    {
      if ( (*(_DWORD *)(a2 + 132) & 0x1F) == 16 && (*(_DWORD *)(a2 + 132) & 0x600FC00) == 0 )
      {
        *(_DWORD *)(a2 + 112) = *(_DWORD *)(a2 + 128);
        *(_DWORD *)(a2 + 128) = v13;
      }
    }
  }
  do
  {
    result = MEMORY[0xFFFF93B4];
    v15 = MEMORY[0xFFFF93B0];
    for ( i = 0; ; ++i )
    {
      v17 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v18 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v17 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v15 != MEMORY[0xFFFF93B0] || result != MEMORY[0xFFFF93B4] );
  if ( __PAIR64__(v17, v18) - __PAIR64__(result, v15) >= qword_641D00 )
  {
    v19 = __mrc(15, 0, 12, 0, 0) & 0xFFFFFFE0;
    v20 = (_QWORD *)v19;
    v43 = v19;
    for ( j = (char *)v19; (unsigned int)j < v19 + 32; j += 128 )
      __pld(j);
    v22 = dword_641CF0;
    v23 = dword_641CF4;
    v24 = dword_641CF8;
    while ( v11 >= 8 )
    {
      v26 = (__PAIR64__(v23, v22) - *v20) >> 32;
      v25 = v22 - *(_DWORD *)v20;
      v27 = v24 & 0x3F;
      v28 = (v26 << (64 - v27)) | (v25 >> (v27 - 32)) | (v25 << (32 - v27));
      v22 = (v25 << (64 - v27)) | (__PAIR64__(v26, v25) >> v27);
      v23 = v28 | (v26 >> v27);
      v20 = (_QWORD *)(v43 + 8);
      v43 += 8;
      v11 = v39 - 8;
      v39 -= 8;
      v24 = dword_641CF8;
    }
    while ( v11 )
    {
      v44 = (_QWORD *)((char *)v20 + 1);
      v30 = (__PAIR64__(v23, v22) - *(unsigned __int8 *)v20) >> 32;
      v29 = v22 - *(unsigned __int8 *)v20;
      v31 = v24 & 0x3F;
      v32 = (v30 << (64 - v31)) | (v29 >> (v31 - 32)) | (v29 << (32 - v31));
      v22 = (v29 << (64 - v31)) | (__PAIR64__(v30, v29) >> v31);
      v23 = v32 | (v30 >> v31);
      v11 = --v39;
      v20 = v44;
      v24 = dword_641CF8;
    }
    if ( (dword_641D08 != v22 || dword_641D0C != v23) && !qword_641CC0 )
    {
      qword_641CC0 = 265i64;
      dword_641CC8 = 0;
      dword_641CCC = 0;
      dword_641CD0 = 0;
      dword_641CD4 = 0;
      dword_641CD8 = 269;
      dword_641CDC = 0;
      dword_641CE0 = v19;
      dword_641CE4 = 0;
    }
    if ( qword_641CC0 )
    {
      if ( (int (*)())dword_641CAC != sub_5C46B4 )
      {
        byte_641CA0 = 19;
        byte_641CA1 = 1;
        word_641CA2 = 0;
        dword_641CAC = (int)sub_5C46B4;
        dword_641CB0 = (int)&byte_641CA0;
        dword_641CBC = 0;
        dword_641CA8 = 0;
      }
      dword_641CE8 = 182710;
      dword_641CEC = 0;
      KiInsertQueueDpc(&byte_641CA0);
    }
    do
    {
      v33 = MEMORY[0xFFFF93B0];
      for ( k = 0; ; ++k )
      {
        v35 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v41 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v35 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v33 != MEMORY[0xFFFF93B0] );
    LODWORD(v36) = ReadTimeStampCounter();
    result = _rt_udiv64(80000000000i64, 41929663 * (v36 >> 4));
    qword_641D00 = __PAIR64__((v37 - v33 + __PAIR64__(v35, v41)) >> 32, 237191168)
                 + (((_DWORD)v37 - (_DWORD)v33 + v41) | 0x4300000000i64);
  }
  return result;
}
