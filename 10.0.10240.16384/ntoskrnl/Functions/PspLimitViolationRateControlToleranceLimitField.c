// PspLimitViolationRateControlToleranceLimitField 
 
int __fastcall PspLimitViolationRateControlToleranceLimitField(int a1, int a2)
{
  if ( !a2 )
    return a1 + 100;
  if ( a2 == 1 )
    return a1 + 92;
  return a1 + 76;
}
