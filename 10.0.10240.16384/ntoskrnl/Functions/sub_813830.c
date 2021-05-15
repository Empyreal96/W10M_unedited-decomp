// sub_813830 
 
void __fastcall sub_813830(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, unsigned int a11)
{
  int v11; // r8
  int v12; // lr
  int v13; // r2
  char v14; // r1
  int v15; // r0
  int v16; // r2
  __int16 v17; // r3
  int v18; // [sp+10h] [bp+10h]

  v13 = 0;
  v18 = 0;
  v14 = dword_641868;
  while ( 1 )
  {
    v15 = v13 + dword_6534DC;
    v16 = *(_DWORD *)(v13 + dword_6534DC);
    if ( !v16 || v16 == *(_DWORD *)(*(_DWORD *)(v11 + 16) + 4) )
    {
      v17 = *(_WORD *)(*(_DWORD *)(v15 + 8) + dword_64185C);
      if ( ((v17 & 0x20) == 0 || (v14 & 4) != 0) && ((v17 & 0x40) == 0 || (v14 & 0x10) != 0) )
      {
        if ( SepSecureBootUpdateBcdDataForRule() < 0 )
          JUMPOUT(0x7A5CD6);
        v12 = dword_641874;
        v14 = dword_641868;
      }
    }
    v13 = v18 + 12;
    ++a11;
    v18 += 12;
    if ( a11 >= *(unsigned __int16 *)(v12 + 36) )
      JUMPOUT(0x7A5CC0);
  }
}
