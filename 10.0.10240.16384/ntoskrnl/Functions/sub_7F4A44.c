// sub_7F4A44 
 
void __fastcall sub_7F4A44(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // r8
  int v7; // r9
  unsigned __int8 *v8; // r4
  unsigned __int16 v9; // r0
  int v10; // r5
  int v11; // r0
  unsigned int v12; // r6
  _WORD *v13; // r2
  int v14; // t1
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r4
  unsigned int v21; // r1
  int v22; // r0
  __int16 v23; // r3

  v8 = (unsigned __int8 *)PsGetProcessImageFileName(v7);
  v9 = (unsigned __int16)strlen((unsigned int)v8);
  v10 = (unsigned __int16)(2 * v9);
  if ( 2 * v9 )
  {
    v11 = ExAllocatePoolWithTag(1, v10 + 2, 1951556175);
    v12 = v11;
    a6 = v11;
    if ( !v11 )
      JUMPOUT(0x7150D4);
    LOWORD(a5) = v10;
    HIWORD(a5) = v10 + 2;
    v13 = (_WORD *)v11;
    do
    {
      v14 = *v8++;
      *v13++ = v14;
    }
    while ( v14 );
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v15 + 310);
    v16 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
    v17 = v16;
    do
      v18 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
    while ( __strex(v18 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v16, (unsigned int)&ObpStackTraceLock);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    if ( (*v6 & 0x20) != 0
      && RtlPrefixUnicodeString((unsigned __int16 *)&a5, (unsigned __int16 *)ObpTraceProcessName, 1) )
    {
      __dmb(0xBu);
      v19 = (unsigned int *)(v7 + 188);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x200, v19) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&ObpStackTraceLock);
    while ( __strex(v21 - 1, (unsigned int *)&ObpStackTraceLock) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
    KeAbPostRelease((unsigned int)&ObpStackTraceLock);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x136) + 1;
    *(_WORD *)(v22 + 310) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 )
      KiCheckForKernelApcDelivery(v22);
    ExFreePoolWithTag(v12);
  }
  JUMPOUT(0x7150D2);
}
