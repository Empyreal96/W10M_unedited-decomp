// MiProcessWorkingSets 
 
int __fastcall MiProcessWorkingSets(_DWORD *a1)
{
  int v1; // r6
  int v3; // r0
  int *v4; // r2
  int v5; // r5
  int v6; // r7
  int v7; // r10
  int result; // r0
  int v9; // r4
  int v10; // r6
  int v11; // r8
  char v12; // r9
  int v13; // r6
  int v14; // r4
  int v15; // r1
  __int64 *v16; // r4
  __int64 v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  int v20; // r2
  int v21; // r0
  unsigned int *v22; // r2
  int *v23; // r1
  int v24; // r5
  _DWORD *v25; // r1
  int **v26; // r2
  int v27; // r0
  __int64 *v28; // r2
  int v29; // r3
  unsigned int v30; // r2
  int v31; // r3
  char v32; // r5
  int v33; // r2
  int v34; // r1
  int v35; // r3
  int v36; // r2
  int v37; // r3
  int v38; // r1
  int v39; // r4
  __int64 **v40; // r2
  _DWORD *v41; // r6
  _DWORD *v42; // r2
  unsigned int *v43; // r2
  unsigned int v44; // r0
  int *v45; // r0
  int *v46; // r1
  int *v47; // r4
  unsigned int v48; // r2
  int *v49; // r2
  __int64 v50; // kr00_8
  int v51; // r4
  __int64 **v52; // r2
  unsigned int v53; // r3
  int v54; // r0
  int v55; // r3
  int v56; // r0
  int v57; // [sp+8h] [bp-148h]
  int v58; // [sp+10h] [bp-140h] BYREF
  int *v59; // [sp+14h] [bp-13Ch]
  unsigned __int8 v60; // [sp+18h] [bp-138h]
  int v61; // [sp+1Ch] [bp-134h]
  _DWORD *v62; // [sp+20h] [bp-130h]
  int v63; // [sp+28h] [bp-128h]
  unsigned int v64; // [sp+2Ch] [bp-124h]
  _DWORD *v65; // [sp+30h] [bp-120h]
  int v66; // [sp+34h] [bp-11Ch]
  int v67; // [sp+38h] [bp-118h]
  char v68[2]; // [sp+58h] [bp-F8h] BYREF
  unsigned __int8 v69; // [sp+5Ah] [bp-F6h]
  int v70; // [sp+5Ch] [bp-F4h]
  int v71; // [sp+60h] [bp-F0h]
  int v72; // [sp+64h] [bp-ECh]
  int v73; // [sp+68h] [bp-E8h]
  int v74; // [sp+6Ch] [bp-E4h]
  int v75; // [sp+70h] [bp-E0h]
  int v76; // [sp+74h] [bp-DCh]
  int v77; // [sp+78h] [bp-D8h]
  int v78; // [sp+80h] [bp-D0h]
  int v79; // [sp+84h] [bp-CCh]
  int v80; // [sp+88h] [bp-C8h]
  int v81; // [sp+8Ch] [bp-C4h]

  v1 = a1[878];
  v57 = v1;
  v65 = a1;
  MiComputeAgingPercent((int)a1);
  v3 = MiComputeSystemTrimCriteria(a1, (int)v68);
  v4 = MiState;
  v5 = v78;
  v6 = v69;
  v7 = v3;
  if ( dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    if ( TlgKeywordOn(dword_634CA0, 1i64) )
      return sub_542AE8();
    v4 = MiState;
  }
  ++*(_DWORD *)(v1 + 88);
  if ( (v7 & 5) != 0 )
  {
    MiDrainZeroLookasides((int)a1, 0, 0, 0);
    v4 = MiState;
  }
  v63 = 0;
  v64 = 0;
  v9 = v1;
  if ( (v7 & 5) != 0 )
    *(_BYTE *)(v1 + 44) = 1;
  if ( (v7 & 2) != 0 )
    ++*(_DWORD *)(v1 + 1212);
  v62 = 0;
  if ( (v7 & 0x40) != 0 )
  {
    if ( *(unsigned __int16 *)(v1 + 1218) > 0xAu )
      *(_WORD *)(v1 + 1218) = 10;
    KeAcquireInStackQueuedSpinLock((unsigned int *)v4 + 1984, (unsigned int)&v58);
    if ( *(_BYTE *)(v1 + 46) == 1 )
    {
      *(_BYTE *)(v1 + 46) = 0;
      v45 = (int *)a1[879];
      v46 = a1 + 879;
      if ( v45 != a1 + 879 )
      {
        do
        {
          v47 = v45 - 3;
          v48 = v45[8];
          v45 = (int *)*v45;
          if ( v48 >= *(_DWORD *)(v1 + 52) )
          {
            v49 = v47 + 3;
            v50 = *(_QWORD *)(v47 + 3);
            if ( *(int **)(v50 + 4) != v47 + 3 || *(int **)HIDWORD(v50) != v49 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v50) = v50;
            *(_DWORD *)(v50 + 4) = HIDWORD(v50);
            v51 = *v46;
            *v49 = *v46;
            v49[1] = (int)v46;
            if ( *(int **)(v51 + 4) != v46 )
              __fastfail(3u);
            *(_DWORD *)(v51 + 4) = v49;
            *v46 = (int)v49;
          }
        }
        while ( v45 != v46 );
        v9 = v1;
      }
    }
  }
  else
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)v4 + 1984, (unsigned int)&v58);
  }
  v10 = (int)(a1 + 879);
  v11 = v80;
  v12 = v68[0];
  *(_BYTE *)(v9 + 45) = 1;
  v66 = v10;
