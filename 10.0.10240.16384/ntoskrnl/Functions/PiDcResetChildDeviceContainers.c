// PiDcResetChildDeviceContainers 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDcResetChildDeviceContainers(int a1, int a2)
{
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r0
  int v6; // r0
  int v7; // r1 OVERLAPPED
  _DWORD v9[2]; // [sp+10h] [bp-88h] BYREF
  int v10[2]; // [sp+18h] [bp-80h] BYREF
  int v11; // [sp+20h] [bp-78h] BYREF
  int v12; // [sp+24h] [bp-74h] BYREF
  char v13[112]; // [sp+28h] [bp-70h] BYREF

  v10[1] = (int)v10;
  v9[0] = a1;
  v9[1] = a2;
  v10[0] = (int)v10;
  v3 = 0;
  if ( wcsicmp(a2, L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}") )
  {
    CmEnumDevicesInContainerWithCallback(PiPnpRtlCtx, a2, 0, PiDcResetChildDeviceContainerCallback, v9);
    v4 = v10[0];
    if ( (int *)v10[0] == v10 )
      goto LABEL_14;
    do
    {
      v11 = 78;
      v5 = CmGetDeviceRegProp(PiPnpRtlCtx, v4 + 8, 0, 37, (int)&v12, (int)v13, (int)&v11);
      v3 = v5;
      if ( v5 == -1073741275 || v12 != 1 || v11 != 78 )
        goto LABEL_11;
      if ( v5 < 0 )
        break;
      v3 = CmRemoveDeviceFromContainer(PiPnpRtlCtx, a2, v13, v4 + 8);
      if ( v3 < 0 )
        break;
      v6 = CmSetDeviceRegProp(PiPnpRtlCtx, v4 + 8, 0, 37, 1, 0, 0, 0);
      v3 = v6;
      if ( v6 == -1073741275 )
      {
LABEL_11:
        v3 = 0;
      }
      else if ( v6 < 0 )
      {
        break;
      }
      v4 = *(_DWORD *)v4;
    }
    while ( (int *)v4 != v10 );
  }
  while ( 1 )
  {
    v4 = v10[0];
LABEL_14:
    if ( (int *)v4 == v10 )
      break;
    *(_QWORD *)&v7 = *(_QWORD *)v4;
    if ( *(int **)(v4 + 4) != v10 || *(_DWORD *)(v7 + 4) != v4 )
      __fastfail(3u);
    v10[0] = v7;
    *(_DWORD *)(v7 + 4) = v10;
    ExFreePoolWithTag(v4);
  }
  return v3;
}
