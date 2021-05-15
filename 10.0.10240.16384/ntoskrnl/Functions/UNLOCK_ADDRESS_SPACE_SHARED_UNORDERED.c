// UNLOCK_ADDRESS_SPACE_SHARED_UNORDERED 
 
int __fastcall UNLOCK_ADDRESS_SPACE_SHARED_UNORDERED(int a1, int a2)
{
  unsigned int *v3; // r5
  unsigned int v4; // r2
  int result; // r0
  __int16 v6; // r3

  v3 = (unsigned int *)(a2 + 252);
  __dmb(0xBu);
  do
    v4 = __ldrex(v3);
  while ( v4 == 17 && __strex(0, v3) );
  if ( v4 != 17 )
    ExfReleasePushLockShared(v3);
  result = KeAbPostRelease((unsigned int)v3);
  *(_BYTE *)(a1 + 968) &= 0xFDu;
  v6 = *(_WORD *)(a1 + 310) + 1;
  *(_WORD *)(a1 + 310) = v6;
  if ( !v6 && *(_DWORD *)(a1 + 100) != a1 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
