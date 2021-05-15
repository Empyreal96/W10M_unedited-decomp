// CmpFreeCallbackObjectContexts 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall CmpFreeCallbackObjectContexts(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  __int64 v7; // r0
  __int64 v8; // r2
  __int64 v9; // kr00_8
  int **v10; // r5
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int result; // r0
  int *v18; // r1 OVERLAPPED
  int *v19; // [sp+0h] [bp-18h] BYREF
  int **v20; // [sp+4h] [bp-14h]

  v20 = &v19;
  v19 = (int *)&v19;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&CmpContextListLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&CmpContextListLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpContextListLock, v4, (unsigned int)&CmpContextListLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  LODWORD(v7) = a1 + 36;
  while ( *(_DWORD *)v7 != (_DWORD)v7 )
  {
    HIDWORD(v7) = *(_DWORD *)v7;
    v8 = *(_QWORD *)*(_DWORD *)v7;
    if ( __PAIR64__(*(_DWORD *)(v8 + 4), HIDWORD(v8)) != v7 )
      __fastfail(3u);
    *(_DWORD *)v7 = v8;
    *(_DWORD *)(v8 + 4) = v7;
    v9 = *(_QWORD *)(HIDWORD(v7) + 8);
    if ( *(_DWORD *)(v9 + 4) != HIDWORD(v7) + 8 || *(_DWORD *)HIDWORD(v9) != HIDWORD(v7) + 8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v9) = v9;
    *(_DWORD *)(v9 + 4) = HIDWORD(v9);
    v10 = v20;
    if ( HIDWORD(v9) == (_DWORD)v9 )
      v2 = 1;
    *(_DWORD *)HIDWORD(v7) = &v19;
    *(_DWORD *)(HIDWORD(v7) + 4) = v10;
    if ( *v10 != (int *)&v19 )
      __fastfail(3u);
    *v10 = (int *)HIDWORD(v7);
    v20 = (int **)HIDWORD(v7);
  }
  __pld(&CmpContextListLock);
  v11 = CmpContextListLock;
  v12 = CmpContextListLock - 16;
  if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
    v12 = 0;
  if ( (CmpContextListLock & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpContextListLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&CmpContextListLock) );
  if ( v13 != v11 )
LABEL_26:
    ExfReleasePushLock(&CmpContextListLock, v11);
  v14 = KeAbPostRelease((unsigned int)&CmpContextListLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  if ( v2 )
  {
    __dmb(0xFu);
    if ( CallbackListDeleteEvent )
      ExfUnblockPushLock((int)&CallbackListDeleteEvent, 0);
  }
  while ( 1 )
  {
    result = (unsigned int)v19;
    if ( v19 == (int *)&v19 )
      break;
    *(_QWORD *)&v18 = *(_QWORD *)v19;
    if ( (int **)v19[1] != &v19 || (int *)v18[1] != v19 )
      __fastfail(3u);
    v19 = v18;
    v18[1] = (int)&v19;
    ExFreePoolWithTag(result);
  }
  return result;
}
