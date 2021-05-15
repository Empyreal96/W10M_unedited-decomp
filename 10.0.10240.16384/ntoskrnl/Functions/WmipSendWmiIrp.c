// WmipSendWmiIrp 
 
int __fastcall WmipSendWmiIrp(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r0
  int v9; // r5
  int v10; // r2
  int v11; // r4

  while ( 1 )
  {
    v8 = IoAllocateIrp(*(_BYTE *)(WmipServiceDeviceObject + 48) + 1, 0);
    v9 = v8;
    if ( !v8 )
      break;
    --*(_BYTE *)(v8 + 35);
    v10 = *(_DWORD *)(v8 + 96) - 40;
    *(_DWORD *)(v8 + 96) = v10;
    *(_DWORD *)(v10 + 24) = WmipServiceDeviceObject;
    *(_DWORD *)(v8 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v8 + 12) = a5;
    v11 = WmipForwardWmiIrp((_DWORD *)v8, a1, a2, a3, a4, a5);
    *a6 = *(_DWORD *)(v9 + 24);
    a6[1] = *(_DWORD *)(v9 + 28);
    IoFreeIrp(v9);
    if ( v11 != -1073741160 )
      return v11;
  }
  return -1073741670;
}
