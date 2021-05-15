// PiDcResetChildDeviceContainerCallback 
 
int __fastcall PiDcResetChildDeviceContainerCallback(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r7
  int v6; // r5
  unsigned __int16 *v8; // r9
  unsigned __int16 *i; // r4
  int v10; // r0
  int v11; // r0
  _DWORD *v12; // r4
  _DWORD *v13; // r1
  int v15; // [sp+20h] [bp-90h] BYREF
  int v16; // [sp+24h] [bp-8Ch] BYREF
  int v17; // [sp+28h] [bp-88h]
  int v18; // [sp+2Ch] [bp-84h] BYREF
  char v19[8]; // [sp+30h] [bp-80h] BYREF
  char v20[8]; // [sp+38h] [bp-78h] BYREF
  char v21[112]; // [sp+40h] [bp-70h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v8 = (unsigned __int16 *)a2;
  v17 = a1;
  for ( i = (unsigned __int16 *)a2; !CmIsRootDevice(i, a2, a3, a4); i = (unsigned __int16 *)v6 )
  {
    v4 = RtlInitUnicodeStringEx((int)v20, i);
    if ( v4 < 0 )
      goto LABEL_27;
    v10 = PnpDeviceObjectFromDeviceInstance((int)v20);
    if ( v10 )
    {
      ObfDereferenceObject(v10);
      break;
    }
    if ( i != v8 )
    {
      v15 = 78;
      v4 = CmGetDeviceRegProp(PiPnpRtlCtx, (int)i, 0, 37, (int)&v18, (int)v21, (int)&v15);
      if ( v4 < 0 )
        goto LABEL_27;
      if ( v18 != 1 || v15 != 78 || wcsicmp((int)v21, *(unsigned __int16 **)(a3 + 4)) )
        break;
    }
    if ( !v6 )
    {
      v6 = ExAllocatePoolWithTag(1, 400, 1198550608);
      if ( !v6 )
        return 0;
    }
    v4 = PnpGetObjectProperty(
           v17,
           (int)i,
           1,
           0,
           0,
           (int)DEVPKEY_Device_LastKnownParent,
           (int)&v16,
           v6,
           400,
           (int)v19,
           0);
    if ( v4 < 0 || v16 != 18 )
      goto LABEL_27;
    *(_WORD *)(v6 + 398) = 0;
    if ( !wcsicmp(v6, *(unsigned __int16 **)a3) )
    {
      v5 = 1;
      break;
    }
  }
  if ( v4 >= 0 )
  {
    if ( v5 )
    {
      v11 = ExAllocatePoolWithTag(1, 408, 1198550608);
      v12 = (_DWORD *)v11;
      if ( v11 )
      {
        if ( RtlStringCbCopyW(v11 + 8, 0x190u) >= 0 )
        {
          v13 = *(_DWORD **)(a3 + 12);
          *v12 = a3 + 8;
          v12[1] = v13;
          if ( *v13 != a3 + 8 )
            __fastfail(3u);
          *v13 = v12;
          *(_DWORD *)(a3 + 12) = v12;
          v12 = 0;
        }
        if ( v12 )
          ExFreePoolWithTag((unsigned int)v12);
      }
    }
  }
LABEL_27:
  if ( v6 )
    ExFreePoolWithTag(v6);
  return 0;
}
