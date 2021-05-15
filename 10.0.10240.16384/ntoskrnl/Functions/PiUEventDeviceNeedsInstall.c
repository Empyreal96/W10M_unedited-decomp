// PiUEventDeviceNeedsInstall 
 
int __fastcall PiUEventDeviceNeedsInstall(int a1, _BYTE *a2)
{
  int v3; // r5
  int v5; // r0
  int result; // r0
  int v7; // [sp+20h] [bp-28h] BYREF
  int v8; // [sp+24h] [bp-24h] BYREF
  char v9[4]; // [sp+28h] [bp-20h] BYREF
  char v10[4]; // [sp+2Ch] [bp-1Ch] BYREF
  int v11[6]; // [sp+30h] [bp-18h] BYREF

  v7 = 0;
  v8 = 0;
  v11[0] = 0;
  v3 = a1;
  v5 = PiPnpRtlCtx;
  *a2 = 0;
  result = PnpGetObjectProperty(v5, a1, 1, 0, 0, (int)DEVPKEY_Device_DevNodeStatus, (int)v10, (int)&v7, 4, (int)v9, 0);
  if ( result >= 0 )
  {
    result = PnpGetObjectProperty(
               PiPnpRtlCtx,
               v3,
               1,
               0,
               0,
               (int)DEVPKEY_Device_ProblemCode,
               (int)v10,
               (int)&v8,
               4,
               (int)v9,
               0);
    if ( result >= 0 )
    {
      if ( (v7 & 0x40000) != 0 || (v7 & 0x400) != 0 && v8 == 22 )
      {
        *a2 = 0;
      }
      else if ( (v7 & 0x400) != 0 && (v8 == 18 || v8 == 1)
             || (result = PnpGetObjectProperty(
                            PiPnpRtlCtx,
                            v3,
                            1,
                            0,
                            0,
                            (int)DEVPKEY_Device_ConfigFlags,
                            (int)v10,
                            (int)v11,
                            4,
                            (int)v9,
                            0),
                 result >= 0)
             && (v11[0] & 0x420) != 0 )
      {
        *a2 = 1;
      }
    }
  }
  return result;
}
