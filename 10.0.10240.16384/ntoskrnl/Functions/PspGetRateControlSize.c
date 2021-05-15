// PspGetRateControlSize 
 
int __fastcall PspGetRateControlSize(int a1)
{
  if ( !a1 )
    return 48;
  if ( a1 == 1 )
    return 20;
  return KeGetSchedulingGroupSize() + 128;
}
