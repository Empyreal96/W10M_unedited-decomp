// MI_LOCK_COMBINE_PAGES_EXCLUSIVE 
 
int __fastcall MI_LOCK_COMBINE_PAGES_EXCLUSIVE(int a1, int a2)
{
  unsigned __int8 *v2; // r5
  int result; // r0
  unsigned int v4; // r2

  --*(_WORD *)(a2 + 310);
  v2 = (unsigned __int8 *)(a1 + 3456);
  result = KeAbPreAcquire(a1 + 3456, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_54F9B8(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
