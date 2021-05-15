// ExpSetSwappingKernelApc 
 
int __fastcall ExpSetSwappingKernelApc(int a1, int a2, unsigned __int8 *a3, int *a4)
{
  int v4; // r4

  v4 = *a4;
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 1) != 0 )
    KeSetKernelStackSwapEnable(*a3);
  return KeSetEvent(v4, 0, 0);
}
