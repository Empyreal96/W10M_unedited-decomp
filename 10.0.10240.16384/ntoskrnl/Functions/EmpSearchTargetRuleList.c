// EmpSearchTargetRuleList 
 
_DWORD *__fastcall EmpSearchTargetRuleList(int a1)
{
  _DWORD *i; // r2
  _DWORD *result; // r0

  for ( i = (_DWORD *)EmpTargetRuleListHead; ; i = (_DWORD *)*i )
  {
    result = 0;
    if ( !i )
      break;
    result = i - 4;
    if ( *(i - 3) == a1 )
      break;
  }
  return result;
}
