// VfGetDmaDomain 
 
int __fastcall VfGetDmaDomain(int a1)
{
  int (__fastcall *v2)(int); // r0

  v2 = (int (__fastcall *)(int))ViGetRealDmaOperation(a1, 132);
  return v2(a1);
}
