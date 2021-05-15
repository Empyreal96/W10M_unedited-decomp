// EtwpUnreferenceGuidEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpUnreferenceGuidEntry(int a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r5
  signed int v4; // r5
  char *v6; // r1
  unsigned int v7; // r2
  unsigned __int8 *v8; // r7
  int v9; // r0
  unsigned int v10; // r2
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 8);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( v4 )
  {
    if ( v4 < 0 )
      KeBugCheckEx(285, 9, a1, 0, 0);
    return v4;
  }
  v6 = (char *)&EtwpGuidHashTable
     + 28
     * (((unsigned __int8)*(_DWORD *)(a1 + 12) ^ (unsigned __int8)(*(_DWORD *)(a1 + 24) ^ *(_QWORD *)(a1 + 20) ^ *(_DWORD *)(a1 + 16))) & 0x3F);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned __int8 *)(v6 + 24);
  v9 = KeAbPreAcquire((unsigned int)(v6 + 24), 0, 0);
  do
    v10 = __ldrex(v8);
  while ( __strex(v10 | 1, v8) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
  {
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    *(_QWORD *)&v11 = *(_QWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v12 != a1 )
      __fastfail(3u);
    *v12 = v11;
    *(_DWORD *)(v11 + 4) = v12;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v8);
    while ( __strex(v13 - 1, (unsigned int *)v8) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v8);
    v14 = KeAbPostRelease((unsigned int)v8);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
    EtwpFreeGuidEntry(a1);
    return v4;
  }
  return sub_7C50A8(v9);
}
