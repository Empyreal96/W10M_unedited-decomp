// WmiTraceRundownNotify 
 
int __fastcall WmiTraceRundownNotify(int a1)
{
  int v1; // r4
  int v2; // r5
  unsigned int v4; // [sp+8h] [bp-20h] BYREF
  int v5; // [sp+Ch] [bp-1Ch] BYREF
  int v6[6]; // [sp+10h] [bp-18h] BYREF

  v4 = 0;
  v5 = 0;
  v6[1] = a1;
  v6[0] = 1;
  v6[2] = 0x400000;
  v1 = WmipBuildTraceDeviceList(0x400000, &v5, &v4);
  v2 = v5;
  if ( v1 >= 0 )
  {
    v1 = WmipSendWmiIrpToTraceDeviceList(v5, v4, 12, 12, v6);
    if ( v1 >= 0 )
      v1 = 0;
  }
  if ( v2 )
    WmipFreeTraceDeviceList(v2, v4);
  return v1;
}
