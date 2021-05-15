// sub_80C064 
 
void __fastcall sub_80C064(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  _DWORD *v6; // r5
  unsigned __int16 *v7; // r6
  int v8; // r7
  int v9; // r0

  if ( v8 )
  {
    v9 = RtlpMuiRegGrowStringPool(v6[6], a2, a5, v5 == 0);
    if ( v9 )
    {
      *v6 |= 2u;
      v6[6] = v9;
      if ( (RtlpMuiRegGetOrAddStringToPool(v9, v7, 1, 0) & 0x8000u) == 0 )
        JUMPOUT(0x79227E);
    }
    JUMPOUT(0x792280);
  }
  JUMPOUT(0x79228E);
}
