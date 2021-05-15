// IopGetRootDevices 
 
int __fastcall IopGetRootDevices(int **a1)
{
  unsigned __int16 *v2; // r7
  int v3; // r6
  int v4; // r5
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r8
  int v12; // r3
  unsigned __int16 *v13; // r8
  int *v14; // r0
  int *v15; // r8
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  int *v19; // r8
  int v20; // t1
  int v21; // [sp+18h] [bp-40h] BYREF
  int v22; // [sp+1Ch] [bp-3Ch] BYREF
  char v23[8]; // [sp+20h] [bp-38h] BYREF
  int v24[2]; // [sp+28h] [bp-30h] BYREF
  int v25; // [sp+30h] [bp-28h]
  int v26; // [sp+34h] [bp-24h]

  *a1 = 0;
  v2 = 0;
  v3 = ExAllocatePoolWithTag(1, 1024, 1684303952);
  v26 = v3;
  if ( !v3 )
    return -1073741670;
  v4 = 0;
  v24[1] = 256;
  v25 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  v7 = ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v5, v6);
  v8 = 2048;
  v21 = 2048;
  v9 = -1073741789;
  v10 = 0;
  while ( v10 < 5 )
  {
    if ( v2 )
      return sub_7C9CAC(v7);
    v2 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v8, 1684303952);
    if ( !v2 )
    {
      v9 = -1073741670;
      break;
    }
    v7 = CmGetMatchingFilteredDeviceList(PiPnpRtlCtx, (int)L"Root", 1, 0, 0, (int)v2, v21, (int)&v21);
    v9 = v7;
    ++v10;
    if ( v7 != -1073741789 )
    {
      if ( v7 < 0 )
        break;
      v12 = *v2;
      v9 = 0;
      v24[0] = 0;
      v13 = v2;
      if ( v12 )
      {
        while ( 1 )
        {
          v9 = CmOpenDeviceRegKey(PiPnpRtlCtx, (int)v13, 16, 0, 983103, 0, (int)&v22, 0);
          if ( v9 < 0 )
            break;
          v9 = RtlInitUnicodeStringEx((int)v23, v13);
          if ( v9 >= 0 && !IopInitializeDeviceInstanceKey(v22, v23, v24) )
          {
            ZwClose();
LABEL_15:
            v4 = v25;
            v3 = v26;
            v9 = v24[0];
            goto LABEL_16;
          }
          ZwClose();
          if ( v9 < 0 )
            break;
          v13 += wcslen(v13) + 1;
          if ( !*v13 )
            goto LABEL_15;
        }
        v4 = v25;
        v3 = v26;
LABEL_34:
        if ( !v4 )
          goto LABEL_27;
LABEL_20:
        if ( v9 >= 0 )
          break;
      }
      else
      {
LABEL_16:
        if ( v9 < 0 )
          goto LABEL_34;
        if ( !v4 )
        {
LABEL_27:
          v9 = -1073741823;
          goto LABEL_20;
        }
        v14 = (int *)ExAllocatePoolWithTag(1, 4 * (v4 + 2), 1684303952);
        v15 = v14;
        if ( v14 )
        {
          *v14 = v4;
          memmove((int)(v14 + 1), v3, 4 * v4);
          *a1 = v15;
          goto LABEL_20;
        }
        v9 = -1073741670;
      }
      if ( v4 )
      {
        v19 = (int *)v3;
        do
        {
          v20 = *v19++;
          ObfDereferenceObject(v20);
          --v4;
        }
        while ( v4 );
      }
      break;
    }
    v8 = v21;
  }
  v16 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  ExFreePoolWithTag(v3);
  if ( v2 )
    ExFreePoolWithTag((unsigned int)v2);
  return v9;
}
