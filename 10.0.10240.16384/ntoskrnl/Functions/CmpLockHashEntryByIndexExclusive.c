// CmpLockHashEntryByIndexExclusive 
 
int __fastcall CmpLockHashEntryByIndexExclusive(int a1, int a2)
{
  unsigned int v2; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0

  v2 = *(_DWORD *)(a1 + 1844) + 12 * a2;
  v4 = KeAbPreAcquire(v2, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)v2);
  while ( __strex(v6 | 1, (unsigned __int8 *)v2) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v2, v4, v2);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = CmpReferenceHive(a1);
  if ( !result )
    sub_7E6C68();
  return result;
}
