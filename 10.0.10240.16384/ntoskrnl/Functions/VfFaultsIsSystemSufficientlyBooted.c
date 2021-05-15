// VfFaultsIsSystemSufficientlyBooted 
 
int __fastcall VfFaultsIsSystemSufficientlyBooted(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int result; // r0
  unsigned __int64 v5; // r0
  unsigned __int64 v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+8h] [bp-8h]

  v6 = __PAIR64__(a3, a2);
  v7 = a4;
  if ( ViSystemSufficientlyBooted )
    return 1;
  KeQuerySystemTime(&v6);
  LODWORD(v5) = _rt_udiv64(10000i64, v6 - KeBootTime);
  if ( v5 <= ViRequiredTimeSinceBootInMsecs )
  {
    result = ViSystemSufficientlyBooted;
    ++dword_908654;
  }
  else
  {
    result = 1;
    ViSystemSufficientlyBooted = 1;
  }
  return result;
}
