// IopWriteAllocatedResourcesToRegistry 
 
int __fastcall IopWriteAllocatedResourcesToRegistry(int a1, int a2)
{
  unsigned int v4; // r4
  int v5; // r4
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r3
  int result; // r0
  int v11; // [sp+10h] [bp-20h] BYREF
  __int16 v12; // [sp+18h] [bp-18h]
  __int16 v13; // [sp+1Ah] [bp-16h]
  const __int16 *v14; // [sp+1Ch] [bp-14h]

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  v5 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 19, 0, 983103, 1u, (int)&v11, 0);
  if ( v5 >= 0 )
  {
    v13 = 24;
    v12 = 22;
    v14 = L"AllocConfig";
    if ( a2 )
      v6 = ZwSetValueKey();
    else
      v6 = ZwDeleteValueKey();
    v5 = v6;
    ZwClose();
  }
  v7 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
  *(_WORD *)(v8 + 308) = v9;
  if ( v9 )
    result = v5;
  else
    result = sub_80DB50(v7);
  return result;
}
