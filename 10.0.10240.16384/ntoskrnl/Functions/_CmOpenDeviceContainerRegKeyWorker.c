// _CmOpenDeviceContainerRegKeyWorker 
 
int __fastcall CmOpenDeviceContainerRegKeyWorker(int *a1, int a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v9; // r0
  unsigned __int16 *v11; // r5
  int v13; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r4
  int v19; // r7
  int v20; // r1
  int v21; // r0
  int v22; // r0
  int v23[2]; // [sp+10h] [bp-38h] BYREF
  int v24; // [sp+18h] [bp-30h] BYREF
  int v25[10]; // [sp+20h] [bp-28h] BYREF

  v9 = 0;
  v11 = 0;
  v23[0] = 0;
  v25[0] = a2;
  v24 = 0;
  if ( !a3 || (a3 & 0xFFFFFEAF) != 0 )
    goto LABEL_34;
  v23[1] = 260;
  v13 = ExAllocatePoolWithTag(1, 260, 1380994640);
  v11 = (unsigned __int16 *)v13;
  if ( !v13 )
    JUMPOUT(0x7CBB80);
  v14 = CmGetDeviceContainerRegKeyPath(v13, a2, a3, 130);
  v17 = v14;
  if ( v14 == -1073741789 )
    return sub_7CBB4C();
  if ( v14 < 0 )
    goto LABEL_19;
  if ( (a3 & 0x100) == 0 )
  {
    v17 = RtlInitUnicodeStringEx((int)v25, v11);
    if ( v17 < 0 )
      goto LABEL_19;
    if ( LOWORD(v25[0]) < 0x104u
      && LOWORD(v25[0]) > 0x32u
      && RtlPrefixUnicodeString(
           (unsigned __int16 *)&`_CmDeleteDeviceRegKeyWorker'::`2'::ObjectPathRootPrefix,
           (unsigned __int16 *)v25,
           1) )
    {
      v19 = (int)(v11 + 25);
      v17 = PnpCtxGetCachedContextBaseKey(a1, 4, &v24);
      if ( v17 >= 0 )
      {
        v20 = v24;
LABEL_14:
        if ( a6 )
        {
          v21 = PnpCtxRegCreateTree(a1, v20, v19, 0, a5, 0, a7, a8);
        }
        else
        {
          if ( a1 )
            v22 = *a1;
          else
            v22 = 0;
          v21 = SysCtxRegOpenKey(v22, v20, v19, 0, a5);
          if ( v21 >= 0 )
            *a8 = 2;
        }
        if ( v21 == -1073741444 )
        {
          v17 = -1073741595;
        }
        else if ( v21 < 0 )
        {
          v17 = v21;
        }
        goto LABEL_19;
      }
      goto LABEL_19;
    }
    v9 = v23[0];
LABEL_34:
    v17 = -1073741811;
    goto LABEL_20;
  }
  v19 = (int)v11;
  v17 = PnpCtxRegOpenCurrentUserKey(a1, v15, v16, v23);
  if ( v17 >= 0 )
  {
    v20 = v23[0];
    goto LABEL_14;
  }
LABEL_19:
  v9 = v23[0];
LABEL_20:
  if ( v9 )
    ZwClose();
  if ( v11 )
    ExFreePoolWithTag((unsigned int)v11);
  return v17;
}
