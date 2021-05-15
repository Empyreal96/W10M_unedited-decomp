// AlpcDeleteBlobByHandle 
 
int __fastcall AlpcDeleteBlobByHandle(_DWORD *a1, int a2, int a3)
{
  int v3; // r5
  unsigned __int8 *v7; // r4
  unsigned int v8; // r7
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r1

  v3 = 0;
  if ( !a1 )
    return sub_805FEC();
  v7 = (unsigned __int8 *)(a1 + 3);
  v8 = a2 - 16;
  v9 = KeAbPreAcquire((unsigned int)(a1 + 3), 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 1, v7) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v9, (unsigned int)v7);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( v8 < a1[1] && *(_DWORD *)(*a1 + 4 * v8) == a3 )
  {
    *(_DWORD *)(*a1 + 4 * v8) = 0;
    v3 = 1;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v7);
  while ( __strex(v12 - 1, (unsigned int *)v7) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  KeAbPostRelease((unsigned int)v7);
  return v3;
}
