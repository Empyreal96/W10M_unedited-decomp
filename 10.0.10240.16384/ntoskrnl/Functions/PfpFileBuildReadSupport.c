// PfpFileBuildReadSupport 
 
int __fastcall PfpFileBuildReadSupport(_DWORD *a1, _DWORD *a2, int a3, int a4, unsigned int *a5)
{
  _BYTE *v9; // r0
  int v10; // r5
  unsigned int v11; // r10
  int *v13; // r6
  int v14; // r4
  char v15; // r7
  int v16; // r6
  int v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // [sp+10h] [bp-70h] BYREF
  unsigned int v29; // [sp+14h] [bp-6Ch] BYREF
  int v30; // [sp+18h] [bp-68h]
  int v31; // [sp+1Ch] [bp-64h]
  int v32; // [sp+20h] [bp-60h] BYREF
  char v33[8]; // [sp+28h] [bp-58h] BYREF
  int v34[6]; // [sp+30h] [bp-50h] BYREF
  int v35; // [sp+48h] [bp-38h] BYREF
  int v36; // [sp+4Ch] [bp-34h]
  int v37; // [sp+50h] [bp-30h]
  int v38; // [sp+54h] [bp-2Ch]
  int v39; // [sp+58h] [bp-28h]
  int v40; // [sp+5Ch] [bp-24h]

  v30 = a4;
  v9 = memset(v34, 0, 20);
  v10 = 0;
  v34[4] |= 2u;
  v28 = 0;
  v29 = 0;
  v11 = 0;
  if ( !a4 )
    return sub_80ED38(v9);
  v31 = 285212672;
  v13 = (int *)(a1[1] + 20 * (((int)a2 - *(_DWORD *)(*a1 + 36) - *a1) >> 5));
  if ( a1[1] && (v13[4] & 4) != 0 )
  {
    v22 = v13[1];
    v23 = v13[2];
    v24 = v13[3];
    v34[0] = *v13;
    v34[1] = v22;
    v34[2] = v23;
    v34[3] = v24;
    v34[4] = v13[4];
    v15 = LOBYTE(v34[4]) | 0x10;
    v34[4] |= 0x10u;
  }
  else
  {
    PfpFileSetupObjectAttributes(a1, a2, a3, v33, &v35, &v32);
    v14 = PfpOpenHandleCreate(v34, (_DWORD *)a1[5], v37, v36, 32, v32, 128, a1[2] + 40 * a3);
    if ( v14 < 0 )
    {
      v15 = v34[4];
LABEL_33:
      v10 = v28;
      goto LABEL_14;
    }
    v14 = PfpFileCheckAttributesForPrefetch(v34[0]);
    if ( v14 < 0 )
    {
      v15 = v34[4];
      v10 = v28;
      goto LABEL_30;
    }
    if ( a1[1] )
    {
      v25 = v34[1];
      v26 = v34[2];
      v27 = v34[3];
      *v13 = v34[0];
      v13[1] = v25;
      v13[2] = v26;
      v13[3] = v27;
      v13[4] = v34[4];
      v15 = LOBYTE(v34[4]) | 0x10;
      v34[4] |= 0x10u;
    }
    else
    {
      v15 = v34[4];
    }
    v10 = v28;
  }
  v16 = v30;
  if ( (*a2 & 1) != 0 && !v30 && *(_DWORD *)(*(_DWORD *)(v34[1] + 20) + 8) )
  {
    v14 = -1073741791;
    goto LABEL_14;
  }
  v35 = 24;
  v36 = 0;
  v38 = 576;
  v37 = 0;
  v39 = 0;
  v40 = 0;
  v17 = NtCreateSection(&v28, 5, (int)&v35, 0, 2, v31, v34[0]);
  v14 = v17;
  if ( v17 >= 0 )
  {
    v14 = PfpFileBuildReadList(a1, a2, v16, &v29);
    if ( v14 >= 0 )
    {
      v18 = v34[1];
      v19 = v34[2];
      v20 = v34[3];
      a5[1] = v34[0];
      a5[2] = v18;
      a5[3] = v19;
      a5[4] = v20;
      a5[5] = v34[4];
      memset(v34, 0, 20);
      v10 = 0;
      v11 = 0;
      v15 = LOBYTE(v34[4]) | 2;
      v21 = v28;
      v34[4] |= 2u;
      v28 = 0;
      a5[6] = v21;
      a5[7] = (unsigned int)a2;
      v14 = 0;
      *a5 = v29;
      goto LABEL_14;
    }
    v11 = v29;
    goto LABEL_33;
  }
  v10 = v28;
  if ( !v16 || v17 != -1073740749 )
  {
LABEL_30:
    if ( (*a2 & 8) == 0 )
    {
      *a2 |= 8u;
      ++*(_DWORD *)(*a1 + 100);
      v10 = v28;
    }
    goto LABEL_15;
  }
LABEL_14:
  if ( (v15 & 1) != 0 )
    goto LABEL_30;
LABEL_15:
  if ( v10 )
    NtClose();
  if ( (v15 & 4) != 0 )
    PfpOpenHandleClose(v34, a1[5]);
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v14;
}
