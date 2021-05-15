// PopPowerRequestFree 
 
unsigned int __fastcall PopPowerRequestFree(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
