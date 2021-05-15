// wcsspn 
 
int __fastcall wcsspn(_WORD *a1, unsigned __int16 *a2)
{
  int v2; // r2
  _WORD *v3; // r3
  unsigned __int16 *v4; // r6
  int v5; // r4
  int v6; // t1

  v2 = (unsigned __int16)*a1;
  v3 = a1;
  if ( *a1 )
  {
    while ( 1 )
    {
      v4 = a2;
      if ( *a2 != v2 )
        break;
LABEL_6:
      v2 = (unsigned __int16)*++v3;
      if ( !*v3 )
        return v3 - a1;
    }
    v5 = *a2;
    while ( v5 )
    {
      v6 = v4[1];
      ++v4;
      v5 = v6;
      if ( v6 == v2 )
        goto LABEL_6;
    }
  }
  return v3 - a1;
}
