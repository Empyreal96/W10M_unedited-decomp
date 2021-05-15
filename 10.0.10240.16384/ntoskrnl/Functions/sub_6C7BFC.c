// sub_6C7BFC 
 
int __fastcall sub_6C7BFC(int a1, int a2)
{
  unsigned __int16 *v2; // r3
  unsigned __int16 *v3; // r0
  unsigned int v4; // r4
  unsigned __int16 *v5; // r3
  int v6; // r0
  unsigned __int16 *v8; // r2
  unsigned int v9; // r3

  v2 = *(unsigned __int16 **)(a1 + 4);
  if ( *(_BYTE *)a1 == 2 )
  {
    v4 = v2[1];
    v3 = v2 + 8;
  }
  else
  {
    v3 = (unsigned __int16 *)*((_DWORD *)v2 + 1);
    v4 = *v2;
  }
  v5 = *(unsigned __int16 **)(a2 + 4);
  if ( *(_BYTE *)a2 == 2 )
  {
    v8 = v5 + 8;
    v9 = v5[1];
  }
  else
  {
    v8 = (unsigned __int16 *)*((_DWORD *)v5 + 1);
    v9 = *v5;
  }
  v6 = RtlCompareUnicodeStrings(v3, v4 >> 1, v8, v9 >> 1);
  if ( v6 > 0 )
    return 1;
  if ( v6 < 0 )
    return -1;
  return 0;
}
