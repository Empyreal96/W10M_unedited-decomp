// sub_7DCD48 
 
void __fastcall sub_7DCD48(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, char a24)
{
  unsigned int v24; // r5
  void (__fastcall *v25)(int, int, char *, int); // r7
  int v26; // r10
  int v27; // r0

  ExFreePoolWithTag(v24);
  v27 = ExAllocatePoolWithTag(1, a11, 1901290063);
  if ( v27 )
  {
    v25(v26, 1, &a24, v27);
    JUMPOUT(0x6E93A8);
  }
  JUMPOUT(0x6E93BE);
}
