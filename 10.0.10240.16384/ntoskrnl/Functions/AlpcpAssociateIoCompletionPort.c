// AlpcpAssociateIoCompletionPort 
 
int __fastcall AlpcpAssociateIoCompletionPort(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned __int8 *v8; // r4
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r6
  int v18; // r3
  int v19; // r0
  int v20; // r0
  unsigned __int8 *v21; // r6
  int v22; // r0
  int v23; // r7
  unsigned int v24; // r2
  _DWORD *i; // r7
  unsigned int v26; // r1
  unsigned int v27; // r1
  unsigned int v28; // r1
  unsigned int v29; // r1
  int v30; // r0
  unsigned int *v31; // r0
  int v32[8]; // [sp+8h] [bp-20h] BYREF

  v32[0] = a4;
  if ( !a2 )
    return sub_7F780C();
  v8 = (unsigned __int8 *)(a1 + 52);
  v9 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v9, (unsigned int)v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( a1[4] )
  {
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)v8);
    while ( __strex(v28 - 1, (unsigned int *)v8) );
    if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v8);
    KeAbPostRelease((unsigned int)v8);
    return -1073741752;
  }
  if ( a1[53] )
  {
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)v8);
    while ( __strex(v29 - 1, (unsigned int *)v8) );
    if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v8);
    KeAbPostRelease((unsigned int)v8);
    return -1073741637;
  }
  v12 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v13 = ObReferenceObjectByHandle(a2, 2, IoCompletionObjectType, v12, v32);
  v16 = v32[0];
  v17 = v13;
  a1[4] = v32[0];
  if ( v13 < 0 )
    goto LABEL_47;
  v18 = a1[53];
  a1[5] = a3;
  if ( v18 )
    v19 = *(_DWORD *)(v18 + 48) >> 2;
  else
    v19 = 1;
  v20 = AlpcpAllocateCompletionPacketLookaside(v19);
  a1[6] = v20;
  if ( !v20 )
  {
    v17 = -1073741670;
LABEL_47:
    v30 = a1[4];
    if ( v30 )
    {
      ObfDereferenceObject(v30);
      a1[4] = 0;
    }
    v31 = (unsigned int *)a1[6];
    if ( v31 )
    {
      AlpcpFreeCompletionPacketLookaside(v31, v16, v14, v15);
      a1[6] = 0;
    }
    goto LABEL_28;
  }
  v21 = (unsigned __int8 *)(a1 + 23);
  v22 = KeAbPreAcquire((unsigned int)(a1 + 23), 0, 0);
  v23 = v22;
  do
    v24 = __ldrex(v21);
  while ( __strex(v24 | 1, v21) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 23, v22, (unsigned int)(a1 + 23));
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  for ( i = (_DWORD *)a1[24]; i != a1 + 24; i = (_DWORD *)*i )
    AlpcpQueueIoCompletionPort(a1, 0, 0);
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)v21);
  while ( __strex(v26 - 1, (unsigned int *)v21) );
  if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v21);
  KeAbPostRelease((unsigned int)v21);
  v17 = 0;
LABEL_28:
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)v8);
  while ( __strex(v27 - 1, (unsigned int *)v8) );
  if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v8);
  KeAbPostRelease((unsigned int)v8);
  return v17;
}
