// _strnset 
 
_BYTE *__fastcall strnset(_BYTE *a1, char a2, int a3)
{
  _BYTE *v3; // r4

  v3 = a1;
  while ( a3 )
  {
    --a3;
    if ( !*a1 )
      break;
    *a1++ = a2;
  }
  return v3;
}
