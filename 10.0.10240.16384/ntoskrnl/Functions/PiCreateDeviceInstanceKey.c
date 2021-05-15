// PiCreateDeviceInstanceKey 
 
int __fastcall PiCreateDeviceInstanceKey(int a1, _DWORD *a2, int *a3, int a4)
{
  unsigned int v7; // r4
  int v8; // r4
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  int result; // r0
  int v14[6]; // [sp+8h] [bp-18h] BYREF

  v14[0] = a4;
  *a2 = 0;
  *a3 = 0;
  LOBYTE(v14[0]) = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  v8 = CmCreateDevice(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 983103, a2, v14, 0);
  if ( v8 >= 0 )
  {
    if ( LOBYTE(v14[0]) )
      v9 = 1;
    else
      v9 = 2;
    *a3 = v9;
  }
  v10 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
  *(_WORD *)(v11 + 308) = v12;
  if ( v12 )
    result = v8;
  else
    result = sub_7EF2B8(v10);
  return result;
}
