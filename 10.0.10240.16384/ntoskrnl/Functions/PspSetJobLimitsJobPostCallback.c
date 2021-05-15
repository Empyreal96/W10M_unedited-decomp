// PspSetJobLimitsJobPostCallback 
 
int __fastcall PspSetJobLimitsJobPostCallback(int a1, int a2)
{
  int result; // r0

  if ( (*(_DWORD *)(a2 + 4) & 1) != 0 )
    result = 0;
  else
    result = sub_7EB23C();
  return result;
}
