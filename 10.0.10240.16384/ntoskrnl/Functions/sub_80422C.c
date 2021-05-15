// sub_80422C 
 
void __fastcall sub_80422C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r5
  int v9; // r9

  if ( a8 == 4 )
  {
    if ( v9 )
      HvpMapEntryReleaseBinAddress(a1, v8);
    JUMPOUT(0x749B10);
  }
  JUMPOUT(0x749B2A);
}
