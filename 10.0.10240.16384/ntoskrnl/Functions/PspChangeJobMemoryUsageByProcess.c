// PspChangeJobMemoryUsageByProcess 
 
int __fastcall PspChangeJobMemoryUsageByProcess(char a1)
{
  int result; // r0

  if ( (a1 & 0x10) != 0 )
    result = sub_8061E8();
  else
    result = 1;
  return result;
}
