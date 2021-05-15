// WmiSetNetworkNotify 
 
int __fastcall WmiSetNetworkNotify(int a1, int a2)
{
  int v2; // r4
  int v3; // r5
  unsigned int v6; // [sp+8h] [bp-10h] BYREF
  int v7[3]; // [sp+Ch] [bp-Ch] BYREF
  _DWORD vars8[2]; // [sp+20h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  v6 = 0;
  v7[0] = 0;
  v2 = WmipBuildTraceDeviceList(0x200000, v7, &v6);
  v3 = v7[0];
  if ( v2 >= 0 )
  {
    v2 = WmipSendWmiIrpToTraceDeviceList(v7[0], v6, 10, 4, vars8, a2);
    if ( v2 >= 0 )
      v2 = 0;
  }
  if ( v3 )
    WmipFreeTraceDeviceList(v3, v6);
  return v2;
}
