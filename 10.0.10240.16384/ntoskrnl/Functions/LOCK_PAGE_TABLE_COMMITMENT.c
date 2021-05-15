// LOCK_PAGE_TABLE_COMMITMENT 
 
int __fastcall LOCK_PAGE_TABLE_COMMITMENT(int a1, int a2)
{
  unsigned __int8 *v2; // r5
  int result; // r0
  int v4; // r4
  unsigned int v5; // r2

  --*(_WORD *)(a1 + 310);
  v2 = (unsigned __int8 *)(a2 + 256);
  result = KeAbPreAcquire(a2 + 256, 0, 0);
  v4 = result;
  do
    v5 = __ldrex(v2);
  while ( __strex(v5 | 1, v2) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v2, result, v2);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  return result;
}
