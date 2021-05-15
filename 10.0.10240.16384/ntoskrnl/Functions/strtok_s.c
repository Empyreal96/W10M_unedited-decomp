// strtok_s 
 
_BYTE *__fastcall strtok_s(_BYTE *a1, unsigned __int8 *a2, _DWORD *a3)
{
  unsigned __int8 *v3; // r6
  _BYTE *v4; // r4
  int v5; // r3
  bool v6; // cf
  unsigned int v7; // t1
  unsigned int i; // r0
  _BYTE *result; // r0
  char v10[56]; // [sp+8h] [bp-38h] BYREF

  v3 = a2;
  v4 = a1;
  if ( !a3 || !a2 || !a1 && !*a3 )
  {
    PopPoCoalescinCallback();
    return 0;
  }
  v5 = 0;
  v6 = 0;
  do
  {
    if ( v6 )
      _report_rangecheckfailure(a1);
    v10[v5] = 0;
    v6 = (unsigned int)++v5 >= 0x20;
  }
  while ( v5 < 32 );
  do
  {
    v7 = *v3++;
    v10[v7 >> 3] |= 1 << (v7 & 7);
  }
  while ( v7 );
  if ( !a1 )
    v4 = (_BYTE *)*a3;
  for ( i = (unsigned __int8)*v4; ((1 << (i & 7)) & (unsigned __int8)v10[i >> 3]) != 0; i = (unsigned __int8)*++v4 )
  {
    if ( !i )
      break;
  }
  result = v4;
  if ( *v4 )
  {
    while ( ((1 << (*v4 & 7)) & (unsigned __int8)v10[(unsigned __int8)*v4 >> 3]) == 0 )
    {
      if ( !*++v4 )
        goto LABEL_20;
    }
    *v4++ = 0;
  }
LABEL_20:
  *a3 = v4;
  if ( result == v4 )
    return 0;
  return result;
}
