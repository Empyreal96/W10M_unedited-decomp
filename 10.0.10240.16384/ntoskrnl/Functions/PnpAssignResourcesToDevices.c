// PnpAssignResourcesToDevices 
 
int __fastcall PnpAssignResourcesToDevices(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r5
  int v5; // r8
  _DWORD *v6; // r4
  int v7; // r7
  int v8; // r1
  char v10[4]; // [sp+20h] [bp-30h] BYREF
  int v11; // [sp+24h] [bp-2Ch] BYREF
  int v12; // [sp+28h] [bp-28h] BYREF
  int v13; // [sp+2Ch] [bp-24h]
  int v14; // [sp+30h] [bp-20h]

  v3 = a2;
  v4 = a1;
  v13 = a2;
  v14 = a3;
  v5 = a3;
  if ( a1 )
  {
    v6 = (_DWORD *)a2;
    v7 = a1;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)(*v6 + 176) + 20);
      if ( (*(_DWORD *)(v8 + 268) & 1) != 0 )
      {
        v11 = 0;
        v12 = 0;
        v10[0] = 0;
        if ( PnpGetObjectProperty(
               PiPnpRtlCtx,
               *(_DWORD *)(v8 + 24),
               1,
               0,
               0,
               (int)DEVPKEY_Device_Reported,
               (int)&v11,
               (int)v10,
               1,
               (int)&v12,
               0) >= 0
          && v11 == 17
          && v12 == 1
          && v10[0] == -1 )
        {
          v6[2] = 0;
        }
      }
      v6 += 10;
      --v7;
    }
    while ( v7 );
    v3 = v13;
    v5 = v14;
  }
  return PnpAllocateResources(v4, v3, 0, v5);
}
