// sub_815AF8 
 
void __fastcall sub_815AF8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _BYTE *v9; // r4
  int v10; // r3

  if ( a3 == 3 )
  {
    if ( !v9 || a9 != 1 || (v10 = (unsigned __int8)*v9, v10 != 1) && *v9 )
      JUMPOUT(0x7ABFE8);
    *(_BYTE *)(a1 + 53) = v10;
  }
  JUMPOUT(0x7ABFE0);
}
