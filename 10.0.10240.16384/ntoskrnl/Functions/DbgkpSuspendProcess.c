// DbgkpSuspendProcess 
 
int __fastcall DbgkpSuspendProcess(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r3
  __int16 v6; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  if ( PsFreezeProcess(a1, 0, a3, v4) )
    return 1;
  v6 = *(_WORD *)(v3 + 308) + 1;
  *(_WORD *)(v3 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
    KiCheckForKernelApcDelivery(0);
  return 0;
}
