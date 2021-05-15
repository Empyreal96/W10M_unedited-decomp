// FsRtlInsertPerFileContextInternal 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlInsertPerFileContextInternal(unsigned int *a1, _QWORD *a2, int a3)
{
  unsigned int v6; // r4
  _DWORD *v7; // r0
  unsigned int v8; // r7
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  _DWORD *v14; // r2 OVERLAPPED
  int v15; // r1 OVERLAPPED
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3

  if ( !a1 )
    return -1073741808;
  __dmb(0xBu);
  do
    v6 = __ldrex(a1);
  while ( !v6 && __strex(0, a1) );
  __dmb(0xBu);
  if ( !v6 )
  {
    v7 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1667650374);
    v6 = (unsigned int)v7;
    if ( !v7 )
      return -1073741670;
    *v7 = 0;
    v7[1] = v7 + 1;
    v7[2] = v7 + 1;
    v7[3] = 0;
    __dmb(0xBu);
    do
      v8 = __ldrex(a1);
    while ( !v8 && __strex((unsigned int)v7, a1) );
    __dmb(0xBu);
    if ( v8 )
      return sub_5233B4();
  }
  if ( a3 )
  {
    *(_DWORD *)(v6 + 12) = a2;
  }
  else
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = KeAbPreAcquire(v6, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v13 | 1, (unsigned __int8 *)v6) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v6, v11, v6);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    v14 = (_DWORD *)(v6 + 4);
    v15 = *(_DWORD *)(v6 + 4);
    *a2 = *(_QWORD *)&v15;
    if ( *(_DWORD *)(v15 + 4) != v6 + 4 )
      __fastfail(3u);
    __pld((void *)v6);
    *(_DWORD *)(v15 + 4) = a2;
    *v14 = a2;
    v16 = *(_DWORD *)v6;
    if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
      v17 = 0;
    else
      v17 = v16 - 16;
    if ( (v16 & 2) != 0 )
      goto LABEL_33;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v6);
    while ( v18 == v16 && __strex(v17, (unsigned int *)v6) );
    if ( v18 != v16 )
LABEL_33:
      ExfReleasePushLock(v6);
    v19 = KeAbPostRelease(v6);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
  return 0;
}
