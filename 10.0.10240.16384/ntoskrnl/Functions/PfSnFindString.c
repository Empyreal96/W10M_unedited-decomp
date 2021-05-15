// PfSnFindString 
 
unsigned __int16 *__fastcall PfSnFindString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned __int16 *v5; // r6
  unsigned __int16 *v6; // r1
  unsigned __int16 *v7; // r0
  bool v8; // zf
  int v9; // t1

  v2 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v3 = (unsigned int)&v2[*a1 >> 1];
  v4 = *((_DWORD *)a2 + 1) + 2 * (*a2 >> 1);
  if ( (unsigned int)v2 >= v3 )
    return 0;
  v5 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  while ( 1 )
  {
    v6 = v5;
    if ( (unsigned int)v2 >= v3 )
    {
LABEL_7:
      v8 = v6 == (unsigned __int16 *)v4;
    }
    else
    {
      v7 = v2;
      while ( 1 )
      {
        v8 = v6 == (unsigned __int16 *)v4;
        if ( (unsigned int)v6 >= v4 )
          break;
        v9 = *v7++;
        if ( v9 == *v6 )
        {
          ++v6;
          if ( (unsigned int)v7 < v3 )
            continue;
        }
        goto LABEL_7;
      }
    }
    if ( v8 )
      return v2;
    if ( (unsigned int)++v2 >= v3 )
      return 0;
  }
}
