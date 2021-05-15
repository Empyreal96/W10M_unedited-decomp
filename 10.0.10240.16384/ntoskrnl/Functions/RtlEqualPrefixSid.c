// RtlEqualPrefixSid 
 
int __fastcall RtlEqualPrefixSid(unsigned __int8 *a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // r4
  int v4; // r6
  int v5; // r0
  unsigned __int8 *v6; // r5

  v2 = a1;
  if ( *a1 != *a2 )
    return 0;
  if ( a1[2] != a2[2] )
    return 0;
  if ( a1[3] != a2[3] )
    return 0;
  if ( a1[4] != a2[4] )
    return 0;
  if ( a1[5] != a2[5] )
    return 0;
  if ( a1[6] != a2[6] )
    return 0;
  if ( a1[7] != a2[7] )
    return 0;
  v4 = a1[1];
  if ( v4 != a2[1] )
    return 0;
  if ( !a1[1] )
    return 1;
  if ( v4 == 11 )
    return sub_7FB784();
  v5 = 0;
  if ( v4 - 1 <= 0 )
    return 1;
  v6 = (unsigned __int8 *)(a2 - v2);
  while ( *((_DWORD *)v2 + 2) == *(_DWORD *)&v2[(_DWORD)v6 + 8] )
  {
    ++v5;
    v2 += 4;
    if ( v5 >= v4 - 1 )
      return 1;
  }
  return 0;
}
