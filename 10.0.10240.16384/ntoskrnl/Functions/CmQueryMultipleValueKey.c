// CmQueryMultipleValueKey 
 
int __fastcall CmQueryMultipleValueKey(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, unsigned int *a6, unsigned int *a7)
{
  _DWORD *v9; // r9
  int v10; // r4
  _DWORD *v11; // r10
  int v12; // r8
  int v13; // r0
  int v14; // r4
  int v15; // r3
  int v16; // r5
  int v17; // r8
  unsigned int v18; // r1
  int v19; // r6
  _DWORD *v20; // r2
  unsigned int v21; // r8
  unsigned int v22; // r6
  int v23; // r0
  unsigned int v24; // r2
  int v25; // r1
  unsigned int *v26; // r3
  int v27; // r8
  int v28; // r0
  unsigned int v29; // r6
  unsigned int v30; // r1
  unsigned int v31; // lr
  unsigned int v32; // r8
  _DWORD *v33; // r2
  int v34; // r0
  char v36; // [sp+10h] [bp-E0h] BYREF
  char v37; // [sp+11h] [bp-DFh]
  char v38; // [sp+12h] [bp-DEh]
  char v39; // [sp+13h] [bp-DDh]
  char v40; // [sp+14h] [bp-DCh]
  int v41; // [sp+18h] [bp-D8h]
  int v42; // [sp+1Ch] [bp-D4h] BYREF
  int v43; // [sp+20h] [bp-D0h]
  int v44; // [sp+24h] [bp-CCh]
  unsigned int v45; // [sp+28h] [bp-C8h]
  unsigned int v46; // [sp+30h] [bp-C0h] BYREF
  int v47; // [sp+34h] [bp-BCh]
  unsigned int v48; // [sp+38h] [bp-B8h]
  unsigned int v49; // [sp+3Ch] [bp-B4h]
  unsigned int v50; // [sp+40h] [bp-B0h]
  unsigned int v51; // [sp+44h] [bp-ACh]
  int v52; // [sp+48h] [bp-A8h]
  int v53; // [sp+4Ch] [bp-A4h]
  int v54; // [sp+50h] [bp-A0h]
  int v55; // [sp+54h] [bp-9Ch]
  unsigned int v56; // [sp+58h] [bp-98h] BYREF
  int v57; // [sp+5Ch] [bp-94h]
  int v58; // [sp+60h] [bp-90h]
  unsigned int v59; // [sp+64h] [bp-8Ch]
  unsigned int v60; // [sp+68h] [bp-88h] BYREF
  int v61; // [sp+6Ch] [bp-84h]
  unsigned int v62; // [sp+70h] [bp-80h]
  int v63; // [sp+74h] [bp-7Ch]
  int v64; // [sp+78h] [bp-78h]
  _DWORD v65[2]; // [sp+7Ch] [bp-74h] BYREF
  unsigned int v66; // [sp+84h] [bp-6Ch]
  int v67; // [sp+88h] [bp-68h] BYREF
  unsigned int v68; // [sp+8Ch] [bp-64h]
  int v69; // [sp+90h] [bp-60h] BYREF
  int v70; // [sp+94h] [bp-5Ch]
  int v71; // [sp+98h] [bp-58h]
  int v72; // [sp+9Ch] [bp-54h]
  _DWORD *v73; // [sp+A0h] [bp-50h]
  int v74; // [sp+A4h] [bp-4Ch]
  _DWORD v75[4]; // [sp+A8h] [bp-48h] BYREF
  _DWORD _B8[20]; // [sp+B8h] [bp-38h] BYREF

  _B8[16] = a1;
  _B8[17] = a2;
  v66 = a4;
  _B8[19] = a4;
  v57 = a3;
  _B8[18] = a3;
  v55 = 0;
  v71 = 0;
  v43 = 0;
  v64 = 0;
  v48 = 0;
  v46 = 0;
  v41 = 0;
  v47 = 0;
  v44 = 0;
  v61 = 0;
  v67 = -1;
  v49 = 0;
  v59 = 0;
  v45 = 0;
  v42 = 0;
  v52 = 0;
  v38 = 0;
  v69 = -1;
  v53 = 0;
  v74 = 0;
  v75[0] = -1;
  v9 = 0;
  v73 = 0;
  v10 = 0;
  v65[0] = 0;
  v63 = 0;
  v37 = 0;
  v58 = 0;
  v39 = 0;
  v56 = 0;
  v36 = 0;
  _B8[0] = -1;
  v50 = 0;
  v62 = 0;
  v68 = 0;
  v75[1] = 0;
  v72 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v40 = v72;
  v11 = (_DWORD *)a1[1];
  v75[2] = v11;
  CmpLockRegistry(a1, 0);
  v12 = a1[7];
  if ( v12 || a1[8] )
  {
    v13 = CmRmIsKCBDeleted(v11, 0);
    if ( v13 == 1 )
    {
      if ( (a1[6] & 1) != 0 )
        v14 = -1073740763;
      else
        v14 = -1073741444;
      goto LABEL_7;
    }
    v13 = CmpSearchAddTrans(a1, 0, 0, v12, a1[8], 0, v65);
    v14 = v13;
    if ( v13 < 0 )
    {
LABEL_7:
      CmpUnlockRegistry(v13);
      return v14;
    }
    v10 = v65[0];
  }
  if ( a2 )
  {
    v9 = *(_DWORD **)(a2 + 4);
    v73 = v9;
  }
  CmpLockTwoKcbsShared(v9, v11);
  if ( CmRmIsKCBDeleted(v11, v10) == 1 )
  {
    v15 = a1[6];
    goto LABEL_19;
  }
  if ( v9 && CmRmIsKCBDeleted(v9, v10) == 1 )
  {
    v15 = *(_DWORD *)(a2 + 24);
LABEL_19:
    if ( (v15 & 1) != 0 )
      v14 = -1073740763;
    else
      v14 = -1073741444;
    goto LABEL_15;
  }
  v16 = v11[5];
  v75[3] = v16;
  CmpLockHiveFlusherShared(v16);
  v17 = (*(int (__fastcall **)(int, _DWORD, int *))(v16 + 4))(v16, v11[6], &v69);
  v70 = v17;
  _B8[1] = v17;
  if ( !v17 )
  {
    CmpUnlockHiveFlusher(v16);
LABEL_30:
    v14 = -1073741670;
LABEL_15:
    v13 = CmpUnlockTwoKcbs(v9, v11);
    goto LABEL_7;
  }
  CmpUpdateKeyNodeAccessBits(v16, v17, v11[6]);
  CmpUnlockHiveFlusher(v16);
  if ( v10 && v11[38] == v10 )
  {
    v63 = 1;
    v37 = 1;
  }
  if ( v9 )
  {
    v55 = v9[5];
    v71 = v55;
    v53 = (*(int (__fastcall **)(int, _DWORD, _DWORD *))(v55 + 4))(v55, v9[6], v75);
    v74 = v53;
    if ( !v53 )
    {
      (*(void (__fastcall **)(int, int *))(v16 + 8))(v16, &v69);
      goto LABEL_30;
    }
    if ( v10 && v9[38] == v10 )
    {
      v58 = 1;
      v39 = 1;
    }
  }
  v14 = 0;
  v54 = 0;
  v18 = 0;
  v19 = 0;
  while ( 1 )
  {
    v65[1] = v18;
    v51 = v18;
    if ( v18 >= v66 )
      break;
    if ( v72 == 1 )
    {
      v20 = *(_DWORD **)(16 * v18 + v57);
      if ( (unsigned int)v20 >= MmUserProbeAddress )
        v20 = (_DWORD *)MmUserProbeAddress;
      v65[0] = *v20;
      _B8[2] = v65[0];
      v21 = v20[1];
      _B8[3] = v21;
      _B8[4] = v65[0];
      _B8[5] = v21;
      v22 = LOWORD(v65[0]);
      if ( LOWORD(v65[0]) )
      {
        if ( (v21 & 1) != 0 )
          ExRaiseDatatypeMisalignment(1);
        if ( LOWORD(v65[0]) + v21 > MmUserProbeAddress || LOWORD(v65[0]) + v21 < v21 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      if ( (v22 & 1) != 0 )
      {
        v14 = -1073741811;
        v54 = -1073741811;
LABEL_87:
        v19 = v43;
        break;
      }
      if ( v22 && v22 > v68 )
      {
        if ( v50 )
          ExFreePoolWithTag(v50);
        v23 = ExAllocatePoolWithTag(512, v22, 538987843);
        v50 = v23;
        v62 = v23;
        if ( !v23 )
        {
          v14 = -1073741670;
          v54 = -1073741670;
          goto LABEL_87;
        }
        v41 = v23;
        v47 = v23;
      }
      else
      {
        v23 = v41;
      }
      memmove(v23, v21, v22);
      v24 = v22;
      v48 = v22;
      LOWORD(v46) = v22;
      HIWORD(v46) = v22;
      v25 = v41;
    }
    else
    {
      v26 = *(unsigned int **)(16 * v18 + v57);
      v24 = *v26;
      v25 = v26[1];
      v41 = v25;
      __dmb(0xBu);
      v46 = v24;
      v47 = v25;
      v24 = (unsigned __int16)v24;
      v48 = (unsigned __int16)v24;
      v50 = v62;
      v14 = v54;
    }
    while ( v24 && !*(_WORD *)(v25 + 2 * (v24 >> 1) - 2) )
    {
      v24 = (unsigned __int16)(v24 - 2);
      LOWORD(v46) = v24;
    }
    v48 = v24;
    v27 = -1;
    v42 = -1;
    if ( v9 )
    {
      v19 = v55;
      v43 = v55;
      v64 = v55;
      if ( v58 )
      {
        CmpFindNameInList(v55, v9 + 36, &v46, 0, 0, &v42);
        v27 = v42;
      }
      else
      {
        v27 = CmpFindValueByName(v55, v53, &v46);
        v42 = v27;
      }
    }
    else
    {
      v19 = v43;
    }
    if ( v27 == -1 )
    {
      v19 = v16;
      v43 = v16;
      v64 = v16;
      if ( v63 )
      {
        CmpFindNameInList(v16, v11 + 36, &v46, 0, 0, &v42);
        v27 = v42;
      }
      else
      {
        v27 = CmpFindValueByName(v16, v70, &v46);
      }
    }
    if ( v27 == -1 )
    {
      v14 = -1073741772;
      break;
    }
    v28 = (*(int (__fastcall **)(int, int, int *))(v19 + 4))(v19, v27, &v67);
    v44 = v28;
    v61 = v28;
    if ( !v28 )
    {
      v14 = -1073741670;
      goto LABEL_94;
    }
    v29 = *(_DWORD *)(v28 + 4);
    if ( v29 >= 0x80000000 )
      v29 += 0x80000000;
    v60 = v29;
    v30 = (v45 + 3) & 0xFFFFFFFC;
    v45 = v30;
    v42 = v30;
    v31 = (v49 + 3) & 0xFFFFFFFC;
    v49 = v31;
    v59 = v31;
    if ( v29 + v30 > *a6 || v29 + v30 < v30 || v52 )
    {
      v52 = 1;
      v38 = 1;
    }
    else
    {
      v19 = v43;
      if ( !CmpGetValueData(v43, v27, v28, &v60, &v56, &v36, _B8) )
      {
        v14 = -1073741670;
        goto LABEL_93;
      }
      v29 = v60;
      v32 = v56;
      memmove(v45 + a5, v56, v60);
      v33 = (_DWORD *)(v57 + 16 * v51);
      v33[3] = *(_DWORD *)(v44 + 12);
      v33[1] = v29;
      v33[2] = v45;
      if ( v36 )
      {
        ExFreePoolWithTag(v32);
        v36 = 0;
      }
      else
      {
        (*(void (__fastcall **)(int, _DWORD *))(v43 + 8))(v43, _B8);
      }
      v56 = 0;
      if ( v14 < 0 )
        goto LABEL_87;
      v45 += v29;
      v42 = v45;
      v31 = v49;
    }
    v49 = v31 + v29;
    v59 = v31 + v29;
    v19 = v43;
    (*(void (__fastcall **)(int, int *))(v43 + 8))(v43, &v67);
    v44 = 0;
    v61 = 0;
    v18 = v51 + 1;
  }
  if ( v14 >= 0 )
  {
    if ( v52 )
      v14 = -2147483643;
    *a6 = v45;
    if ( a7 )
      *a7 = v49;
  }
LABEL_93:
  v28 = v44;
LABEL_94:
  if ( v28 )
    (*(void (__fastcall **)(int, int *))(v19 + 8))(v19, &v67);
  if ( v53 )
    (*(void (__fastcall **)(int, _DWORD *))(v55 + 8))(v55, v75);
  (*(void (__fastcall **)(int, int *))(v16 + 8))(v16, &v69);
  v34 = CmpUnlockTwoKcbs(v9, v11);
  CmpUnlockRegistry(v34);
  if ( v50 )
    ExFreePoolWithTag(v50);
  return v14;
}
