// PiAllocateDeviceObjectList 
 
_DWORD *__fastcall PiAllocateDeviceObjectList(int a1, int a2)
{
  _DWORD *v4; // r0
  _DWORD *v5; // r4

  v4 = (_DWORD *)PnpAllocateCriticalMemory(a1, 1, 16 * (a2 + 1), 1416654416);
  v5 = v4;
  if ( v4 )
  {
    *v4 = 0;
    v4[1] = a2;
    v4[2] = 0;
    v4[3] = a1;
    PiClearDeviceObjectList();
  }
  return v5;
}
