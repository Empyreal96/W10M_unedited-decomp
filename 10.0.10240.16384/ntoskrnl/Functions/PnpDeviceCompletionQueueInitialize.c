// PnpDeviceCompletionQueueInitialize 
 
int PnpDeviceCompletionQueueInitialize()
{
  dword_630708 = 0;
  *(_QWORD *)&dword_6306E4 = (unsigned int)&PnpDeviceCompletionQueue;
  PnpDeviceCompletionQueue = (int)&PnpDeviceCompletionQueue;
  byte_6306F4 = 5;
  byte_6306F6 = 5;
  dword_6306F8 = 0;
  dword_630700 = (int)&dword_6306FC;
  dword_6306FC = (int)&dword_6306FC;
  dword_630704 = 0x7FFFFFFF;
  dword_6306F0 = (int)&dword_6306EC;
  dword_6306EC = (int)&dword_6306EC;
  return 0;
}
