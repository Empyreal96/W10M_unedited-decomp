// EmpSearchCallbackDatabase 
 
_DWORD *__fastcall EmpSearchCallbackDatabase(unsigned int a1)
{
  _DWORD *i; // r4
  _DWORD *v3; // r5

  for ( i = (_DWORD *)EmpCallbackListHead; ; i = (_DWORD *)*i )
  {
    v3 = 0;
    if ( !i )
      break;
    v3 = i - 7;
    if ( !memcmp((unsigned int)(i - 7), a1, 16) )
      break;
  }
  return v3;
}
