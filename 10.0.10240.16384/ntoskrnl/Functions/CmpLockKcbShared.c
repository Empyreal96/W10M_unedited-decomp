// CmpLockKcbShared 
 
int __fastcall CmpLockKcbShared(_DWORD *a1)
{
  int result; // r0
  unsigned int *v3; // r6
  int v4; // r4
  unsigned int v5; // r2
  unsigned int *v6; // r2
  unsigned int v7; // r1

  if ( (a1[1] & 0x100000) != 0 )
    return sub_7FE92C();
  v3 = a1 + 7;
  result = KeAbPreAcquire((unsigned int)(a1 + 7), 0, 0);
  v4 = result;
  do
    v5 = __ldrex(v3);
  while ( !v5 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v5 )
    result = ExfAcquirePushLockSharedEx(a1 + 7, result, (unsigned int)(a1 + 7));
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  __dmb(0xBu);
  v6 = a1 + 8;
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  return result;
}