LABEL_15:
  v13 = v66;
  v14 = v57;
  while ( 2 )
  {
    v70 = 0;
    v67 = v7 & 1;
    if ( (v7 & 1) != 0 )
      v81 = MiOrderTrimList(v65, *((unsigned __int8 *)MiTrimPassToAge + (v12 & 0x7F)));
    v15 = (unsigned __int16)(*(_WORD *)(v14 + 1216) + 1);
    v79 = v5 - v11;
    v61 = v15;
    *(_WORD *)(v14 + 1216) = v15;
    while ( *(_DWORD *)v13 != v13 )
    {
      v16 = *(__int64 **)v13;
      v17 = *(_QWORD *)*(_DWORD *)v13;
      if ( HIDWORD(v17) != v13 || *(__int64 **)(v17 + 4) != v16 )
        __fastfail(3u);
      *(_DWORD *)v13 = v17;
      *(_DWORD *)(v17 + 4) = v13;
      v18 = *((unsigned __int16 *)v16 + 43);
      *(_DWORD *)v16 = 0;
      if ( v18 == v15 )
      {
        v28 = *(__int64 **)v13;
        *(_DWORD *)v16 = *(_DWORD *)v13;
        *((_DWORD *)v16 + 1) = v13;
        if ( *((_DWORD *)v28 + 1) != v13 )
          __fastfail(3u);
        v29 = v67;
        *((_DWORD *)v28 + 1) = v16;
        *(_DWORD *)v13 = v16;
        if ( v29 )
        {
          v56 = MiCheckSystemTrimEndCriteria(v65, v68, &v58);
          v11 = v80;
          v12 = v68[0];
          if ( !v56 )
          {
            v5 = v78;
            v6 = v69;
            goto LABEL_15;
          }
        }
        break;
      }
      *((_WORD *)v16 + 43) = v15;
      if ( (v7 & 0x40) != 0 && *((_DWORD *)v16 + 8) < *(_DWORD *)(v57 + 52) )
      {
        v40 = *(__int64 ***)(v13 + 4);
        *(_DWORD *)v16 = v13;
        *((_DWORD *)v16 + 1) = v40;
        if ( *v40 != (__int64 *)v13 )
          __fastfail(3u);
        *v40 = v16;
        *(_DWORD *)(v13 + 4) = v16;
        break;
      }
      v19 = *((_DWORD *)v16 + 12);
      if ( v19 > 3 || (*((_BYTE *)v16 + 100) & 7) != 0 )
      {
        v20 = 0;
        if ( v6 == 2 )
        {
          v53 = *((_DWORD *)v16 + 9);
          if ( v19 <= v53 || v19 - v53 < 0x40000 )
            v20 = 1;
        }
        *((_BYTE *)v16 + 101) = *((_BYTE *)v16 + 101) & 0xF9 | 2;
        if ( !v20 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v58);
          }
          else
          {
            v21 = v58;
            if ( !v58 )
            {
              v22 = (unsigned int *)v59;
              __dmb(0xBu);
              do
                v23 = (int *)__ldrex(v22);
              while ( v23 == &v58 && __strex(0, v22) );
              if ( v23 == &v58 )
                goto LABEL_33;
              v21 = KxWaitForLockChainValid(&v58);
            }
            v58 = 0;
            __dmb(0xBu);
            v43 = (unsigned int *)(v21 + 4);
            do
              v44 = __ldrex(v43);
            while ( __strex(v44 ^ 1, v43) );
          }
LABEL_33:
          KfLowerIrql(v60);
          v24 = MiTrimOrAgeWorkingSet((char *)v16 - 12, v68, v7);
          v59 = &dword_634980;
          v58 = 0;
          __dmb(0xBu);
          v60 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireQueuedSpinLockInstrumented(&v58, &dword_634980);
          }
          else
          {
            do
              v25 = (_DWORD *)__ldrex((unsigned int *)&dword_634980);
            while ( __strex((unsigned int)&v58, (unsigned int *)&dword_634980) );
            __dmb(0xBu);
            if ( v25 )
              KxWaitForLockOwnerShip((int)&v58, v25);
          }
          if ( v24 || !v67 )
            goto LABEL_38;
          if ( *((_DWORD *)v16 + 24) )
          {
            if ( (*((_BYTE *)v16 + 100) & 0x38) != 0 )
              *((_BYTE *)v16 + 100) ^= (*((_BYTE *)v16 + 100) ^ (8 * ((*((_BYTE *)v16 + 100) >> 3) - 1))) & 0x38;
            if ( (*((_BYTE *)v16 + 100) & 0x38) == 0 )
              goto LABEL_38;
          }
          v68[1] = *((_BYTE *)MiTrimPassToAge + (v68[0] & 0x7F));
          v54 = MiComputeTrimAmount(v68, (char *)v16 - 12, 0);
          if ( v54 )
          {
            v55 = v80;
            *((_DWORD *)v16 + 24) = v54;
            v11 = v54 + v55;
            LOBYTE(v55) = *((_BYTE *)v16 + 100);
            v80 = v11;
            *((_BYTE *)v16 + 100) = v55 | 0x38;
            v70 += v54;
          }
          else
          {
LABEL_38:
            v11 = v80;
          }
          v12 = v68[0];
          v6 = v69;
        }
        if ( (v7 & 0x40) == 0 || *((_DWORD *)v16 + 8) < *(_DWORD *)(v57 + 52) || *((_DWORD *)v16 - 2) )
        {
          *((_BYTE *)v16 + 101) &= 0xF9u;
          v26 = (int **)dword_6404C0;
          *(_DWORD *)v16 = &dword_6404BC;
          *((_DWORD *)v16 + 1) = v26;
          if ( *v26 != &dword_6404BC )
            __fastfail(3u);
          *v26 = (int *)v16;
          dword_6404C0 = (int)v16;
          v27 = *((_DWORD *)v16 - 2);
          v15 = v61;
          if ( v27 )
          {
            KeSignalGate(v27, 1);
            v15 = v61;
          }
        }
        else
        {
          v15 = v61;
          *((_BYTE *)v16 + 101) |= 6u;
          *((_DWORD *)v16 + 1) = v62;
          v62 = (_DWORD *)v16 + 1;
        }
      }
      else if ( *((_DWORD *)v16 - 2) )
      {
        v52 = *(__int64 ***)(v13 + 4);
        *(_DWORD *)v16 = v13;
        *((_DWORD *)v16 + 1) = v52;
        if ( *v52 != (__int64 *)v13 )
          __fastfail(3u);
        v15 = v61;
        *v52 = v16;
        *(_DWORD *)(v13 + 4) = v16;
      }
      else
      {
        *((_BYTE *)v16 + 101) |= 6u;
        KeReleaseInStackQueuedSpinLock((int)&v58);
        KeRetryOutswapProcess(v16 - 63);
        KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)&v58);
        *((_BYTE *)v16 + 101) &= 0xF9u;
        MiReturnWsToExpansionList((int *)v16 - 3, 0);
        v15 = v61;
      }
    }
    if ( (v7 & 0x40) != 0 )
    {
      v41 = v62;
      while ( 1 )
      {
        v42 = v41;
        if ( !v41 )
          break;
        v41 = (_DWORD *)*v41;
        *((_BYTE *)v42 + 97) &= 0xF9u;
        MiReturnWsToExpansionList(v42 - 4, 1);
      }
      v62 = 0;
      v13 = v66;
    }
    v14 = v57;
    v30 = v64 | v7 & 0xFFFFFF3C;
    v31 = *(_DWORD *)(v57 + 32);
    v32 = v63 | v7;
    v63 |= v7;
    v64 = v30;
    if ( v30 != v31 )
    {
      if ( (v31 & 5) != 0 )
        *(_BYTE *)(v57 + 44) = 1;
      v6 = 7;
      v5 = v78;
      v69 = 7;
      v7 = v31 ^ v30;
      continue;
    }
    break;
  }
  *(_BYTE *)(v57 + 45) = 0;
  if ( (v32 & 5) != 0 )
    *(_BYTE *)(v57 + 44) = 0;
  if ( *(_DWORD *)(v57 + 32) )
  {
    *(_DWORD *)(v57 + 32) = 0;
    KeSetEvent(v57, 0, 0);
  }
  if ( (v32 & 0x83) != 0 )
  {
    v33 = v72;
    v34 = v73;
    *(_DWORD *)(v57 + 1256) = v71;
    v35 = v74;
    *(_DWORD *)(v57 + 1260) = v33;
    v36 = v75;
    *(_DWORD *)(v57 + 1268) = v35;
    v37 = v77;
    *(_DWORD *)(v57 + 1264) = v34;
    v38 = v76;
    *(_DWORD *)(v57 + 1272) = v36;
    *(_DWORD *)(v57 + 1276) = v38;
    *(_DWORD *)(v57 + 1280) = v37;
    *(_DWORD *)(v57 + 1252) = v37 + v38;
  }
  result = KeReleaseInStackQueuedSpinLock((int)&v58);
  v39 = dword_634CA0;
  if ( dword_634CA0 )
  {
    if ( *(_DWORD *)dword_634CA0 > 5u )
    {
      result = TlgKeywordOn(dword_634CA0, 1i64);
      if ( result )
        result = MmTlgWrite(v39, (char *)&word_413FDA + 1);
    }
  }
  return result;
}
