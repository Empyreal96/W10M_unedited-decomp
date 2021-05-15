// sub_7CEF48 
 
void __fastcall sub_7CEF48(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, __int64 a11, __int64 a12)
{
  unsigned __int16 *v12; // r4
  unsigned __int16 *v13; // r5
  _DWORD *v14; // r7
  int v15; // r3

  if ( (a7 & 0xCFFFFFFF) == 11 )
  {
    a12 = 0i64;
    a11 = 0i64;
    RtlInitUnicodeString((unsigned int)&a12, v13);
    RtlInitUnicodeString((unsigned int)&a11, v12);
    KsepEvntLogFlagsApplied((int)&a12, (int)&a11, (a7 & 0x10000000) == 0, v15);
    *v14 = a9;
    v14[1] = a10;
    JUMPOUT(0x78807E);
  }
  JUMPOUT(0x78808A);
}
