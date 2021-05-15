// IopDeleteDriver 
 
int __fastcall IopDeleteDriver(_DWORD *a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r4
  int result; // r0
  unsigned int v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r0

  v2 = *(_DWORD **)(a1[6] + 20);
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      ExFreePoolWithTag((unsigned int)v2);
      v2 = v3;
    }
    while ( v3 );
  }
  if ( (a1[2] & 0x200) != 0 )
    return sub_7CEE58();
  if ( a1[5] )
  {
    KeFlushQueuedDpcs();
    MmUnloadSystemImage(a1[5]);
    PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 2, 0, 38, 0, 0);
  }
  v5 = a1[8];
  if ( v5 )
    ExFreePoolWithTag(v5);
  v6 = *(_DWORD *)(a1[6] + 16);
  if ( v6 )
    ExFreePoolWithTag(v6);
  v7 = *(_DWORD *)(a1[6] + 24);
  if ( v7 )
    ExFreePoolWithTag(v7);
  result = *(_DWORD *)(a1[6] + 28);
  if ( result )
    result = ExFreePoolWithTag(result);
  return result;
}
