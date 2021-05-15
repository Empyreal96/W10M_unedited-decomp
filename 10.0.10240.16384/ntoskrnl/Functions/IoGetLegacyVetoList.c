// IoGetLegacyVetoList 
 
int __fastcall IoGetLegacyVetoList(unsigned int *a1, _DWORD *a2)
{
  int result; // r0
  int v5; // r1
  int v6; // [sp+0h] [bp-30h] BYREF
  _DWORD v7[8]; // [sp+10h] [bp-20h] BYREF

  if ( a1 )
    *a1 = 0;
  v6 = 0;
  *a2 = 0;
  if ( !PnPInitialized )
    return 0;
  v7[0] = a1;
  v7[1] = 0;
  v7[2] = a2;
  v7[3] = &v6;
  IopGetLegacyVetoListDrivers(v7);
  result = v6;
  if ( v6 < 0 )
    goto LABEL_18;
  if ( !*a2 )
  {
    PpDevNodeLockTree(0, v5);
    IopGetLegacyVetoListDeviceNode(IopRootDeviceNode, v7);
    PpDevNodeUnlockTree(0);
    result = v6;
  }
  if ( result < 0 )
  {
LABEL_18:
    if ( a1 && *a1 )
    {
      ExFreePoolWithTag(*a1);
      result = v6;
      *a1 = 0;
    }
  }
  else if ( *a2 )
  {
    result = sub_7BDE1C();
  }
  return result;
}
