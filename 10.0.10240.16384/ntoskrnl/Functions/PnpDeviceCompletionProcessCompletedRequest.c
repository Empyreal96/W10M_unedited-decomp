// PnpDeviceCompletionProcessCompletedRequest 
 
int __fastcall PnpDeviceCompletionProcessCompletedRequest(_DWORD *a1)
{
  _DWORD *v2; // r4
  int v3; // r0
  int v4; // r2
  int v5; // r2
  int v6; // r1
  int v7; // r0
  int v8; // r3

  v2 = (_DWORD *)a1[2];
  v2[88] = a1[7];
  v2[66] = a1[6];
  v3 = PipSetDevNodeState(v2, a1[4]);
  if ( (int)a1[6] >= 0 )
  {
    v4 = a1[4];
    if ( v4 == 774 || v4 == 779 )
    {
      v5 = v2[4];
      v6 = 0;
      v7 = v5;
      if ( v5 )
      {
        do
        {
          v8 = *(_DWORD *)(v7 + 32);
          v7 = *(_DWORD *)(v7 + 16);
          v6 |= v8 & 0x40000;
        }
        while ( v7 );
        if ( v6 )
        {
          do
          {
            *(_DWORD *)(v5 + 32) |= v6;
            v5 = *(_DWORD *)(v5 + 16);
          }
          while ( v5 );
        }
      }
      PnpSetObjectProperty(PiPnpRtlCtx, v2[6], 1, 0, 0, (int)DEVPKEY_Device_DriverProblemDesc, 0, 0, 0, 0);
      v3 = PiSwProcessParentStartIrp(v2[4]);
    }
  }
  if ( a1[4] == 781 )
  {
    if ( (v2[114] & 0x80) == 0 )
      sub_7CADC4(v3);
    PoFxIdleDevice(v2[4]);
    v2[114] &= 0xFFFFFF7F;
  }
  PnpDeviceCompletionRequestDestroy((int)a1);
  return v2[66];
}
