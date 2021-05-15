// MiCreateNewSection 
 
int __fastcall MiCreateNewSection(int a1, int a2, int a3, int a4, int a5, unsigned __int8 *a6, int a7, int *a8, _DWORD *a9)
{
  int v10; // r10
  int v11; // r9
  _DWORD *v12; // r5
  int v13; // r0
  __int16 v14; // r2
  int v15; // r4
  int *v17; // r8
  int v18; // r1
  _DWORD *v19; // r7
  int v20; // r9
  int v21; // r7
  int v22; // r3
  int v23; // r5
  int v24; // r5
  int v25; // r3
  int v26; // r7
  int v27; // r5
  char v28[4]; // [sp+10h] [bp-A0h] BYREF
  _DWORD *v29; // [sp+14h] [bp-9Ch] BYREF
  int v30; // [sp+18h] [bp-98h]
  char v31[4]; // [sp+1Ch] [bp-94h] BYREF
  int v32; // [sp+20h] [bp-90h] BYREF
  _DWORD *v33; // [sp+24h] [bp-8Ch]
  _DWORD *v34; // [sp+28h] [bp-88h] BYREF
  int v35; // [sp+30h] [bp-80h] BYREF
  int v36; // [sp+34h] [bp-7Ch]
  int v37; // [sp+7Ch] [bp-34h]
  int v38; // [sp+80h] [bp-30h]

  v28[0] = 0;
  v10 = *a6;
  v29 = 0;
  v30 = a1;
  v33 = 0;
  v11 = a2 & 0x1000000;
  if ( (a2 & 0x1000000) != 0 )
  {
    v13 = MiCreateImageFileMap(a1, a4, *a8, &v32, (int *)&v34, &v35, &v29);
    v12 = v34;
    v14 = v36;
    v33 = v29;
    v29 = v34;
  }
  else
  {
    v12 = 0;
    v29 = 0;
    v13 = MiCreateDataFileMap(a1, &v32, a7);
    v14 = 0;
    v36 = 0;
  }
  v15 = v13;
  if ( v13 < 0 )
    return sub_7D4CE0();
  v17 = *(int **)v32;
  *a9 = v32;
  v18 = *a8;
  if ( (*a8 & 0x2000) != 0 && (*(_DWORD *)(*(_DWORD *)(a1 + 4) + 32) & 0x10) == 0 && (!v11 || (v14 & 0xFFF) == 0) )
    v17[7] |= 0x20000000u;
  if ( (v18 & 0x4000) != 0 )
    v17[7] |= 0x20000u;
  if ( !v11 && (v18 & 0x10000) != 0 )
    v17[7] |= 0x40000000u;
  v19 = (_DWORD *)MiSectionCreated(a1, v17, v12);
  if ( (*a8 & 2) != 0 )
  {
    IoSetTopLevelIrp(0);
    FsRtlReleaseFile(v30);
    *a8 &= 0xFFFFFFFD;
  }
  if ( !v11 )
    goto LABEL_14;
  v20 = v32;
  v21 = *(_DWORD *)(v32 + 36);
  v15 = MiParseComImage(v17, &v35, v28);
  if ( v15 < 0 )
    goto LABEL_58;
  if ( !v37 && !v38 && !*(_BYTE *)(v21 + 34) )
    *(_BYTE *)(v20 + 11) |= 1u;
  if ( (*(_BYTE *)(v20 + 10) & 1) != 0 )
  {
    if ( (*a8 & 0x20000) != 0 )
    {
      v15 = -1073740749;
      dword_632EE4 = 80;
      goto LABEL_58;
    }
    v15 = MiSetPagesModified(v17, a5);
    if ( v15 < 0 )
      goto LABEL_58;
  }
  if ( (*(_WORD *)(v21 + 30) & 0x80) != 0 && *(_DWORD *)(v21 + 16) == 17 )
    *a8 |= 0x8000u;
  v22 = *a8;
  if ( (*a8 & 0x100) != 0 )
  {
    v23 = 4;
  }
  else if ( (v22 & 0x20) != 0 )
  {
    v23 = 1;
  }
  else if ( (v22 & 0x10) != 0 )
  {
    if ( (v22 & 0x1000) != 0 )
      v23 = 8;
    else
      v23 = 2;
  }
  else
  {
    v23 = 0;
  }
  if ( (v22 & 0x800) != 0 )
    v23 |= 0x10u;
  if ( (v22 & 0x8400) == 0 || (v22 & 0x810) != 0 || !v10 )
    goto LABEL_28;
  v15 = SeGetImageRequiredSigningLevel(v30, v23, v10, 0, v31);
  if ( v15 < 0 )
  {
LABEL_58:
    MiReturnPfnReferenceCount((int)v29);
    return v15;
  }
  v10 = (unsigned __int8)v31[0];
  *a6 = v31[0];
LABEL_28:
  if ( (*a8 & 0x20000) != 0 )
  {
    v23 |= 0x40000000u;
    if ( !v10 )
      v10 = 4;
  }
  if ( (*a8 & 0x8400) == 0 || !v10 && (*(_WORD *)(v21 + 30) & 0x80) == 0 )
    goto LABEL_30;
  v25 = v23;
  v24 = v30;
  v15 = MiValidateSectionCreate(v30, v17, a5, v25, v10);
  if ( v15 < 0 )
    goto LABEL_34;
  v26 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v27 = ((unsigned int)*a8 >> 11) & 1;
  if ( !SeCompareSigningLevels(*(unsigned __int8 *)(v20 + 11) >> 4, v10) && (v27 || (*(_BYTE *)(v26 + 734) & 8) == 0) )
    v15 = -1073740760;
  if ( v15 >= 0 )
  {
LABEL_30:
    v15 = MiRelocateImage(v20, &v35, v33);
    if ( v15 >= 0 && v28[0] == 1 )
      MiMakeImageReadOnly((int)v17);
  }
  v24 = v30;
LABEL_34:
  MiReturnPfnReferenceCount((int)v29);
  if ( v15 < 0 )
    return v15;
  v19 = (_DWORD *)MiReleaseImageSection(v24, v17);
LABEL_14:
  MiReleaseControlAreaWaiters(v19);
  return v15;
}
