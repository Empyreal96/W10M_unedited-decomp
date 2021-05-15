// EmpRuleParserStackPush 
 
_DWORD *__fastcall EmpRuleParserStackPush(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(1, 20, 1953713477);
  if ( result )
  {
    *result = a2;
    result[1] = a3;
    result[2] = a4;
    result[3] = a5;
    result[4] = a1[1];
    a1[1] = result + 4;
    ++*a1;
  }
  return result;
}
