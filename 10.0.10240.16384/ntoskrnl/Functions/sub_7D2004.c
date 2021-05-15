// sub_7D2004 
 
void __fastcall sub_7D2004(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, char a23)
{
  __int64 v23; // r0

  LODWORD(v23) = &a23;
  HIDWORD(v23) = 0x20000;
  EtwGetKernelTraceTimestamp(v23);
  JUMPOUT(0x6D1042);
}
