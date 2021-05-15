// PipGenerateContainerID 
 
int __fastcall PipGenerateContainerID(int a1, int a2, int a3, int a4, int *a5)
{
  char *v7; // r0
  int v8; // r4
  int v9; // r0
  unsigned int v11; // r2
  int v12; // r4
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r3
  int v16; // r5
  int v17; // [sp+10h] [bp-88h] BYREF
  int v18; // [sp+14h] [bp-84h]
  int v19; // [sp+18h] [bp-80h] BYREF
  int v20; // [sp+1Ch] [bp-7Ch] BYREF
  char v21[16]; // [sp+20h] [bp-78h] BYREF
  unsigned __int16 v22[52]; // [sp+30h] [bp-68h] BYREF

  *a5 = 0;
  v17 = 0;
  v18 = 0;
  if ( !a3 )
  {
    v7 = (char *)(*(_DWORD *)(a1 + 8) + 424);
    goto LABEL_3;
  }
  if ( !a4 )
  {
    if ( a2 )
    {
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v11 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      v19 = 78;
      v12 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), a2, 37, (int)&v20, (int)v22, (int)&v19);
      v13 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(v13);
      if ( v12 >= 0 && v20 == 1 && RtlCreateUnicodeString((int)&v17, v22) )
      {
        v8 = RtlGUIDFromString((unsigned __int16 *)&v17, v21);
        if ( v8 >= 0 )
        {
          v16 = *(_DWORD *)(a1 + 8);
          if ( !v16 )
            goto LABEL_4;
          while ( (char *)(v16 + 424) != v21 && RtlCompareMemory((unsigned __int8 *)(v16 + 424), (int)v21, 16) != 16 )
          {
            v16 = *(_DWORD *)(v16 + 8);
            if ( !v16 )
              goto LABEL_4;
          }
        }
        RtlFreeAnsiString(&v17);
      }
    }
    v8 = ExUuidCreate((int)v21);
    if ( v8 < 0 )
      return v8;
    v7 = v21;
LABEL_3:
    v8 = RtlStringFromGUIDEx((int)v7, (int)&v17, 1);
LABEL_4:
    if ( v8 >= 0 && v18 )
    {
      v9 = ExAllocatePoolWithTag(1, HIWORD(v17), 1852141648);
      *a5 = v9;
      if ( v9 )
        memmove(v9, v18, HIWORD(v17));
      else
        v8 = -1073741670;
      RtlFreeAnsiString(&v17);
    }
    return v8;
  }
  return sub_7EFA28();
}
