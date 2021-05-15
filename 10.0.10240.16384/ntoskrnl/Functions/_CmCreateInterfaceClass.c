// _CmCreateInterfaceClass 
 
int __fastcall CmCreateInterfaceClass(int a1, int a2, int a3, int a4, _BYTE *a5, int a6)
{
  int (__fastcall *v9)(int, int, int, int, int, int *); // r7
  int v10; // r3
  int v11; // r0
  int v12; // r4
  int v13; // r0
  int v16; // [sp+10h] [bp-50h] BYREF
  int v17[19]; // [sp+14h] [bp-4Ch] BYREF

  v16 = 0;
  memset(v17, 0, 40);
  v9 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  if ( !a3 )
    a3 = a4 == 0;
  v10 = a6;
  v17[4] = a6;
  v17[1] = a3;
  if ( v9 )
  {
    v11 = v9(a1, a2, 4, 2, 1, &v16);
    if ( v11 == -1073741822 )
    {
      v9 = 0;
    }
    else
    {
      if ( v11 == -1073741536 )
        goto LABEL_20;
      if ( v11 )
      {
        v12 = -1073741595;
        goto LABEL_15;
      }
    }
    a3 = v17[1];
    v10 = v17[4];
  }
  v12 = CmCreateInterfaceClassWorker(a1, a2, a3, &v17[2], &v17[3], v10);
  if ( !v9 )
    goto LABEL_13;
  v16 = v12;
  v13 = ((int (__fastcall *)(int, int, int))v9)(a1, a2, 4);
  if ( v13 == -1073741822 )
    goto LABEL_13;
  if ( v13 == -1073741536 )
  {
LABEL_20:
    v12 = v16;
    goto LABEL_13;
  }
  if ( v13 )
    v12 = -1073741595;
LABEL_13:
  if ( a4 )
    return sub_7EF350();
LABEL_15:
  if ( v17[2] )
    ZwClose();
  if ( a5 )
  {
    if ( v12 >= 0 )
      *a5 = v17[3];
  }
  return v12;
}
