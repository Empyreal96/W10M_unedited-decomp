// MiResolveImageReferences 
 
int __fastcall MiResolveImageReferences(unsigned int a1, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // r8
  int v7; // r0
  int *v8; // r9
  unsigned int v9; // r7
  int v10; // r5
  int v11; // r4
  __int16 *v12; // r6
  int v13; // r5
  int v14; // r3
  int v15; // r5
  unsigned int i; // r7
  int j; // r4
  unsigned int v18; // r7
  int v19; // r2
  int v20; // r3
  int v21; // r5
  unsigned int v22; // r8
  int v23; // r3
  int v24; // t1
  int v26; // r0
  int v27; // r1
  int v28; // r0
  int v29; // r1
  int v30; // [sp+8h] [bp-88h]
  unsigned int v31; // [sp+Ch] [bp-84h]
  __int64 v32; // [sp+10h] [bp-80h] BYREF
  char v33[4]; // [sp+18h] [bp-78h] BYREF
  __int16 *v34; // [sp+1Ch] [bp-74h] BYREF
  __int64 v35; // [sp+20h] [bp-70h] BYREF
  int v36; // [sp+28h] [bp-68h]
  __int16 v37; // [sp+30h] [bp-60h] BYREF
  unsigned int v38; // [sp+34h] [bp-5Ch]
  int v39; // [sp+38h] [bp-58h] BYREF
  __int64 *v40; // [sp+3Ch] [bp-54h]
  __int16 *v41; // [sp+40h] [bp-50h]
  char v42[4]; // [sp+44h] [bp-4Ch] BYREF
  int v43; // [sp+48h] [bp-48h]
  int v44; // [sp+4Ch] [bp-44h]
  int v45; // [sp+50h] [bp-40h]
  char v46[4]; // [sp+54h] [bp-3Ch] BYREF
  __int16 v47[2]; // [sp+58h] [bp-38h] BYREF
  const __int16 *v48; // [sp+5Ch] [bp-34h]
  __int16 *v49; // [sp+60h] [bp-30h]
  unsigned __int16 v50[20]; // [sp+68h] [bp-28h] BYREF

  v36 = a4;
  v32 = 0i64;
  v5 = a5;
  v47[0] = 58;
  v47[1] = 60;
  v48 = L"\\SystemRoot\\System32\\drivers\\";
  v49 = (__int16 *)a3;
  v44 = a2;
  if ( a5 )
    *a5 = -2;
  v7 = RtlImageDirectoryEntryToData(a1, 1, 1, (int)&v39);
  v8 = (int *)v7;
  if ( !v7 )
    return 0;
  v9 = 0;
  v10 = 0;
  v30 = 0;
  LOBYTE(v31) = 0;
  v34 = 0;
  v39 = 0;
  v40 = 0;
  HIDWORD(v35) = 0;
  v11 = MiAllocateImportList(v7, &v34);
  v12 = v34;
  if ( v11 < 0 )
    goto LABEL_61;
  v13 = v8[3];
  if ( !v13 )
  {
LABEL_37:
    if ( v5 )
      *v5 = MiCompressImportList(v12);
    else
      ExFreePoolWithTag((unsigned int)v12);
    return 0;
  }
  v41 = v34;
  while ( 1 )
  {
    if ( !*v8 )
      goto LABEL_37;
    v40 = 0;
    RtlInitAnsiString((unsigned int)v50, v13 + a1);
    v11 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&v32, v50, 1, v14);
    if ( v11 < 0 )
      goto LABEL_48;
    if ( !HIDWORD(v32) )
LABEL_67:
      JUMPOUT(0x7CDBB4);
    v11 = ApiSetResolveToHost(dword_632ED4, (unsigned __int16 *)&v32, v44, v33, (int)&v37);
    if ( v11 < 0 )
      goto LABEL_48;
    if ( !v33[0] )
    {
      v34 = v49;
      v43 = 0;
      goto LABEL_13;
    }
    RtlFreeAnsiString(&v32);
    if ( v37 )
      break;
LABEL_36:
    v8 += 5;
    v13 = v8[3];
    if ( !v13 )
      goto LABEL_37;
  }
  v34 = v47;
  v43 = 0x80000000;
  v11 = RtlDuplicateUnicodeString(0, &v37, &v32);
  if ( v11 < 0 )
    goto LABEL_48;
