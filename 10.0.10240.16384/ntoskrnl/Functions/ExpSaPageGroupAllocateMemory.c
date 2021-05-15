// ExpSaPageGroupAllocateMemory 
 
int __fastcall ExpSaPageGroupAllocateMemory(_DWORD *a1, unsigned int a2)
{
  int v4; // r4
  unsigned __int8 *v5; // r6
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1

  if ( a1[5] < a2 )
    return -1;
  v5 = (unsigned __int8 *)(a1 + 3);
  v6 = KeAbPreAcquire((unsigned int)(a1 + 3), 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( __strex(v8 | 1, v5) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 3, v6, (unsigned int)(a1 + 3));
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( a1[5] >= a2 )
  {
    v9 = RtlFindClearBitsAndSet(a1 + 8, a2, a1[7]);
    v4 = -1;
    if ( v9 != -1 )
    {
      a1[5] -= a2;
      a1[7] = v9 + a2;
      v4 = 8 * (v9 & 0x3FF | ((a1[4] & 0x3FFFF) << 10));
    }
  }
  else
  {
    v4 = -1;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v5);
  while ( __strex(v10 - 1, (unsigned int *)v5) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 3);
  KeAbPostRelease((unsigned int)(a1 + 3));
  return v4;
}
