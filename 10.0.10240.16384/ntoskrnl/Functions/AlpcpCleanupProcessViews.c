// AlpcpCleanupProcessViews 
 
int __fastcall AlpcpCleanupProcessViews(int a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v6; // r1
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  int v10; // r3
  int v11; // r5
  int v12; // r6
  bool v13; // zf
  unsigned int *v14; // r7
  int v15; // r0
  int v16; // r1
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r1
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 656);
  v4 = KeAbPreAcquire(a1 + 656, 0, 0);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7C07DC(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  while ( *(_DWORD *)(a1 + 660) != a1 + 660 )
  {
    v10 = *(_DWORD *)(a1 + 660);
    v11 = v10 - 44;
    v12 = *(_DWORD *)(v10 - 56);
    v13 = v12 == 0;
    if ( v12 <= 0 )
    {
LABEL_26:
      if ( !v13 )
        KeBugCheckEx(24, 0, v11, 32, v12);
LABEL_29:
      v11 = 0;
      goto LABEL_30;
    }
    v14 = (unsigned int *)(v10 - 56);
    while ( 1 )
    {
      v15 = v12;
      __dmb(0xBu);
      do
        v16 = __ldrex(v14);
      while ( v16 == v12 && __strex(v12 + 1, v14) );
      v12 = v16;
      __dmb(0xBu);
      if ( v16 == v15 )
        break;
      if ( v16 <= 0 )
      {
        v13 = v16 == 0;
        goto LABEL_26;
      }
    }
    if ( v16 == -1 )
      goto LABEL_29;
LABEL_30:
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v3);
    while ( __strex(v17 - 1, (unsigned int *)v3) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v3);
    KeAbPostRelease((unsigned int)v3);
    if ( v11 )
    {
      AlpcpForceUnlinkSecureView(v11);
      __dmb(0xBu);
      v18 = (unsigned int *)(v11 - 12);
      do
      {
        v19 = __ldrex(v18);
        v20 = v19 - 1;
      }
      while ( __strex(v20, v18) );
      __dmb(0xBu);
      if ( v20 <= 0 )
      {
        if ( v20 )
          KeBugCheckEx(24, 0, v11, 33, v20);
        AlpcpDestroyBlob(v11);
      }
    }
    v21 = KeAbPreAcquire((unsigned int)v3, 0, 0);
    v22 = v21;
    do
      v23 = __ldrex(v3);
    while ( __strex(v23 | 1, v3) );
    __dmb(0xBu);
    if ( (v23 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v3, v21, (unsigned int)v3);
    if ( v22 )
      *(_BYTE *)(v22 + 14) |= 1u;
  }
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)v3);
  while ( __strex(v6 - 1, (unsigned int *)v3) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  result = KeAbPostRelease((unsigned int)v3);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
