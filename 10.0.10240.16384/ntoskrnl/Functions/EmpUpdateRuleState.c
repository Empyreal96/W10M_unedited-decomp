// EmpUpdateRuleState 
 
int *__fastcall EmpUpdateRuleState(int *result)
{
  int v1; // r4
  unsigned int v2; // r6
  int v3; // r7
  int v4; // r5
  int v5; // r2
  _DWORD *i; // r2
  _DWORD *j; // r2
  _DWORD *v8; // r6
  int v9; // t1

  v1 = (int)result;
  v2 = result[10];
  v3 = result[4];
  v4 = 1;
  v5 = 0;
  if ( v2 )
  {
    result = (int *)result[11];
    while ( 1 )
    {
      v9 = *result++;
      if ( *(int *)(v9 + 16) <= 0 )
        break;
      if ( ++v5 >= v2 )
        goto LABEL_2;
    }
LABEL_5:
    v4 = 0;
  }
  else
  {
LABEL_2:
    for ( i = *(_DWORD **)(v1 + 48); i; i = (_DWORD *)*i )
    {
      if ( !*(_DWORD *)(*(i - 1) + 16) )
        goto LABEL_5;
    }
    for ( j = *(_DWORD **)(v1 + 52); j; j = (_DWORD *)*j )
    {
      if ( !*(_BYTE *)(*(j - 1) + 20) )
        goto LABEL_5;
    }
  }
  if ( *(unsigned __int8 *)(v1 + 20) != v4 )
  {
    v8 = *(_DWORD **)(v1 + 28);
    *(_BYTE *)(v1 + 20) = v4;
    while ( v8 )
    {
      result = (int *)EmpUpdateRuleState(*(v8 - 1), 0);
      v8 = (_DWORD *)*v8;
    }
  }
  *(_BYTE *)(v1 + 20) = v4;
  if ( v4 )
  {
    if ( v3 == 1 )
      *(_DWORD *)(v1 + 16) = 0;
    result = EmpSearchTargetRuleList(v1);
    if ( result && *result > 0 )
      result = (int *)EmpEvaluateUpdateRuleEvalState();
  }
  else
  {
    *(_DWORD *)(v1 + 16) = 1;
  }
  if ( *(_DWORD *)(v1 + 16) != v3 && *(_DWORD *)(v1 + 56) != v1 + 56 )
    result = (int *)sub_52795C();
  return result;
}
