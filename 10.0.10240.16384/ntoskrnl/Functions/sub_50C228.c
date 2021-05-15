// sub_50C228 
 
void __fastcall sub_50C228(int a1, int a2, char a3, int a4)
{
  int v4; // r6
  int v5; // r10

  if ( a4 != 4 )
  {
    switch ( a4 )
    {
      case 0:
        *(_BYTE *)(a1 + 72) = a3 & 0xF8 | 2;
        *(_DWORD *)(a1 + 136) = v5;
        *(_BYTE *)(v4 + 9) = 0;
        JUMPOUT(0x4723C8);
      case 5:
        *(_BYTE *)(a1 + 72) = a3 & 0xF8 | 6;
        break;
      case 3:
        *(_BYTE *)(v4 + 9) = 2;
        break;
    }
    JUMPOUT(0x4723C6);
  }
  JUMPOUT(0x472334);
}
