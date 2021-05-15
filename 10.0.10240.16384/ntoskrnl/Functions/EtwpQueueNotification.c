// EtwpQueueNotification 
 
int __fastcall EtwpQueueNotification(int a1, int a2, int a3)
{
  int v6; // r6
  int *v7; // r8
  _BYTE *v8; // r0
  _BYTE *v9; // r5
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3
  int v15; // r4
  int v16; // r4
  int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r2
  unsigned __int8 *v21; // r4
  int v22; // r0
  int v23; // r7
  unsigned int v24; // r2
  int *v25; // r2
  BOOL v26; // r0
  int **v27; // r1
  int v28; // r1
  unsigned int v29; // r0

  v6 = 0;
  v7 = (int *)EtwpAddDataSource();
  if ( !v7 )
    return -1073741801;
  v8 = (_BYTE *)ExAllocatePoolWithTag(512, 32, 1920431173);
  v9 = v8;
  if ( !v8 )
    return -1073741801;
  memset(v8, 0, 32);
  *((_DWORD *)v9 + 2) = a2;
  *((_DWORD *)v9 + 3) = a3;
  *((_WORD *)v9 + 12) = *(_WORD *)(a3 + 48);
  *((_DWORD *)v9 + 7) = 1;
  if ( !*(_BYTE *)(a2 + 12) )
    goto LABEL_15;
  v15 = *(_DWORD *)(a2 + 24);
  __dmb(0xBu);
  *((_DWORD *)v9 + 7) |= 2u;
  ObfReferenceObject(v15);
  *((_DWORD *)v9 + 4) = v15;
  v16 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( v16
    && (*(_DWORD *)(v16 + 744) & 0x1000) != 0
    && PspCheckConditionalWakeCharge(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v16, 3) )
  {
    PspChargeJobWakeCounter((_DWORD *)v16, 0, 3, 0, 1u, 0, 1, a1, a3);
    ObfReferenceObjectWithTag(v16);
    v17 = v16 | 3;
  }
  else
  {
    v17 = 0;
  }
  *((_DWORD *)v9 + 5) = v17;
  v6 = EtwpAddReplyIndex(a3, v9);
  if ( v6 >= 0 )
  {
LABEL_15:
    __dmb(0xBu);
    v18 = (unsigned int *)(a2 + 8);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 + 1, v18) );
    __dmb(0xBu);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v20 + 308);
    v21 = (unsigned __int8 *)(v7 + 1);
    v22 = KeAbPreAcquire((unsigned int)(v7 + 1), 0, 0);
    v23 = v22;
    do
      v24 = __ldrex(v21);
    while ( __strex(v24 | 1, v21) );
    __dmb(0xBu);
    if ( (v24 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v7 + 1, v22, (unsigned int)(v7 + 1));
    if ( v23 )
      *(_BYTE *)(v23 + 14) |= 1u;
    v25 = v7 + 2;
    v26 = v7[2] == (_DWORD)(v7 + 2);
    v27 = (int **)v7[3];
    *(_DWORD *)v9 = v25;
    *((_DWORD *)v9 + 1) = v27;
    if ( *v27 != v25 )
      __fastfail(3u);
    *v27 = (int *)v9;
    v7[3] = (int)v9;
    if ( v26 && *v7 )
      KeSetEvent(*v7, 1, 0);
    __pld(v21);
    v28 = *(_DWORD *)v21;
    if ( (*(_DWORD *)v21 & 0xFFFFFFF0) <= 0x10 )
      v29 = 0;
    else
      v29 = v28 - 16;
    if ( (v28 & 2) != 0 )
      goto LABEL_37;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)v21);
    while ( v10 == v28 && __strex(v29, (unsigned int *)v21) );
    if ( v10 != v28 )
LABEL_37:
      ExfReleasePushLock(v7 + 1, v28);
    v11 = KeAbPostRelease((unsigned int)(v7 + 1));
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(v11);
    return v6;
  }
  return sub_808570();
}
