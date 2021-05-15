// PspRateControlLimitFlag 
 
int __fastcall PspRateControlLimitFlag(int a1)
{
  if ( !a1 )
    return 0x100000;
  if ( a1 == 1 )
    return 0x80000;
  return 0x40000;
}
