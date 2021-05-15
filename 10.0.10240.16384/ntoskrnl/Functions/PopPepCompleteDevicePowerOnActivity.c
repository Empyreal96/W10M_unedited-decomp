// PopPepCompleteDevicePowerOnActivity 
 
int __fastcall PopPepCompleteDevicePowerOnActivity(int result)
{
  *(_BYTE *)(result + 88) = 1;
  return result;
}
