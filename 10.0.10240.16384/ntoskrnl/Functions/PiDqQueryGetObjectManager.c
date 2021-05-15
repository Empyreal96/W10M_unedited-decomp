// PiDqQueryGetObjectManager 
 
void *__fastcall PiDqQueryGetObjectManager(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 16);
  switch ( v1 )
  {
    case 1:
      return &PiDqDeviceInterfaceManager;
    case 2:
      return &PiDqDeviceContainerManager;
    case 3:
      return &PiDqDeviceManager;
  }
  return (void *)sub_7C76B0();
}
