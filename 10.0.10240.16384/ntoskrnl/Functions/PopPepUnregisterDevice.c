// PopPepUnregisterDevice 
 
unsigned int __fastcall PopPepUnregisterDevice(int *a1, int a2)
{
  unsigned int v3; // r6
  int *v4; // r4

  DbgPrintEx(146, 3, (int)"PopPep: unregister device (0x%p)\n", (int)a1);
  PopPepProcessEvent((int)a1, 0, 6, 5u, a2, 0);
  KeWaitForSingleObject((unsigned int)(a1 + 7), 0, 0, 0, 0);
  PopPepWaitForDeviceRelease((int)a1);
  PopPepRemoveDevice(a1);
  PopPepUpdateIdleStateRefCount(a1[24], 0, 0);
  v3 = 0;
  if ( a1[30] )
  {
    v4 = a1;
    do
    {
      PopPepUpdateIdleStateRefCount(*(_DWORD *)(v4[72] + 16), 0, 0);
      ++v3;
      v4 += 42;
    }
    while ( v3 < a1[30] );
  }
  return ExFreePoolWithTag((unsigned int)a1);
}
