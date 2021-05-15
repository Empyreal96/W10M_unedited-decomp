// VfCalculateScatterGatherListSize 
 
int __fastcall VfCalculateScatterGatherListSize(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v8)(int, int, int, int); // r0

  v8 = (int (__fastcall *)(int, int, int, int))ViGetRealDmaOperation(a1, 52);
  return v8(a1, a2, a3, a4);
}
