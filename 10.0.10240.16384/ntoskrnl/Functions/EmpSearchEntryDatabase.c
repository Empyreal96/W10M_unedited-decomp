// EmpSearchEntryDatabase 
 
_DWORD *__fastcall EmpSearchEntryDatabase(unsigned int a1)
{
  _DWORD *i; // r4
  _DWORD *v3; // r5

  for ( i = (_DWORD *)EmpEntryListHead; ; i = (_DWORD *)*i )
  {
    v3 = 0;
    if ( !i )
      break;
    v3 = i - 5;
    if ( !memcmp((unsigned int)(i - 5), a1, 16) )
      break;
  }
  return v3;
}
