// CmpCanGrowHive 
 
int __fastcall CmpCanGrowHive(void *a1, unsigned int a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r3

  if ( a2 > 0x7FFFE000 )
    return 0;
  if ( a1 != off_60E8A4 )
    return 1;
  v3 = a2 + 4096;
  if ( a2 + 4096 > CmSystemHiveLimitSize )
    return 0;
  if ( (MmGetNumberOfPhysicalPages(0) & 0xFFFFFFFE) >= 0x32000 )
    v4 = 102400;
  else
    v4 = (unsigned int)MmGetNumberOfPhysicalPages(0) >> 1;
  if ( v3 <= 36864 * v4 / 0xA )
    return 1;
  return sub_80A330();
}
