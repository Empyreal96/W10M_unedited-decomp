// sub_7CDDBC 
 
void __fastcall sub_7CDDBC(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r4
  unsigned int v8; // r7
  int v9; // r9
  int v10; // r10
  int v11; // r0
  int v12; // r6

  v11 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v12 = v11;
  if ( (v7[7] & v9) == 0 || MiCreatePerSessionProtos(v7, v11) >= 0 )
  {
    if ( MiMakeZeroedPageTables(
           (a7 & (v8 >> 10)) - (v9 + 1006632960),
           (a7 & ((v8 + (v10 << 12) - 1) >> 10)) - (v9 + 1006632960),
           1) )
    {
      JUMPOUT(0x772DE6);
    }
    if ( (v7[7] & v9) != 0 )
      MiDereferencePerSessionProtos(v7, v12);
  }
  JUMPOUT(0x772E22);
}
