// ExHandleTableQuery 
 
int __fastcall ExHandleTableQuery(int result, unsigned int *a2, unsigned int *a3)
{
  unsigned int *v3; // r10
  _DWORD *v4; // r8
  unsigned int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r4
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r4
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r6
  unsigned int *v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r3
  _DWORD *v20; // [sp+4h] [bp-24h]

  v3 = a3;
  v20 = (_DWORD *)result;
  v4 = (_DWORD *)result;
  v5 = 0;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = 0;
  v9 = dword_92038C;
  if ( dword_92038C )
  {
    v10 = result + 40;
    do
    {
      result = KeAbPreAcquire(v10, 0, 0);
      do
        v11 = __ldrex((unsigned __int8 *)v10);
      while ( __strex(v11 | 1, (unsigned __int8 *)v10) );
      __dmb(0xBu);
      if ( (v11 & 1) != 0 )
        return sub_7F6A54(result);
      if ( result )
        *(_BYTE *)(result + 14) |= 1u;
      ++v8;
      v5 += *(_DWORD *)(v10 + 12);
      v12 = *(_DWORD *)(v10 + 16);
      v10 += 52;
      v6 += v12;
      v9 = dword_92038C;
    }
    while ( v8 < dword_92038C );
    v3 = a3;
    v4 = v20;
  }
  v13 = 0;
  if ( v9 )
  {
    v14 = v4 + 10;
    do
    {
      __dmb(0xBu);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 - 1, v14) );
      if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
        ExfTryToWakePushLock(v14);
      result = KeAbPostRelease((unsigned int)v14);
      ++v13;
      v14 += 13;
    }
    while ( v13 < dword_92038C );
    v3 = a3;
  }
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  v18 = 511 * (*v4 >> 2);
  if ( v5 > v18 >> 9 )
    v5 = v18 >> 9;
  if ( v6 > v5 )
    v6 = v5;
  if ( a2 )
    *a2 = v5;
  if ( v3 )
    *v3 = v6;
  return result;
}
