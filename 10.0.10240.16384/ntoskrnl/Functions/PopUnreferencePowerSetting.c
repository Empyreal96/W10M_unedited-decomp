// PopUnreferencePowerSetting 
 
unsigned int __fastcall PopUnreferencePowerSetting(unsigned int a1)
{
  if ( (*(_DWORD *)a1)-- == 1 )
    a1 = ExFreePoolWithTag(a1);
  return a1;
}
