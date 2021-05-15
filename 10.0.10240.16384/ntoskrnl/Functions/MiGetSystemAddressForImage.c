// MiGetSystemAddressForImage 
 
unsigned int __fastcall MiGetSystemAddressForImage(int a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  int *v5; // r8
  int v6; // r6
  int *i; // r2
  unsigned int v8; // r4
  int *v9; // r1
  int v10; // r0
  unsigned int v11; // r10
  int v12; // r0
  int v13; // r1
  int v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r0
  int v19; // r1
  int v20; // r6
  unsigned int v21; // r4
  int v22; // r0
  unsigned int v23; // r4
  int v24; // lr
  unsigned int v25; // r2
  int v26; // r1
  int v27; // r5
  unsigned int v28; // r0
  int v29; // r6
  int v31; // [sp+8h] [bp-C8h]
  char v32; // [sp+Ch] [bp-C4h]
  _DWORD v33[5]; // [sp+14h] [bp-BCh] BYREF
  _DWORD v34[4]; // [sp+28h] [bp-A8h] BYREF
  int v35; // [sp+38h] [bp-98h]
  int v36; // [sp+3Ch] [bp-94h]
  int v37; // [sp+40h] [bp-90h]
  int v38; // [sp+44h] [bp-8Ch]
  int v39; // [sp+48h] [bp-88h]
  __int16 v40; // [sp+4Ch] [bp-84h]
  __int16 v41; // [sp+4Eh] [bp-82h]
  __int16 v42; // [sp+50h] [bp-80h]
  __int16 v43; // [sp+52h] [bp-7Eh]
  __int16 v44; // [sp+54h] [bp-7Ch]
  __int16 v45; // [sp+56h] [bp-7Ah]
  __int16 v46; // [sp+58h] [bp-78h]
  int v47; // [sp+5Ch] [bp-74h]
  int v48; // [sp+60h] [bp-70h]
  int v49; // [sp+64h] [bp-6Ch]
  int v50; // [sp+68h] [bp-68h]
  int v51; // [sp+6Ch] [bp-64h]
  int v52; // [sp+70h] [bp-60h]
  int v53; // [sp+74h] [bp-5Ch]
  int v54; // [sp+78h] [bp-58h]
  int v55; // [sp+7Ch] [bp-54h]
  int v56; // [sp+80h] [bp-50h]
  char v57; // [sp+84h] [bp-4Ch]
  unsigned int _88[24]; // [sp+88h] [bp-48h] BYREF

  _88[20] = a1;
  _88[22] = (unsigned int)a3;
  _88[23] = a4;
  v32 = a2;
  _88[21] = a2;
  *a3 = 1;
  v5 = (int *)MiSectionControlArea(a1);
  v33[2] = v5;
  v31 = *(_DWORD *)(*v5 + 4);
  v33[3] = v31;
  v6 = 0;
  v8 = ((int (*)(void))MiImageSuitableForSystem)();
  if ( v8 )
  {
    v9 = &PsLoadedModuleList;
    for ( i = (int *)PsLoadedModuleList; i != v9; i = (int *)*i )
    {
      v10 = i[15];
      if ( v10 && v5 == (int *)MiSectionControlArea(v10) )
      {
        *a3 = 0;
        v6 = 1;
        break;
      }
    }
  }
  if ( !v8
    || v6 == 1
    || (v32 & 2) != 0
    || (v11 = dword_63389C, (v32 & 1) != 0)
    && (v8 < dword_63389C
     || (v12 = MiGetSystemRegionIndex(v8), *(_BYTE *)(v12 + v13 + 9692) != 1)
     && (v14 = MiGetSystemRegionIndex(v8), *(_BYTE *)(v14 + v15 + 9692) != 11))
    || (v32 & 1) == 0
    && v8 >= v11
    && ((v16 = MiGetSystemRegionIndex(v8), *(_BYTE *)(v16 + v17 + 9692) == 1)
     || (v18 = MiGetSystemRegionIndex(v8), *(_BYTE *)(v18 + v19 + 9692) == 11)) )
  {
    if ( (v32 & 1) != 0 )
      v20 = 2;
    else
      v20 = 1;
    if ( v33[0] )
    {
      v27 = v31;
    }
    else
    {
      if ( MiMapImageInSystemSpace((int)v5, 3, _88) < 0 )
        return 0;
      v21 = _88[0];
      v22 = RtlImageNtHeader(_88[0]);
      v23 = *(_DWORD *)(v21 + 60) + 52;
      v33[1] = v23;
      v40 = *(_WORD *)(v22 + 24);
      v34[1] = *(_DWORD *)(v22 + 60);
      v34[2] = *(_DWORD *)(v22 + 56);
      v34[3] = *(_DWORD *)(v22 + 80);
      v24 = *(_DWORD *)(v22 + 112);
      v35 = v24;
      v34[0] = *(_DWORD *)(v22 + 52);
      v36 = *(_DWORD *)(v22 + 84);
      v37 = *(_DWORD *)(v22 + 40);
      v38 = *(_DWORD *)(v22 + 96);
      v39 = *(_DWORD *)(v22 + 100);
      v41 = *(_WORD *)(v22 + 92);
      v42 = *(_WORD *)(v22 + 72);
      v43 = *(_WORD *)(v22 + 74);
      v44 = *(_WORD *)(v22 + 64);
      v45 = *(_WORD *)(v22 + 66);
      v46 = *(_WORD *)(v22 + 94);
      v47 = *(_DWORD *)(v22 + 88);
      v48 = *(_DWORD *)(v22 + 28);
      v57 = 0;
      v25 = *(_DWORD *)(v22 + 116);
      if ( v25 > 6 && *(_DWORD *)(v22 + 168) )
        v57 = 1;
      if ( v25 > 0xC )
      {
        v49 = *(_DWORD *)(v22 + 216);
        v50 = *(_DWORD *)(v22 + 220);
      }
      if ( v25 <= 0xE )
      {
        v51 = 0;
        v52 = 0;
      }
      else
      {
        v51 = *(_DWORD *)(v22 + 232);
        v26 = *(_DWORD *)(v22 + 236);
        v52 = v26;
        if ( v51 && v26 )
          v35 = v24 | 1;
      }
      if ( v25 <= 5 )
      {
        v53 = 0;
        v54 = 0;
      }
      else
      {
        v53 = *(_DWORD *)(v22 + 160);
        v54 = *(_DWORD *)(v22 + 164);
      }
      if ( v25 <= 0xA )
      {
        v55 = 0;
        v56 = 0;
      }
      else
      {
        v55 = *(_DWORD *)(v22 + 200);
        v56 = *(_DWORD *)(v22 + 204);
      }
      v27 = v31;
      MiUnmapImageInSystemSpace(_88);
      if ( MiRelocateImage(*v5, (int)v34, v23, v20, 1) < 0 )
        return 0;
      MiImageSuitableForSystem(v5, v33);
      if ( !v33[0] )
        return 0;
    }
    v28 = MiSelectSystemImageAddress(v20, v27, i);
    v8 = v28;
    if ( !v28 )
      return 0;
    v29 = 1;
    if ( !MiAddPrivateFixupEntryForSystemImage((int)v5, v28) )
    {
LABEL_53:
      MiReturnSystemImageAddress(v8, v27 << 12);
      return 0;
    }
  }
  else
  {
    v27 = v31;
    v29 = 0;
  }
  if ( (v32 & 1) != 0 && MiSessionInsertImage(v8, (int)v5) < 0 )
  {
    if ( v29 == 1 )
      MiFreePrivateFixupEntryForSystemImage(v8, 1);
    goto LABEL_53;
  }
  return v8;
}
