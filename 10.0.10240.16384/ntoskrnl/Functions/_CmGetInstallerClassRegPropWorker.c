// _CmGetInstallerClassRegPropWorker 
 
int __fastcall CmGetInstallerClassRegPropWorker(int *a1, unsigned __int16 *a2, int a3, int a4, unsigned int *a5, unsigned __int16 *a6, int *a7, __int16 a8)
{
  int v8; // r7
  int v10; // r5
  int v11; // r6
  int v12; // r4
  unsigned __int16 *v14; // r10
  const __int16 *v15; // r0
  int v16; // r5
  int v17; // r0
  unsigned int v18; // r2
  int v19; // [sp+4h] [bp-44h]
  int v20; // [sp+10h] [bp-38h] BYREF
  int v21; // [sp+14h] [bp-34h] BYREF
  int *v22; // [sp+18h] [bp-30h]
  unsigned int v23; // [sp+1Ch] [bp-2Ch] BYREF
  unsigned int v24; // [sp+20h] [bp-28h] BYREF
  unsigned int v25; // [sp+24h] [bp-24h]

  v8 = a3;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v21 = 0;
  v22 = a1;
  v20 = 0;
  v24 = 0;
  if ( a8 )
    return sub_7CB690();
  if ( !a7 || !a5 )
  {
    v12 = -1073741811;
    goto LABEL_21;
  }
  v25 = *a7;
  if ( v25 )
  {
    v14 = a6;
    if ( !a6 )
      return sub_7CB690();
  }
  else
  {
    v14 = 0;
  }
  *a7 = 0;
  *a5 = 0;
  if ( (unsigned int)(a4 - 1) <= 0x24 && *((_BYTE *)ClassPropertyRead + a4) )
  {
    if ( !a3 )
    {
      v12 = CmOpenInstallerClassRegKey(a1, a2, (int)a5, 33554433, 33554433, 0, (int)&v20, 0);
      if ( v12 < 0 )
        goto LABEL_20;
      v10 = v20;
      v11 = v21;
      a1 = v22;
    }
    if ( a4 == 8 || a4 == 13 || a4 <= 19 && a4 > 17 )
    {
      if ( !v8 )
        v8 = v10;
    }
    else
    {
      if ( !v8 )
        v8 = v10;
      a1 = (int *)PnpOpenPropertiesKey(a1, v8, 0, 1, 0, v19, &v21);
      v12 = (int)a1;
      v10 = v20;
      v11 = v21;
      if ( (int)a1 < 0 )
      {
        v12 = -1073741275;
        goto LABEL_21;
      }
      v8 = v21;
    }
    if ( v12 < 0 )
    {
LABEL_21:
      if ( v11 )
      {
        ZwClose();
        v10 = v20;
      }
      if ( v10 )
        ZwClose();
      return v12;
    }
    v15 = MapCmClassPropertyToRegValue((int)a1, a4);
    if ( !v15 )
    {
      v12 = -1073741264;
      goto LABEL_21;
    }
    v16 = v25;
    v23 = v25;
    v17 = PnpCtxRegQueryValueIndirect((int)v22, v8, (int)v15, &v24, v14, &v23, 0);
    if ( v17 != -1073741772 && v17 != -1073741444 )
    {
      if ( v17 < 0 && v17 != -1073741789 )
      {
        v12 = v17;
        goto LABEL_20;
      }
      v18 = v24;
      if ( (v24 != 1 || v23 >= 2) && (v24 != 7 || v23 >= 2) && (v24 != 4 || v23 == 4) )
      {
        if ( a4 == 8 && v23 > 0x40 )
        {
          v12 = -1073741595;
        }
        else
        {
          *a7 = v23;
          *a5 = v18;
          if ( v17 || !v16 )
            v12 = -1073741789;
        }
        goto LABEL_20;
      }
    }
    v12 = -1073741275;
LABEL_20:
    v10 = v20;
    v11 = v21;
    goto LABEL_21;
  }
  return -1073741264;
}
