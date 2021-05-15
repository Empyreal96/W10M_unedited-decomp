// ExCreateHandleTable 
 
int __fastcall ExCreateHandleTable(int a1, int a2)
{
  unsigned int v3; // r6
  int v4; // r0
  int v5; // r4
  int v7; // r0
  unsigned int v8; // r2
  void ***v9; // r0
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = ExpAllocateHandleTable(a1, 1);
  v5 = v4;
  if ( !v4 )
    return 0;
  if ( !a2 )
  {
    *(_DWORD *)(v4 + 16) = v4 + 16;
    *(_DWORD *)(v4 + 20) = v4 + 16;
    return v5;
  }
  --*(_WORD *)(v3 + 308);
  v7 = KeAbPreAcquire((unsigned int)&HandleTableListLock, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&HandleTableListLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&HandleTableListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
  {
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = (void ***)off_92039C;
    *(_DWORD *)(v5 + 16) = &HandleTableListHead;
    *(_DWORD *)(v5 + 20) = v9;
    if ( *v9 != &HandleTableListHead )
      __fastfail(3u);
    *v9 = (void **)(v5 + 16);
    off_92039C = (void *)(v5 + 16);
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&HandleTableListLock);
    while ( __strex(v10 - 1, (unsigned int *)&HandleTableListLock) );
    if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&HandleTableListLock);
    v11 = KeAbPostRelease((unsigned int)&HandleTableListLock);
    v12 = (__int16)(*(_WORD *)(v3 + 308) + 1);
    *(_WORD *)(v3 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
      KiCheckForKernelApcDelivery(v11);
    return v5;
  }
  return sub_7DDFCC(v7);
}
