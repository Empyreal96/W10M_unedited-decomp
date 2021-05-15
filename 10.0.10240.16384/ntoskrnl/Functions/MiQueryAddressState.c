// MiQueryAddressState 
 
int __fastcall MiQueryAddressState(unsigned int a1, int a2, _DWORD *a3, int a4, unsigned int *a5, int *a6, _DWORD *a7)
{
  int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r1
  int v11; // r7
  int v12; // r6
  unsigned int v13; // r4
  BOOL v14; // r3
  unsigned int v15; // r4
  int v16; // r2
  unsigned int v17; // r6
  unsigned int v18; // r4
  _QWORD *v19; // r2
  unsigned int *v20; // r6
  unsigned int v21; // r1
  unsigned int v22; // r2
  unsigned int v23; // r2
  int v24; // r1
  int v25; // r4
  unsigned int v26; // r1
  int v27; // r1
  int result; // r0
  int v29; // r2
  int *v30; // r4
  _QWORD *v31; // r2
  int v32; // r10
  int v33; // r4
  unsigned __int8 *v34; // r1
  unsigned int v35; // r2
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int *v38; // r9
  unsigned int v39; // r5
  unsigned int *v40; // r10
  unsigned int v41; // r1
  unsigned int v42; // r2
  _DWORD *v43; // r4
  int v44; // r9
  int v45; // t1
  int v46; // r2
  int v48; // r0
  unsigned int v49; // r1
  unsigned int *v50; // r4
  unsigned int *v51; // r0
  unsigned int v52; // r6
  int v53; // kr08_4
  unsigned int v54; // r2
  unsigned int v55; // r8
  unsigned int v56; // r1
  unsigned int v57; // lr
  unsigned __int64 v58; // kr20_8
  unsigned int v59; // kr28_4
  unsigned int v60; // r6
  unsigned int v61; // r2
  int v62; // r1
  int v63; // r3
  int v64; // r3
  unsigned int v65; // r2
  int v66; // [sp+8h] [bp-50h]
  unsigned int v67; // [sp+Ch] [bp-4Ch]
  unsigned int *v69; // [sp+14h] [bp-44h] BYREF
  int v70; // [sp+18h] [bp-40h]
  unsigned int v71; // [sp+1Ch] [bp-3Ch]
  int v72; // [sp+20h] [bp-38h]
  int v73; // [sp+24h] [bp-34h]
  unsigned __int64 v74; // [sp+28h] [bp-30h] BYREF
  _DWORD v75[10]; // [sp+30h] [bp-28h] BYREF

  v73 = a4;
  LODWORD(v74) = a3;
  v66 = 0x2000;
  v8 = a3[4];
  v67 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v70 = a2;
  v71 = 4 * ((v8 & 0xFFFFF) - 0x10000000);
  v72 = 4194300;
  v9 = v67;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v75[0] = ((v67 >> 10) & 0x3FFFFC) - 0x40000000;
  v75[1] = ((v71 >> 10) & 0x3FFFFC) - 0x40000000;
  v69 = 0;
  do
  {
    v13 = v75[2 * v12];
    while ( !*(_DWORD *)v13 )
    {
      v13 += 4;
      v10 |= 3u;
      v69 = (unsigned int *)v10;
      if ( (v13 & 0xFFF) == 0 )
        return sub_5373A0(0);
      if ( v13 > v75[2 * v12 + 1] )
      {
        v9 = 0;
        v14 = 0;
        goto LABEL_12;
      }
    }
    if ( (*(_DWORD *)v13 & 2) == 0 )
    {
      MiMakeSystemAddressValid(v13 << 10, 0);
      v10 = (unsigned int)v69;
    }
    if ( (v10 & 1) != 0 )
    {
      v10 &= 0xFFFFFFFE;
      v69 = (unsigned int *)v10;
    }
    ++v12;
  }
  while ( !v12 );
  if ( (v10 & 2) != 0 || (*(_DWORD *)v13 & 0x400) != 0 )
    v9 = v13 << 10;
  v14 = (*(_DWORD *)v13 & 0x400) != 0;
LABEL_12:
  if ( !v9 )
  {
    v9 = v71 + 4;
    goto LABEL_16;
  }
  if ( !v14 )
  {
    if ( v67 == v9 )
    {
      v15 = *(_DWORD *)v67;
      v9 = 0;
      if ( *(_DWORD *)v67 )
      {
        if ( ((v15 >> 5) & 0x1F) != 16 || (v15 & 2) != 0 || (v15 & 0x400) != 0 && (v15 & 0xFFFFE000) != -8192 )
        {
          v29 = a3[7];
          v27 = 4096;
          v66 = 4096;
          if ( (v29 & 7) == 1 )
          {
            v11 = (unsigned __int8)v29 >> 3;
            goto LABEL_52;
          }
          if ( (v29 & 7) == 3 )
          {
            if ( ((v15 >> 5) & 1) != 0 )
            {
              if ( (v15 & 0x80) != 0 )
                v11 = 4;
              else
                v11 = 1;
            }
            else
            {
              v11 = 24;
            }
            goto LABEL_52;
          }
          v11 = MiGetPageProtection(a3, v67, v70, 0);
          if ( (v15 & 3) == 0 && (v15 & 0x400) != 0 && (a3[7] & 0x8000) == 0 )
          {
            v30 = (int *)MiGetProtoPteAddress(a3, a1 >> 12, 9, &v69);
            if ( !v30 )
              goto LABEL_106;
            v31 = (_QWORD *)a3[17];
            if ( (int)v31 < 0 && (a1 >> 12) - a3[3] > (unsigned int)((*v31 - 1i64) >> 12) )
              goto LABEL_106;
            if ( !*a5 || a1 > *a5 )
            {
              v38 = v69;
              v39 = v69[1] + 4 * v69[7];
              v40 = (unsigned int *)(v73 + 492);
              if ( (dword_682604 & 0x10000) != 0 )
              {
                ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v73 + 492);
              }
              else
              {
                __dmb(0xBu);
                do
                  v41 = __ldrex(v40);
                while ( __strex(v41 & 0xBFFFFFFF, v40) );
                __dmb(0xBu);
                do
                  v42 = __ldrex(v40);
                while ( __strex(v42 - 1, v40) );
              }
              KfLowerIrql(v70);
              if ( (*((_WORD *)v38 + 9) & 2) != 0 )
                v39 = (unsigned int)(v30 + 1);
              v45 = *v30;
              v43 = v30 + 1;
              v44 = v45;
              v46 = 0;
              if ( v43 != (_DWORD *)v39 )
              {
                do
                {
                  if ( !*v43++ )
                    break;
                  ++v46;
                  if ( v43 == (_DWORD *)v39 )
                    break;
                }
                while ( ((unsigned __int16)v43 & 0xFFF) != 0 );
              }
              *a5 = (a1 & 0xFFFFF000) + (v46 << 12);
              KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v40);
              }
              else
              {
                v48 = *v40 & 0x7FFFFFFF;
                do
                  v49 = __ldrex(v40);
                while ( v49 == v48 && __strex(v48 + 1, v40) );
                __dmb(0xBu);
                if ( v49 != v48 )
                  ExpWaitForSpinLockSharedAndAcquire(v40);
              }
              if ( !v44 )
              {
LABEL_106:
                v27 = 0x2000;
                v11 = 0;
                goto LABEL_52;
              }
            }
          }
        }
        v27 = v66;
LABEL_52:
        v9 = v67 + 4;
        goto LABEL_40;
      }
    }
