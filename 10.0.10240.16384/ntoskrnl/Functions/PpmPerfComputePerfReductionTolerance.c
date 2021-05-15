// PpmPerfComputePerfReductionTolerance 
 
int __fastcall PpmPerfComputePerfReductionTolerance(unsigned int a1)
{
  int v1; // r2
  char *v2; // r1
  unsigned int v3; // t1

  v1 = 0;
  if ( a1 < 0x5F )
  {
    v2 = &PpmPerfReductionBoostPolicies;
    do
    {
      v3 = (unsigned __int8)*++v2;
      ++v1;
    }
    while ( a1 < v3 );
  }
  return *((unsigned __int8 *)PpmPerfReductionOffsetPercent + v1);
}
