// PopFxQueryBiosDeviceName 
 
int __fastcall PopFxQueryBiosDeviceName(int a1, int a2)
{
  int v4; // r6
  __int16 v5; // r4
  int result; // r0
  unsigned int v7; // [sp+10h] [bp-20h]

  v4 = 0;
  v5 = 0;
  result = IoGetDevicePropertyData(*(_DWORD *)(a1 + 16), DEVPKEY_Device_BiosDeviceName, 0);
  if ( result == -1073741789 )
  {
    if ( v7 >= 0xFFFE )
      return result;
    v4 = ExAllocatePoolWithTag(512, v7);
    if ( !v4 )
      return -1073741670;
    result = 0;
    v5 = v7;
  }
  if ( result >= 0 )
  {
    result = IoGetDevicePropertyData(*(_DWORD *)(a1 + 16), DEVPKEY_Device_BiosDeviceName, 0);
    if ( result >= 0 )
    {
      *(_WORD *)a2 = v5 - 2;
      *(_WORD *)(a2 + 2) = v5;
      *(_DWORD *)(a2 + 4) = v4;
    }
  }
  return result;
}