LABEL_16:
    v16 = a3[7];
    if ( (v16 & 7) != 3 && (v16 & 7) != 1 )
    {
      if ( (v16 & 0x8000) != 0 )
      {
        if ( (int)a3[8] < 0 )
        {
          v27 = 4096;
          v11 = (unsigned __int8)v16 >> 3;
LABEL_39:
          if ( v9 )
          {
LABEL_40:
            result = v27;
            *a7 = v9 << 10;
            *a6 = v11;
            return result;
          }
          goto LABEL_52;
        }
      }
      else
      {
        v17 = a1;
        v18 = MiGetProtoPteAddress(a3, a1 >> 12, 1, &v69);
        if ( !v18 )
        {
          if ( MiVadPureReserve((int)a3) && (v50 = v69) != 0 && !v69[1] && v9 )
          {
            v51 = (unsigned int *)a3[11];
            v52 = v9 - v67;
            v53 = (a1 >> 12) - a3[3];
            v74 = ((int)(a3[12] - v51[1]) >> 2) + (unsigned __int64)(unsigned int)v53;
            MiLocatePagefileSubsection(v51, (int)&v74);
            v54 = v50[7];
            v9 = v67;
            v55 = v54;
            v58 = v74 + v52;
            v57 = HIDWORD(v58);
            v56 = v58;
            if ( v58 < v54 )
              goto LABEL_122;
            while ( !v50[1] )
            {
              if ( v54 >= v52 )
              {
                v9 += 4 * v52;
                break;
              }
              v50 = (unsigned int *)v50[2];
              v52 -= v54;
              v59 = v56 - v55;
              v57 = (__PAIR64__(v57, v56) - v55) >> 32;
              v56 -= v55;
              v9 += 4 * v54;
              if ( !v50 )
              {
                v9 = v71 + 4;
                break;
              }
              v54 = v50[7];
              v55 = v54;
              if ( __PAIR64__(v57, v59) < v54 )
                break;
            }
            if ( v9 == v67 )
LABEL_122:
              v9 = v67 + 4;
          }
          else
          {
            v9 = v67 + 4;
          }
          goto LABEL_38;
        }
        if ( v9 && MiVadPureReserve((int)a3) )
        {
          v60 = v18;
          v61 = v69[1] + 4 * v69[7];
          v62 = (int)(v9 - v67) >> 2;
          if ( v62 < (int)(v61 - v18) >> 2 )
            v61 = v18 + 4 * v62;
          do
          {
            v63 = *(_DWORD *)((v72 & (v18 >> 10)) - 0x40000000);
            if ( (v63 & 2) != 0 )
              break;
            if ( (v63 & 0x3E0) != 0 )
              break;
            v18 = ((v72 & (v18 >> 10)) - 1073741820) << 10;
          }
          while ( v18 < v61 );
          if ( v18 != v60 )
          {
            if ( v18 > v61 )
              v18 = v61;
            v9 = v67 + 4 * ((int)(v18 - v60) >> 2);
            goto LABEL_38;
          }
          v17 = a1;
          v9 = v67 + 4;
        }
        else
        {
          v9 = v67 + 4;
        }
        if ( v18 )
        {
          v19 = (_QWORD *)a3[17];
          if ( (int)v19 >= 0 || (v17 >> 12) - a3[3] <= (unsigned int)((*v19 - 1i64) >> 12) )
          {
            v20 = (unsigned int *)(v73 + 492);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v73 + 492);
            }
            else
            {
              __dmb(0xBu);
              do
                v21 = __ldrex(v20);
              while ( __strex(v21 & 0xBFFFFFFF, v20) );
              __dmb(0xBu);
              do
                v22 = __ldrex(v20);
              while ( __strex(v22 - 1, v20) );
            }
            KfLowerIrql(v70);
            v23 = *(_DWORD *)v18;
            if ( *(_DWORD *)v18 )
            {
              v66 = 4096;
              v24 = *(_DWORD *)(v74 + 28);
              if ( (v24 & 7) == 2 && (v24 & 0xF8) == 56 )
              {
                if ( (v23 & 2) != 0 )
                {
                  v32 = MiMakeProtoAddressValid(v18);
                  v11 = MiCaptureProtectionFromLockedProto((unsigned int *)v18);
                  v33 = KfRaiseIrql(2);
                  v34 = (unsigned __int8 *)(v32 + 15);
                  do
                    v35 = __ldrex(v34);
                  while ( __strex(v35 | 0x80, v34) );
                  __dmb(0xBu);
                  if ( v35 >> 7 )
                  {
                    do
                    {
                      do
                      {
                        __dmb(0xAu);
                        __yield();
                        v64 = *(_DWORD *)(v32 + 12);
                        __dmb(0xBu);
                      }
                      while ( (v64 & 0x80000000) != 0 );
                      do
                        v65 = __ldrex(v34);
                      while ( __strex(v65 | 0x80, v34) );
                      __dmb(0xBu);
                    }
                    while ( v65 >> 7 );
                  }
                  MiRemoveLockedPageChargeAndDecRef(v32);
                  __dmb(0xBu);
                  v36 = (unsigned int *)(v32 + 12);
                  do
                    v37 = __ldrex(v36);
                  while ( __strex(v37 & 0x7FFFFFFF, v36) );
                  KfLowerIrql(v33);
                }
                else if ( (v23 & 0x400) != 0 )
                {
                  v11 = (*(unsigned __int16 *)((*(_DWORD *)v18 & 0xFFFFF800 | (2 * (*(_DWORD *)v18 & 0x3FC))) + 0x10) >> 1) & 0x1F;
                }
                else
                {
                  v11 = (v23 >> 5) & 0x1F;
                }
              }
              else
              {
                v11 = (unsigned __int8)v24 >> 3;
              }
            }
            KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v20);
            }
            else
            {
              v25 = *v20 & 0x7FFFFFFF;
              do
                v26 = __ldrex(v20);
              while ( v26 == v25 && __strex(v25 + 1, v20) );
              __dmb(0xBu);
              if ( v26 != v25 )
                ExpWaitForSpinLockSharedAndAcquire(v20);
            }
          }
        }
      }
    }
LABEL_38:
    v27 = v66;
    goto LABEL_39;
  }
  result = 4096;
  *a6 = (unsigned __int8)a3[7] >> 3;
  *a7 = (((a1 >> 20) & 0xFFC) + 4) << 20;
  return result;
}
