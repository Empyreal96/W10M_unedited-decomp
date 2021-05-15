// _CmCreateDeviceContainer 
 
int __fastcall CmCreateDeviceContainer(int a1, int a2, int a3, _DWORD *a4, _BYTE *a5)
{
  int (__fastcall *v8)(int, int, int, int, int, int *); // r5
  int v9; // r0
  int v11; // r4
  int v12; // r0
  int v13; // [sp+8h] [bp-50h] BYREF
  int v14[10]; // [sp+Ch] [bp-4Ch] BYREF

  v13 = 0;
  memset(v14, 0, sizeof(v14));
  v8 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v14[1] = 4;
  v14[4] = 0;
  if ( v8 )
  {
    v9 = v8(a1, a2, 5, 2, 1, &v13);
    if ( v9 == -1073741822 )
    {
      v8 = 0;
    }
    else
    {
      if ( v9 == -1073741536 )
        goto LABEL_17;
      if ( v9 )
        return sub_7CB980();
    }
  }
  v11 = CmCreateDeviceContainerWorker(a1, a2);
  if ( !v8 )
    goto LABEL_11;
  v13 = v11;
  v12 = ((int (__fastcall *)(int, int, int))v8)(a1, a2, 5);
  if ( v12 == -1073741822 )
    goto LABEL_11;
  if ( v12 != -1073741536 )
  {
    if ( v12 )
      v11 = -1073741595;
    goto LABEL_11;
  }
LABEL_17:
  v11 = v13;
LABEL_11:
  if ( v11 < 0 || !a4 )
    JUMPOUT(0x7CB982);
  *a4 = v14[2];
  if ( a5 )
    *a5 = v14[3];
  return v11;
}
