// AuthzBasepOperandValueTypesCompatible 
 
BOOL __fastcall AuthzBasepOperandValueTypesCompatible(unsigned __int16 *a1)
{
  unsigned __int16 *v2; // r1
  unsigned __int16 *v3; // r4
  int v4; // r2
  int v5; // r3
  int v6; // r0
  int v7; // r2

  if ( *((_DWORD *)a1 + 3) == 1 )
  {
    v2 = a1;
    v3 = a1 + 14;
  }
  else
  {
    if ( *((_DWORD *)a1 + 10) != 1 )
      return *a1 == a1[14];
    v2 = a1 + 14;
    v3 = a1;
  }
  v4 = *v2;
  if ( v4 == 16 && *((_BYTE *)v2 + 4) )
    return 1;
  v5 = *v3;
  if ( v5 == 16 && (v4 == 2 || v4 == 3) )
    return 1;
  if ( (v5 == 2 || v5 == 1) && v4 == 2 )
  {
    v6 = *((_DWORD *)v2 + 6);
    v7 = *(unsigned __int8 *)(v6 + 8);
    return v5 == 2 && v7 != 2 || v5 == 1 && (v7 == 2 || *(_DWORD *)(v6 + 4) <= 0x7FFFFFFFu);
  }
  if ( v5 == 6 && v4 == 2 || v5 == 5 && v4 == 16 )
    return 1;
  return *a1 == a1[14];
}
