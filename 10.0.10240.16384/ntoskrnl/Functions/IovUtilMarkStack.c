// IovUtilMarkStack 
 
int __fastcall IovUtilMarkStack(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r1
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v4 = a3;
  v5 = IovUtilVerifierEnabled;
  if ( IovUtilVerifierEnabled && a2 )
    return sub_5284C0();
  if ( a3 )
  {
    v8[0] = a3;
    if ( IovUtilVerifierEnabled )
    {
      result = VfDevObjAdjustFdoForVerifierFilters(v8);
      v4 = v8[0];
    }
    if ( v5 && v4 )
    {
      v7 = 2;
      v6 = v4;
      return IovpUtilMarkDeviceObject(v6, v7);
    }
  }
  else if ( IovUtilVerifierEnabled && a4 )
  {
    v6 = IovpUtilMarkDeviceObject(result, 2);
    v7 = 3;
    return IovpUtilMarkDeviceObject(v6, v7);
  }
  return result;
}
