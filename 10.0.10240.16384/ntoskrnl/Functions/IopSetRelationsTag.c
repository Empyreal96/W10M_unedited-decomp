// IopSetRelationsTag 
 
int __fastcall IopSetRelationsTag(_DWORD **a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  if ( !PipIsDeviceInDeviceObjectList(*a1, a2, (int)&v6) )
    return -1073741810;
  if ( (*(_DWORD *)(v6 + 12) & 1) != 0 )
    return sub_819868();
  *(_DWORD *)(v6 + 12) |= 1u;
  ++(*a1)[2];
  return 0;
}
