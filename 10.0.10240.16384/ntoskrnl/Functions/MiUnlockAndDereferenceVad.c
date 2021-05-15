// MiUnlockAndDereferenceVad 
 
int __fastcall MiUnlockAndDereferenceVad(int a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  BOOL v5; // r6
  unsigned int v6; // r4
  unsigned int *v7; // r7
  unsigned int v8; // r1
  int result; // r0
  __int16 v10; // r3

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 20);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  v5 = !v4 && *(int *)(a1 + 28) < 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (unsigned int *)(a1 + 24);
  *(_BYTE *)(v6 + 0x3C8) &= 0x7Fu;
  __dmb(0xBu);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 - 1, v7) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 24);
  result = KeAbPostRelease(a1 + 24);
  v10 = *(_WORD *)(v6 + 310) + 1;
  *(_WORD *)(v6 + 310) = v10;
  if ( !v10 && *(_DWORD *)(v6 + 100) != v6 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  if ( v5 )
    result = sub_530AD0(result);
  return result;
}
