// AlpcRegionDestroyProcedure 
 
int __fastcall AlpcRegionDestroyProcedure(int a1)
{
  int v1; // r4
  unsigned __int8 *v3; // r7
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *v7; // r1
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r7
  unsigned int *v11; // r6
  unsigned int v12; // r1
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r1

  v1 = *(_DWORD *)(a1 + 8);
  v3 = (unsigned __int8 *)(v1 - 4);
  v4 = KeAbPreAcquire(v1 - 4, 0, 0);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7E7D88(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_BYTE *)(v1 - 16) |= 1u;
  __dmb(0xBu);
  v7 = (unsigned int *)(v1 - 12);
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 + 0x10000;
  }
  while ( __strex(v9, v7) );
  __dmb(0xBu);
  if ( v9 <= 0 )
    KeBugCheckEx(24, 0, v1, 38, v9);
  v10 = 0;
  **(_DWORD **)(a1 + 4) = *(_DWORD *)a1;
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4);
  --*(_DWORD *)(v1 + 28);
  if ( (*(_BYTE *)(v1 - 16) & 1) != 0 )
  {
    v10 = 0x10000 - *(__int16 *)(v1 - 14);
    *(_BYTE *)(v1 - 16) &= 0xFEu;
    *(_WORD *)(v1 - 14) = 0;
  }
  v11 = (unsigned int *)(v1 - 4);
  __dmb(0xBu);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 - 1, v11) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v1 - 4));
  KeAbPostRelease(v1 - 4);
  if ( v10 > 0 )
  {
    __dmb(0xBu);
    v13 = (unsigned int *)(v1 - 12);
    do
    {
      v14 = __ldrex(v13);
      v15 = v14 - v10;
    }
    while ( __strex(v15, v13) );
    __dmb(0xBu);
    if ( v15 <= 0 )
    {
      if ( v15 )
        KeBugCheckEx(24, 0, v1, 40, v15);
      AlpcpDestroyBlob(v1);
    }
  }
  __dmb(0xBu);
  v16 = (unsigned int *)(v1 - 12);
  do
  {
    v17 = __ldrex(v16);
    v18 = v17 - 1;
  }
  while ( __strex(v18, v16) );
  __dmb(0xBu);
  if ( v18 <= 0 )
  {
    if ( v18 )
      KeBugCheckEx(24, 0, v1, 33, v18);
    AlpcpDestroyBlob(v1);
  }
  return 0;
}
