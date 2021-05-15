// sub_520444 
 
void __fastcall sub_520444(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r2
  int v5; // r3

  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v4 = *(_DWORD **)(a3 + 8);
      v5 = PoPowerSequence;
      *v4 = PoPowerSequence;
      v4[1] = v5;
      v4[2] = v5;
      goto LABEL_7;
    }
    if ( a4 == 3 )
LABEL_7:
      JUMPOUT(0x451E6C);
  }
  JUMPOUT(0x451E82);
}
