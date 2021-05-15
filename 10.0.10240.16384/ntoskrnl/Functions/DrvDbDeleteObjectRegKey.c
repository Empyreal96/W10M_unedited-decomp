// DrvDbDeleteObjectRegKey 
 
int DrvDbDeleteObjectRegKey(int a1, int a2, ...)
{
  int v2; // r8
  int v5; // r2
  int v6; // r4
  _DWORD *v7; // r5
  int v8; // r0
  int v9; // r3
  _DWORD *v11; // r7
  int v12; // r0
  int v13; // r2
  int v14; // [sp+0h] [bp-30h] BYREF
  _DWORD *v15; // [sp+4h] [bp-2Ch] BYREF
  int v16; // [sp+8h] [bp-28h]
  int v17; // [sp+Ch] [bp-24h]
  int v18; // [sp+10h] [bp-20h]
  _WORD *varg_r2; // [sp+40h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]
  va_list va1; // [sp+48h] [bp+18h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _WORD *);
  varg_r3 = va_arg(va1, _DWORD);
  v2 = varg_r3;
  v18 = varg_r3;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = a2;
  v6 = DrvDbGetObjectDatabaseNode(a1, varg_r2, (_WORD **)varg_r2a, &v15);
  v7 = v15;
  if ( v6 < 0 )
    goto LABEL_7;
  if ( v15 )
  {
    v8 = DrvDbAcquireDatabaseNodeBaseKey((int **)a1, v15, a2, &v14);
    v6 = v8;
    if ( v8 < 0 )
    {
      v9 = v14;
      if ( v8 == -1073740697 )
        v6 = -1073741662;
      goto LABEL_8;
    }
    v6 = DrvDbDeleteObjectSubKey(a1, v14, varg_r2, v2);
LABEL_7:
    v9 = v14;
    goto LABEL_8;
  }
  v11 = *(_DWORD **)(a1 + 12);
  if ( v11 == (_DWORD *)(a1 + 12) )
  {
LABEL_20:
    v9 = v14;
  }
  else
  {
    do
    {
      v7 = v11;
      v12 = DrvDbAcquireDatabaseNodeBaseKey((int **)a1, v11, v17, &v14);
      v6 = v12;
      if ( v12 == -1073740697 )
      {
        v9 = v14;
        v6 = -1073741662;
      }
      else
      {
        if ( v12 < 0 )
          goto LABEL_20;
        v6 = DrvDbDeleteObjectSubKey(a1, v14, varg_r2, v18);
        DrvDbReleaseDatabaseNodeBaseKey(a1, (int)v11, v13, v14);
        v9 = 0;
        v14 = 0;
        if ( v6 < 0 )
        {
          if ( v6 != -1073741772 )
            goto LABEL_22;
        }
        else
        {
          v5 = 1;
          v16 = 1;
        }
      }
      v11 = (_DWORD *)*v11;
    }
    while ( v11 != (_DWORD *)(a1 + 12) );
  }
  if ( v6 != -1073741772 )
  {
LABEL_22:
    if ( v6 != -1073741662 )
      goto LABEL_8;
  }
  v5 = v16;
  if ( v16 )
    v6 = 0;
LABEL_8:
  if ( v9 )
    DrvDbReleaseDatabaseNodeBaseKey(a1, (int)v7, v5, v9);
  return v6;
}
