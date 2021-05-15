// PspThreadDelete 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspThreadDelete(int a1)
{
  _DWORD *v1; // r7
  int v2; // r0
  int v3; // r2
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r3
  unsigned int v7; // r1 OVERLAPPED
  unsigned int v8; // r2 OVERLAPPED
  int v9; // r9
  int result; // r0
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r6
  unsigned __int64 v14; // kr08_8
  int v15; // r7
  int v16; // r0
  int v17; // r5
  int v18; // r9
  int v19; // lr
  unsigned int v20; // r1
  int *v21; // r0
  int v22; // r5
  int v23; // t1
  __int64 *v24; // r10
  char *v25; // r3
  int v26; // lr
  int v27; // r6
  char v28; // r7
  char v29; // r8
  __int64 v30; // kr28_8
  unsigned int v31; // r5
  __int64 v32; // kr30_8
  int v33; // r4
  unsigned int v34; // r2
  unsigned int v35; // t1
  unsigned int v36; // r5
  unsigned int v37; // kr38_4
  int v38; // r4
  unsigned int v39; // r2
  __int64 v40; // kr40_8
  unsigned int v41; // r9
  unsigned int v42; // r10
  unsigned __int64 v43; // r0
  __int64 v44; // r2
  unsigned __int8 *v45; // r5
  int v46; // r0
  int v47; // r4
  unsigned int v48; // r2
  unsigned __int8 *v49; // r4
  int v50; // r0
  int v51; // r6
  unsigned int v52; // r2
  __int64 v53; // r0
  unsigned int v54; // r1
  int v55; // r0
  int v56; // r3
  unsigned int v57; // [sp+8h] [bp-40h]
  int v59; // [sp+10h] [bp-38h]
  char v60; // [sp+14h] [bp-34h]
  char v61; // [sp+1Ch] [bp-2Ch]

  v1 = (_DWORD *)a1;
  v2 = KeCleanupThreadState(a1);
  if ( v1[262] )
    sub_7F6D00(v2);
  v3 = v1[250];
  if ( v3 )
    KeBugCheckEx(316, (int)v1, v3, 0, 0);
  if ( v1[8] )
    KeEnumerateKernelStackSegments((int)v1, (int (__fastcall *)(int, int *, int))PspDeleteKernelStack, 0);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v57 = v4;
  if ( v1[220] )
  {
    --*(_WORD *)(v4 + 308);
    if ( !ExMapHandleToPointer(PspCidTable, v1[220]) )
      KeBugCheck(23);
    v5 = ExDestroyHandle(PspCidTable, v1[220]);
    v6 = (__int16)(*(_WORD *)(v4 + 308) + 1);
    *(_WORD *)(v4 + 308) = v6;
    if ( !v6 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v5);
  }
  PspDeleteThreadSecurity(v1);
  do
  {
    *(_QWORD *)&v7 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v12 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v13 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v12 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v7 != MEMORY[0xFFFF93B0] || v8 != MEMORY[0xFFFF93B4] );
  v14 = __PAIR64__(v12, v13) - __PAIR64__(v8, v7);
  v15 = a1;
  result = qword_646260;
  if ( v14 >= qword_646260 )
  {
    v16 = dword_646254;
    v17 = dword_646250;
    v19 = unk_646224;
    v18 = dword_646220;
    if ( *(_QWORD *)&dword_646250 )
    {
      v20 = 0;
      v59 = unk_646224;
      if ( dword_646268 )
      {
        v21 = &ObpObjectTypes;
        do
        {
          v23 = *v21++;
          v22 = v23;
          if ( (((*((int *)&unk_646200 + (v20 >> 5) + 28) >> (v20 & 0x1F)) ^ (*(unsigned __int8 *)(v23 + 42) >> 6)) & 1) != 0
            && !(v18 | v19) )
          {
            v19 = 0;
            v18 = __ROR4__(-2147483516, 31);
            dword_646220 = v18;
            unk_646224 = 0;
            unk_646228 = 0;
            unk_64622C = 0;
            unk_646230 = 0;
            unk_646234 = 0;
            dword_646238 = 268;
            dword_64623C = 0;
            dword_646240 = v22;
            dword_646244 = 0;
          }
          ++v20;
        }
        while ( v20 < dword_646268 );
        v16 = dword_646254;
        v17 = dword_646250;
        v59 = v19;
      }
      v24 = (__int64 *)(dword_646290 + 88);
      v25 = (char *)(dword_646290 + 88);
      if ( dword_646290 + 88 < (unsigned int)(dword_646290 + 120) )
      {
        do
        {
          __pld(v25);
          v25 += 128;
        }
        while ( (unsigned int)v25 < dword_646290 + 120 );
      }
      v26 = 4;
      v27 = 32;
      v28 = 64 - (dword_646258 & 0x3F);
      v61 = v28;
      v60 = dword_646258 & 0x3F;
      v29 = dword_646258 & 0x3F;
      do
      {
        v30 = *v24++;
        v32 = __PAIR64__(v16, v17) - v30;
        v31 = (__PAIR64__(v16, v17) - v30) >> 32;
        v33 = __PAIR64__(v31, v32) << v28 >> 32;
        v34 = v31 >> v29;
        v17 = ((_DWORD)v32 << v28) | (__PAIR64__(v31, v32) >> v29);
        v27 -= 8;
        v16 = v33 | v34;
        --v26;
      }
      while ( v26 );
      v4 = v57;
      v15 = a1;
      v19 = v59;
      if ( v27 )
      {
        do
        {
          v35 = *(unsigned __int8 *)v24;
          v24 = (__int64 *)((char *)v24 + 1);
          v37 = v17 - v35;
          v36 = (__PAIR64__(v16, v17) - v35) >> 32;
          v38 = __PAIR64__(v36, v37) << v61 >> 32;
          v39 = v36 >> v60;
          v17 = (v37 << v61) | (__PAIR64__(v36, v37) >> v60);
          v16 = v38 | v39;
          --v27;
        }
        while ( v27 );
        v4 = v57;
        v15 = a1;
      }
      if ( *(_DWORD *)&algn_646294[4] != v17 || *(_DWORD *)&algn_646294[8] != v16 )
      {
        if ( v18 | v59 )
          goto LABEL_52;
        v19 = 0;
        v18 = __ROR4__(277872640, 20);
        dword_646220 = v18;
        unk_646224 = 0;
        unk_646228 = 0;
        unk_64622C = 0;
        unk_646230 = 0;
        unk_646234 = 0;
        dword_646238 = 268;
        dword_64623C = 0;
        dword_646240 = dword_646290;
        dword_646244 = 0;
      }
    }
    if ( !(v18 | v19) )
    {
      do
      {
LABEL_55:
        v40 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          v41 = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          v42 = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( v41 == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
      while ( v40 != MEMORY[0xFFFF93B0] );
      LODWORD(v43) = ReadTimeStampCounter();
      result = _rt_udiv64(80000000000i64, 41929663 * (v43 >> 4));
      qword_646260 = v44 - v40 + __PAIR64__(v41, v42) + 288000000000i64;
      goto LABEL_10;
    }
LABEL_52:
    if ( (void (__fastcall *)(int, int *))dword_64620C != sub_5C4694 )
      KeInitializeDpc((int)&unk_646200, (int)sub_5C4694, (int)&unk_646200);
    dword_646248 = 1829520;
    dword_64624C = 0;
    KeInsertQueueDpc((int)&unk_646200);
    goto LABEL_55;
  }
LABEL_10:
  v9 = *(_DWORD *)(v15 + 336);
  if ( v9 )
  {
    if ( *(_DWORD *)(v15 + 932) )
    {
      --*(_WORD *)(v4 + 308);
      v45 = (unsigned __int8 *)(v9 + 168);
      v46 = KeAbPreAcquire(v9 + 168, 0, 0);
      v47 = v46;
      do
        v48 = __ldrex(v45);
      while ( __strex(v48 | 1, v45) );
      __dmb(0xBu);
      if ( (v48 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 168), v46, v9 + 168);
      if ( v47 )
        *(_BYTE *)(v47 + 14) |= 1u;
      v49 = (unsigned __int8 *)(v9 + 720);
      v50 = KeAbPreAcquire(v9 + 720, 0, 0);
      v51 = v50;
      do
        v52 = __ldrex(v49);
      while ( __strex(v52 | 1, v49) );
      __dmb(0xBu);
      if ( (v52 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 720), v50, v9 + 720);
      if ( v51 )
        *(_BYTE *)(v51 + 14) |= 1u;
      KeFoldProcessStatisticsThread(v15);
      v53 = *(_QWORD *)(v15 + 932);
      if ( *(_DWORD *)(v53 + 4) != v15 + 932 || *(_DWORD *)HIDWORD(v53) != v15 + 932 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v53) = v53;
      *(_DWORD *)(v53 + 4) = HIDWORD(v53);
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)v49);
      while ( __strex(v11 - 1, (unsigned int *)v49) );
      if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v9 + 720));
      KeAbPostRelease(v9 + 720);
      __dmb(0xBu);
      do
        v54 = __ldrex((unsigned int *)v45);
      while ( __strex(v54 - 1, (unsigned int *)v45) );
      if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v9 + 168));
      v55 = KeAbPostRelease(v9 + 168);
      v56 = (__int16)(*(_WORD *)(v4 + 308) + 1);
      *(_WORD *)(v4 + 308) = v56;
      if ( !v56 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
        KiCheckForKernelApcDelivery(v55);
    }
    if ( *(_DWORD *)(v15 + 1072) )
      dword_61D9C8(v15);
    result = ObfDereferenceObjectWithTag(v9);
  }
  return result;
}
