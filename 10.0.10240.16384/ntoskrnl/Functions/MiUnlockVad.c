// MiUnlockVad 
 
int __fastcall MiUnlockVad(int a1, int a2)
{
  unsigned int *v3; // r5
  unsigned int v4; // r1
  int result; // r0
  __int16 v6; // r3

  v3 = (unsigned int *)(a2 + 24);
  *(_BYTE *)(a1 + 968) &= 0x7Fu;
  __dmb(0xBu);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 - 1, v3) );
  if ( (v4 & 2) != 0 )
    return sub_546CD4();
  result = KeAbPostRelease((unsigned int)v3);
  v6 = *(_WORD *)(a1 + 310) + 1;
  *(_WORD *)(a1 + 310) = v6;
  if ( !v6 && *(_DWORD *)(a1 + 100) != a1 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
