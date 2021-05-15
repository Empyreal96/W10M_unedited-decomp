// _PnpGetObjectPropertyKeys 
 
int __fastcall PnpGetObjectPropertyKeys(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, int a9)
{
  int v13; // lr
  int (__fastcall *v14)(int, int, int, int, int, int *); // r5
  int v15; // r2
  int v16; // r1
  int v17; // r0
  int v18; // r3
  int v19; // r9
  int v20; // r0
  int v21; // r4
  int v22; // r0
  int v24; // [sp+18h] [bp-48h] BYREF
  _DWORD v25[9]; // [sp+1Ch] [bp-44h] BYREF

  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v13 = a9;
  v14 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  v15 = a6;
  v16 = a7;
  v17 = a8;
  v18 = 0;
  v25[5] = a8;
  v25[6] = a9;
  v25[1] = a4;
  v25[2] = 0;
  LOBYTE(v25[3]) = a6;
  v25[4] = a7;
  v19 = 0;
  v25[7] = 0;
  if ( v14 )
  {
    v20 = v14(a1, a2, a3, 6, 1, &v24);
    if ( v20 == -1073741822 )
    {
      v14 = 0;
    }
    else
    {
      if ( v20 == -1073741536 )
        return v24;
      if ( v20 )
        return -1073741595;
    }
    a4 = v25[1];
    v18 = v25[2];
    v15 = LOBYTE(v25[3]);
    v16 = v25[4];
    v17 = v25[5];
    v13 = v25[6];
    v19 = v25[7];
  }
  v21 = PnpGetObjectPropertyKeysWorker(a1, a2, a3, a4, v18, v15, v16, v17, v13, v19);
  if ( !v14 )
    return v21;
  v24 = v21;
  v22 = v14(a1, a2, a3, 6, 2, &v24);
  if ( v22 == -1073741822 )
    return v21;
  if ( v22 == -1073741536 )
    return v24;
  if ( v22 )
    return -1073741595;
  return v21;
}
