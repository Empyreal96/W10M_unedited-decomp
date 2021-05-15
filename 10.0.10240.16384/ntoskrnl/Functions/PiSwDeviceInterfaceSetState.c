// PiSwDeviceInterfaceSetState 
 
int __fastcall PiSwDeviceInterfaceSetState(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  unsigned __int16 *v5; // r4
  int v6; // r5
  int v9; // r3
  int v10; // r0
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v4 = *(_DWORD *)(a1 + 64);
  v5 = 0;
  v6 = 0;
  v12[0] = 0;
  if ( !v4
    || (v9 = *(_DWORD *)(v4 + 40)) == 0
    || (*(_DWORD *)(v9 + 4) & 1) == 0
    || *(unsigned __int8 *)(a2 + 20) == a3
    || (v10 = PnpAllocatePWSTR(*(unsigned __int16 **)(a2 + 8), 0x7FFFFFFFu, 1466986064, v12),
        v6 = v10,
        v5 = (unsigned __int16 *)v12[0],
        v10 >= 0)
    && (v6 = CmSetDeviceInterfacePathFormat(v10, v12[0], 1), v6 >= 0)
    && (RtlInitUnicodeString((unsigned int)v12, v5), v6 = IoSetDeviceInterfaceState((int)v12, a3), v6 >= 0) )
  {
    *(_BYTE *)(a2 + 20) = a3;
  }
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  return v6;
}
