// MiUnlockDriverMappings 
 
int __fastcall MiUnlockDriverMappings(int a1)
{
  unsigned int v2; // r0
  int result; // r0
  __int16 v4; // r3

  __dmb(0xBu);
  do
    v2 = __ldrex(dword_632F40);
  while ( __strex(v2 - 1, dword_632F40) );
  if ( (v2 & 2) != 0 )
    return sub_519440();
  result = KeAbPostRelease((unsigned int)dword_632F40);
  v4 = *(_WORD *)(a1 + 310) + 1;
  *(_WORD *)(a1 + 310) = v4;
  if ( !v4 && *(_DWORD *)(a1 + 100) != a1 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
