// RtlFindAceBySid 
 
int __fastcall RtlFindAceBySid(int a1, unsigned __int16 *a2, unsigned int *a3)
{
  unsigned int v5; // r6
  unsigned int v6; // r5
  unsigned __int8 *v7; // r4
  unsigned __int16 *v9; // r0

  if ( !a1 )
    return 0;
  v5 = *(unsigned __int16 *)(a1 + 4);
  v6 = 0;
  v7 = (unsigned __int8 *)(a1 + 8);
  if ( !*(_WORD *)(a1 + 4) )
    return 0;
  while ( 1 )
  {
    if ( *v7 > 3u )
      return sub_517C18();
    v9 = (unsigned __int16 *)(v7 + 8);
    if ( v7 == (unsigned __int8 *)-8 )
      goto LABEL_8;
    if ( a3 )
      break;
    if ( *v9 == *a2 && !memcmp((unsigned int)v9, (unsigned int)a2, 4 * (v7[9] + 2)) )
      return (int)v7;
LABEL_8:
    ++v6;
    v7 += *((unsigned __int16 *)v7 + 1);
    if ( v6 >= v5 )
      return 0;
  }
  if ( v6 < *a3 || !RtlEqualSid(v9, a2) )
    goto LABEL_8;
  *a3 = v6;
  return (int)v7;
}
