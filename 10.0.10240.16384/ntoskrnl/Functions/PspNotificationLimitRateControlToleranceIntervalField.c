// PspNotificationLimitRateControlToleranceIntervalField 
 
int __fastcall PspNotificationLimitRateControlToleranceIntervalField(int a1, int a2)
{
  if ( !a2 )
    return a1 + 64;
  if ( a2 == 1 )
    return a1 + 56;
  return a1 + 36;
}
