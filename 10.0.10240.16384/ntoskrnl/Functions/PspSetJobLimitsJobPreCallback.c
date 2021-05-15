// PspSetJobLimitsJobPreCallback 
 
int __fastcall PspSetJobLimitsJobPreCallback(int a1, int a2)
{
  int v3; // r0
  int result; // r0

  v3 = PspSetEffectiveJobLimits(a1, a2);
  if ( (*(_DWORD *)(a2 + 4) & 1) != 0 )
    result = 0;
  else
    result = sub_7E9904(v3);
  return result;
}
