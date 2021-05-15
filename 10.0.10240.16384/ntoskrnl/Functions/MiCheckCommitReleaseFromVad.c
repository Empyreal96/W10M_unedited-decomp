// MiCheckCommitReleaseFromVad 
 
int __fastcall MiCheckCommitReleaseFromVad(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  unsigned int *v6; // r6
  unsigned int v7; // r5
  unsigned int v8; // r7
  int v9; // r10
  int v10; // r8
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r9
  int v15; // r9
  unsigned int v16; // r6
  int v17; // r8
  int v18; // r4
  unsigned int v19; // r7
  unsigned int v20; // r7
  unsigned int v21; // r8
  unsigned int v22; // r4
  int v23; // r7
  unsigned int v24; // r1
  unsigned int v25; // r2
  int v26; // r6
  unsigned int v27; // r4
  int v28; // r0
  int v29; // r9
  unsigned int v30; // r0
  unsigned int v31; // r1
  unsigned int v32; // r2
  unsigned int v33; // r1
  int v34; // r0
  int v35; // r6
  unsigned int v36; // r4
  unsigned int v37; // r0
  unsigned int v38; // r2
  int v39; // r2
  unsigned int v40; // r3
  unsigned int v41; // r3
  int v42; // r3
  int v43; // r2
  unsigned int v45; // [sp+Ch] [bp-54h]
  unsigned int v46; // [sp+14h] [bp-4Ch]
  int v48; // [sp+1Ch] [bp-44h]
  int v49; // [sp+20h] [bp-40h]
  int v50; // [sp+24h] [bp-3Ch] BYREF
  int v51; // [sp+28h] [bp-38h] BYREF
  int v52; // [sp+2Ch] [bp-34h]
  unsigned int *v53; // [sp+30h] [bp-30h]
  _DWORD v54[10]; // [sp+38h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a4 + 12);
  v6 = (unsigned int *)a3;
  v52 = a1;
  v53 = (unsigned int *)a3;
  v7 = 4 * ((v5 & 0xFFFFF) - 0x10000000);
  v8 = 4 * ((*(_DWORD *)(a4 + 16) & 0xFFFFF) - 0x10000000);
  v9 = 0;
  v45 = v8;
  v10 = KfRaiseIrql(2);
  v48 = v10;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_536658();
  v12 = *v6 & 0x7FFFFFFF;
  do
    v13 = __ldrex(v6);
  while ( v13 == v12 && __strex(v12 + 1, v6) );
  __dmb(0xBu);
  if ( v13 != v12 )
    ExpWaitForSpinLockSharedAndAcquire(v6);
  if ( v7 <= v8 )
  {
    v14 = ((v8 >> 10) & 0x3FFFFC) - 0x40000000;
    v49 = v14;
    while ( 2 )
    {
      v54[0] = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
      v54[1] = v14;
      v15 = a4;
      v16 = v7;
      v17 = 0;
      v18 = 0;
      do
      {
        v19 = v54[2 * v18];
        while ( !*(_DWORD *)v19 )
        {
          v19 += 4;
          v17 |= 3u;
          if ( v19 > v54[2 * v18 + 1] )
          {
            v16 = 0;
            goto LABEL_21;
          }
        }
        if ( (*(_DWORD *)v19 & 2) == 0 )
          MiMakeSystemAddressValid(v19 << 10, 0);
        if ( (v17 & 1) != 0 )
          v17 &= 0xFFFFFFFE;
        ++v18;
      }
      while ( !v18 );
      if ( (v17 & 2) != 0 || (*(_DWORD *)v19 & 0x400) != 0 )
        v16 = v19 << 10;
LABEL_21:
      if ( v16 == v7
        || (!v16 ? (v42 = (int)(v45 - v7) >> 2, v43 = v42 + 1) : (v42 = v16 - v7, v43 = (int)(v16 - v7) >> 2),
            v9 += MiComputeCommitChargeForZeroPteRange(a4, v7, v43, v42),
            v16) )
      {
        v20 = v45;
        v21 = (v16 & 0xFFFFF000) + 4092;
        v46 = v21;
        v7 = v16;
        if ( v21 > v45 )
        {
          v21 = v45;
          v46 = v45;
        }
        if ( v16 <= v21 )
        {
          while ( 1 )
          {
            v22 = *(_DWORD *)v7;
            if ( !*(_DWORD *)v7 )
            {
              v23 = 0;
              if ( (*(_DWORD *)(v15 + 28) & 0x8000) != 0 )
              {
                if ( *(int *)(v15 + 32) < 0 )
                  v23 = 1;
              }
              else if ( (*(_DWORD *)(v15 + 28) & 7) == 2 )
              {
                v26 = (v7 >> 2) & 0xFFFFF;
                v27 = 1;
                do
                {
                  v28 = MiGetProtoPteAddress(a4, v26, 13, &v50);
                  v29 = *(_DWORD *)(v50 + 28);
                  v30 = (v28 - *(_DWORD *)(v50 + 4)) >> 2;
                  v31 = v29 - v30;
                  if ( v29 - v30 > v27 )
                    v31 = v27;
                  v32 = 0;
                  if ( (*(_WORD *)(v50 + 16) & 0xA) == 10 )
                  {
                    v40 = v29 - *(_DWORD *)(v50 + 36);
                    if ( v30 < v40 )
                    {
                      v32 = v40 - v30;
                      if ( v40 - v30 > v31 )
                        v32 = v31;
                    }
                  }
                  v23 += v32;
                  v26 += v31;
                  v27 -= v31;
                }
                while ( v27 );
                v21 = v46;
                v15 = a4;
              }
              else if ( (*(_DWORD *)(v15 + 28) & 0x28) == 40 )
              {
                v23 = 1;
              }
              v9 += v23;
              goto LABEL_30;
            }
            if ( (v22 & 2) != 0 )
              break;
            if ( (v22 & 0x400) != 0 )
            {
              if ( (v22 & 0xFFFFE000) != -8192 )
              {
                v33 = (*(_DWORD *)v7 & 0x1FC | (*(_DWORD *)v7 >> 2) & 0x3FFFFE00) - 0x40000000;
                if ( (v33 < dword_640484 || v33 >= dword_640488)
                  && (!*(_DWORD *)(a2 + 272) || !MiLocateCloneAddress(a2, v33)) )
                {
                  v34 = MiGetProtoPteAddress(v15, (v7 >> 2) & 0xFFFFF, 13, &v51);
                  v35 = *(_DWORD *)(v51 + 28);
                  v36 = (v34 - *(_DWORD *)(v51 + 4)) >> 2;
                  v37 = v35 - v36;
                  if ( v35 - v36 > 1 )
                    v37 = 1;
                  v38 = 0;
                  if ( (*(_WORD *)(v51 + 16) & 0xA) == 10 )
                  {
                    v41 = v35 - *(_DWORD *)(v51 + 36);
                    if ( v36 < v41 )
                    {
                      v38 = v41 - v36;
                      if ( v41 - v36 > v37 )
                        v38 = v37;
                    }
                  }
                  v9 += v38;
                }
                goto LABEL_30;
              }
              if ( (*(_DWORD *)v7 & 0xA0) == 160 )
                goto LABEL_61;
            }
            else if ( (v22 & 0x800) == 0 )
            {
              if ( (v22 & 0x10) != 0 )
              {
                if ( !a5 || ((v22 >> 2) & 1) != *(_DWORD *)(v52 + 668) )
                  goto LABEL_30;
                goto LABEL_61;
              }
              if ( (*(_DWORD *)v7 & 0x3E0) != 512 )
                goto LABEL_61;
            }
LABEL_30:
            v7 += 4;
            if ( v7 > v21 )
            {
              v20 = v45;
              goto LABEL_32;
            }
          }
          if ( (v22 & 0x100) == 0 || (*(_DWORD *)(v15 + 28) & 7) == 6 && MiRotatedToFrameBuffer(v7) )
            goto LABEL_30;
          v39 = *(_DWORD *)(MmPfnDatabase + 24 * (v22 >> 12) + 4);
          if ( v39 >= 0 || *(_DWORD *)(a2 + 272) && MiLocateCloneAddress(a2, v39 | 0x80000000) )
            goto LABEL_30;
LABEL_61:
          ++v9;
          goto LABEL_30;
        }
LABEL_32:
        if ( v7 <= v20 )
        {
          v14 = v49;
          continue;
        }
      }
      break;
    }
    v6 = v53;
    v10 = v48;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v6);
  }
  else
  {
    __dmb(0xBu);
    do
      v24 = __ldrex(v6);
    while ( __strex(v24 & 0xBFFFFFFF, v6) );
    __dmb(0xBu);
    do
      v25 = __ldrex(v6);
    while ( __strex(v25 - 1, v6) );
  }
  KfLowerIrql(v10);
  return v9;
}
