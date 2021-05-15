// PsTerminateProcess 
 
int __fastcall PsTerminateProcess(int a1, int a2)
{
  unsigned int v2; // r4
  int v3; // r0
  int v4; // r5
  __int16 v5; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = PspTerminateProcess(a1, v2, a2, 1);
  v4 = v3;
  v5 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v3);
  return v4;
}
