// wcscspn 
 
int __fastcall wcscspn(_WORD *a1, _WORD *a2)
{
  _WORD *v2; // r2
  _WORD *v3; // r5
  int v4; // r3
  int v5; // t1

  v2 = a1;
  if ( *a1 )
  {
    while ( 1 )
    {
      v3 = a2;
      if ( *a2 )
        break;
LABEL_6:
      if ( !*++v2 )
        return v2 - a1;
    }
    v4 = (unsigned __int16)*a2;
    while ( v4 != (unsigned __int16)*v2 )
    {
      v5 = (unsigned __int16)v3[1];
      ++v3;
      v4 = v5;
      if ( !v5 )
        goto LABEL_6;
    }
  }
  return v2 - a1;
}
