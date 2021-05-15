// AlpcConnectionDestroyProcedure 
 
int __fastcall AlpcConnectionDestroyProcedure(int a1)
{
  int v2; // r7
  unsigned __int8 *v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v7; // r1
  unsigned int *v8; // r5
  unsigned int v9; // r1
  unsigned int *v10; // r2
  int v11; // r0
  unsigned __int8 *v12; // r6
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  __int64 v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r1

  v2 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 )
  {
    v3 = (unsigned __int8 *)(*(_DWORD *)(v2 + 8) - 4);
    v4 = KeAbPreAcquire((unsigned int)v3, 0, 0);
    do
      v5 = __ldrex(v3);
    while ( __strex(v5 | 1, v3) );
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
      return sub_806B40(v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    v12 = (unsigned __int8 *)(v2 + 208);
    v13 = KeAbPreAcquire(v2 + 208, 0, 0);
    v14 = v13;
    do
      v15 = __ldrex(v12);
    while ( __strex(v15 | 1, v12) );
    __dmb(0xBu);
    if ( (v15 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 208), v13, v2 + 208);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    v16 = *(_QWORD *)(a1 + 12);
    if ( *(_DWORD *)(v16 + 4) != a1 + 12 || *(_DWORD *)HIDWORD(v16) != a1 + 12 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v16) = v16;
    *(_DWORD *)(v16 + 4) = HIDWORD(v16);
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)v12);
    while ( __strex(v7 - 1, (unsigned int *)v12) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v2 + 208));
    KeAbPostRelease(v2 + 208);
    v8 = (unsigned int *)(*(_DWORD *)(v2 + 8) - 4);
    __dmb(0xBu);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 - 1, v8) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock(v8);
    KeAbPostRelease((unsigned int)v8);
    ObfDereferenceObject(*(_DWORD *)a1);
  }
  if ( *(_DWORD *)(a1 + 20) )
  {
    if ( *(_DWORD *)(a1 + 24) == 16 )
      ExFreeToPagedLookasideList((int)&unk_643600, *(_DWORD **)(a1 + 20));
    else
      ExFreePoolWithTag(*(_DWORD *)(a1 + 20));
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 36);
  do
    v11 = __ldrex(v10);
  while ( __strex(0, v10) );
  __dmb(0xBu);
  if ( v11 )
  {
    __dmb(0xBu);
    v17 = (unsigned int *)(v11 - 12);
    do
    {
      v18 = __ldrex(v17);
      v19 = v18 - 1;
    }
    while ( __strex(v19, v17) );
    __dmb(0xBu);
    if ( v19 <= 0 )
    {
      if ( v19 )
        KeBugCheckEx(24, 0, v11, 33, v19);
      AlpcpDestroyBlob(v11);
    }
  }
  return 0;
}
