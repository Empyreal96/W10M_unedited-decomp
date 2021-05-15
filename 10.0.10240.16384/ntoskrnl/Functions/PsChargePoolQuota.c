// PsChargePoolQuota 
 
int PsChargePoolQuota()
{
  int result; // r0

  result = PsChargeProcessPoolQuota();
  if ( result < 0 )
    j_RtlRaiseStatus_0();
  return result;
}
