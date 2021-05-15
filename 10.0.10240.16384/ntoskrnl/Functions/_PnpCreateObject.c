// _PnpCreateObject 
 
int __fastcall PnpCreateObject(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int (__fastcall *v8)(int, int, int, int, int, int *); // r7
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r0
  int v15; // [sp+18h] [bp-48h] BYREF
  int v16[17]; // [sp+1Ch] [bp-44h] BYREF

  v15 = 0;
  memset(v16, 0, 36);
  v8 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  if ( !a4 )
    a4 = a5 == 0;
  v9 = 0;
  v16[4] = 0;
  v16[1] = a4;
  if ( v8 )
  {
    v10 = v8(a1, a2, a3, 3, 1, &v15);
    if ( v10 == -1073741822 )
    {
      v8 = 0;
    }
    else
    {
      if ( v10 == -1073741536 )
        goto LABEL_16;
      if ( v10 )
      {
        v11 = -1073741595;
        goto LABEL_19;
      }
    }
    a4 = v16[1];
    v9 = v16[4];
  }
  v11 = PnpCreateObjectDispatch(a1, a2, a3, a4, &v16[2], &v16[3], v9);
  if ( !v8 )
    goto LABEL_12;
  v15 = v11;
  v12 = v8(a1, a2, a3, 3, 2, &v15);
  if ( v12 == -1073741822 )
    goto LABEL_12;
  if ( v12 == -1073741536 )
  {
LABEL_16:
    v11 = v15;
    goto LABEL_12;
  }
  if ( v12 )
    v11 = -1073741595;
LABEL_12:
  if ( v11 >= 0 && a5 )
  {
    *a5 = v16[2];
    return v11;
  }
LABEL_19:
  if ( v16[2] )
    ZwClose();
  return v11;
}
