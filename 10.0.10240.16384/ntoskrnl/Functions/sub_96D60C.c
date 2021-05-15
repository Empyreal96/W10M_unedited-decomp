// sub_96D60C 
 
void __fastcall sub_96D60C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, __int16 a35)
{
  int v35; // r4

  if ( !a3 )
  {
    RtlStringCbPrintfW(&a35, 0x30u, (int)L"PCI_DEBUG_%04X_%02X_%02X_%02X", *(unsigned __int16 *)(v35 + 8));
    JUMPOUT(0x95E024);
  }
  JUMPOUT(0x95E092);
}
