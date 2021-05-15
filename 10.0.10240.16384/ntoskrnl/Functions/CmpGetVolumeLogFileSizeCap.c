// CmpGetVolumeLogFileSizeCap 
 
unsigned int CmpGetVolumeLogFileSizeCap()
{
  unsigned int result; // r0
  int v1; // r3
  unsigned int v2; // [sp+10h] [bp-28h]
  int v3; // [sp+14h] [bp-24h]
  unsigned int v4; // [sp+20h] [bp-18h]
  unsigned int v5; // [sp+24h] [bp-14h]

  if ( ZwQueryVolumeInformationFile() < 0 )
    return 0x2000000;
  result = ((((v5 * v4 * (unsigned __int64)v2) >> 32) + ((v5 * (unsigned __int64)v4) >> 32) * v2 + v5 * v4 * v3) << 21) | ((v5 * v4 * v2) >> 11);
  v1 = 0x2000000;
  if ( result >= 0x2000000 || (v1 = 0x80000, result <= 0x80000) )
    result = v1;
  return result;
}
