// PipFreeDeviceObjectList 
 
unsigned int __fastcall PipFreeDeviceObjectList(unsigned int a1)
{
  PiClearDeviceObjectList();
  return ExFreePoolWithTag(a1);
}
