// SepDuplicateToken 
 
int __fastcall SepDuplicateToken(int a1, int a2, int a3, int a4, int a5, char a6, unsigned __int8 a7, int *a8)
{
  _DWORD *v11; // r0
  unsigned int v12; // r8
  int v13; // r7
  int v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r1
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r5
  int v25; // r3
  int v26; // r5
  int v27; // r3
  int v28; // r0
  int v29; // r8
  int v30; // r2
  int v31; // r3
  unsigned int v32; // r3
  int v33; // r1
  int v34; // r3
  int v35; // r3
  int v36; // r0
  int v37; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  int *v40; // r0
  int *v42; // r2
  int j; // r1
  int v44; // t1
  int v45; // r3
  unsigned int *v46; // r2
  unsigned int v47; // r1
  signed int v48; // r1
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r0
  unsigned int v53; // r1
  __int16 v54; // r3
  int v55; // r0
  unsigned int v56; // r1
  __int16 v57; // r3
  int v58; // r0
  unsigned int v59; // r1
  __int16 v60; // r3
  int *v61; // r2
  int i; // r1
  int v63; // t1
  int v64; // r0
  unsigned int v65; // r1
  __int16 v66; // r3
  int v67; // r0
  unsigned int v68; // r1
  __int16 v69; // r3
  int v70; // r0
  unsigned int v71; // r1
  __int16 v72; // r3
  unsigned int *v73; // r2
  unsigned int v74; // r1
  signed int v75; // r1
  unsigned int *v76; // r2
  unsigned int v77; // r1
  signed int v78; // r1
  int v79; // r0
  int v80; // r0
  unsigned int v81; // r1
  __int16 v82; // r3
  int v83; // r0
  unsigned int v84; // r1
  __int16 v85; // r3
  int v86; // [sp+18h] [bp-28h]

  if ( a4 != 2 || a5 <= 3 && a5 >= 0 )
  {
    v11 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1950442835);
    v12 = (unsigned int)v11;
    if ( v11 )
    {
      *v11 = 0;
      v11[1] = v11 + 1;
      v11[2] = v11 + 1;
      v11[3] = 0;
      v11[4] = v11 + 4;
      v11[5] = v11 + 4;
      v13 = ExAllocatePoolWithTag(512, 56, 1817470291);
      if ( v13 )
      {
        v14 = ObCreateObjectEx(a6, SeTokenObjectType, a2, a6);
        if ( v14 >= 0 )
        {
          ExAllocateLocallyUniqueId((int *)(v86 + 16));
          *(_BYTE *)(v86 + 180) = 0;
          *(_DWORD *)(v86 + 168) = a4;
          *(_DWORD *)(v86 + 172) = a5;
          *(_DWORD *)(v86 + 48) = v13;
          ExInitializeResourceLite(v13);
          *(_DWORD *)(v86 + 24) = *(_DWORD *)(a1 + 24);
          *(_DWORD *)(v86 + 28) = *(_DWORD *)(a1 + 28);
          v15 = *(_DWORD *)(a1 + 4);
          v16 = *(_DWORD *)(a1 + 8);
          v17 = *(_DWORD *)(a1 + 12);
          *(_DWORD *)v86 = *(_DWORD *)a1;
          *(_DWORD *)(v86 + 4) = v15;
          *(_DWORD *)(v86 + 8) = v16;
          *(_DWORD *)(v86 + 12) = v17;
          *(_DWORD *)(v86 + 140) = 0;
          *(_DWORD *)(v86 + 32) = *(_DWORD *)(a1 + 32);
          *(_DWORD *)(v86 + 36) = *(_DWORD *)(a1 + 36);
          *(_DWORD *)(v86 + 40) = *(_DWORD *)(a1 + 40);
          *(_DWORD *)(v86 + 44) = *(_DWORD *)(a1 + 44);
          *(_DWORD *)(v86 + 196) = *(_DWORD *)(a1 + 196);
          *(_DWORD *)(v86 + 200) = *(_DWORD *)(a1 + 200);
          *(_DWORD *)(v86 + 648) = 0;
          *(_DWORD *)(v86 + 652) = 0;
          *(_DWORD *)(v86 + 636) = 0;
          v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v18 + 308);
          ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
          *(_DWORD *)(v86 + 52) = *(_DWORD *)(a1 + 52);
          *(_DWORD *)(v86 + 56) = *(_DWORD *)(a1 + 56);
          *(_DWORD *)(v86 + 136) = *(_DWORD *)(a1 + 136);
          *(_DWORD *)(v86 + 144) = *(_DWORD *)(a1 + 144);
          *(_DWORD *)(v86 + 128) = *(_DWORD *)(a1 + 128);
          *(_DWORD *)(v86 + 132) = *(_DWORD *)(a1 + 132);
          *(_DWORD *)(v86 + 176) = *(_DWORD *)(a1 + 176) & 0xFFFFFBDF;
          *(_DWORD *)(v86 + 120) = *(_DWORD *)(a1 + 120);
          *(_DWORD *)(v86 + 88) = *(_DWORD *)(a1 + 88);
          *(_DWORD *)(v86 + 92) = *(_DWORD *)(a1 + 92);
          *(_DWORD *)(v86 + 96) = *(_DWORD *)(a1 + 96);
          *(_DWORD *)(v86 + 100) = *(_DWORD *)(a1 + 100);
          *(_DWORD *)(v86 + 104) = *(_DWORD *)(a1 + 104);
          *(_DWORD *)(v86 + 108) = *(_DWORD *)(a1 + 108);
          *(_DWORD *)(v86 + 112) = *(_DWORD *)(a1 + 112);
          *(_WORD *)(v86 + 116) = *(_WORD *)(a1 + 116);
          *(_BYTE *)(v86 + 118) = *(_BYTE *)(a1 + 118);
          *(_DWORD *)(v86 + 184) = *(_DWORD *)(a1 + 184);
          *(_DWORD *)(v86 + 188) = *(_DWORD *)(a1 + 188);
          v19 = *(_DWORD *)(a1 + 68);
          v20 = *(_DWORD *)(a1 + 72);
          v21 = *(_DWORD *)(a1 + 76);
          *(_DWORD *)(v86 + 64) = *(_DWORD *)(a1 + 64);
          *(_DWORD *)(v86 + 68) = v19;
          *(_DWORD *)(v86 + 72) = v20;
          *(_DWORD *)(v86 + 76) = v21;
          v22 = *(_DWORD *)(a1 + 84);
          *(_DWORD *)(v86 + 80) = *(_DWORD *)(a1 + 80);
          *(_DWORD *)(v86 + 84) = v22;
          *(_DWORD *)(v86 + 476) = v12;
          *(_DWORD *)(v86 + 628) = 0;
          *(_DWORD *)(v86 + 632) = 0;
          *(_DWORD *)(v86 + 480) = 0;
          *(_DWORD *)(v86 + 484) = 0;
          *(_DWORD *)(v86 + 488) = 0;
          memset((_BYTE *)(v86 + 492), 0, 136);
          *(_DWORD *)(v86 + 160) = 0;
          *(_DWORD *)(v86 + 640) = 0;
          *(_DWORD *)(v86 + 644) = 0;
          if ( *(_BYTE *)(v86 + 118) == 2 )
            SepModifyTokenPolicyCounter(v86 + 88, 1);
          if ( (*(_DWORD *)(a1 + 176) & 0x20) != 0 )
          {
            v14 = SepReferenceLogonSession(a1 + 24, v86 + 192);
            if ( v14 < 0 )
            {
              v23 = *(_DWORD *)(v86 + 176);
              *(_DWORD *)(v86 + 192) = 0;
              *(_DWORD *)(v86 + 176) = v23 | 0x20;
              v49 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
              v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v51 = *(_WORD *)(v50 + 0x134) + 1;
              *(_WORD *)(v50 + 308) = v51;
              if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
                KiCheckForKernelApcDelivery(v49);
              goto LABEL_123;
            }
          }
          else
          {
            v45 = *(_DWORD *)(a1 + 192);
            *(_DWORD *)(v86 + 192) = v45;
            v46 = (unsigned int *)(v45 + 20);
            do
            {
              v47 = __ldrex(v46);
              v48 = v47 + 1;
            }
            while ( __strex(v48, v46) );
            if ( v48 <= 1 )
              __fastfail(0xEu);
            v14 = 0;
          }
          if ( !**(_DWORD **)(a1 + 476) )
            goto LABEL_12;
          v14 = SepRefDerefLuidToIndexEntryIfNecessary(a1, 0);
          if ( v14 < 0 )
          {
            v52 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
            v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v54 = *(_WORD *)(v53 + 0x134) + 1;
            *(_WORD *)(v53 + 308) = v54;
            if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
              KiCheckForKernelApcDelivery(v52);
            goto LABEL_123;
          }
          v14 = AuthzBasepDuplicateSecurityAttributes(*(_DWORD *)(a1 + 476), *(_DWORD *)(v86 + 476), a7);
          if ( v14 < 0 )
          {
            SepRefDerefLuidToIndexEntryIfNecessary(a1, 1);
            v55 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
            v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v57 = *(_WORD *)(v56 + 0x134) + 1;
            *(_WORD *)(v56 + 308) = v57;
            if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
              KiCheckForKernelApcDelivery(v55);
          }
          else
          {
LABEL_12:
            memmove(v86 + 656, a1 + 656, *(_DWORD *)(a1 + 132));
            if ( !SepTokenSidSharingEnabled )
            {
              v24 = v86 - a1;
              *(_DWORD *)(v86 + 124) = *(_DWORD *)(a1 + 124);
              v61 = (int *)(v86 - a1 + *(_DWORD *)(a1 + 148));
              *(_DWORD *)(v86 + 148) = v61;
              for ( i = *(_DWORD *)(v86 + 124); i; --i )
              {
                v63 = *v61;
                v61 += 2;
                *(v61 - 2) = v63 + v24;
              }
LABEL_14:
              v25 = *(_DWORD *)(a1 + 152);
              *(_DWORD *)(v86 + 152) = v25;
              if ( v25 )
              {
                v42 = (int *)(v25 + v24);
                *(_DWORD *)(v86 + 152) = v25 + v24;
                for ( j = *(_DWORD *)(v86 + 128); j; --j )
                {
                  v44 = *v42;
                  v42 += 2;
                  *(v42 - 2) = v44 + v24;
                }
              }
              v26 = 4 * (*(unsigned __int8 *)(*(_DWORD *)(a1 + 156) + 1) + 2);
              v27 = *(_DWORD *)(a1 + 164);
              if ( v27 )
                v26 += *(unsigned __int16 *)(v27 + 2);
              v28 = ExAllocatePoolWithTag(1, v26, 1683252563);
              v29 = v28;
              *(_DWORD *)(v86 + 160) = v28;
              if ( !v28 )
              {
                v64 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
                v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v66 = *(_WORD *)(v65 + 0x134) + 1;
                *(_WORD *)(v65 + 308) = v66;
                if ( !v66 && *(_DWORD *)(v65 + 100) != v65 + 100 && !*(_WORD *)(v65 + 310) )
                  KiCheckForKernelApcDelivery(v64);
                ObfDereferenceObject(v86);
                return -1073741670;
              }
              memmove(v28, *(_DWORD *)(a1 + 160), v26);
              v30 = v29 - *(_DWORD *)(a1 + 160);
              v31 = *(_DWORD *)(a1 + 164);
              *(_DWORD *)(v86 + 164) = v31;
              if ( v31 )
                *(_DWORD *)(v86 + 164) = v31 + v30;
              *(_DWORD *)(v86 + 156) = *(_DWORD *)(a1 + 156) + v30;
              v32 = *(_DWORD *)(a1 + 488);
              if ( v32 )
                v14 = SepSetTokenCapabilities(v86, *(_DWORD *)(a1 + 480), *(_DWORD *)(a1 + 484), v32);
              if ( v14 < 0 )
              {
                v67 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
                v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v69 = *(_WORD *)(v68 + 0x134) + 1;
                *(_WORD *)(v68 + 308) = v69;
                if ( !v69 && *(_DWORD *)(v68 + 100) != v68 + 100 && !*(_WORD *)(v68 + 310) )
                  KiCheckForKernelApcDelivery(v67);
              }
              else
              {
                v33 = *(_DWORD *)(a1 + 480);
                if ( v33 )
                  v14 = SepSetTokenPackage(v86, v33);
                if ( v14 < 0 )
                {
                  v70 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
                  v71 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                  v72 = *(_WORD *)(v71 + 0x134) + 1;
                  *(_WORD *)(v71 + 308) = v72;
                  if ( !v72 && *(_DWORD *)(v71 + 100) != v71 + 100 && !*(_WORD *)(v71 + 310) )
                    KiCheckForKernelApcDelivery(v70);
                }
                else
                {
                  v34 = *(_DWORD *)(a1 + 628);
                  if ( v34 )
                  {
                    v73 = (unsigned int *)(v34 + 12);
                    do
                    {
                      v74 = __ldrex(v73);
                      v75 = v74 + 1;
                    }
                    while ( __strex(v75, v73) );
                    if ( v75 <= 1 )
                      __fastfail(0xEu);
                    *(_DWORD *)(v86 + 628) = *(_DWORD *)(a1 + 628);
                  }
                  v35 = *(_DWORD *)(a1 + 632);
                  if ( v35 )
                  {
                    v76 = (unsigned int *)(v35 + 12);
                    do
                    {
                      v77 = __ldrex(v76);
                      v78 = v77 + 1;
                    }
                    while ( __strex(v78, v76) );
                    if ( v78 <= 1 )
                      __fastfail(0xEu);
                    *(_DWORD *)(v86 + 632) = *(_DWORD *)(a1 + 632);
                  }
                  if ( *(_DWORD *)(a1 + 636) && (v79 = SepDuplicateTokenClaims(a1), v14 = v79, v79 < 0) )
                  {
                    v80 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
                    v81 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                    v82 = *(_WORD *)(v81 + 0x134) + 1;
                    *(_WORD *)(v81 + 308) = v82;
                    if ( !v82 && *(_DWORD *)(v81 + 100) != v81 + 100 && !*(_WORD *)(v81 + 310) )
                      KiCheckForKernelApcDelivery(v80);
                  }
                  else
                  {
                    v14 = SepSetTokenTrust(v86);
                    v36 = *(_DWORD *)(a1 + 48);
                    if ( v14 >= 0 )
                    {
                      v37 = ExReleaseResourceLite(v36);
                      v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                      v39 = *(_WORD *)(v38 + 0x134) + 1;
                      *(_WORD *)(v38 + 308) = v39;
                      if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
                        KiCheckForKernelApcDelivery(v37);
                      if ( a3 )
                        SepMakeTokenEffectiveOnly();
                      RtlSidHashInitialize(*(int **)(v86 + 148), *(_DWORD *)(v86 + 124), v86 + 204);
                      RtlSidHashInitialize(*(int **)(v86 + 152), *(_DWORD *)(v86 + 128), v86 + 340);
                      v40 = *(int **)(v86 + 484);
                      if ( v40 )
                        RtlSidHashInitialize(v40, *(_DWORD *)(v86 + 488), v86 + 492);
                      *a8 = v86;
                      return v14;
                    }
                    v83 = ExReleaseResourceLite(v36);
                    v84 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                    v85 = *(_WORD *)(v84 + 0x134) + 1;
                    *(_WORD *)(v84 + 308) = v85;
                    if ( !v85 && *(_DWORD *)(v84 + 100) != v84 + 100 && !*(_WORD *)(v84 + 310) )
                      KiCheckForKernelApcDelivery(v83);
                  }
                }
              }
              goto LABEL_123;
            }
            v24 = v86 - a1;
            *(_DWORD *)(v86 + 148) = *(_DWORD *)(a1 + 148) + v86 - a1;
            v14 = SepDuplicateTokenUserAndGroups(a1);
            if ( v14 >= 0 )
              goto LABEL_14;
            *(_DWORD *)(v86 + 148) = 0;
            v58 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
            v59 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v60 = *(_WORD *)(v59 + 0x134) + 1;
            *(_WORD *)(v59 + 308) = v60;
            if ( !v60 && *(_DWORD *)(v59 + 100) != v59 + 100 && !*(_WORD *)(v59 + 310) )
              KiCheckForKernelApcDelivery(v58);
          }
LABEL_123:
          ObfDereferenceObject(v86);
          return v14;
        }
        ExFreePoolWithTag(v12);
        ExFreePoolWithTag(v13);
        return v14;
      }
      ExFreePoolWithTag(v12);
    }
    return -1073741670;
  }
  return sub_7C55C8();
}
