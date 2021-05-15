// VfGetDmaAdapterInfo 
 
int __fastcall VfGetDmaAdapterInfo(int a1, int a2)
{
  int (__fastcall *v4)(int, int); // r0

  v4 = (int (__fastcall *)(int, int))ViGetRealDmaOperation(a1, 64);
  return v4(a1, a2);
}
