// PopPepStartDeviceUnregisterActivity 
 
int __fastcall PopPepStartDeviceUnregisterActivity(int a1)
{
  KeSetEvent(a1 + 28, 0, 0);
  return 0;
}
