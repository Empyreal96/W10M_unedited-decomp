// CmpInsertCallbackInListByAltitude 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpInsertCallbackInListByAltitude(int a1, int a2)
{
  int v4; // r7
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r5
  int v10; // r0
  int *v11; // r2 OVERLAPPED
  int v12; // r1 OVERLAPPED
  unsigned int v13; // r1
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&CmpCallbackListLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&CmpCallbackListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpCallbackListLock, v6, (unsigned int)&CmpCallbackListLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *(_QWORD *)(a1 + 16) = ++CmpCallbackCookie;
  v9 = CallbackListHead;
  if ( (int *)CallbackListHead != &CallbackListHead )
  {
    do
    {
      v10 = RtlCompareAltitudes((unsigned __int16 *)(v9 + 32), (unsigned __int16 *)(a1 + 32));
      if ( v10 )
      {
        if ( v10 < 0 )
          break;
      }
      else if ( !a2 )
      {
        goto LABEL_15;
      }
      v9 = *(_DWORD *)v9;
    }
    while ( (int *)v9 != &CallbackListHead );
    if ( !v10 && !a2 )
    {
LABEL_15:
      v4 = -1071906799;
      goto LABEL_21;
    }
  }
  v11 = *(int **)(v9 + 4);
  v12 = *v11;
  *(_QWORD *)a1 = *(_QWORD *)&v12;
  if ( *(int **)(v12 + 4) != v11 )
    __fastfail(3u);
  *(_DWORD *)(v12 + 4) = a1;
  *v11 = a1;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpCallBackCount);
  while ( __strex(v13 + 1, (unsigned int *)&CmpCallBackCount) );
  __dmb(0xBu);
LABEL_21:
  __pld(&CmpCallbackListLock);
  v14 = CmpCallbackListLock;
  v15 = CmpCallbackListLock - 16;
  if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v15 = 0;
  if ( (CmpCallbackListLock & 2) != 0 )
    goto LABEL_28;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&CmpCallbackListLock) );
  if ( v16 != v14 )
LABEL_28:
    ExfReleasePushLock(&CmpCallbackListLock, v14);
  v17 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v4;
}
