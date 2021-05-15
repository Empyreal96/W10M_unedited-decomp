// sub_80454C 
 
void __fastcall sub_80454C(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r2

  v5 = *(_DWORD *)(a4 + 152);
  if ( v5 )
  {
    if ( v5 == v4 )
LABEL_6:
      JUMPOUT(0x74B448);
  }
  else if ( a2 )
  {
    goto LABEL_6;
  }
  JUMPOUT(0x74B446);
}
