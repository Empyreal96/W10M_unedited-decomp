// PiDqActionDataGetRequestedProperties 
 
int __fastcall PiDqActionDataGetRequestedProperties(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, unsigned int a7, int *a8, _DWORD *a9)
{
  int v9; // r8
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int *v13; // r4
  unsigned int v15; // r7
  int v17; // r5
  int v18; // r0
  int v19; // r1
  _DWORD *v20; // r10
  int v21; // r3
  int v22; // r4
  int v23; // r0
  int v24; // r5
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // [sp+18h] [bp-38h] BYREF
  int v31; // [sp+1Ch] [bp-34h] BYREF
  int v32; // [sp+20h] [bp-30h]
  int v33; // [sp+24h] [bp-2Ch]
  int v34; // [sp+28h] [bp-28h]
  int v35; // [sp+2Ch] [bp-24h]

  v32 = a3;
  v33 = a2;
  v34 = a1;
  v35 = a4;
  v30 = 0;
  v9 = 0;
  v31 = 0;
  *a9 = 0;
  v10 = ExAllocatePoolWithTag(1, 40 * a7, 1483763280);
  v13 = a8;
  *a8 = v10;
  if ( !v10 )
    return sub_7C6784();
  PiPnpRtlBeginOperation(&v31, v11, v12, -1);
  v15 = 0;
  if ( !a7 )
  {
LABEL_15:
    v24 = v31;
    v18 = v30;
    goto LABEL_16;
  }
  v17 = a5;
  while ( 1 )
  {
    v18 = v30;
    v19 = 0;
    v20 = (_DWORD *)(*v13 + 40 * *a9);
    v21 = a6[5];
    if ( !v21 )
    {
      v22 = v33;
      goto LABEL_7;
    }
    if ( v21 != 1 )
      break;
    v22 = 0;
    if ( !v30 )
    {
      v9 = PiDqOpenObjectRegKey(1, v32, v33, 1, 0, v34, &v30);
      if ( v9 == -1073741772 )
      {
        v30 = -1;
        v9 = 0;
LABEL_24:
        v25 = a6[1];
        v26 = a6[2];
        v27 = a6[3];
        *v20 = *a6;
        v20[1] = v25;
        v20[2] = v26;
        v20[3] = v27;
        v28 = a6[5];
        v29 = a6[6];
        v20[4] = a6[4];
        v20[5] = v28;
        v20[6] = v29;
        v20[7] = 0;
        v20[8] = 0;
        v20[9] = 0;
        v17 = a5;
        ++*a9;
        goto LABEL_12;
      }
      v18 = v30;
    }
    if ( v18 == -1 )
      goto LABEL_24;
    v19 = v18;
LABEL_7:
    if ( v9 < 0 )
      goto LABEL_32;
    if ( v35 )
      v23 = PiDqPnPGetObjectPropertyInBestLocale(v32, v22, v19, a6, a6[5], v17, v20);
    else
      v23 = PiDqPnPGetObjectProperty(v32, v22, v19, a6, a6[5], a6[6], v20);
    v9 = v23;
    if ( v23 < 0 )
      goto LABEL_15;
    ++*a9;
LABEL_12:
    ++v15;
    a6 += 7;
    if ( v15 >= a7 )
      goto LABEL_15;
    v13 = a8;
  }
  v9 = -1073741811;
LABEL_32:
  v24 = v31;
LABEL_16:
  if ( v18 && v18 != -1 )
    ZwClose();
  if ( v24 )
    PiPnpRtlEndOperation(v24);
  return v9;
}
