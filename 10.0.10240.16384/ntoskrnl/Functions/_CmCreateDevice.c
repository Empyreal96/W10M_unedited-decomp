// _CmCreateDevice 
 
int __fastcall CmCreateDevice(int a1, int a2, int a3, _DWORD *a4, _BYTE *a5, int a6)
{
  _BYTE *v9; // r0
  int (__fastcall *v10)(int, int, int, int, int, int *); // r7
  int v12; // r3
  int v13; // r0
  int v14; // r4
  int v15; // r0
  int v17; // [sp+10h] [bp-50h] BYREF
  int v18[19]; // [sp+14h] [bp-4Ch] BYREF

  v17 = 0;
  v9 = memset(v18, 0, 40);
  v10 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  if ( !a3 )
    return sub_7EF2D8(v9);
  v12 = a6;
  v18[4] = a6;
  v18[1] = a3;
  if ( v10 )
  {
    v13 = v10(a1, a2, 1, 2, 1, &v17);
    if ( v13 == -1073741822 )
    {
      v10 = 0;
    }
    else
    {
      if ( v13 == -1073741536 )
        goto LABEL_21;
      if ( v13 )
      {
        v14 = -1073741595;
        goto LABEL_23;
      }
    }
    a3 = v18[1];
    v12 = v18[4];
  }
  v14 = CmCreateDeviceWorker(a1, a2, a3, &v18[2], &v18[3], v12);
  if ( !v10 )
    goto LABEL_13;
  v17 = v14;
  v15 = ((int (__fastcall *)(int, int, int))v10)(a1, a2, 1);
  if ( v15 == -1073741822 )
    goto LABEL_13;
  if ( v15 == -1073741536 )
  {
LABEL_21:
    v14 = v17;
    goto LABEL_13;
  }
  if ( v15 )
    v14 = -1073741595;
LABEL_13:
  if ( v14 < 0 || !a4 )
  {
LABEL_23:
    if ( v18[2] )
      ZwClose();
    goto LABEL_16;
  }
  *a4 = v18[2];
LABEL_16:
  if ( a5 )
  {
    if ( v14 >= 0 )
      *a5 = v18[3];
  }
  return v14;
}
