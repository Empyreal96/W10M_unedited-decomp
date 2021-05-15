// MmIsAddressValid 
 
int __fastcall MmIsAddressValid(unsigned int a1, int a2, int a3, int a4)
{
  return MiIsAddressValid(a1, 0, a3, a4);
}
