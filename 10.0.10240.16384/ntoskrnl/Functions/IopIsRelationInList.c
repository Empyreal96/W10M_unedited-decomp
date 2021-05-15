// IopIsRelationInList 
 
BOOL __fastcall IopIsRelationInList(_DWORD **a1, int a2)
{
  return PipIsDeviceInDeviceObjectList(*a1, a2, 0);
}
