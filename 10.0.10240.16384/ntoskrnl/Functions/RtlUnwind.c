// RtlUnwind 
 
int __fastcall RtlUnwind(unsigned int a1, int a2, int a3, int a4)
{
  char v5[424]; // [sp+8h] [bp-1A8h] BYREF

  return RtlUnwindEx(a1, a2, a3, a4, (int)v5, 0);
}
