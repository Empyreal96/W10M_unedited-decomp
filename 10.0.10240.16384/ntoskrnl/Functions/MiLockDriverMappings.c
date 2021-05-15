// MiLockDriverMappings 
 
int __fastcall MiLockDriverMappings(int a1)
{
  int result; // r0
  unsigned int v2; // r1

  --*(_WORD *)(a1 + 310);
  result = KeAbPreAcquire((unsigned int)dword_632F40, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)dword_632F40);
  while ( __strex(v2 | 1, (unsigned __int8 *)dword_632F40) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_519454(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
