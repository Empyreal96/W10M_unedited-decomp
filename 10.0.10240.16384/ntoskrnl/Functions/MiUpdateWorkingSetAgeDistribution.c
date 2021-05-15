// MiUpdateWorkingSetAgeDistribution 
 
int __fastcall MiUpdateWorkingSetAgeDistribution(int result, int a2, int a3)
{
  if ( a2 )
  {
    *(_DWORD *)(result + 4 * (a2 - 1) + 20) += a3;
    if ( a2 == 7 )
      result = MiVolunteerForTrimFirst();
  }
  return result;
}
