// RtlFindAceByType 
 
unsigned __int8 *__fastcall RtlFindAceByType(int a1, int a2, unsigned int *a3)
{
  unsigned __int8 *v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r5

  if ( !a1 )
    return 0;
  v4 = (unsigned __int8 *)(a1 + 8);
  v5 = *(unsigned __int16 *)(a1 + 4);
  v6 = 0;
  if ( !v5 )
    return 0;
  while ( !a3 )
  {
    if ( *v4 == a2 )
      return v4;
LABEL_9:
    ++v6;
    v4 += *((unsigned __int16 *)v4 + 1);
    if ( v6 >= v5 )
      return 0;
  }
  if ( v6 < *a3 || *v4 != a2 )
    goto LABEL_9;
  *a3 = v6;
  return v4;
}
