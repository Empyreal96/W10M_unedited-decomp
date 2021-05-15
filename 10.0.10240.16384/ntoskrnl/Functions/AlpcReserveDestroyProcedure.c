// AlpcReserveDestroyProcedure 
 
int __fastcall AlpcReserveDestroyProcedure(int *a1)
{
  int v2; // r4
  unsigned __int8 *v3; // r8
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *v7; // r1
  unsigned int v8; // r2
  int v9; // r2
  char v10; // r2
  int v11; // r8
  int v12; // r3
  unsigned int *v13; // r7
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r3
  unsigned __int8 *v20; // r6
  int *v21; // r4
  int v22; // r0
  int v23; // r7
  unsigned int v24; // r2
  int *v25; // r2
  unsigned int v26; // r1
  int **v27; // r1

  v2 = a1[3];
  if ( v2 )
  {
    v3 = (unsigned __int8 *)(v2 - 4);
    v4 = KeAbPreAcquire(v2 - 4, 0, 0);
    do
      v5 = __ldrex(v3);
    while ( __strex(v5 | 1, v3) );
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
      return sub_7EA374(v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    *(_BYTE *)(v2 - 16) |= 1u;
    __dmb(0xBu);
    v7 = (unsigned int *)(v2 - 12);
    do
    {
      v8 = __ldrex(v7);
      v9 = v8 + 0x10000;
    }
    while ( __strex(v9, v7) );
    __dmb(0xBu);
    if ( v9 <= 0 )
      KeBugCheckEx(24, 0, v2, 38, v9);
    *(_DWORD *)(v2 + 52) = 0;
    a1[3] = 0;
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v2);
    v10 = *(_BYTE *)(v2 - 16);
    v11 = 0;
    if ( (v10 & 1) != 0 )
    {
      v12 = *(__int16 *)(v2 - 14);
      *(_WORD *)(v2 - 14) = 0;
      v11 = 0x10000 - v12;
      *(_BYTE *)(v2 - 16) = v10 & 0xFE;
    }
    v13 = (unsigned int *)(v2 - 4);
    __dmb(0xBu);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 - 1, v13) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v2 - 4));
    KeAbPostRelease(v2 - 4);
    if ( v11 > 0 )
    {
      __dmb(0xBu);
      v15 = (unsigned int *)(v2 - 12);
      do
      {
        v16 = __ldrex(v15);
        v17 = v16 - v11;
      }
      while ( __strex(v17, v15) );
      __dmb(0xBu);
      if ( v17 <= 0 )
      {
        if ( v17 )
          KeBugCheckEx(24, 0, v2, 40, v17);
        AlpcpDestroyBlob(v2);
      }
    }
  }
  v18 = a1[1];
  if ( v18 )
    AlpcDeleteBlobByHandle(v18, a1[2], a1);
  v19 = *a1;
  if ( *a1 )
  {
    v20 = (unsigned __int8 *)(v19 + 196);
    v21 = a1 - 6;
    v22 = KeAbPreAcquire(v19 + 196, 0, 0);
    v23 = v22;
    do
      v24 = __ldrex(v20);
    while ( __strex(v24 | 1, v20) );
    __dmb(0xBu);
    if ( (v24 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v20, v22, (unsigned int)v20);
    if ( v23 )
      *(_BYTE *)(v23 + 14) |= 1u;
    v25 = (int *)*v21;
    if ( (int *)*v21 != v21 )
    {
      v27 = (int **)*(a1 - 5);
      if ( (int *)v25[1] != v21 || *v27 != v21 )
        __fastfail(3u);
      *v27 = v25;
      v25[1] = (int)v27;
      *v21 = (int)v21;
      *(a1 - 5) = (int)(a1 - 6);
    }
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)v20);
    while ( __strex(v26 - 1, (unsigned int *)v20) );
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v20);
    KeAbPostRelease((unsigned int)v20);
    ObfDereferenceObject(*a1);
  }
  return 0;
}
