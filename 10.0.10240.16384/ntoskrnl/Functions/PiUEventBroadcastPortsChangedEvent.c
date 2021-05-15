// PiUEventBroadcastPortsChangedEvent 
 
int __fastcall PiUEventBroadcastPortsChangedEvent(int a1, int *a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int result; // r0
  int v12; // [sp+10h] [bp-50h] BYREF
  unsigned int v13; // [sp+14h] [bp-4Ch] BYREF
  int v14; // [sp+18h] [bp-48h] BYREF
  int v15; // [sp+20h] [bp-40h]
  _DWORD var3C[16]; // [sp+24h] [bp-3Ch] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  int *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v15 = 0;
  memset(var3C, 0, 44);
  v12 = 0;
  v14 = 0;
  v6 = CmOpenDeviceRegKey(PiPnpRtlCtx, a3, 17, 0, 131097, 0, (int)&v12, 0);
  if ( v6 >= 0 )
  {
    v13 = 32;
    if ( PnpCtxRegQueryValue(v6, v12, L"PortName", &v14, (int)&var3C[3], &v13) >= 0 )
    {
      v7 = a2[1];
      v8 = a2[2];
      v9 = a2[3];
      v15 = *a2;
      var3C[0] = v7;
      var3C[1] = v8;
      var3C[2] = v9;
      if ( varg_r0 == -1 )
      {
        ZwUpdateWnfStateData();
      }
      else
      {
        v10 = MmGetSessionById(varg_r0, v7, v8, v9);
        if ( v10 )
        {
          ZwUpdateWnfStateData();
          ObfDereferenceObject(v10);
        }
      }
    }
  }
  result = v12;
  if ( v12 )
    result = ZwClose();
  return result;
}
