// PspUserApcReserveKernelRoutine 
 
int __fastcall PspUserApcReserveKernelRoutine(int a1)
{
  __dmb(0xBu);
  *(_DWORD *)(a1 - 4) = 0;
  return ObfDereferenceObject(a1 - 4);
}
