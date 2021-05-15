// EtwpReceiveNotification 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpReceiveNotification(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  int v6; // r5
  int v7; // r7
  unsigned int v9; // r4
  unsigned __int8 *v10; // r4
  int v11; // r0
  unsigned int v12; // r2
  __int64 **v13; // r2 OVERLAPPED
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r4
  unsigned int v20; // r4
  int v21; // r7
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  __int64 *v28; // r6
  __int64 v29; // kr00_8
  __int64 *v30; // r1 OVERLAPPED
  BOOL v31; // r8
  int v32; // r3
  int v33; // r1
  unsigned int v34; // r0

  v6 = 0;
  v7 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 348);
  if ( !v7 || (v7 & 1) != 0 )
    return -1073741811;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = (unsigned __int8 *)(v7 + 4);
  v11 = KeAbPreAcquire(v7 + 4, 0, 0);
  do
    v12 = __ldrex(v10);
  while ( __strex(v12 | 1, v10) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
  {
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = (__int64 **)(v7 + 8);
    if ( *(_DWORD *)(v7 + 8) == v7 + 8 )
    {
      __pld(v10);
      v22 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
        v23 = 0;
      else
        v23 = v22 - 16;
      if ( (v22 & 2) != 0 )
        goto LABEL_38;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)v10);
      while ( v24 == v22 && __strex(v23, (unsigned int *)v10) );
      if ( v24 != v22 )
LABEL_38:
        ExfReleasePushLock((_DWORD *)(v7 + 4), v22);
      v25 = KeAbPostRelease(v7 + 4);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x134) + 1;
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
      v6 = -2147483622;
    }
    else
    {
      v28 = *v13;
      v29 = **v13;
      if ( (__int64 **)HIDWORD(v29) != v13 || *(__int64 **)(v29 + 4) != v28 )
        __fastfail(3u);
      *v13 = (__int64 *)v29;
      *(_DWORD *)(v29 + 4) = v13;
      v21 = *((_DWORD *)v28 + 2);
      if ( *(_DWORD *)(v21 + 4) > a2 )
      {
        v30 = *v13;
        *v28 = *(_QWORD *)(&v13 - 1);
        if ( *((__int64 ***)v30 + 1) != v13 )
          __fastfail(3u);
        v6 = -1073741789;
        *((_DWORD *)v30 + 1) = v28;
        *v13 = v28;
      }
      v31 = *v13 != (__int64 *)v13;
      v32 = *(_DWORD *)(v21 + 4);
      __pld(v10);
      *a3 = v32;
      v33 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
        v34 = 0;
      else
        v34 = v33 - 16;
      if ( (v33 & 2) != 0 )
        goto LABEL_54;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)v10);
      while ( v14 == v33 && __strex(v34, (unsigned int *)v10) );
      if ( v14 != v33 )
LABEL_54:
        ExfReleasePushLock(v10, v33);
      v15 = KeAbPostRelease((unsigned int)v10);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = *(_WORD *)(v16 + 0x134) + 1;
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
      if ( v6 >= 0 )
      {
        __dmb(0xBu);
        v18 = (unsigned int *)(v21 + 20);
        do
        {
          v19 = __ldrex(v18);
          v20 = v19 + 1;
        }
        while ( __strex(v20, v18) );
        __dmb(0xBu);
        memmove((int)a1, v21, *(_DWORD *)(v21 + 4));
        a1[5] = v20;
        a1[6] = *((unsigned __int16 *)v28 + 12);
        if ( *(_BYTE *)(v21 + 12) == 1 )
          a1[4] = *((unsigned __int16 *)v28 + 13);
        EtwpUnreferenceDataBlock(v21);
        EtwpReleaseQueueEntry(v28, 1);
        if ( v31 )
          v6 = 261;
      }
    }
    return v6;
  }
  return sub_8083B4(v11);
}
