// PiDqQueryLock 
 
int __fastcall PiDqQueryLock(int a1)
{
  unsigned int v1; // r2
  unsigned __int8 *v2; // r5
  int result; // r0
  unsigned int v4; // r2

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = (unsigned __int8 *)(a1 + 32);
  result = KeAbPreAcquire(a1 + 32, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7C76A0(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
