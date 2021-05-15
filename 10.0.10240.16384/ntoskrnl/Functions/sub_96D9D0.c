// sub_96D9D0 
 
void __fastcall sub_96D9D0(int a1, int a2)
{
  int v2; // r5
  int v3; // r2
  char v4; // r3

  v2 = *(_DWORD *)(a2 + 40) + a2 + 60;
  dword_6534DC = v2;
  if ( a1 )
  {
    v3 = dword_64A564;
    do
    {
      v4 = *(_BYTE *)(v2 + 7);
      v2 += 12;
      v3 |= 1 << (v4 & 0xF);
      --a1;
    }
    while ( a1 );
    dword_64A564 = v3;
  }
  JUMPOUT(0x95F014);
}
