// DrvDbGetDriverPackageMappedPropertyKeys 
 
int __fastcall DrvDbGetDriverPackageMappedPropertyKeys(int **a1, int a2, int a3, int *a4, unsigned int a5, unsigned int *a6)
{
  int *v6; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r4
  unsigned __int16 **v13; // r8
  unsigned int v14; // r10
  int v15; // r2
  unsigned __int16 *v16; // r4
  int *v17; // r5
  unsigned int v18; // lr
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r3
  unsigned int v23; // r2
  int v25; // [sp+10h] [bp-40h] BYREF
  int **v26; // [sp+14h] [bp-3Ch]
  unsigned int v27; // [sp+18h] [bp-38h]
  unsigned int v28; // [sp+1Ch] [bp-34h]
  int *v29; // [sp+20h] [bp-30h]
  unsigned int v30; // [sp+24h] [bp-2Ch] BYREF
  int v31; // [sp+28h] [bp-28h]
  int v32[9]; // [sp+2Ch] [bp-24h] BYREF

  v26 = a1;
  v6 = a4;
  v31 = a2;
  *a6 = 0;
  v9 = 0;
  v27 = a5;
  v28 = 0;
  v25 = 0;
  v10 = DrvDbGetCompositeMappedPropertyKeys((int)a1, (_DWORD **)off_618D24, 9u, a4, a5, a6);
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = *a6;
    if ( *a6 )
    {
      if ( v6 )
        v6 += 5 * v12;
      v27 = a5 - v12;
    }
    if ( a3 )
      goto LABEL_9;
    v10 = DrvDbOpenObjectRegKey(v26, 0, 2, a2, 1, 0, (int)&v25, 0);
    v11 = v10;
    if ( v10 >= 0 )
    {
      v9 = v25;
LABEL_9:
      v13 = (unsigned __int16 **)&off_402398;
      v14 = 0;
      v29 = v6;
      while ( 1 )
      {
        if ( a3 )
          v9 = a3;
        v30 = 0;
        v10 = PnpCtxRegQueryValue(v10, v9, v13[2], 0, 0, &v30);
        v11 = v10;
        if ( v10 == -1073741772 )
        {
          v10 = (int)*v13;
          if ( *((_DWORD *)*v13 + 4) != 7 )
            goto LABEL_28;
          v10 = memcmp(v10, (unsigned int)DEVPKEY_DriverPackage_SignerName, 16);
          if ( v10 )
            goto LABEL_28;
          v15 = a3 ? a3 : v25;
          v10 = DrvDbGetDriverPackageSignerScore(v26, v31, v15, v32);
          if ( v10 < 0 || v32[0] != 218103811 )
            goto LABEL_28;
        }
        else if ( v10 && v10 != -1073741789 )
        {
          break;
        }
        if ( v6 && v28 < v27 )
        {
          v16 = *v13;
          v17 = v29;
          v18 = v28 + 1;
          v10 = *(_DWORD *)*v13;
          v19 = *((_DWORD *)*v13 + 1);
          v20 = *((_DWORD *)*v13 + 2);
          v21 = *((_DWORD *)*v13 + 3);
          *v29 = v10;
          v17[1] = v19;
          v17[2] = v20;
          v17[3] = v21;
          v22 = *((_DWORD *)v16 + 4);
          v28 = v18;
          v17[4] = v22;
          v29 = v17 + 5;
        }
        v23 = *a6 + 1;
        if ( v23 < *a6 )
        {
          *a6 = -1;
          v11 = -1073741675;
          *a6 = 0;
          break;
        }
        *a6 = v23;
LABEL_28:
        ++v14;
        v11 = 0;
        v13 += 6;
        if ( v14 >= 0x1A )
          break;
        v9 = v25;
      }
    }
    if ( v25 )
      ZwClose();
  }
  return v11;
}
