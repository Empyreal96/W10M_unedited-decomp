// PiQueryResourceRequirements 
 
int __fastcall PiQueryResourceRequirements(_DWORD *a1)
{
  int v2; // r0
  unsigned __int8 v3; // r6
  int v4; // r8
  unsigned int v5; // r4
  int v6; // r2
  int v7; // r0
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r1
  int v14; // r3
  int v15; // [sp+10h] [bp-28h] BYREF
  unsigned int v16; // [sp+14h] [bp-24h] BYREF
  __int16 v17; // [sp+18h] [bp-20h]
  __int16 v18; // [sp+1Ah] [bp-1Eh]
  const __int16 *v19; // [sp+1Ch] [bp-1Ch]

  v2 = a1[4];
  v3 = 0;
  v15 = 0;
  v4 = PpIrpQueryResourceRequirements(v2, &v16);
  if ( v4 >= 0 )
    v5 = v16;
  else
    v5 = 0;
  v6 = a1[67] & 0x2000;
  if ( v6 && a1[69] == 9 || v6 && ((v12 = a1[69], v12 == 3) || v12 == 19) )
  {
    v7 = v15;
LABEL_10:
    if ( !v5 )
    {
LABEL_11:
      if ( v7 )
        ZwClose();
      return v4;
    }
    ExFreePoolWithTag(v5);
LABEL_28:
    v7 = v15;
    goto LABEL_11;
  }
  if ( v5 )
    v3 = 1;
  if ( CmOpenDeviceRegKey(PiPnpRtlCtx, a1[6], 20, 0, 983103, v3, (int)&v15, 0) >= 0 )
  {
    v7 = v15;
  }
  else
  {
    v7 = 0;
    v15 = 0;
  }
  if ( !v7 )
    goto LABEL_10;
  v18 = 36;
  v17 = 34;
  v19 = L"BasicConfigVector";
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  if ( !v5 )
  {
    ZwDeleteValueKey();
    ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 )
      JUMPOUT(0x7C9B62);
    goto LABEL_28;
  }
  ZwSetValueKey();
  KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
  v10 = KfRaiseIrql(1);
  do
    v11 = __ldrex((unsigned __int8 *)&PiResourceListLock);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    JUMPOUT(0x7C9B00);
  return sub_7C9AF8(v10);
}
