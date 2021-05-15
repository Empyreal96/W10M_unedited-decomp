// PpmSetProfilePolicySetting 
 
int __fastcall PpmSetProfilePolicySetting(unsigned int a1, unsigned int a2, int a3, int a4, int a5)
{
  int v7; // r10
  int v8; // r3
  char **v9; // r6
  int v10; // r2
  unsigned int v11; // r7
  unsigned int v12; // r8
  char *v13; // r5
  int v14; // r1
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r4
  char v18; // r5
  int v19; // r4
  char v20; // r2
  int v21; // r9
  char *v22; // r8
  int *v23; // r5
  char *v24; // r10
  int v25; // r3
  int v26; // r0
  int *v27; // r1
  int v28; // r3
  unsigned int v30; // r7
  unsigned int v31; // r8
  int v32; // r5
  char *v33; // r8
  int v34; // r7
  char *v35; // r9
  int v36; // r3
  int v37; // r0
  _DWORD *v38; // r1
  int v39; // r3
  unsigned int v40; // r5
  int v41; // r2
  int v42; // r1
  int v43; // lr
  int v44; // r8
  _DWORD *v45; // r0
  int v46; // r3
  int v47; // r0
  __int64 v48; // [sp+10h] [bp-60h]
  int v49; // [sp+18h] [bp-58h]
  int v50; // [sp+1Ch] [bp-54h]
  int *v52; // [sp+20h] [bp-50h]
  int v53; // [sp+24h] [bp-4Ch]
  int *v54; // [sp+28h] [bp-48h]
  int v55; // [sp+2Ch] [bp-44h]
  int v56; // [sp+30h] [bp-40h]
  _DWORD v58[3]; // [sp+40h] [bp-30h] BYREF
  int v59; // [sp+4Ch] [bp-24h]

  v7 = a3;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v55 = a4;
  v56 = 0;
  v50 = 0;
  if ( !a5 || !a4 )
  {
    v19 = -1073741811;
LABEL_17:
    if ( v8 )
    {
      PpmInfoApplySettingUpdate(v9);
      return v19;
    }
    if ( !v10 )
      return v19;
LABEL_19:
    PpmInfoReleaseLocks((int)v9);
    return v19;
  }
  v9 = &PpmPolicyConfigTable;
  v11 = 0;
LABEL_4:
  v12 = 1;
  if ( (*((_BYTE *)v9 + 25) & 4) != 0 )
    v12 = 2;
  v13 = v9[1];
  v14 = *((_DWORD *)v13 + 1);
  v15 = *((_DWORD *)v13 + 2);
  v16 = *((_DWORD *)v13 + 3);
  v58[0] = *(_DWORD *)v13;
  v58[1] = v14;
  v58[2] = v15;
  v59 = v16;
  v17 = 0;
  v18 = HIBYTE(v16);
  while ( memcmp((unsigned int)v58, a2, 16) )
  {
    ++v18;
    ++v17;
    HIBYTE(v59) = v18;
    if ( v17 >= v12 )
    {
      ++v11;
      v9 += 7;
      if ( v11 >= 0x2A )
        return -1073741275;
      goto LABEL_4;
    }
  }
  v20 = *((_BYTE *)v9 + 24);
  HIDWORD(v48) = 1 << (v20 - 32);
  v49 = v17;
  LODWORD(v48) = 1 << v20;
  PpmInfoAcquireLocks((int)v9);
  v54 = PpmCurrentProfile;
  v53 = dword_61EC0C;
  if ( memcmp(a1, (unsigned int)&NullGuid, 16) )
  {
    v30 = 0;
    v31 = (unsigned __int8)PpmProfileCount;
    if ( !PpmProfileCount )
    {
LABEL_35:
      v19 = -1073741275;
      goto LABEL_19;
    }
    v32 = PpmProfiles;
    while ( memcmp(v32 + 8, a1, 16) )
    {
      ++v30;
      v32 += 424;
      if ( v30 >= v31 )
        goto LABEL_35;
    }
    v33 = v9[5];
    v34 = v32 + 176 * v7 + 32;
    v35 = &v9[4][(_DWORD)v33 * v17 + v34];
    if ( (*((_BYTE *)v9 + 25) & 4) == 0 || v17 || (v48 & *(_QWORD *)(v32 + 176 * v7 + 40)) != 0 )
      v36 = v17;
    else
      v36 = 1;
    v37 = PpmInfoAdjustSetting(v9, v32 + 176 * v7 + 32, v17, v36, v55, a5);
    v38 = (_DWORD *)(v34 + 8 * v17);
    v39 = v38[1];
    *v38 |= v48;
    v38[1] = v39 | HIDWORD(v48);
    if ( v37 )
    {
      PpmEventTraceProfileSetting(*(unsigned __int8 *)(v32 + 4), *v9, v9[1], (unsigned __int8)v17, v35, v33, v7, 0);
      if ( v54 == (int *)v32 && v53 == v7 )
      {
        v8 = 1;
        goto LABEL_16;
      }
    }
    goto LABEL_15;
  }
  v21 = 176 * v7;
  v22 = v9[5];
  v23 = &dword_61DBC0[44 * v7];
  v24 = &v9[4][(_DWORD)v22 * v17 + (_DWORD)v23];
  if ( (*((_BYTE *)v9 + 25) & 4) == 0 || v17 || (v48 & *((_QWORD *)v23 + 1)) != 0 )
  {
    v25 = v17;
  }
  else
  {
    v25 = 1;
    v56 = 1;
    v49 = 1;
  }
  v26 = PpmInfoAdjustSetting(v9, v23, v17, v25, v55, a5);
  v27 = &v23[2 * v17];
  v28 = v27[1];
  *v27 |= v48;
  v27[1] = v28 | HIDWORD(v48);
  if ( !v26 )
  {
LABEL_15:
    v8 = 0;
LABEL_16:
    v10 = 1;
    v19 = 0;
    goto LABEL_17;
  }
  PpmEventTraceProfileSetting((unsigned __int8)byte_61DBA4, *v9, v9[1], (unsigned __int8)v17, v24, v22, a3, 0);
  if ( v54 == &PpmDefaultProfile && v53 == a3 )
    v50 = 1;
  v40 = 0;
  if ( !PpmProfileCount )
  {
LABEL_49:
    v8 = v50;
    goto LABEL_16;
  }
  v41 = v21 + 32;
  v43 = HIDWORD(v48);
  v42 = v48;
  v44 = 0;
  while ( 1 )
  {
    v45 = (_DWORD *)(v41 + PpmProfiles + v44);
    v52 = (int *)(PpmProfiles + v44);
    if ( !(*(int *)((char *)&v52[2 * v17 + 1] + v41) & v43 | v42 & *(int *)((char *)&v52[2 * v17] + v41)) )
      break;
LABEL_47:
    v42 = v48;
LABEL_48:
    ++v40;
    v41 = v21 + 32;
    v44 += 424;
    if ( v40 >= (unsigned __int8)PpmProfileCount )
      goto LABEL_49;
  }
  v42 = v48;
  if ( v17 && v45[1] & v43 | *v45 & (unsigned int)v48 )
    goto LABEL_48;
  if ( (*((_BYTE *)v9 + 25) & 4) == 0 || v17 )
    goto LABEL_44;
  if ( !v56 )
  {
    v46 = 0;
    goto LABEL_54;
  }
  if ( v45[3] & v43 | v45[2] & (unsigned int)v48 )
  {
LABEL_44:
    v46 = v49;
    goto LABEL_45;
  }
  v46 = 1;
LABEL_54:
  v49 = v46;
LABEL_45:
  v47 = PpmInfoAdjustSetting(v9, v45, v17, v46, v55, a5);
  v43 = HIDWORD(v48);
  if ( v54 != v52 )
    goto LABEL_47;
  return sub_7C3670(v47);
}
