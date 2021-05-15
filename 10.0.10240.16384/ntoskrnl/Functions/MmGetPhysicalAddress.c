// MmGetPhysicalAddress 
 
int __fastcall MmGetPhysicalAddress(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  if ( MiGetPhysicalAddress(a2, a1, &v6) )
    result = a1;
  else
    result = sub_510840();
  return result;
}
