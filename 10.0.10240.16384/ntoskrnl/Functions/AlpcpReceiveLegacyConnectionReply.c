// AlpcpReceiveLegacyConnectionReply 
 
int __fastcall AlpcpReceiveLegacyConnectionReply(int *a1, int a2, unsigned int *a3, int a4, int a5, _DWORD *a6)
{
  int v9; // r1
  int v10; // r4
  int v11; // r0
  int v12; // r5
  int v13; // r4
  int v14; // r9
  unsigned int *v15; // r8
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r1
  int v21; // r6
  unsigned int v22; // r3
  unsigned int v23; // r2
  int v24; // r1
  int v25; // r0
  int v26; // r9
  unsigned int *v27; // r8
  unsigned int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v33; // [sp+Ch] [bp-2Ch] BYREF
  _DWORD v34[10]; // [sp+10h] [bp-28h] BYREF

  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v33 = 0;
  v10 = *a1;
  v11 = AlpcpReceiveSynchronousReply(a1, v9, &v33, 0, 0);
  v12 = v11;
  if ( v11 )
  {
    if ( (*(_DWORD *)(v10 + 244) & 0x10) != 0 || v11 == -1073740031 )
      v12 = -1073741759;
    return v12;
  }
  if ( a4 )
  {
    v12 = AlpcpQueryRemoteView(v10, a4, v34);
    if ( v12 < 0 )
    {
      v13 = v33;
      if ( AlpcpMessageLogEnabled )
        AlpcpEnterStateChangeEventMessageLog(v33);
      v14 = 0;
      if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
      {
        v14 = 0x10000 - *(__int16 *)(v13 - 14);
        *(_BYTE *)(v13 - 16) &= 0xFEu;
        *(_WORD *)(v13 - 14) = 0;
      }
      v15 = (unsigned int *)(v13 - 4);
      __dmb(0xBu);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 - 1, v15) );
      if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v13 - 4));
      KeAbPostRelease(v13 - 4);
      if ( v14 > 0 )
      {
        __dmb(0xBu);
        v17 = (unsigned int *)(v13 - 12);
        do
        {
          v18 = __ldrex(v17);
          v19 = v18 - v14;
        }
        while ( __strex(v19, v17) );
        __dmb(0xBu);
        if ( v19 <= 0 )
        {
          if ( v19 )
            KeBugCheckEx(24, 0, v13, 40, v19);
LABEL_22:
          AlpcpDestroyBlob(v13);
          return v12;
        }
      }
      return v12;
    }
    *(_DWORD *)(a5 + 20) = v34[2];
  }
  v13 = v33;
  if ( a6 )
  {
    v20 = *(_DWORD *)(v33 + 76);
    if ( v20 )
    {
      *a6 = 12;
      a6[2] = *(_DWORD *)(v20 + 20);
      a6[1] = *(_DWORD *)(*(_DWORD *)(v20 + 8) + 20);
    }
  }
  if ( a2 )
  {
    v21 = 0;
    v22 = *(unsigned __int16 *)(v13 + 120);
    if ( *a3 >= v22 )
    {
      *a3 = v22;
    }
    else
    {
      v21 = *(unsigned __int16 *)(v13 + 120);
      *(_WORD *)(v13 + 120) = *a3;
    }
    if ( *(_DWORD *)(v13 + 88) )
    {
      AlpcpGetDataFromUserVaSafe(v13, a2);
    }
    else
    {
      v23 = *(unsigned __int16 *)(v13 + 120);
      v24 = v13 + 144;
      v25 = a2;
      if ( v23 > 0x100 )
      {
        memmove(a2, v24, 0x100u);
        v23 = *(unsigned __int16 *)(v13 + 120) - 256;
        v24 = *(_DWORD *)(v13 + 108);
        v25 = a2 + 256;
      }
      memmove(v25, v24, v23);
    }
    if ( v21 )
      *(_WORD *)(v13 + 120) = v21;
  }
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v13);
  v26 = 0;
  if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
  {
    v26 = 0x10000 - *(__int16 *)(v13 - 14);
    *(_BYTE *)(v13 - 16) &= 0xFEu;
    *(_WORD *)(v13 - 14) = 0;
  }
  v27 = (unsigned int *)(v13 - 4);
  __dmb(0xBu);
  do
    v28 = __ldrex(v27);
  while ( __strex(v28 - 1, v27) );
  if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v13 - 4));
  KeAbPostRelease(v13 - 4);
  if ( v26 > 0 )
  {
    __dmb(0xBu);
    v29 = (unsigned int *)(v13 - 12);
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 - v26;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( v31 <= 0 )
    {
      if ( v31 )
        KeBugCheckEx(24, 0, v13, 40, v31);
      goto LABEL_22;
    }
  }
  return v12;
}
