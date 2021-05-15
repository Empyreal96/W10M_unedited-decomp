// DrvDbOpenObjectRegKey 
 
int __fastcall DrvDbOpenObjectRegKey(int **a1, int a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v11; // r4
  int v12; // r6
  int v13; // r0
  int v14; // r0
  int **v16; // r7
  int v17; // r0
  int v18; // r0
  int var28[15]; // [sp+10h] [bp-28h] BYREF
  int varg_r3; // [sp+4Ch] [bp+14h]

  var28[12] = (int)a1;
  var28[13] = a2;
  var28[14] = a3;
  var28[0] = 0;
  var28[1] = 0;
  varg_r3 = a4;
  v11 = DrvDbGetObjectDatabaseNode();
  v12 = 0;
  if ( v11 < 0 )
  {
LABEL_8:
    if ( var28[0] )
      DrvDbReleaseDatabaseNodeBaseKey(a1, v12);
    return v11;
  }
  v12 = a2;
  if ( a2 )
  {
    v13 = DrvDbAcquireDatabaseNodeBaseKey(a1, a2, a3, var28);
    v11 = v13;
    if ( v13 < 0 )
    {
      if ( v13 == -1073740697 )
        v11 = -1073741772;
    }
    else
    {
      if ( a6 )
        JUMPOUT(0x7E2C2C);
      if ( *a1 )
        v14 = **a1;
      else
        v14 = 0;
      v11 = SysCtxRegOpenKey(v14, var28[0], varg_r3, 0, a5);
      if ( v11 >= 0 && a8 )
        *a8 = 2;
    }
    goto LABEL_8;
  }
  v16 = (int **)a1[3];
  if ( v16 == a1 + 3 )
LABEL_28:
    JUMPOUT(0x7E2BF0);
  v17 = DrvDbAcquireDatabaseNodeBaseKey(a1, a1[3], a3, var28);
  if ( v17 != -1073740697 )
  {
    if ( v17 >= 0 )
    {
      if ( *a1 )
        v18 = **a1;
      else
        v18 = 0;
      v11 = SysCtxRegOpenKey(v18, var28[0], varg_r3, 0, a5);
      DrvDbReleaseDatabaseNodeBaseKey(a1, v16);
      var28[0] = 0;
      if ( v11 == -1073741772 )
        JUMPOUT(0x7E2BE4);
      return v11;
    }
    goto LABEL_28;
  }
  return sub_7E2BE0();
}
