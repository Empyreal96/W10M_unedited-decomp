// EmpSearchRuleDatabase 
 
_DWORD *__fastcall EmpSearchRuleDatabase(unsigned int a1)
{
  _DWORD *i; // r4
  _DWORD *v3; // r5

  for ( i = (_DWORD *)EmpRuleListHead; ; i = (_DWORD *)*i )
  {
    v3 = 0;
    if ( !i )
      break;
    v3 = i - 6;
    if ( !memcmp((unsigned int)(i - 6), a1, 16) )
      break;
  }
  return v3;
}
