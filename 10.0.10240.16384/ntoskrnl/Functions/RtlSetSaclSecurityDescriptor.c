// RtlSetSaclSecurityDescriptor 
 
int __fastcall RtlSetSaclSecurityDescriptor(int a1, int a2, int a3, int a4)
{
  __int16 v5; // r2
  __int16 v6; // r3
  __int16 v8; // r2

  if ( *(_BYTE *)a1 != 1 )
    return -1073741736;
  v5 = *(_WORD *)(a1 + 2);
  if ( (v5 & 0x8000) == 0 )
  {
    if ( a2 )
    {
      v8 = v5 | 0x10;
      *(_WORD *)(a1 + 2) = v8;
      *(_DWORD *)(a1 + 12) = 0;
      if ( a3 )
        *(_DWORD *)(a1 + 12) = a3;
      *(_WORD *)(a1 + 2) = v8 & 0xFFDF;
      if ( !a4 )
        return 0;
      v6 = v8 & 0xFFDF | 0x20;
    }
    else
    {
      v6 = v5 & 0xFFEF;
    }
    *(_WORD *)(a1 + 2) = v6;
    return 0;
  }
  return -1073741703;
}
