// sub_959478 
 
int __fastcall sub_959478(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-8h] BYREF
  int v6; // [sp+4h] [bp-4h]

  v5 = a3;
  v6 = a4;
  RtlInitUnicodeString((unsigned int)&v5, a1);
  return RtlComputeCrc32(0, v6, (unsigned __int16)v5);
}
