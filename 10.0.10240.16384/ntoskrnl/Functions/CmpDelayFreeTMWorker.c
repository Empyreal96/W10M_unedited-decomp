// CmpDelayFreeTMWorker 
 
void __fastcall __noreturn CmpDelayFreeTMWorker(unsigned int *a1)
{
  int *v2; // r6
  int v3; // r0
  __int64 v4; // r2
  unsigned int v5; // r2
  char *v6; // r10
  unsigned int v7; // r4
  int v8; // r5
  int v9; // r0
  unsigned int v10; // r9
  int v11; // r4
  int v12; // r5
  int v13; // r5
  int v14; // r3
  int v15; // r0
  int v16; // r3
  unsigned int v17; // r6
  int *v18; // r4
  unsigned int i; // r2
  char v20; // r3
  unsigned int v21; // r5
  int v22; // r7
  int v23; // r1
  int v24; // r1
  int v25; // r3
  unsigned int v26; // r1
  int v27; // r2
  unsigned int v28; // r8
  unsigned int j; // r0
  unsigned int v30; // r4
  unsigned int v31; // r2
  char v32; // r1
  unsigned int k; // r3
  char v34; // r5
  int v35; // r1
  __int64 v36; // r0
  int *v37; // r6
  _BYTE *v38; // r3
  int v39; // r2
  int *v40; // r3
  int v41; // r2
  int v42; // r3
  int v43; // r3
  unsigned int v44; // [sp+8h] [bp-60h]
  int v45; // [sp+8h] [bp-60h]
  int v46; // [sp+8h] [bp-60h]
  unsigned int v47; // [sp+Ch] [bp-5Ch]
  int v48; // [sp+Ch] [bp-5Ch]
  unsigned int v49; // [sp+Ch] [bp-5Ch]
  unsigned int v50; // [sp+10h] [bp-58h]
  int v51; // [sp+10h] [bp-58h]
  int v52; // [sp+14h] [bp-54h] BYREF
  unsigned int v53; // [sp+18h] [bp-50h]
  int *v54; // [sp+1Ch] [bp-4Ch]
  __int64 v55; // [sp+20h] [bp-48h] BYREF
  char v56[16]; // [sp+28h] [bp-40h] BYREF
  char v57[4]; // [sp+38h] [bp-30h] BYREF
  int v58; // [sp+3Ch] [bp-2Ch]
  int v59[10]; // [sp+40h] [bp-28h] BYREF

  v2 = (int *)PspGetReaperLink();
  v54 = v2;
  v3 = ExGenRandom(1);
  _rt_sdiv64(100000000i64, (unsigned int)v3);
  v55 = -6000000000i64 - v4;
  if ( a1[1] == 1 )
    KeRundownApcQueues(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( ExGenRandom(1) % 0xAu < 3 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 310);
  }
  v6 = (char *)*a1;
  KeWaitForSingleObject(*a1, 0, 0, 0, 0);
  if ( ExGenRandom(1) % 0xAu >= 5 )
  {
    KeResetEvent((int)v6);
  }
  else
  {
    v57[0] = 0;
    v57[1] = 0;
    v57[2] = 4;
    v58 = 0;
    v59[1] = (int)v59;
    v6 = v57;
    v59[0] = (int)v59;
  }
  v7 = a1[2];
  a1[2] = 0;
  v8 = *(_DWORD *)(v7 + 16);
  v9 = ExGenRandom(1);
  *v2 = 0;
  v10 = v9 ^ 0xBC2A27DB;
  v53 = v9 ^ 0xBC2A27DB;
  __dmb(0xBu);
  v44 = v9 ^ 0xBC2A27DB ^ v7;
  __dmb(0xBu);
  v47 = v9 ^ 0xBC2A27DB ^ v8;
  v12 = v44;
  v11 = v47;
  while ( 1 )
  {
    if ( ((v10 ^ v11) & 3) == 0 )
    {
      __dmb(0xBu);
      v45 = v10 ^ v12;
      __dmb(0xBu);
      v13 = v45;
      (*(void (__fastcall **)(int, unsigned int, _DWORD, _DWORD))(v45 + 12))(
        v45,
        v10 ^ v11,
        *(_DWORD *)(v45 + 20),
        *(_DWORD *)(v45 + 24));
      v14 = *(_DWORD *)(v45 + 16) ^ v10;
      __dmb(0xBu);
      v48 = v14;
      __dmb(0xBu);
      v12 = v10 ^ v13;
      v11 = v48;
    }
    v15 = KfRaiseIrql(2);
    v16 = *(_DWORD *)((v10 ^ v12) + 0x20);
    v46 = v15;
    v17 = (v16 ^ v10 ^ v11) & 0xFFFFFFFC;
    v50 = __ROR4__(v17, (v16 ^ v10 ^ v11) & 0x1C);
    v56[0] = 10;
    v56[1] = 9;
    v56[2] = 15;
    v56[3] = 2;
    v56[4] = 12;
    v56[5] = 3;
    v56[6] = 6;
    v56[7] = 13;
    v56[8] = 7;
    v56[9] = 0;
    v56[10] = 4;
    v56[11] = 14;
    v56[12] = 11;
    v56[13] = 5;
    v56[14] = 1;
    v56[15] = 8;
    v18 = (int *)v17;
    for ( i = 0; i < 0x10; ++i )
    {
      v20 = v56[i] ^ 0xA;
      __dmb(0xBu);
      v56[i] = v20;
    }
    v21 = 0;
    v22 = 0;
    do
    {
      v23 = *v18;
      *v18 = (KiWaitAlways ^ bswap32(v50 ^ __ROR4__(KiWaitNever ^ *v18, -(char)KiWaitNever))) + v22;
      v50 = __ROL4__(__ROR4__((200 - v21) * v21, ~(_BYTE)v23 & 0x1F) ^ v50, v23 & 0x1F) + v17;
      v24 = 8;
      do
      {
        *v18 = __ROR4__(*v18 & 0xFFFFFFF0 | (unsigned __int8)v56[*v18 & 0xF], 4);
        --v24;
      }
      while ( v24 );
      ++v21;
      ++v18;
      v22 += v17;
    }
    while ( v21 < 0x32 );
    v10 = v53;
    __dmb(0xBu);
    v49 = 1142023213;
    __dmb(0xBu);
    v25 = (v49 >> 22) | 0x4790B400;
    __dmb(0xBu);
    __dmb(0xBu);
    v51 = *(_DWORD *)v17 ^ v25;
    __dmb(0xBu);
    *(_BYTE *)(v17 + 3) = 71;
    __dmb(0xBu);
    *(_BYTE *)(v17 + 2) = -112;
    __dmb(0xBu);
    *(_BYTE *)(v17 + 1) = -75;
    __dmb(0xBu);
    *(_BYTE *)v17 = 16;
    *(_BYTE *)v17 = *(_BYTE *)v17;
    v26 = __mrc(15, 1, 0, 0, 1);
    v27 = __mrc(15, 0, 0, 0, 0);
    v28 = (v26 >> 21) & 7;
    if ( (v27 & 0xFFF0) == 49296 && (v27 & 0xFF000000) == 1090519040 && (v27 & 0xF00000u) < 0x100000 )
      v28 = (v26 >> 27) & 7;
    for ( j = 0; j < v28; ++j )
    {
      __mcr(15, 2, 2 * (j & 7), 0, 0, 0);
      __isb(0xFu);
      v30 = __mrc(15, 1, 0, 0, 0);
      v31 = ((v30 >> 3) & 0x3FF) + 1;
      v32 = 0;
      for ( k = v31 >> 1; k; k >>= 1 )
        ++v32;
      if ( ((v30 >> 3) & 0x3FF & (((v30 >> 3) & 0x3FF) + 1)) != 0 )
        ++v32;
      v34 = 32 - v32;
      do
      {
        --v31;
        v35 = ((v30 >> 13) & 0x7FFF) + 1;
        do
          __mcr(15, 0, (--v35 << ((v30 & 7) + 4)) | (2 * j) | (v31 << v34), 7, 10, 2);
        while ( v35 );
      }
      while ( v31 );
    }
    __dsb(0xFu);
    __mcr(15, 0, 0, 7, 5, 0);
    __mcr(15, 0, 0, 7, 5, 6);
    __dsb(0xFu);
    __isb(0xFu);
    ((void (__fastcall *)(unsigned int, int, int (*)()))(v17 | 1))(v17 + 4, v51, KiRundownScbQueue);
    v36 = KfLowerIrql(v46);
    v37 = v54;
    if ( *v54 > 0 )
    {
      v52 = -*v54;
      *v54 = 0;
      (*(void (__fastcall **)(_DWORD, _DWORD))(v52 + 8))(*(_DWORD *)(v52 + 12), HIDWORD(v36));
      v38 = (_BYTE *)v52;
      v39 = 16;
      do
      {
        *v38++ = 0;
        --v39;
      }
      while ( v39 );
      v40 = &v52;
      v41 = 4;
      do
      {
        *(_BYTE *)v40 = 0;
        v40 = (int *)((char *)v40 + 1);
        --v41;
      }
      while ( v41 );
    }
    while ( 1 )
    {
      v42 = *v37;
      if ( *v37 )
        break;
      if ( (v10 & 1) != 0 )
        KeDelayExecutionThread(0, 0, (unsigned int *)&v55);
      else
        KeWaitForSingleObject((unsigned int)v6, 0, 0, 0, (int *)&v55);
    }
    v12 = v42 ^ v10;
    v43 = *(_DWORD *)(v42 + 16);
    *v37 = 0;
    v11 = v43 ^ v10;
    if ( (v10 & 1) != 0 )
      KeDelayExecutionThread(0, 0, (unsigned int *)&v55);
    else
      KeWaitForSingleObject((unsigned int)v6, 0, 0, 0, (int *)&v55);
  }
}
