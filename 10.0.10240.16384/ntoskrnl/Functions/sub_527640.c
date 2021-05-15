// sub_527640 
 
void __fastcall sub_527640(int a1, int a2, int a3, int a4)
{
  int v4; // lr
  unsigned int v5; // r4
  unsigned int v6; // r1
  _BYTE *v7; // r3

  v5 = *(_DWORD *)(a1 + 56);
  v6 = 8 * v4;
  if ( 8 * v4 )
  {
    if ( v6 >= 0x10000 )
    {
      if ( (v5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v7 = *(_BYTE **)(a4 + 16);
      if ( v5 + v6 > (unsigned int)v7 || v5 + v6 < v5 )
        *v7 = 0;
    }
    else if ( (v5 & 3) != 0 )
    {
      ExRaiseDatatypeMisalignment(a1);
    }
  }
  JUMPOUT(0x4D8CC0);
}
