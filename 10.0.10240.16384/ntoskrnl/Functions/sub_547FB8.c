// sub_547FB8 
 
void __fastcall sub_547FB8(int a1, int a2)
{
  int v2; // r6
  unsigned int v3; // r3
  unsigned int v4; // r4
  _BYTE *v5; // r2
  unsigned int v6; // r4

  v3 = *(_DWORD *)(a1 + 56);
  v4 = 4 * a2;
  if ( 4 * a2 )
  {
    if ( v4 >= 0x10000 )
    {
      if ( (v3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v5 = *(_BYTE **)(v2 + 16);
      v6 = v4 + v3;
      if ( v6 > (unsigned int)v5 || v6 < v3 )
        *v5 = 0;
    }
    else if ( (v3 & 3) != 0 )
    {
      ExRaiseDatatypeMisalignment(a1);
    }
  }
  JUMPOUT(0x4C6CE8);
}
