// DrvDbLoadDatabaseNode 
 
int __fastcall DrvDbLoadDatabaseNode(int **a1, int *a2)
{
  int v3; // r3
  int v4; // r7
  int v5; // r5
  int (__fastcall *v7)(int **, int, int, int, int *, int); // r8
  int v8; // r0
  int v9; // r3
  int v10; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r1
  int v17; // r0
  int *v18; // r3
  int v19; // r2
  unsigned int v20; // r2
  int v21; // [sp+10h] [bp-30h] BYREF
  int v22; // [sp+14h] [bp-2Ch] BYREF
  int v23; // [sp+18h] [bp-28h] BYREF
  int v24[9]; // [sp+1Ch] [bp-24h] BYREF

  v22 = 1;
  v23 = 0;
  v3 = a2[7];
  v4 = 0;
  v5 = 0;
  v21 = 0;
  v7 = 0;
  if ( (v3 & 1) == 0 )
  {
    v7 = (int (__fastcall *)(int **, int, int, int, int *, int))a2[9];
    if ( v7 )
    {
      v24[0] = (int)(a2 + 11);
      v8 = v7(a1, a2[3], 1, 1, v24, a2[10]);
      if ( v8 == -1073741822 )
      {
        v7 = 0;
      }
      else if ( v8 < 0 )
      {
        v5 = v8;
        goto LABEL_7;
      }
    }
    if ( !a2[11] )
    {
      v16 = a2[4];
      if ( v16 )
      {
        v5 = PnpCtxGetCachedContextBaseKey(*a1, v16, &v21);
        if ( v5 < 0 )
          goto LABEL_7;
        v4 = v21;
      }
      if ( *a1 )
        v17 = **a1;
      else
        v17 = 0;
      v5 = SysCtxRegOpenKey(v17, v4, a2[6], 0, 0x2000000);
      if ( v5 < 0 )
        goto LABEL_7;
    }
LABEL_6:
    v9 = a2[7];
    if ( (v9 & 8) != 0 )
    {
LABEL_7:
      if ( v7 )
      {
        v10 = v7(a1, a2[3], 1, 2, v24, a2[10]);
        if ( v10 < 0 && v10 != -1073741822 && !v5 )
          v5 = v10;
      }
      goto LABEL_9;
    }
    a2[7] = v9 | 8;
    v14 = DrvDbGetDriverDatabaseMappedProperty(a1, a2[3], a2[11], DEVPKEY_DriverDatabase_Version, &v22, a2 + 8, 4, &v23);
    v5 = v14;
    if ( v14 == -1073741275 )
    {
      v18 = a1[1];
      if ( v18 && v18 != (int *)-1 )
      {
        a2[8] = (int)v18;
        DrvDbInitializeDatabaseNodeVersion(a1, a2);
LABEL_43:
        v5 = 0;
LABEL_44:
        v19 = a2[8];
        if ( v19 )
        {
          if ( v19 == -1 || (v20 = v19 & 0xFFFF0000, v20 < 0x6020000) || v20 > ((unsigned int)a1[1] & 0xFFFF0000) )
          {
            DrvDbUnloadDatabaseNode(a1, a2);
            v5 = -1073740697;
            a2[7] |= 4u;
          }
        }
        goto LABEL_7;
      }
    }
    else if ( v14 >= 0 )
    {
      if ( v22 != 7 || v23 != 4 )
        a2[8] = -1;
      goto LABEL_44;
    }
    a2[8] = 0;
    goto LABEL_43;
  }
  if ( a2[11] )
  {
    v5 = 0;
    goto LABEL_9;
  }
  if ( a1[5] )
  {
    v5 = -1073741811;
    goto LABEL_9;
  }
  v12 = a2[4];
  if ( v12 )
  {
    v5 = PnpCtxGetCachedContextBaseKey(*a1, v12, &v21);
    if ( v5 < 0 )
      goto LABEL_9;
    v4 = v21;
  }
  if ( *a1 )
    v13 = **a1;
  else
    v13 = 0;
  v15 = SysCtxRegOpenKey(v13, v4, a2[6], 0, 0x2000000);
  v5 = v15;
  if ( v15 != -1073741772 )
  {
    if ( v15 >= 0 )
    {
      a1[5] = a2;
      goto LABEL_6;
    }
LABEL_9:
    a2[19] = v5;
    return v5;
  }
  return sub_7E2D30();
}
