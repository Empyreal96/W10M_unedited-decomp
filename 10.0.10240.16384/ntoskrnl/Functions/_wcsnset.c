// _wcsnset 
 
_WORD *__fastcall wcsnset(_WORD *a1, __int16 a2, int a3)
{
  _WORD *v3; // r4

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
