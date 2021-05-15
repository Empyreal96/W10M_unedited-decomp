// sub_7F1CE4 
 
void __fastcall sub_7F1CE4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
  if ( a16 == 4 && a17 == 4 && ZwDeleteValueKey() >= 0 )
    ZwUpdateWnfStateData();
  JUMPOUT(0x78D61E);
}
