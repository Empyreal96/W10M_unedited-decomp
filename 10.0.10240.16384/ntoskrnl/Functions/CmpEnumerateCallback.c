// CmpEnumerateCallback 
 
int __fastcall CmpEnumerateCallback(int ***a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int **v6; // r3
  int **v7; // r5
  int *v8; // r0
  int v9; // r6
  int v10; // r3
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&CmpCallbackListLock) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(&CmpCallbackListLock, v3, (unsigned int)&CmpCallbackListLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = *a1;
  if ( *a1 )
  {
    v7 = *a1;
  }
  else
  {
    v6 = (int **)&CallbackListHead;
    v7 = 0;
  }
  v8 = *v6;
  v9 = 0;
  while ( v8 != &CallbackListHead )
  {
    v10 = v8[2];
    __dmb(0xBu);
    if ( (v10 & 0x80000000) == 0 )
    {
      __dmb(0xBu);
      v11 = (unsigned int *)(v8 + 2);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 + 1, v11) );
      __dmb(0xBu);
      v9 = v8[7];
      *a1 = (int **)v8;
      break;
    }
    v8 = (int *)*v8;
  }
  __pld(&CmpCallbackListLock);
  v13 = CmpCallbackListLock;
  v14 = CmpCallbackListLock - 16;
  if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  if ( (CmpCallbackListLock & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpCallbackListLock) );
  if ( v15 != v13 )
LABEL_26:
    ExfReleasePushLock(&CmpCallbackListLock, v13);
  v16 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  if ( v7 )
  {
    __dmb(0xBu);
    v19 = (unsigned int *)(v7 + 2);
    do
    {
      v20 = __ldrex(v19);
      v21 = v20 - 1;
    }
    while ( __strex(v21, v19) );
    __dmb(0xBu);
    if ( v21 == 0x80000000 )
    {
      __dmb(0xFu);
      if ( CallbackListDeleteEvent )
        ExfUnblockPushLock((int)&CallbackListDeleteEvent, 0);
    }
  }
  return v9;
}
