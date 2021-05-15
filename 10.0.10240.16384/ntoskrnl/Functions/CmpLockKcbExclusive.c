// CmpLockKcbExclusive 
 
int __fastcall CmpLockKcbExclusive(_DWORD *a1)
{
  int result; // r0
  unsigned __int8 *v3; // r6
  int v4; // r4
  unsigned int v5; // r2

  if ( (a1[1] & 0x100000) != 0 )
    return sub_804F24();
  v3 = (unsigned __int8 *)(a1 + 7);
  result = KeAbPreAcquire((unsigned int)(a1 + 7), 0, 0);
  v4 = result;
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(a1 + 7, result, (unsigned int)(a1 + 7));
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  a1[8] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}
