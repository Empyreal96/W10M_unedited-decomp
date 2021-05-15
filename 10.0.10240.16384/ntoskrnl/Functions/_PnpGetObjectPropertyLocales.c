// _PnpGetObjectPropertyLocales 
 
int __fastcall PnpGetObjectPropertyLocales(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int (__fastcall *v12)(int, int, int, int, int, int *); // r5
  int v13; // r3
  int v14; // r6
  int v15; // r7
  int v16; // r2
  int v17; // r1
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v22; // [sp+18h] [bp-48h] BYREF
  int v23[9]; // [sp+1Ch] [bp-44h] BYREF

  v22 = 0;
  memset(v23, 0, sizeof(v23));
  v12 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  v13 = a5;
  v14 = a6;
  v15 = a7;
  v16 = a8;
  v17 = 0;
  v23[2] = a5;
  v23[3] = a6;
  v23[4] = a7;
  v23[5] = a8;
  v23[1] = a4;
  v23[6] = 0;
  if ( v12 )
  {
    v18 = v12(a1, a2, a3, 7, 1, &v22);
    if ( v18 == -1073741822 )
    {
      v12 = 0;
    }
    else
    {
      if ( v18 == -1073741536 )
        return v22;
      if ( v18 )
        return -1073741595;
    }
    a4 = v23[1];
    v13 = v23[2];
    v14 = v23[3];
    v15 = v23[4];
    v16 = v23[5];
    v17 = v23[6];
  }
  v19 = PnpGetObjectPropertyLocalesWorker(a1, a2, a3, a4, v13, v14, v15, v16, v17);
  if ( !v12 )
    return v19;
  v22 = v19;
  v20 = v12(a1, a2, a3, 7, 2, &v22);
  if ( v20 == -1073741822 )
    return v19;
  if ( v20 == -1073741536 )
    return v22;
  if ( v20 )
    return -1073741595;
  return v19;
}