LABEL_13:
  if ( v36
    && strnicmp((unsigned __int8 *)(v13 + a1), "ntoskrnl", 8)
    && strnicmp((unsigned __int8 *)(v13 + a1), "hal", 3) )
  {
    return sub_7CDAF8();
  }
  v35 = v32;
  v45 = HIDWORD(v32);
  v15 = v43;
  v40 = &v35;
  for ( i = v9 & 0xFFFFFFFE; ; i |= 1u )
  {
    v31 = i;
    for ( j = PsLoadedModuleList; ; j = *(_DWORD *)j )
    {
      if ( (int *)j == &PsLoadedModuleList )
        goto LABEL_41;
      if ( RtlEqualUnicodeString((unsigned __int16 *)&v35, (unsigned __int16 *)(j + 44), 1) )
        break;
    }
    v18 = *(_DWORD *)(j + 24);
    if ( (v31 & 1) == 0 && (*(_DWORD *)(j + 52) & 0x1000) == 0 )
    {
      if ( v18 >= dword_63389C
        && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(*(_DWORD *)(j + 24))) == 1
         || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v18)) == 11) )
      {
        if ( !MiSessionReferenceImage(v18) )
          v18 = 0;
      }
      else
      {
        if ( !v5 )
          JUMPOUT(0x7CDB34);
        ++*(_WORD *)(j + 56);
      }
    }
    if ( v18 )
      break;
    i = v31;
LABEL_41:
    if ( !MiFormFullImageName(v34, &v32, &v37) )
      goto LABEL_67;
    v11 = MiLoadImportDll(&v37, v36, v15, v42, v46);
    if ( v11 == -1073741800 )
    {
      if ( a1 < dword_63389C )
        goto LABEL_44;
      v26 = MiGetSystemRegionIndex(a1);
      if ( *(_BYTE *)(v26 + v27 + 9692) != 1 )
      {
        v28 = MiGetSystemRegionIndex(a1);
        if ( *(_BYTE *)(v28 + v29 + 9692) != 11 )
          goto LABEL_44;
      }
      v11 = MiLoadImportDll(&v37, v36, v15 | 1, v42, v46);
    }
    if ( v11 == -1073741772 )
      JUMPOUT(0x7CDB68);
LABEL_44:
    ExFreePoolWithTag(v38);
    if ( v11 < 0 )
      goto LABEL_48;
  }
  if ( (*(_DWORD *)(j + 52) & 0x1000) == 0 )
  {
    v19 = (int)v41;
    *((_DWORD *)v41 + 1) = j;
    v41 = (__int16 *)(v19 + 4);
    ++v30;
  }
  v20 = *v8;
  if ( !*v8 )
  {
LABEL_35:
    RtlFreeAnsiString(&v32);
    v9 = v31;
    if ( (v31 & 2) != 0 )
      JUMPOUT(0x7CDBA4);
    goto LABEL_36;
  }
  v21 = v20 + a1;
  v22 = v8[4] + a1;
  v23 = *(_DWORD *)(v20 + a1);
  while ( 1 )
  {
    if ( !v23 )
    {
      v5 = a5;
      goto LABEL_35;
    }
    v11 = MiSnapThunk(v18, a1, v21, v22, 0);
    if ( v11 < 0 )
      break;
    v24 = *(_DWORD *)(v21 + 4);
    v21 += 4;
    v23 = v24;
    v22 += 4;
  }
  v39 = MiSnapUnresolvedImport(a1, v21, v18);
LABEL_48:
  v10 = v30;
LABEL_61:
  MiLogFailedDriverLoad(v44, v40, v39, v11);
  if ( (v31 & 2) != 0 )
    ExFreePoolWithTag(HIDWORD(v35));
  RtlFreeAnsiString(&v32);
  if ( v12 )
  {
    if ( v10 != *(_DWORD *)v12 )
      *(_DWORD *)v12 = v10;
    MiDereferenceImports(v12);
    ExFreePoolWithTag((unsigned int)v12);
  }
  return v11;
}
