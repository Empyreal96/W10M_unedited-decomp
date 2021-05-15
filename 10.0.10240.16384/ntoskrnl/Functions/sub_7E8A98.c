// sub_7E8A98 
 
void __fastcall sub_7E8A98(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, char a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, unsigned __int16 a31)
{
  int v31; // r3

  if ( a26 == 4
    && a27 == 4
    && a28 == 5243136
    && RtlStringCchCopyW(&a31, 0x104u, (int)L"\\SystemRoot\\System32\\") >= 0
    && RtlStringCchCatW(&a31, 0x104u, (int)L"loc2008.nls", v31) >= 0 )
  {
    RtlInitUnicodeString((unsigned int)&a21, &a31);
    ZwOpenFile();
  }
  JUMPOUT(0x6FED46);
}
