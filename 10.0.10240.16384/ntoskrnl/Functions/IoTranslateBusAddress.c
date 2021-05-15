// IoTranslateBusAddress 
 
int __fastcall IoTranslateBusAddress(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r3
  char v11; // r3
  __int16 v12; // r2
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r6
  int v17; // r7
  int v18; // r4
  int v19; // r10
  int v20; // r6
  int v21; // r4
  int v22; // [sp+10h] [bp-48h] BYREF
  int v23; // [sp+14h] [bp-44h] BYREF
  int v24; // [sp+18h] [bp-40h] BYREF
  int v25; // [sp+1Ch] [bp-3Ch]
  int v26; // [sp+20h] [bp-38h]
  int v27; // [sp+24h] [bp-34h]
  int v28; // [sp+28h] [bp-30h]
  int v29; // [sp+2Ch] [bp-2Ch]
  int v30; // [sp+30h] [bp-28h]
  int v31; // [sp+34h] [bp-24h]
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  if ( KeGetCurrentIrql(a1) || !IopRootDeviceNode )
  {
    *a6 = varg_r2;
    v9 = varg_r3;
LABEL_3:
    a6[1] = v9;
    return 1;
  }
  if ( *a5 )
  {
    if ( *a5 != 1 )
      return 0;
    v11 = 1;
    v12 = 1;
  }
  else
  {
    v11 = 3;
    v12 = 0;
  }
  LOBYTE(v24) = v11;
  BYTE1(v24) = 3;
  HIWORD(v24) = v12;
  v25 = varg_r2;
  v26 = varg_r3;
  v27 = 1;
  PpDevNodeLockTree(0, v8);
  v13 = IopFindLegacyBusDeviceNode(a1, a2);
  v16 = IopRootDeviceNode;
  v17 = v13;
  if ( v13 == IopRootDeviceNode )
  {
LABEL_22:
    PpDevNodeUnlockTree(0, v14, v15);
    if ( (unsigned __int8)v24 == 3 || (unsigned __int8)v24 == 7 )
    {
      *a5 = 0;
    }
    else
    {
      if ( (unsigned __int8)v24 != 1 )
        return 0;
      *a5 = 1;
    }
    *a6 = v25;
    v9 = v26;
    goto LABEL_3;
  }
  v18 = (unsigned __int8)v24;
  while ( 1 )
  {
    v19 = IopFindResourceHandlerInfo(1, v17, v18, &v22);
    if ( !v19 )
    {
      if ( IopQueryResourceHandlerInterface(1, *(_DWORD *)(v17 + 16), v18, &v23) >= 0 )
      {
        v20 = v23;
        goto LABEL_16;
      }
LABEL_20:
      v18 = (unsigned __int8)v24;
      v16 = IopRootDeviceNode;
      goto LABEL_21;
    }
    if ( v22 )
      break;
LABEL_21:
    v17 = *(_DWORD *)(v17 + 8);
    if ( v17 == v16 )
      goto LABEL_22;
  }
  v20 = *(_DWORD *)(v22 + 12);
LABEL_16:
  v21 = (*(int (__fastcall **)(_DWORD, int *, _DWORD))(v20 + 16))(*(_DWORD *)(v20 + 4), &v24, 0);
  if ( !v19 )
  {
    (*(void (__fastcall **)(_DWORD))(v20 + 12))(*(_DWORD *)(v20 + 4));
    ExFreePoolWithTag(v20);
  }
  if ( v21 >= 0 )
  {
    v24 = v28;
    v25 = v29;
    v26 = v30;
    v27 = v31;
    if ( v21 == 288 )
      goto LABEL_22;
    goto LABEL_20;
  }
  PpDevNodeUnlockTree(0, v14, v15);
  return 0;
}
