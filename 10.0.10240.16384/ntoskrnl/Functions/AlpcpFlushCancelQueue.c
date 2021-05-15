// AlpcpFlushCancelQueue 
 
unsigned int __fastcall AlpcpFlushCancelQueue(int a1, int a2)
{
  unsigned __int8 *v2; // r4
  _DWORD **v5; // r6
  int v6; // r0
  unsigned int v7; // r2
  _DWORD *v9; // r5
  unsigned int v10; // r1
  int v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1

  v2 = (unsigned __int8 *)(a1 + 92);
  v5 = (_DWORD **)(a1 + 224);
  v6 = KeAbPreAcquire(a1 + 92, 0, 0);
  do
    v7 = __ldrex(v2);
  while ( __strex(v7 | 1, v2) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    return sub_8070D8(v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = *v5;
  while ( v9 != v5 )
  {
    v11 = (int)(v9 - 11);
    v9 = (_DWORD *)*v9;
    if ( !a2 || *(_DWORD *)(v11 + 32) == a2 )
    {
      **(_DWORD **)(v11 + 48) = *(_DWORD *)(v11 + 44);
      *(_DWORD *)(*(_DWORD *)(v11 + 44) + 4) = *(_DWORD *)(v11 + 48);
      --*(_DWORD *)(a1 + 276);
      *(_DWORD *)(v11 + 32) = 0;
      *(_DWORD *)(v11 + 36) = 0;
      __dmb(0xBu);
      v12 = (unsigned int *)(v11 - 12);
      do
      {
        v13 = __ldrex(v12);
        v14 = v13 - 1;
      }
      while ( __strex(v14, v12) );
      __dmb(0xBu);
      if ( v14 <= 0 )
      {
        if ( v14 )
          KeBugCheckEx(24, 0, v11, 33, v14);
        AlpcpDestroyBlob(v11);
      }
    }
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v2);
  while ( __strex(v10 - 1, (unsigned int *)v2) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v2);
  return KeAbPostRelease((unsigned int)v2);
}
