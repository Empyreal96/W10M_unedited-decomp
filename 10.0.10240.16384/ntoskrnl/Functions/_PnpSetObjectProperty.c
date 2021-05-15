// _PnpSetObjectProperty 
 
int __fastcall PnpSetObjectProperty(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v14; // lr
  int (__fastcall *v15)(int, int, int, int, int, int *); // r5
  int v16; // r3
  int v17; // r2
  int v18; // r1
  int v19; // r0
  int v20; // r9
  int v21; // r0
  int v22; // r4
  int v24; // r0
  int v25; // [sp+18h] [bp-48h] BYREF
  _DWORD v26[9]; // [sp+1Ch] [bp-44h] BYREF

  v25 = 0;
  memset(v26, 0, sizeof(v26));
  v14 = a9;
  v15 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  v16 = a5;
  v17 = a6;
  v18 = a7;
  v19 = a8;
  v20 = a10;
  v26[5] = a8;
  v26[6] = a9;
  v26[1] = a4;
  v26[2] = a5;
  v26[3] = a6;
  v26[4] = a7;
  v26[7] = a10;
  if ( v15 )
  {
    v21 = v15(a1, a2, a3, 9, 1, &v25);
    if ( v21 == -1073741822 )
    {
      v15 = 0;
    }
    else
    {
      if ( v21 == -1073741536 )
        return v25;
      if ( v21 )
        return -1073741595;
    }
    a4 = v26[1];
    v16 = v26[2];
    v17 = v26[3];
    v18 = v26[4];
    v19 = v26[5];
    v14 = v26[6];
    v20 = v26[7];
  }
  v22 = PnpSetObjectPropertyWorker(a1, a2, a3, a4, v16, v17, v18, v19, v14, v20);
  if ( v15 )
  {
    v25 = v22;
    v24 = v15(a1, a2, a3, 9, 2, &v25);
    if ( v24 != -1073741822 )
    {
      if ( v24 == -1073741536 )
        return v25;
      if ( !v24 )
        return v22;
      return -1073741595;
    }
  }
  return v22;
}
