// KiSynchronizePassiveInterruptExecution 
 
int __fastcall KiSynchronizePassiveInterruptExecution(int a1, int (__fastcall *a2)(int), int a3)
{
  unsigned int v6; // r4
  int v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  KeWaitForSingleObject(*(_DWORD *)(a1 + 80), 0, 0, 0, 0);
  v7 = a2(a3);
  v8 = KeSetEvent(*(_DWORD *)(a1 + 80), 0, 0);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v7;
}
