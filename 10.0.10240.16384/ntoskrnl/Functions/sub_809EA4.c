// sub_809EA4 
 
void __fastcall sub_809EA4(int a1, __int16 a2, int a3, int a4)
{
  int v4; // r5
  __int16 v5; // r3
  bool v6; // zf
  __int16 v7; // r3

  if ( a4 == 3 )
  {
    v5 = *(_WORD *)(v4 + 52) | 8;
  }
  else
  {
    v6 = a4 == 2;
    v7 = *(_WORD *)(v4 + 52);
    if ( v6 )
      v5 = v7 | 4;
    else
      v5 = v7 | a2;
  }
  *(_WORD *)(v4 + 52) = v5;
  JUMPOUT(0x75F06E);
}
