// sub_8111F8 
 
void sub_8111F8()
{
  unsigned int v0; // r2
  int v1; // r1
  _DWORD *v2; // r0
  unsigned int v4; // r2
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  void (__fastcall *v9)(_DWORD, void *); // r3
  unsigned int *v10; // r2
  unsigned int v11; // r1
  void (__fastcall *v12)(int, void *); // r3
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  unsigned __int16 *v20; // r6
  void ***v21; // r8
  unsigned int v22; // r1
  int v23; // r0
  int v24; // r4
  unsigned int v25; // r2
  void **v26; // r4
  unsigned int v27; // r2
  _DWORD *v28; // r2
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3

  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v22 + 308);
  v23 = KeAbPreAcquire((unsigned int)&ExpHostListLock, 0, 0);
  v24 = v23;
  do
    v25 = __ldrex((unsigned int *)&ExpHostListLock);
  while ( !v25 && __strex(0x11u, (unsigned int *)&ExpHostListLock) );
  __dmb(0xBu);
  if ( v25 )
    ExfAcquirePushLockSharedEx(&ExpHostListLock, v23, (unsigned int)&ExpHostListLock);
  if ( v24 )
    *(_BYTE *)(v24 + 14) |= 1u;
  v26 = ExpFindHost(*v20, v20[1]);
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)&ExpHostListLock);
  while ( v27 == 17 && __strex(0, (unsigned int *)&ExpHostListLock) );
  if ( v27 != 17 )
    ExfReleasePushLockShared(&ExpHostListLock);
  v17 = KeAbPostRelease((unsigned int)&ExpHostListLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = (__int16)(*(_WORD *)(v18 + 0x134) + 1);
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  if ( v26 )
  {
    v0 = v20[2];
    if ( v0 >= *((unsigned __int16 *)v26 + 8) )
    {
      v1 = 0;
      if ( v20[2] )
      {
        v2 = (_DWORD *)*((_DWORD *)v20 + 2);
        do
        {
          if ( !*v2++ )
            goto LABEL_35;
        }
        while ( ++v1 < v0 );
      }
      v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v4 + 308);
      v5 = (unsigned __int8 *)(v26 + 10);
      v6 = KeAbPreAcquire((unsigned int)(v26 + 10), 0, 0);
      v7 = v6;
      do
        v8 = __ldrex(v5);
      while ( __strex(v8 | 1, v5) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v26 + 10, v6, (unsigned int)(v26 + 10));
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      if ( !v26[11] && ((_BYTE)v26[12] & 1) == 0 )
      {
        v9 = (void (__fastcall *)(_DWORD, void *))v26[7];
        if ( v9 )
          v9(0, v26[8]);
        v26[11] = (void *)*((_DWORD *)v20 + 2);
        __dmb(0xBu);
        v10 = (unsigned int *)(v26 + 9);
        do
          v11 = __ldrex(v10);
        while ( __strex(0, v10) );
        __dmb(0xBu);
        v12 = (void (__fastcall *)(int, void *))v26[7];
        if ( v12 )
          v12(1, v26[8]);
        __dmb(0xBu);
        do
          v13 = __ldrex((unsigned int *)v5);
        while ( __strex(v13 - 1, (unsigned int *)v5) );
        if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v26 + 10);
        v14 = KeAbPostRelease((unsigned int)(v26 + 10));
        v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
        *(_WORD *)(v15 + 308) = v16;
        if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
          KiCheckForKernelApcDelivery(v14);
        v28 = (_DWORD *)*((_DWORD *)v20 + 3);
        if ( v28 )
          *v28 = v26[6];
        *v21 = v26;
        goto LABEL_65;
      }
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)v5);
      while ( __strex(v29 - 1, (unsigned int *)v5) );
      if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v26 + 10);
      v30 = KeAbPostRelease((unsigned int)(v26 + 10));
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v32 = *(_WORD *)(v31 + 0x134) + 1;
      *(_WORD *)(v31 + 308) = v32;
      if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
        KiCheckForKernelApcDelivery(v30);
    }
LABEL_35:
    ExpDereferenceHost(v26);
  }
LABEL_65:
  JUMPOUT(0x79F244);
}
