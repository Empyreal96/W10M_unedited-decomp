// VfLeaveDmaDomain 
 
int __fastcall VfLeaveDmaDomain(int a1)
{
  int (__fastcall *v2)(int); // r0

  v2 = (int (__fastcall *)(int))ViGetRealDmaOperation(a1, 128);
  return v2(a1);
}
