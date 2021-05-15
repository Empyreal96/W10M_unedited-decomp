// MI_LOCK_RELOCATIONS_EXCLUSIVE 
 
int __fastcall MI_LOCK_RELOCATIONS_EXCLUSIVE(int a1, int a2)
{
  unsigned __int8 *v4; // r5
  int result; // r0
  unsigned int v6; // r2

  --*(_WORD *)(a1 + 310);
  v4 = (unsigned __int8 *)(a2 + 12);
  result = KeAbPreAcquire(a2 + 12, 0, 0);
  do
    v6 = __ldrex(v4);
  while ( __strex(v6 | 1, v4) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    return sub_546CC4(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  *(_DWORD *)(a2 + 4) = a1;
  return result;
}
