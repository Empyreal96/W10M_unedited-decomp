// _PnpGetObjectProperty 
 
int __fastcall PnpGetObjectProperty(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int (__fastcall *v15)(int, int, int, int, int, int *); // r6
  int v16; // r3
  int v17; // r2
  int v18; // r1
  int v19; // r0
  int v20; // lr
  int v21; // r0
  int v22; // r4
  int v23; // r0
  int v25; // [sp+20h] [bp-50h]
  int v26; // [sp+24h] [bp-4Ch]
  int v27; // [sp+28h] [bp-48h] BYREF
  int v28[9]; // [sp+2Ch] [bp-44h] BYREF

  v27 = 0;
  memset(v28, 0, sizeof(v28));
  v15 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  v16 = a5;
  v26 = a10;
  v28[7] = a10;
  v17 = a6;
  v18 = a7;
  v19 = a8;
  v20 = a9;
  v25 = a11;
  v28[8] = a11;
  v28[1] = a4;
  v28[2] = a5;
  v28[3] = a6;
  v28[4] = a7;
  v28[5] = a8;
  v28[6] = a9;
  if ( v15 )
  {
    v21 = v15(a1, a2, a3, 8, 1, &v27);
    if ( v21 == -1073741822 )
    {
      v15 = 0;
    }
    else
    {
      if ( v21 == -1073741536 )
        return v27;
      if ( v21 )
        return -1073741595;
    }
    a4 = v28[1];
    v17 = v28[3];
    v18 = v28[4];
    v25 = v28[8];
    v20 = v28[6];
    v19 = v28[5];
    v26 = v28[7];
    v16 = v28[2];
  }
  v22 = PnpGetObjectPropertyWorker(a1, a2, a3, a4, v16, v17, v18, v19, v20, v26, v25);
  if ( !v15 )
    return v22;
  v27 = v22;
  v23 = v15(a1, a2, a3, 8, 2, &v27);
  if ( v23 == -1073741822 )
    return v22;
  if ( v23 != -1073741536 )
  {
    if ( !v23 )
      return v22;
    return -1073741595;
  }
  return v27;
}
