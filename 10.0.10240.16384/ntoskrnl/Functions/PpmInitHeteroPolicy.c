// PpmInitHeteroPolicy 
 
__int64 PpmInitHeteroPolicy()
{
  unsigned int v0; // r2
  __int64 result; // r0
  char *v2; // r3

  PpmHeteroMinRelativePerformance = 0x10000;
  v0 = 0;
  do
  {
    if ( v0 )
      result = 0x3200000050i64;
    else
      result = 0x1E0000005Ai64;
    v2 = (char *)&PpmDefaultProfile + v0++;
    v2[168] = result;
    v2[344] = result;
    v2[136] = BYTE4(result);
    v2[312] = BYTE4(result);
  }
  while ( v0 < 0x20 );
  byte_61DC26 = 3;
  byte_61DCD6 = 3;
  byte_61DC68 = 50;
  byte_61DD18 = 50;
  byte_61DC69 = 50;
  byte_61DD19 = 50;
  return result;
}
