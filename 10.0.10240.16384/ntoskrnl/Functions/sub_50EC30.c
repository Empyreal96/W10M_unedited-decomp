// sub_50EC30 
 
void __fastcall sub_50EC30(int a1, int a2, int a3)
{
  do
    a3 = *(_DWORD *)(a3 + 16);
  while ( !*(_DWORD *)(a3 + 20) );
  JUMPOUT(0x4CBFB0);
}
