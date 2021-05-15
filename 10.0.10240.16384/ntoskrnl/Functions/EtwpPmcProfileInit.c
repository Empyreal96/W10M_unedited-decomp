// EtwpPmcProfileInit 
 
int EtwpPmcProfileInit()
{
  unsigned int v0; // r6
  int v1; // r5
  int result; // r0

  v0 = 0;
  if ( EtwpPmcProfile )
  {
    v1 = 0;
    do
    {
      result = KeStartProfile(v1 + dword_61AA64);
      ++v0;
      v1 += 52;
    }
    while ( v0 < EtwpPmcProfile );
  }
  return result;
}
