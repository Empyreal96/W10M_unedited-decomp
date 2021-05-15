// AlpcpDeleteBlob 
 
int __fastcall AlpcpDeleteBlob(int a1)
{
  int v1; // r6
  unsigned __int8 *v2; // r4
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  unsigned int v7; // r1
  void (__fastcall *v8)(int); // r3
  unsigned int v9; // r1

  v1 = a1 - 24;
  v2 = (unsigned __int8 *)(a1 - 4);
  v4 = KeAbPreAcquire(a1 - 4, 0, 0);
  do
    v5 = __ldrex(v2);
  while ( __strex(v5 | 1, v2) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7F7C6C(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( (*(_BYTE *)(v1 + 8) & 8) != 0 )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)v2);
    while ( __strex(v9 - 1, (unsigned int *)v2) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v2);
    KeAbPostRelease((unsigned int)v2);
    result = 0;
  }
  else
  {
    *(_BYTE *)(v1 + 8) |= 8u;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)v2);
    while ( __strex(v7 - 1, (unsigned int *)v2) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v2);
    KeAbPostRelease((unsigned int)v2);
    v8 = *(void (__fastcall **)(int))(AlpcpRegisteredTypes[*(unsigned __int8 *)(v1 + 9)] + 20);
    if ( v8 )
      v8(a1);
    result = 1;
  }
  return result;
}
