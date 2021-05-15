// VfConfigureAdapterChannel 
 
int __fastcall VfConfigureAdapterChannel(int a1, int a2, int a3)
{
  int (__fastcall *v6)(int, int, int); // r0

  v6 = (int (__fastcall *)(int, int, int))ViGetRealDmaOperation(a1, 84);
  return v6(a1, a2, a3);
}
