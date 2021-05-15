// PiPnpRtlGatherInstallerClassChangeInfo 
 
int __fastcall PiPnpRtlGatherInstallerClassChangeInfo(int a1, unsigned __int16 *a2, int **a3)
{
  int *v6; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r4
  char v11[4]; // [sp+20h] [bp-80h] BYREF
  char v12[4]; // [sp+24h] [bp-7Ch] BYREF
  char v13[16]; // [sp+28h] [bp-78h] BYREF
  char v14[104]; // [sp+38h] [bp-68h] BYREF

  v6 = (int *)ExAllocatePoolWithTag(1, 12, 1198550608);
  *a3 = v6;
  if ( !v6 )
    return sub_7E5520();
  *v6 = 0;
  v6[1] = 0;
  v6[2] = 0;
  if ( a2 && PiDmAddCacheReferenceForObject(2, a2, *a3 + 2) < 0
    || (v8 = PiDmGetObject(1, a1, *a3), v8 < 0) && v8 != -1073741772 )
  {
LABEL_17:
    JUMPOUT(0x7E5522);
  }
  v9 = PnpGetObjectProperty(
         PiPnpRtlCtx,
         a1,
         1,
         0,
         0,
         (int)DEVPKEY_Device_ClassGuid,
         (int)v11,
         (int)v13,
         16,
         (int)v12,
         0);
  if ( v9 == -1073741772 || v9 == -1073741275 )
  {
    v10 = 0;
  }
  else
  {
    if ( v9 < 0 || PnpStringFromGuid((int)v13, (int)v14) < 0 )
      goto LABEL_17;
    v10 = PiDmGetObject(2, (int)v14, *a3 + 1);
    if ( v10 == -1073741772 )
      return 0;
  }
  if ( v10 < 0 )
    goto LABEL_17;
  return v10;
}
