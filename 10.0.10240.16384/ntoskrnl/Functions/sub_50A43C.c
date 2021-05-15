// sub_50A43C 
 
void __fastcall sub_50A43C(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  char v5; // r5
  int v6; // r7

  if ( a2 )
  {
    if ( a2 == 5 )
    {
      *(_BYTE *)(v4 + 72) = v5 & 0xF8 | 6;
    }
    else if ( a2 == 3 )
    {
      *(_BYTE *)(a4 + 9) = 2;
    }
  }
  else
  {
    *(_BYTE *)(v4 + 72) = v5 & 0xF8 | 2;
    *(_DWORD *)(v4 + 136) = v6;
    *(_BYTE *)(a4 + 9) = 0;
  }
  JUMPOUT(0x43A02C);
}
