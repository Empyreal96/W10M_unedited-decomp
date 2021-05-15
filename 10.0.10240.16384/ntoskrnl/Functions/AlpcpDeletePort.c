// AlpcpDeletePort 
 
int __fastcall AlpcpDeletePort(int a1)
{
  unsigned int v2; // r2
  int result; // r0
  int v4; // r3
  unsigned __int8 *v5; // r6
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r3
  unsigned int *v11; // r5
  unsigned int v12; // r1
  int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r1
  int v17; // r0
  int v18; // r2
  int v19; // r0
  int v20; // r0
  unsigned int *v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  if ( (*(_DWORD *)(a1 + 152) & 0x1000) != 0 )
    return sub_806D48();
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 )
  {
    v5 = (unsigned __int8 *)(v4 - 4);
    v6 = KeAbPreAcquire(v4 - 4, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v5);
    while ( __strex(v8 | 1, v5) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v5, v6, (unsigned int)v5);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = (*(_DWORD *)(a1 + 244) >> 1) & 3;
    switch ( v9 )
    {
      case 1:
        **(_DWORD **)(a1 + 8) = 0;
        break;
      case 2:
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = 0;
        v10 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4);
LABEL_14:
        if ( v10 )
        {
          *(_DWORD *)(v10 + 248) = 0;
          *(_DWORD *)(v10 + 252) = 0;
        }
        break;
      case 3:
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) = 0;
        v10 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
        goto LABEL_14;
    }
    v11 = (unsigned int *)(*(_DWORD *)(a1 + 8) - 4);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock(v11);
    KeAbPostRelease((unsigned int)v11);
    v13 = *(_DWORD *)(a1 + 8);
    __dmb(0xBu);
    v14 = (unsigned int *)(v13 - 12);
    do
    {
      v15 = __ldrex(v14);
      v16 = v15 - 1;
    }
    while ( __strex(v16, v14) );
    __dmb(0xBu);
    if ( v16 <= 0 )
    {
      if ( v16 )
        KeBugCheckEx(24, 0, v13, 33, v16);
      AlpcpDestroyBlob(v13);
    }
    *(_DWORD *)(a1 + 8) = 0;
  }
  v17 = *(_DWORD *)(a1 + 16);
  if ( v17 )
  {
    ObfDereferenceObject(v17);
    AlpcpFreeCompletionPacketLookaside(*(unsigned int **)(a1 + 24), v26, v27, v28);
  }
  v18 = *(_DWORD *)(a1 + 244);
  if ( (v18 & 6) == 4 && (v18 & 0x400) == 0 )
  {
    v25 = *(_DWORD *)(a1 + 44);
    if ( v25 )
      ObfDereferenceObject(v25);
  }
  v19 = *(_DWORD *)(a1 + 12);
  if ( (v19 & 1) == 0 && v19 )
  {
    if ( (v19 & 1) != 0 )
      v19 = 0;
    ObfDereferenceObjectWithTag(v19);
  }
  v20 = *(_DWORD *)(a1 + 216);
  if ( v20 )
    ObfDereferenceObject(v20);
  __dmb(0xBu);
  v21 = (unsigned int *)(a1 + 256);
  do
    v22 = __ldrex(v21);
  while ( __strex(0, v21) );
  __dmb(0xBu);
  if ( v22 )
  {
    __dmb(0xBu);
    v29 = (unsigned int *)(v22 - 12);
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 - 1;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( v31 <= 0 )
    {
      if ( v31 )
        KeBugCheckEx(24, 0, v22, 33, v31);
      AlpcpDestroyBlob(v22);
    }
  }
  result = AlpcpDestroyPort(a1);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
