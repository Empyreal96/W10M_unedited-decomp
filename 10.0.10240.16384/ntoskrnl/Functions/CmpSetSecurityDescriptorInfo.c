// CmpSetSecurityDescriptorInfo 
 
int __fastcall CmpSetSecurityDescriptorInfo(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r5
  unsigned int v9; // r10
  int (__fastcall *v10)(int, unsigned int, int *); // r3
  int v11; // r6
  int v13; // r4
  int v14; // r0
  int v16; // r0
  int *v17; // r7
  int v18; // r6
  int v19; // r8
  int v20; // r8
  int v21; // r9
  __int64 v22; // r2
  int v23; // r0
  unsigned int v24; // r8
  unsigned int v25; // r0
  int v26; // r3
  unsigned int v27; // r8
  __int64 v28; // r2
  int v29; // r8
  int v30; // r0
  unsigned int v31; // r0
  int v32; // r0
  int v33; // r0
  int v34; // r1
  unsigned int v35; // r2
  int v36; // r3
  unsigned int v37; // r8
  char *v38; // r8
  int v39; // r10
  int v40; // r3
  int *v41; // [sp+8h] [bp-78h] BYREF
  unsigned int v42; // [sp+Ch] [bp-74h]
  char v43[4]; // [sp+10h] [bp-70h] BYREF
  unsigned int v44; // [sp+14h] [bp-6Ch]
  int v45; // [sp+18h] [bp-68h]
  int v46; // [sp+1Ch] [bp-64h]
  char v47[4]; // [sp+20h] [bp-60h] BYREF
  int v48; // [sp+24h] [bp-5Ch]
  int v49; // [sp+28h] [bp-58h] BYREF
  _DWORD *v50; // [sp+2Ch] [bp-54h] BYREF
  unsigned int v51; // [sp+30h] [bp-50h]
  int v52; // [sp+34h] [bp-4Ch]
  unsigned int v53; // [sp+38h] [bp-48h] BYREF
  int v54; // [sp+3Ch] [bp-44h]
  int v55; // [sp+40h] [bp-40h] BYREF
  int v56; // [sp+44h] [bp-3Ch] BYREF
  int v57; // [sp+48h] [bp-38h] BYREF
  int v58; // [sp+4Ch] [bp-34h] BYREF
  __int64 v59; // [sp+50h] [bp-30h] BYREF
  char v60[40]; // [sp+58h] [bp-28h] BYREF

  v54 = 0;
  v9 = *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 20);
  v49 = -1;
  v50 = a2;
  v55 = -1;
  v57 = -1;
  v58 = -1;
  v41 = 0;
  v42 = 0;
  v43[0] = 0;
  v45 = 0;
  v10 = *(int (__fastcall **)(int, unsigned int, int *))(v8 + 4);
  v11 = a3;
  v51 = v9;
  v52 = a1;
  v13 = 0;
  v56 = a3;
  v46 = 0;
  v14 = v10(v8, v9, &v57);
  v48 = v14;
  if ( !v14 )
    return sub_7EE57C();
  CmpUpdateKeyNodeAccessBits(v8, v14, v9);
  v44 = *(_DWORD *)CmGetKCBCacheSecurity(a1, a7);
  v16 = (*(int (__fastcall **)(int, unsigned int, int *))(v8 + 4))(v8, v44, &v49);
  v17 = (int *)v16;
  if ( v16 )
  {
    if ( *(_DWORD *)(a1 + 20) == dword_60E8B4 && (*v50 & 4) != 0 )
    {
      SepCheckForAllAppPackagesAceRemoval(v16 + 20, v11, v47, 0);
      if ( v47[0] )
      {
        v38 = (char *)CmpConstructName(a1);
        if ( v38 )
        {
          v39 = 1;
        }
        else
        {
          RtlInitUnicodeString((unsigned int)v60, L"<Unknown registry key>");
          v38 = v60;
          v39 = 0;
        }
        v18 = SeAdjustObjectAppContainerSecurity(v38, v17 + 5, v11, &v41, v43);
        if ( v39 )
          ExFreePoolWithTag((unsigned int)v38);
        if ( v18 < 0 )
        {
          v24 = 0;
          v25 = (unsigned int)v41;
          v21 = 0;
          goto LABEL_18;
        }
        v9 = v51;
        if ( v43[0] )
        {
          v42 = (unsigned int)v41;
          v11 = (int)v41;
        }
        else
        {
          v11 = v56;
          v42 = (unsigned int)v41;
        }
      }
    }
    v41 = v17 + 5;
    v18 = SeSetSecurityDescriptorInfo(0, v50, v11, &v41);
    if ( v18 < 0 )
    {
      v24 = 0;
      v21 = 0;
      goto LABEL_17;
    }
    v53 = RtlLengthSecurityDescriptor((int)v41);
    if ( a7 )
      v19 = 1;
    else
      v19 = v9 >> 31;
    KeQuerySystemTime(&v59);
    if ( a7 )
    {
      if ( !HvpMarkCellDirty(v8, v44, 0, 0) )
      {
LABEL_55:
        v18 = -1073741443;
LABEL_76:
        v21 = 0;
        goto LABEL_16;
      }
      *(_DWORD *)(a8 + 36) = 9;
      *(_DWORD *)(a8 + 48) = -1;
    }
    else if ( !HvpMarkCellDirty(v8, v51, 0, 0) || !HvpMarkCellDirty(v8, v44, 0, 0) )
    {
      goto LABEL_55;
    }
    if ( CmpFindMatchingDescriptorCell(v8, (unsigned int)v41, v19, &v56, &v50) )
    {
      v20 = v56;
      if ( v56 == v44 )
      {
        v21 = 0;
        if ( a7 )
        {
          ++v17[3];
          *(_DWORD *)(a8 + 48) = v20;
        }
        else
        {
          v22 = v59;
          v23 = v52;
          *(_QWORD *)(v48 + 4) = v59;
          *(_QWORD *)(v23 + 88) = v22;
        }
        goto LABEL_16;
      }
      if ( !HvpMarkCellDirty(v8, v56, 0, 0) )
        goto LABEL_55;
      if ( a7 )
      {
        *(_DWORD *)(a8 + 48) = *v50;
      }
      else if ( v17[3] == 1 && (!HvpMarkCellDirty(v8, v17[1], 0, 0) || !HvpMarkCellDirty(v8, v17[2], 0, 0)) )
      {
        goto LABEL_55;
      }
      v13 = (*(int (__fastcall **)(int, int, int *))(v8 + 4))(v8, v20, &v55);
      if ( !v13 )
      {
        if ( !a7 )
          KeBugCheckEx(81, 4, 5, v8, v20);
        v18 = -1073741670;
        goto LABEL_76;
      }
      if ( !a7 )
      {
        v26 = v17[3];
        if ( v26 == 1 )
        {
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v49);
          v17 = 0;
          CmpRemoveSecurityCellList(v8, v44);
          HvFreeCell(v8, v44);
        }
        else
        {
          v17[3] = v26 - 1;
        }
        *(_DWORD *)(v48 + 44) = v20;
      }
      ++*(_DWORD *)(v13 + 12);
      v27 = v44;
      goto LABEL_40;
    }
    v31 = RtlLengthSecurityDescriptor((int)v41);
    v32 = HvAllocateCell(v8, v31 + 20);
    v27 = v32;
    if ( v32 != -1 )
    {
      v54 = v32;
      if ( a7 )
      {
        v13 = v46;
        *(_DWORD *)(v46 + 4) = v32;
        *(_DWORD *)(v13 + 8) = v32;
      }
      else
      {
        if ( !HvpMarkCellDirty(v8, v17[1], 0, 0) || v17[3] == 1 && !HvpMarkCellDirty(v8, v17[2], 0, 0) )
        {
          v18 = -1073741443;
          goto LABEL_75;
        }
        v33 = (*(int (__fastcall **)(int, int, int *))(v8 + 4))(v8, v17[1], &v58);
        v13 = v46;
        v45 = v33;
        if ( !v33 )
        {
          v18 = -1073741670;
          goto LABEL_42;
        }
        *(_DWORD *)(v46 + 4) = v17[1];
        *(_DWORD *)(v13 + 8) = v44;
        v17[1] = v27;
        *(_DWORD *)(v33 + 8) = v27;
        --v17[3];
      }
      *(_WORD *)v13 = 27507;
      *(_DWORD *)(v13 + 12) = 1;
      v34 = (int)v41;
      v35 = v53;
      *(_DWORD *)(v13 + 16) = v53;
      memmove(v13 + 20, v34, v35);
      if ( CmpAddSecurityCellToCache(v8, v27, 0, v36) < 0 )
      {
        v21 = v45;
        if ( !a7 )
        {
          ++v17[3];
          v17[1] = *(_DWORD *)(v13 + 4);
          *(_DWORD *)(v21 + 8) = *(_DWORD *)(v13 + 8);
        }
        v18 = -1073741670;
        goto LABEL_16;
      }
      v54 = 0;
      if ( !a7 )
      {
        *(_DWORD *)(v48 + 44) = v27;
        if ( !v17[3] )
        {
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v49);
          v37 = v44;
          v17 = 0;
          CmpRemoveSecurityCellList(v8, v44);
          HvFreeCell(v8, v37);
        }
LABEL_41:
        v28 = v59;
        v29 = v48;
        v30 = v52;
        *(_QWORD *)(v48 + 4) = v59;
        *(_QWORD *)(v30 + 88) = v28;
        CmpAssignSecurityToKcb(v30, *(_DWORD *)(v29 + 44), 0, 1);
LABEL_42:
        v21 = v45;
LABEL_16:
        v24 = (unsigned int)v41;
LABEL_17:
        v25 = v42;
LABEL_18:
        if ( v25 )
          ExFreePoolWithTag(v25);
        if ( v24 )
          ExFreePoolWithTag(v24);
        if ( v54 )
          HvFreeCell(v8, v54);
        if ( v21 )
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v58);
        if ( v13 )
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v55);
        if ( v17 )
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v49);
        goto LABEL_30;
      }
      if ( !CmpFindSecurityCellCacheIndex((_DWORD *)v8, v27, (int *)&v53) )
        KeBugCheckEx(81, 4, 3, v52, v27);
      *(_DWORD *)(a8 + 48) = **(_DWORD **)(*(_DWORD *)(v8 + 2004) + 8 * v53 + 4);
LABEL_40:
      if ( a7 )
      {
        v18 = CmAddLogForAction(a8);
        if ( v18 < 0 )
        {
          v40 = *(_DWORD *)(v13 + 12) - 1;
          *(_DWORD *)(v13 + 12) = v40;
          if ( !v40 )
          {
            CmpRemoveSecurityCellList(v8, v27);
            HvFreeCell(v8, v27);
          }
        }
        goto LABEL_42;
      }
      goto LABEL_41;
    }
    v18 = -1073741670;
LABEL_75:
    v13 = v46;
    goto LABEL_76;
  }
  v18 = -1073741670;
LABEL_30:
  (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v57);
  return v18;
}
