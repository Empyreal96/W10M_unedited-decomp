// PpmResetIdlePolicy 
 
_DWORD *__fastcall PpmResetIdlePolicy(_DWORD *result)
{
  int v1; // r4

  v1 = (int)result;
  if ( *result )
  {
    PpmApplyIdlePolicy();
    PpmScaleIdleStateValues(v1);
    result = (_DWORD *)PpmResetIdleAccounting(v1);
  }
  return result;
}
