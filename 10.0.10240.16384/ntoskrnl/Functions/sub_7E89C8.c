// sub_7E89C8 
 
void __fastcall sub_7E89C8(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, int a11, int a12, char a13, int a14, int a15, int a16, int a17, int a18, char *a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, char a27)
{
  int v27; // r5

  RtlInitUnicodeString(
    (unsigned int)&a13,
    L"\\Registry\\Machine\\Software\\Microsoft\\SecurityManager\\AdminCapabilities");
  a17 = 24;
  a18 = 0;
  a20 = 576;
  a19 = &a13;
  a21 = 0;
  a22 = 0;
  if ( ZwOpenKey() >= 0 && ZwQueryValueKey() >= 0 )
  {
    RtlInitializeSid((int)&a27, (int)&a9, 1u);
    *(_DWORD *)RtlSubAuthoritySid((int)&a27, 0) = 18;
    RtlCheckTokenMembership(v27, (int)&a27, (int)&a7);
    JUMPOUT(0x6FE3A2);
  }
  JUMPOUT(0x6FE34C);
}
