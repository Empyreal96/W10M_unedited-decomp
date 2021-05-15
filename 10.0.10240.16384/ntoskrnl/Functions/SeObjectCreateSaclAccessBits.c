// SeObjectCreateSaclAccessBits 
 
int __fastcall SeObjectCreateSaclAccessBits(int a1)
{
  int v1; // r3
  int v2; // r3
  int result; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1
  unsigned __int8 *v6; // r2
  int v7; // r3

  if ( (*(_WORD *)(a1 + 2) & 0x10) == 0 )
    return 0x1000000;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v1 = *(_DWORD *)(a1 + 12);
    if ( !v1 )
      return 0x1000000;
    v2 = v1 + a1;
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 12);
  }
  result = 0;
  if ( !v2 )
    return 0x1000000;
  v4 = *(unsigned __int16 *)(v2 + 4);
  v5 = 0;
  v6 = (unsigned __int8 *)(v2 + 8);
  if ( *(_WORD *)(v2 + 4) )
  {
    while ( 1 )
    {
      v7 = *v6;
      if ( v7 != 17 && v7 != 20 )
        break;
      ++v5;
      v6 += *((unsigned __int16 *)v6 + 1);
      if ( v5 >= v4 )
        return result;
    }
    result = sub_7E9364(0, v5);
  }
  return result;
}
