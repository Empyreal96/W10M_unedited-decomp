// UNLOCK_PAGE_TABLE_COMMITMENT 
 
unsigned int __fastcall UNLOCK_PAGE_TABLE_COMMITMENT(int a1, int a2)
{
  unsigned int *v3; // r5
  unsigned int v4; // r0
  unsigned int result; // r0
  int v6; // r3

  v3 = (unsigned int *)(a2 + 256);
  __dmb(0xBu);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 - 1, v3) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock(a2 + 256);
  result = KeAbPostRelease((unsigned int)v3);
  v6 = (__int16)(*(_WORD *)(a1 + 310) + 1);
  *(_WORD *)(a1 + 310) = v6;
  if ( !v6 )
    result = sub_545634(result);
  return result;
}
