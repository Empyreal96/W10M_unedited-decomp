// sub_50A1EC 
 
void __fastcall sub_50A1EC(int a1, _DWORD *a2, int a3, int a4)
{
  if ( a4 == 2 )
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x40C) = *a2;
  JUMPOUT(0x432D46);
}
