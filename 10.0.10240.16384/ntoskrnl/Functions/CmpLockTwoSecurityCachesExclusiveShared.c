// CmpLockTwoSecurityCachesExclusiveShared 
 
int __fastcall CmpLockTwoSecurityCachesExclusiveShared(unsigned int a1, unsigned int a2)
{
  unsigned __int8 *v4; // r7
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  unsigned int *v8; // r6
  int result; // r0
  int v10; // r5
  unsigned int v11; // r2
  unsigned int *v12; // r4
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  unsigned __int8 *v16; // r6
  unsigned int v17; // r2
  unsigned __int8 *v18; // r6
  unsigned int v19; // r2

  if ( a1 < a2 )
  {
    v4 = (unsigned __int8 *)(a1 + 1928);
    v5 = KeAbPreAcquire(a1 + 1928, 0, 0);
    v6 = v5;
    do
      v7 = __ldrex(v4);
    while ( __strex(v7 | 1, v4) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v5, (unsigned int)v4);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v8 = (unsigned int *)(a2 + 1928);
    result = KeAbPreAcquire((unsigned int)v8, 0, 0);
    v10 = result;
    do
      v11 = __ldrex(v8);
    while ( !v11 && __strex(0x11u, v8) );
    __dmb(0xBu);
    if ( v11 )
      result = ExfAcquirePushLockSharedEx(v8, result, (unsigned int)v8);
    goto LABEL_13;
  }
  if ( a1 > a2 )
  {
    v12 = (unsigned int *)(a2 + 1928);
    v13 = KeAbPreAcquire(a2 + 1928, 0, 0);
    v14 = v13;
    do
      v15 = __ldrex(v12);
    while ( !v15 && __strex(0x11u, v12) );
    __dmb(0xBu);
    if ( v15 )
      ExfAcquirePushLockSharedEx((_DWORD *)(a2 + 1928), v13, a2 + 1928);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    v16 = (unsigned __int8 *)(a1 + 1928);
    result = KeAbPreAcquire(a1 + 1928, 0, 0);
    v10 = result;
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 1, v16) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      result = ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 1928), result, a1 + 1928);
LABEL_13:
    if ( !v10 )
      return result;
    goto LABEL_32;
  }
  v18 = (unsigned __int8 *)(a2 + 1928);
  result = KeAbPreAcquire(a2 + 1928, 0, 0);
  v10 = result;
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 | 1, v18) );
  __dmb(0xBu);
  if ( (v19 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v18, result, (unsigned int)v18);
  if ( v10 )
LABEL_32:
    *(_BYTE *)(v10 + 14) |= 1u;
  return result;
}
