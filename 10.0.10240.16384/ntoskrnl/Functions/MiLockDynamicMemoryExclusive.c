// MiLockDynamicMemoryExclusive 
 
int __fastcall MiLockDynamicMemoryExclusive(int a1, int a2)
{
  unsigned __int8 *v2; // r5
  int result; // r0
  unsigned int v4; // r2

  --*(_WORD *)(a2 + 310);
  v2 = (unsigned __int8 *)(a1 + 164);
  result = KeAbPreAcquire(a1 + 164, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_54E96C(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
