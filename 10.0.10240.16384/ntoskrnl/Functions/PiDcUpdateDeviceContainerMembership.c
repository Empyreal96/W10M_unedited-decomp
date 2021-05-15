// PiDcUpdateDeviceContainerMembership 
 
int __fastcall PiDcUpdateDeviceContainerMembership(int a1, int a2, unsigned __int16 *a3)
{
  int v6; // r4
  unsigned int v8; // r0
  char v9[4]; // [sp+10h] [bp-118h] BYREF
  int v10; // [sp+14h] [bp-114h] BYREF
  int v11; // [sp+18h] [bp-110h] BYREF
  char v12[4]; // [sp+1Ch] [bp-10Ch] BYREF
  unsigned __int16 v13[80]; // [sp+20h] [bp-108h] BYREF
  char v14[104]; // [sp+C0h] [bp-68h] BYREF

  v10 = 0;
  v6 = PiPnpRtlBeginOperation(&v10, a2, (int)a3, 0);
  if ( v6 >= 0 )
  {
    v11 = 78;
    v6 = CmGetDeviceRegProp(PiPnpRtlCtx, a1, a2, 37, (int)v12, (int)v13, (int)&v11);
    if ( v6 >= 0 && wcsicmp((int)a3, v13) )
      return sub_7CB918();
    if ( v6 == -1073741275 )
      v6 = 0;
    if ( v6 >= 0 )
    {
      v6 = CmGetDeviceContainerIdFromBase(PiPnpRtlCtx, a1, a3, v14);
      if ( v6 >= 0 )
      {
        v8 = wcslen(a3);
        v6 = CmSetDeviceRegProp(PiPnpRtlCtx, a1, a2, 37, 1, (int)a3, 2 * (v8 + 1), 0);
        if ( v6 >= 0 && !PnpIsNullGuidString(a3) )
        {
          v6 = CmAddDeviceToContainer(PiPnpRtlCtx, v14, a3, a1, v9);
          if ( v6 >= 0 && !v9[0] )
            PiDcContainerRequiresConfiguration(v14);
        }
      }
    }
  }
  if ( v10 )
    PiPnpRtlEndOperation(v10);
  return v6;
}
