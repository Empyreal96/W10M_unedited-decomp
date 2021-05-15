// ElapsedDaysToYears 
 
unsigned int __fastcall ElapsedDaysToYears(unsigned int a1)
{
  unsigned int v1; // r5
  unsigned int v2; // r0

  v1 = a1 / 0x23AB1;
  v2 = a1 % 0x23AB1;
  return 4 * (25 * ((100 * v2 + 75) / 0x37BB49 + 4 * v1) + (v2 - 36524 * ((100 * v2 + 75) / 0x37BB49)) / 0x5B5)
       + (100 * ((v2 - 36524 * ((100 * v2 + 75) / 0x37BB49)) % 0x5B5) + 75) / 0x8EAD;
}
