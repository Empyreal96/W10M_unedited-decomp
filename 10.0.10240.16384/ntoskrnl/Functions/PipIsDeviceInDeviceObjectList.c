// PipIsDeviceInDeviceObjectList 
 
BOOL __fastcall PipIsDeviceInDeviceObjectList(_DWORD *a1, int a2, int a3)
{
  return PipDeviceObjectListIndexOf(a1, a2, *a1, a3) != -1;
}
