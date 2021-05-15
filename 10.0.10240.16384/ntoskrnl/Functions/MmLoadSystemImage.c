// MmLoadSystemImage 
 
int __fastcall MmLoadSystemImage(int a1, int a2, int a3, int a4, int *a5, int *a6)
{
  int v7; // r5
  int v8; // r0
  int v9; // r4
  int v10; // r7
  int v11; // r6
  int v12; // r0
  _DWORD *v13; // r7
  int v14; // r5
  int v15; // r8
  int v16; // r0
  int v17; // r5
  int v18; // r0
  int v19; // r5
  int v20; // r7
  int v21; // r0
  unsigned int v22; // r10
  int v23; // r9
  int *v24; // r5
  int *v25; // r3
  int v26; // r5
  int v27; // r9
  int v28; // r7
  int v29; // r9
  int v30; // r5
  int v32; // r4
  unsigned int v33; // r5
  const char *v34; // r0
  int v35; // r3
  int v36; // r0
  int v37; // r2
  int v38; // r3
  int v39; // r1
  int v40; // t1
  int *i; // r5
  int v42; // r3
  int v43; // r0
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // t1
  int v48; // r4
  int v49; // r1
  int v50; // [sp+10h] [bp-C0h]
  int v51; // [sp+14h] [bp-BCh]
  int v53; // [sp+1Ch] [bp-B4h]
  _DWORD *v54; // [sp+20h] [bp-B0h] BYREF
  int v55; // [sp+24h] [bp-ACh] BYREF
  int v56; // [sp+28h] [bp-A8h]
  int v57; // [sp+2Ch] [bp-A4h]
  int v58; // [sp+30h] [bp-A0h]
  int v59; // [sp+34h] [bp-9Ch]
  int v60[2]; // [sp+38h] [bp-98h] BYREF
  int v61; // [sp+40h] [bp-90h]
  char v62[4]; // [sp+48h] [bp-88h] BYREF
  unsigned int v63; // [sp+4Ch] [bp-84h]
  char v64[8]; // [sp+50h] [bp-80h] BYREF
  int v65; // [sp+58h] [bp-78h] BYREF
  int v66[22]; // [sp+5Ch] [bp-74h] BYREF

  v58 = a4;
  v7 = a1;
  *a6 = 0;
  v61 = a2;
  if ( (a4 & 1) == 0 )
  {
    v8 = MiGenerateSystemImageNames(a1, a2, a3, v60, v64, v62);
    v9 = v8;
    if ( v8 >= 0 )
    {
      v59 = 0;
      v54 = 0;
      v57 = 0;
      v10 = 0;
      v50 = MmAcquireLoadLock(v8);
      v9 = MiObtainSectionForDriver(v62, v7, a4, &v54);
      v11 = (int)v54;
      if ( v9 < 0 )
      {
LABEL_49:
        v30 = v50;
        v29 = a1;
        goto LABEL_50;
      }
      v12 = v54[15];
      v56 = v12;
      if ( v12 )
      {
        v13 = (_DWORD *)MiSectionControlArea(v12);
        v14 = *(_DWORD *)(*v13 + 4);
      }
      else
      {
        v13 = 0;
        v14 = 0;
      }
      v54 = v13;
      if ( v9 )
      {
        v15 = *(_DWORD *)(v11 + 24);
        v53 = 0;
        if ( v9 == 272 )
        {
          *a5 = v11;
          *a6 = v15;
          if ( (*(_DWORD *)(v11 + 52) & 0x4000000) != 0 )
            v9 = -1073741411;
          else
            v9 = -1073741554;
          MmReleaseLoadLock(v50);
          goto LABEL_40;
        }
        ++*(_WORD *)(v11 + 56);
      }
      else
      {
        v53 = 1;
        *(_DWORD *)(v11 + 32) = v14 << 12;
        v15 = MiGetSystemAddressForImage();
        if ( !v15 )
        {
          ObDereferenceObjectDeferDelete(v56);
          ExFreePoolWithTag(v11);
          v9 = -1073741670;
          v30 = v50;
          v29 = a1;
LABEL_52:
          MmReleaseLoadLock(v30);
          if ( v59 == 1 )
            MiLogFailedDriverLoad(v29, 0, 0, v9);
          goto LABEL_40;
        }
        MiCheckPurgeAndUpMapCount(v13);
        *(_DWORD *)(v11 + 24) = v15;
      }
      v9 = MiMapSystemImage(v56, v15, v58);
      if ( v9 < 0 )
      {
        v10 = 0;
        goto LABEL_49;
      }
      v51 = 1;
      if ( v15 == *(_DWORD *)(*v13 + 24) )
      {
        v16 = MiUseLargeDriverPage(v56, v14, v15, v60);
        if ( v16 )
        {
          v32 = -v14;
          do
            v33 = __ldrex((unsigned int *)&algn_632F58[4]);
          while ( __strex(v33 + v32, (unsigned int *)&algn_632F58[4]) );
          v15 = v16;
          *(_DWORD *)(v11 + 24) = v16;
        }
      }
      v17 = v53;
      v59 = 1;
      if ( v53 == 1 )
      {
        v18 = RtlImageNtHeader(*(_DWORD *)(v11 + 24));
        v19 = v18;
        if ( !v18 )
        {
          v9 = -1073741279;
LABEL_68:
          v10 = v51;
          goto LABEL_49;
        }
        if ( *(_WORD *)(v18 + 4) != 452 || *(_WORD *)(v18 + 24) != 267 )
        {
          v9 = -1073741520;
          goto LABEL_68;
        }
        if ( (MiFlags & 0x30000) != 0 )
        {
          v9 = MiValidateStrongCodeDriverImage(v18);
          if ( v9 < 0 && (BYTE2(MiFlags) & 3) == 1 )
          {
            v65 = 0;
            memset(v66, 0, sizeof(v66));
            v66[10] = v60[0];
            v66[11] = v60[1];
            v66[15] = *(_DWORD *)(v19 + 88);
            v66[21] = *(_DWORD *)(v19 + 8);
            MiLogStrongCodeDriverLoadFailure("SectionWXable", &v65);
LABEL_73:
            v30 = v50;
            v29 = a1;
            goto LABEL_39;
          }
        }
        v9 = MiConstructLoaderEntry(v11, v60, v62, v58, 1, &v55);
        if ( v9 < 0 )
          goto LABEL_68;
        ExFreePoolWithTag(v11);
        v11 = v55;
        v17 = v53;
      }
      v51 = 5;
      if ( v17 != 1 )
      {
        v27 = v57;
        if ( v57 != 1 )
          goto LABEL_35;
      }
      v9 = MiProcessLoadConfigForDriver(v11);
      if ( v9 < 0 )
        goto LABEL_68;
      v20 = 0;
      v21 = RtlImageDirectoryEntryToData(*(_DWORD *)(v11 + 24), 1, 12, (int)&v55);
      v22 = v21;
      if ( v21 && (v23 = v55) != 0 )
      {
        if ( MiSetImageProtection(v11, v21, v55) )
        {
          v20 = 1;
          v24 = 0;
LABEL_25:
          *(_DWORD *)(v11 + 52) |= 0x1000u;
          v55 = -2;
          if ( v53 )
            v25 = &v55;
          else
            v25 = 0;
          v9 = MiResolveImageReferences(v15, v60, v64, v61, v25);
          if ( v54[22] )
          {
            if ( v22 )
            {
              MiSetImageProtection(v11, v22, v23);
            }
            else
            {
              for ( i = &v24[-5 * v20]; i; i += 5 )
              {
                v42 = *i;
                if ( !*i )
                  break;
                v43 = *(_DWORD *)(v11 + 24);
                v44 = v43 + v42;
                v45 = *(_DWORD *)(v43 + v42);
                v46 = 0;
                while ( v45 )
                {
                  v47 = *(_DWORD *)(v44 + 4);
                  v44 += 4;
                  v45 = v47;
                  ++v46;
                }
                MiSetImageProtection(v11, i[4] + v43, 4 * v46);
              }
            }
          }
          *(_DWORD *)(v11 + 52) &= 0xFFFFEFFF;
          if ( v9 < 0 )
          {
            v59 = 0;
            goto LABEL_73;
          }
          if ( v53 == 1 )
            *(_DWORD *)(v11 + 76) = v55;
LABEL_33:
          v26 = (int)v54;
          v10 = 21;
          v51 = 21;
          if ( (*(_WORD *)(*(_DWORD *)(*v54 + 36) + 30) & 0x40) == 0 )
          {
            v48 = *(_DWORD *)(*(_DWORD *)v54[14] + 28);
            MiSetImageProtection(v11, v48 + v15, 4);
            *(_DWORD *)(v48 + v15) = v15 - MiRelocateAmount(v26, v49);
            if ( *(_DWORD *)(v26 + 88) )
              MiSetImageProtection(v11, v48 + v15, 4);
          }
          v27 = v57;
          v17 = v53;
          if ( v57 == 1 )
          {
            v9 = MiCompactServiceTable(v11, v53);
            if ( v9 < 0 )
              goto LABEL_49;
          }
LABEL_35:
          v28 = v58;
          v9 = MiHandleDriverNonPagedSections(v11, v58, 1);
          if ( v9 < 0 )
          {
            v30 = v50;
            v29 = a1;
LABEL_58:
            v10 = v51;
LABEL_50:
            if ( v11 )
              MiUnloadSystemImage(v11, v10);
            goto LABEL_52;
          }
          v51 |= 8u;
          if ( v27 == 1 )
            *((_BYTE *)MiSessionLookupImage(v15) + 36) = 1;
          v29 = a1;
          MiDriverLoadSucceeded(v11, v56, a1, v62, v60, v17, v28);
          KeSweepIcache();
          v30 = v50;
          MmReleaseLoadLock(v50);
          v9 = 0;
          *a5 = v11;
          *a6 = v15;
LABEL_39:
          if ( v9 >= 0 )
          {
LABEL_40:
            if ( v61 )
              ExFreePoolWithTag(v63);
            return v9;
          }
          goto LABEL_58;
        }
        if ( (BYTE2(MiFlags) & 3) != 1 )
          goto LABEL_67;
        v34 = "UnwritableIAT";
      }
      else
      {
        v22 = 0;
        v23 = 0;
        v24 = (int *)RtlImageDirectoryEntryToData(*(_DWORD *)(v11 + 24), 1, 1, (int)&v55);
        if ( !v24 )
          goto LABEL_33;
        while ( 1 )
        {
          v35 = *v24;
          if ( !*v24 )
          {
LABEL_86:
            if ( !v20 )
              goto LABEL_33;
            goto LABEL_25;
          }
          v36 = *(_DWORD *)(v11 + 24);
          v37 = v36 + v35;
          v38 = *(_DWORD *)(v36 + v35);
          v39 = 0;
          while ( v38 )
          {
            v40 = *(_DWORD *)(v37 + 4);
            v37 += 4;
            v38 = v40;
            ++v39;
          }
          v23 = 4 * v39;
          if ( !MiSetImageProtection(v11, v24[4] + v36, 4 * v39) )
            break;
          ++v20;
          v24 += 5;
          if ( !v24 )
            goto LABEL_86;
        }
        if ( (BYTE2(MiFlags) & 3) != 1 )
          goto LABEL_67;
        v34 = "UnwritableImportDirectory";
      }
      MiLogStrongCodeDriverLoadFailure(v34, v11);
LABEL_67:
      v9 = -1073741701;
      dword_632EE4 = 192;
      goto LABEL_68;
    }
    return v9;
  }
  if ( (a4 & 2) != 0 )
    return -1073741582;
  return sub_7CD760();
}
