// MiUnlockControlAreaFileObjectShared 
 
int __fastcall MiUnlockControlAreaFileObjectShared(int a1)
{
  unsigned int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r2
  int result; // r0
  __int16 v5; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = (unsigned int *)(a1 + 72);
  __dmb(0xBu);
  do
    v3 = __ldrex(v2);
  while ( v3 == 17 && __strex(0, v2) );
  if ( v3 != 17 )
    return sub_51233C();
  result = KeAbPostRelease(a1 + 72);
  v5 = *(_WORD *)(v1 + 310) + 1;
  *(_WORD *)(v1 + 310) = v5;
  if ( !v5 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
