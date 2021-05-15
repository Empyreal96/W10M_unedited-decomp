// _strset 
 
_BYTE *__fastcall strset(_BYTE *a1, char a2)
{
  int v2; // r3
  _BYTE *v3; // r2
  int v4; // t1

  v2 = (char)*a1;
  v3 = a1;
  while ( v2 )
  {
    *a1 = a2;
    v4 = (char)*++a1;
    v2 = v4;
  }
  return v3;
}
