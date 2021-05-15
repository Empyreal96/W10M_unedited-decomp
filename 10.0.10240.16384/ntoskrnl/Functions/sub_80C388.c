// sub_80C388 
 
void __fastcall sub_80C388(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, unsigned int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, unsigned __int16 a23)
{
  RtlStringCchPrintfW(&a23, 0x3Cu, (int)L"\\Driver\\%08u", KeTickCount);
  RtlStringCchLengthW(&a23, 0x3Cu, &a15);
  if ( a15 > 0xFFFF )
    JUMPOUT(0x79324C);
  JUMPOUT(0x793150);
}
