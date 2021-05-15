// PipMakeGloballyUniqueId 
 
int __fastcall PipMakeGloballyUniqueId(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  _WORD *v5; // r8
  unsigned __int16 *v6; // r5
  int v7; // r6
  unsigned int v8; // r4
  int v9; // r0
  int result; // r0
  int v11; // r7
  int v12; // r4
  unsigned int v13; // r7
  int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r0
  _WORD *v17; // r0
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  int v21; // r7
  unsigned __int16 *v22; // r0
  const __int16 *v23; // r1
  int v24; // r4
  unsigned int v25; // r5
  unsigned int v26; // r0
  int v27; // t1
  unsigned __int16 *v28; // r0
  int v29; // r3
  unsigned int v30; // [sp+18h] [bp-58h]
  int v31; // [sp+20h] [bp-50h] BYREF
  const __int16 *v32; // [sp+24h] [bp-4Ch]
  unsigned __int16 *v33; // [sp+28h] [bp-48h] BYREF
  int v34; // [sp+2Ch] [bp-44h] BYREF
  int v35; // [sp+30h] [bp-40h]
  int v36; // [sp+34h] [bp-3Ch]
  unsigned int v37; // [sp+38h] [bp-38h]
  _DWORD *v38; // [sp+3Ch] [bp-34h]
  int v39; // [sp+44h] [bp-2Ch]
  int v40; // [sp+48h] [bp-28h]
  int v41; // [sp+4Ch] [bp-24h]

  v38 = a3;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
  if ( !a1 )
    return sub_81609C(v9);
  v11 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  v12 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(v11 + 24), 16, 0, 131103, 0, (int)&v34, 0);
  if ( v12 >= 0 )
  {
    v31 = 1966108;
    v32 = L"UniqueParentID";
    v12 = ZwQueryValueKey();
    if ( v12 >= 0 )
    {
      if ( v39 == 4 && v40 == 4 )
      {
        v21 = v41;
        v22 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 18, 1852141648);
        v6 = v22;
        if ( v22 )
        {
          RtlStringCbPrintfW(v22, 0x12u, (int)L"%x", v21);
LABEL_10:
          v15 = wcslen(v6);
          if ( a2 )
            v16 = wcslen(a2);
          else
            v16 = 0;
          v30 = v16 + v15 + 2;
          v17 = (_WORD *)ExAllocatePoolWithTag(1, 2 * v30, 1852141648);
          v5 = v17;
          if ( v17 )
          {
            if ( a2 )
              RtlStringCchPrintfW(v17, v30, (int)L"%s&%s", (int)v6);
            else
              RtlStringCchCopyW(v17, v30, (int)v6);
            goto LABEL_15;
          }
        }
LABEL_25:
        v12 = -1073741670;
        goto LABEL_15;
      }
    }
    else
    {
      v31 = 1966108;
      v32 = L"ParentIdPrefix";
      v7 = ExAllocatePoolWithTag(1, 66, 1852141648);
      if ( !v7 )
        goto LABEL_25;
      v12 = ZwQueryValueKey();
      if ( v12 < 0 )
      {
        v12 = RtlUpcaseUnicodeString((unsigned __int16 *)&v31, (unsigned __int16 *)(v11 + 20), 1, 31);
        if ( v12 < 0 )
          goto LABEL_15;
        v23 = v32;
        v24 = 0;
        v25 = 0;
        if ( v32 > &v32[(unsigned __int16)v31 >> 1] )
          v26 = 0;
        else
          v26 = (unsigned int)(2 * ((unsigned __int16)v31 >> 1) + 1) >> 1;
        if ( v26 )
        {
          do
          {
            v27 = *(unsigned __int16 *)v23++;
            ++v25;
            v24 = 37 * v24 + v27;
          }
          while ( v25 < v26 );
        }
        v36 = (int)abs32(314159269 * v24) % 1000000007;
        RtlFreeAnsiString(&v31);
        v37 = 62;
        v28 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 62, 1852141648);
        v6 = v28;
        if ( !v28 )
          goto LABEL_25;
        RtlStringCbPrintfW(v28, 0x3Eu, (int)L"%s.%x.%x", (int)L"NextParentID");
        v12 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 5, (int *)&v33);
        if ( v12 < 0 )
          goto LABEL_15;
        RtlInitUnicodeString((unsigned int)&v31, v6);
        if ( ZwQueryValueKey() >= 0 && v39 == 4 && v40 == 4 )
          v29 = v41;
        else
          v29 = 0;
        v35 = v29 + 1;
        v12 = ZwSetValueKey();
        if ( v12 < 0 )
          goto LABEL_15;
        --v35;
        v31 = 1966108;
        v32 = L"ParentIdPrefix";
        v33 = v6;
        RtlStringCchPrintfExW((int)v6, v37 >> 1, &v33, 0, 0, L"%x&%x&%x");
        v12 = ZwSetValueKey();
        if ( v12 < 0 )
          goto LABEL_15;
        goto LABEL_10;
      }
      if ( *(_DWORD *)(v7 + 4) == 1 )
      {
        v13 = *(_DWORD *)(v7 + 8);
        v14 = ExAllocatePoolWithTag(1, v13, 1852141648);
        v6 = (unsigned __int16 *)v14;
        if ( v14 )
        {
          RtlStringCbCopyW(v14, v13);
          goto LABEL_10;
        }
        goto LABEL_25;
      }
    }
    v12 = -1073741811;
LABEL_15:
    ZwClose();
  }
  v18 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  if ( v7 )
    ExFreePoolWithTag(v7);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  result = v12;
  *v38 = v5;
  return result;
}
