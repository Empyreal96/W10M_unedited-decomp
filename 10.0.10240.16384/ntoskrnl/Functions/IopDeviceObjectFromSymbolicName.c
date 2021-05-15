// IopDeviceObjectFromSymbolicName 
 
int __fastcall IopDeviceObjectFromSymbolicName(int a1)
{
  int v2; // r7
  unsigned __int16 *v3; // r6
  int v4; // r4
  int v6; // [sp+20h] [bp-28h] BYREF
  unsigned int v7; // [sp+24h] [bp-24h] BYREF
  int v8; // [sp+28h] [bp-20h] BYREF
  char v9[24]; // [sp+30h] [bp-18h] BYREF

  v2 = 0;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 4) )
    {
      if ( *(_WORD *)a1 )
      {
        if ( PnpUnicodeStringToWstr((int *)&v7, 0, (unsigned __int16 *)a1) >= 0 )
        {
          v6 = 400;
          v3 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 400, 1198550608);
          if ( v3 )
          {
            v4 = PnpGetObjectProperty(
                   PiPnpRtlCtx,
                   v7,
                   3,
                   0,
                   0,
                   (int)DEVPKEY_Device_InstanceId,
                   (int)&v8,
                   (int)v3,
                   v6,
                   (int)&v6,
                   0);
            PnpUnicodeStringToWstrFree(v7, a1);
            if ( v4 >= 0 && v8 == 18 && RtlInitUnicodeStringEx((int)v9, v3) >= 0 )
              v2 = PnpDeviceObjectFromDeviceInstance((int)v9);
            ExFreePoolWithTag((unsigned int)v3);
          }
        }
      }
    }
  }
  return v2;
}
