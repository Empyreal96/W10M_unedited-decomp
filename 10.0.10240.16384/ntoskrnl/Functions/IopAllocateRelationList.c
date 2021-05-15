// IopAllocateRelationList 
 
int __fastcall IopAllocateRelationList(int a1)
{
  int v2; // r4
  int v3; // r0

  v2 = PnpAllocateCriticalMemory(a1, 1, 8, 1416654416);
  if ( v2 )
  {
    v3 = PiAllocateDeviceObjectList(a1, 8);
    *(_DWORD *)v2 = v3;
    if ( !v3 )
      return sub_7DFAEC();
    *(_BYTE *)(v2 + 4) = 0;
  }
  return v2;
}
