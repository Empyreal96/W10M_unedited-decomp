// PspNotificationLimitRateControlToleranceField 
 
int __fastcall PspNotificationLimitRateControlToleranceField(int a1, int a2)
{
  if ( !a2 )
    return a1 + 60;
  if ( a2 == 1 )
    return a1 + 44;
  return a1 + 32;
}
