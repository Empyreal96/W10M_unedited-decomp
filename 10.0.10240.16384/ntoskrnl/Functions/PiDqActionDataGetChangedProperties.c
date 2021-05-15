// PiDqActionDataGetChangedProperties 
 
int __fastcall PiDqActionDataGetChangedProperties(int a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int a7, int a8, unsigned int *a9, unsigned int *a10)
{
  int v10; // r5
  int v11; // r7
  unsigned int v12; // r10
  _DWORD *v13; // r8
  unsigned int v14; // r2
  int v15; // r4
  unsigned int v16; // r6
  int v17; // r9
  unsigned int v18; // r6
  int v19; // r8
  unsigned int v20; // r5
  int v22; // r3
  unsigned __int16 *v23; // r4
  int v24; // r5
  int v25; // r0
  unsigned int v26; // r6
  unsigned int v27; // r5
  unsigned int *v28; // r5
  unsigned int v29; // r3
  unsigned int *v30; // r4
  int v31; // r8
  int v32; // r9
  unsigned int v33; // r4
  unsigned int v34; // r3
  unsigned int v35; // r3
  int v36; // [sp+18h] [bp-78h] BYREF
  int v37; // [sp+1Ch] [bp-74h]
  _DWORD *v38; // [sp+20h] [bp-70h]
  unsigned int *v39; // [sp+24h] [bp-6Ch]
  int v40; // [sp+28h] [bp-68h]
  int v41; // [sp+2Ch] [bp-64h]
  unsigned int *v42; // [sp+30h] [bp-60h]
  unsigned int v43; // [sp+34h] [bp-5Ch]
  int v44; // [sp+38h] [bp-58h]
  int v45; // [sp+3Ch] [bp-54h] BYREF
  int v46; // [sp+40h] [bp-50h]
  unsigned __int16 *v47; // [sp+44h] [bp-4Ch]
  char v48[16]; // [sp+48h] [bp-48h] BYREF
  int v49; // [sp+58h] [bp-38h]
  int v50; // [sp+5Ch] [bp-34h]
  int v51; // [sp+60h] [bp-30h]

  v44 = a4;
  v40 = a8;
  v41 = a3;
  v10 = a2;
  v46 = a1;
  v47 = (unsigned __int16 *)a5;
  v39 = a9;
  v36 = 0;
  v37 = a2;
  v42 = a10;
  *a10 = 0;
  v11 = 0;
  v12 = 0;
  v45 = 0;
  PiPnpRtlBeginOperation(&v45, a2, 0, (int)a10);
  v43 = 0;
  if ( *(_DWORD *)(a8 + 44) )
  {
    v13 = (_DWORD *)(a8 + 48);
    v14 = a6;
    v15 = v36;
    v38 = (_DWORD *)(a8 + 48);
    while ( 1 )
    {
      v16 = a7;
      v17 = 0;
      if ( !v14 )
        goto LABEL_14;
      v18 = 0;
      if ( a7 )
        break;
LABEL_35:
      v13 += 7;
      v29 = *(_DWORD *)(v40 + 44);
      ++v43;
      v38 = v13;
      if ( v43 >= v29 )
        goto LABEL_36;
    }
    v19 = v13[4];
    v20 = v14;
    while ( v19 != *(_DWORD *)(v20 + 16) || memcmp((unsigned int)v38, v20, 16) || v38[5] != *(_DWORD *)(v20 + 20) )
    {
      ++v18;
      v20 += 28;
      if ( v18 >= a7 )
      {
        v13 = v38;
        goto LABEL_34;
      }
    }
    if ( v38[6] )
      return sub_7EE444();
    v10 = v37;
    v13 = v38;
    v16 = a7;
LABEL_14:
    v22 = v13[5];
    if ( v22 )
    {
      if ( v22 != 1 )
      {
        v11 = -1073741811;
        goto LABEL_36;
      }
      v10 = 0;
      if ( !v15 )
      {
        v11 = PiDqOpenObjectRegKey(1, v41, v37, 1, 0, v46, &v36);
        if ( v11 == -1073741772 )
        {
          v11 = 0;
          v15 = -1;
          v36 = -1;
        }
        else
        {
          v15 = v36;
        }
      }
      if ( v15 == -1 )
      {
LABEL_34:
        v14 = a6;
        v10 = v37;
        goto LABEL_35;
      }
      v17 = v15;
    }
    if ( v11 < 0 )
      goto LABEL_36;
    if ( v44 )
    {
      v23 = v47;
      v11 = PiDqPnPGetObjectPropertyInBestLocale(v41, v10, v17, v13, v13[5], v47, v48);
      if ( v11 >= 0 )
      {
        v24 = v51;
        while ( 1 )
        {
          if ( !*v23 )
            v23 = 0;
          v25 = v13[6];
          if ( (unsigned __int16 *)v25 == v23 || v25 && v23 && !wcsicmp(v25, v23) )
            break;
          if ( (unsigned __int16 *)v24 == v23 || v24 && (!v23 || !wcsicmp(v24, v23)) || !v23 )
          {
LABEL_59:
            PnpFreeDevProperty(v48, 1483763280);
            goto LABEL_33;
          }
          v23 += wcslen(v23) + 1;
        }
        v26 = 0;
        v27 = *v42;
        if ( *v42 )
        {
          v32 = v49;
          v31 = v50;
          v33 = *v39;
          do
          {
            if ( v32 == *(_DWORD *)(v33 + 16) && !memcmp((unsigned int)v48, v33, 16) && v31 == *(_DWORD *)(v33 + 20) )
            {
              v13 = v38;
              goto LABEL_59;
            }
            ++v26;
            v33 += 40;
          }
          while ( v26 < v27 );
          v13 = v38;
        }
        if ( v12 > v27 )
          goto LABEL_32;
        if ( a7 )
        {
          v12 = a7;
        }
        else
        {
          v34 = *(_DWORD *)(v40 + 44);
          if ( v34 <= 5 )
            v34 = 5;
          v12 += v34;
        }
        v11 = PiDqGrowPropertyArray(v39);
        if ( v11 >= 0 )
        {
LABEL_32:
          v28 = v42;
          memmove(*v39 + 40 * *v42, (int)v48, 0x28u);
          ++*v28;
          goto LABEL_33;
        }
        PnpFreeDevProperty(v48, 1483763280);
      }
      goto LABEL_46;
    }
    v30 = v42;
    if ( v12 <= *v42 )
    {
      if ( v16 )
      {
        v12 = v16;
      }
      else
      {
        v35 = *(_DWORD *)(v40 + 44);
        if ( v35 <= 5 )
          v35 = 5;
        v12 += v35;
      }
      v11 = PiDqGrowPropertyArray(v39);
      if ( v11 < 0 )
        goto LABEL_46;
    }
    v11 = PiDqPnPGetObjectProperty(v41, v10, v17, v13, v13[5], v13[6], (_DWORD *)(*v39 + 40 * *v30));
    if ( v11 < 0 )
      goto LABEL_46;
    ++*v30;
LABEL_33:
    v15 = v36;
    goto LABEL_34;
  }
LABEL_46:
  v15 = v36;
LABEL_36:
  if ( v15 && v15 != -1 )
    ZwClose();
  if ( v45 )
    PiPnpRtlEndOperation(v45);
  return v11;
}
