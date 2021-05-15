// CmQueryValueKey 
 
int __fastcall CmQueryValueKey(int a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r5
  unsigned int v8; // r1
  _DWORD *v9; // r7
  int v10; // r3
  unsigned int *v12; // r8
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  unsigned int *v16; // r9
  unsigned int v17; // r2
  int v18; // r4
  int v19; // r3
  int v20; // r8
  unsigned int *v21; // r2
  int v22; // r3
  unsigned int v23; // r9
  int v24; // r0
  unsigned int v25; // r6
  int (*v26)(); // r3
  int v27; // r3
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r6
  unsigned __int16 *v31; // r5
  int v32; // r7
  int v33; // r10
  unsigned __int8 *v34; // r6
  unsigned int v35; // r0
  unsigned int v36; // t1
  unsigned int v37; // r4
  unsigned int v38; // t1
  unsigned int v39; // r0
  int v40; // r9
  int v41; // r5
  unsigned int v42; // r4
  int v43; // r1
  int v44; // r0
  int v45; // r1
  unsigned int v46; // r3
  int v47; // r4
  int *v48; // r8
  unsigned int v49; // r2
  int v50; // r1
  unsigned int v51; // r0
  unsigned int v52; // r2
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  char v56[4]; // [sp+10h] [bp-58h] BYREF
  unsigned int v57; // [sp+14h] [bp-54h] BYREF
  unsigned int v58; // [sp+18h] [bp-50h] BYREF
  int v59; // [sp+1Ch] [bp-4Ch]
  unsigned int v60; // [sp+20h] [bp-48h]
  unsigned int v61; // [sp+24h] [bp-44h]
  int v62[3]; // [sp+28h] [bp-40h] BYREF
  _DWORD *v63; // [sp+34h] [bp-34h]
  unsigned int *v64; // [sp+38h] [bp-30h]
  int v65; // [sp+3Ch] [bp-2Ch]
  _DWORD var24[12]; // [sp+44h] [bp-24h] BYREF
  int varg_r1; // [sp+74h] [bp+Ch]
  unsigned __int16 *varg_r2; // [sp+78h] [bp+10h]
  int varg_r3; // [sp+7Ch] [bp+14h]

  var24[11] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v65 = a4;
  v58 = -1;
  v7 = (_DWORD *)a1;
  v59 = 0;
  if ( !CmpPuntBoot )
  {
    PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    a1 = ExAcquireResourceSharedLite((int)&CmpRegistryLock, 1);
  }
  v9 = (_DWORD *)v7[1];
  v10 = v7[7];
  v63 = v9;
  if ( v10 || v7[8] )
    return sub_7FF18C(a1);
  if ( (v9[1] & 0x100000) != 0 )
    JUMPOUT(0x7FF1C8);
  v12 = v9 + 7;
  v13 = KeAbPreAcquire((unsigned int)(v9 + 7), 0, 0);
  v14 = v13;
  do
    v15 = __ldrex(v12);
  while ( !v15 && __strex(0x11u, v12) );
  __dmb(0xBu);
  if ( v15 )
    ExfAcquirePushLockSharedEx(v9 + 7, v13, (unsigned int)(v9 + 7));
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  __dmb(0xBu);
  v16 = v9 + 8;
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + 1, v16) );
  __dmb(0xBu);
  v18 = v9[1];
  v62[1] = 0;
  if ( (v18 & 0x20000) != 0 )
    JUMPOUT(0x7FF2E4);
  if ( v59 )
    JUMPOUT(0x7FF1D6);
  if ( (v18 & 8) != 0 )
    JUMPOUT(0x7FF23C);
  v19 = v9[13];
  v62[0] = -1;
  v57 = -1;
  v20 = 0;
  if ( v19 )
  {
    v21 = (unsigned int *)(*(int (__fastcall **)(_DWORD, _DWORD, int *))(v9[5] + 4))(v9[5], v9[14], v62);
    if ( v21 )
    {
      v22 = v9[13];
      v23 = 0;
      v61 = 0;
      if ( v22 )
      {
        while ( 1 )
        {
          v24 = v9[5];
          v25 = *v21;
          v26 = *(int (**)())(v24 + 4);
          v64 = v21 + 1;
          if ( v26 != HvpGetCellPaged )
            JUMPOUT(0x7FF298);
          v27 = (unsigned __int8)HvShutdownComplete;
          __dmb(0xBu);
          if ( v27 == 1 )
            JUMPOUT(0x7FF292);
          v28 = *(_DWORD *)(v24 + 412 * (v25 >> 31) + 956);
          v29 = (v25 & 0xFFF)
              + HvpMapEntryGetBlockAddress(
                  v28,
                  (int *)(*(_DWORD *)(v28 + 4 * ((v25 >> 21) & 0x3FF)) + 20 * ((v25 >> 12) & 0x1FF)),
                  v56,
                  var24);
          HvpFaultCellWithClustering();
          v20 = v29 + 4;
          v30 = v25 & 0xFFFFFFFE | v56[0] & 1;
          v57 = v30;
          v60 = v30;
          if ( v29 == -4 )
            break;
          if ( (*(_WORD *)(v29 + 20) & 1) != 0 )
          {
            v31 = varg_r2;
            v32 = *(unsigned __int16 *)(v29 + 6);
            v33 = (unsigned __int16)varg_r1 >> 1;
            v34 = (unsigned __int8 *)(v29 + 24);
            if ( v33 )
            {
              while ( v32 )
              {
                v36 = *v31++;
                v35 = v36;
                v38 = *v34++;
                v37 = v38;
                if ( v35 != v38 )
                {
                  if ( v35 >= 0x61 )
                  {
                    if ( v35 > 0x7A )
                      LOWORD(v35) = RtlUpcaseUnicodeChar(v35);
                    else
                      LOWORD(v35) = v35 - 32;
                  }
                  v40 = (unsigned __int16)v35;
                  if ( v37 >= 0x61 )
                  {
                    if ( v37 > 0x7A )
                      LOWORD(v37) = RtlUpcaseUnicodeChar(v37);
                    else
                      LOWORD(v37) = v37 - 32;
                  }
                  v39 = v40 - (unsigned __int16)v37;
                  if ( v40 != (unsigned __int16)v37 )
                    goto LABEL_34;
                }
                v33 = (unsigned __int16)(v33 - 1);
                v32 = (unsigned __int16)(v32 - 1);
                if ( !v33 )
                  break;
              }
            }
            v39 = v33 - v32;
LABEL_34:
            v9 = v63;
            v30 = v60;
            v23 = v61;
          }
          else
          {
            v39 = RtlCompareUnicodeStrings(
                    varg_r2,
                    (unsigned __int16)varg_r1 >> 1,
                    v29 + 24,
                    *(unsigned __int16 *)(v29 + 6) >> 1,
                    1);
          }
          if ( !v39 )
          {
            v58 = v30;
            HvpGetCellContextReinitialize(&v57);
            break;
          }
          v41 = v9[5];
          if ( *(int (**)())(v41 + 8) != HvpReleaseCellPaged )
            JUMPOUT(0x7FF2AA);
          v42 = v30 & 0xFFFFFFFE;
          v43 = v41 + 412 * ((v30 & 0xFFFFFFFE) >> 31);
          if ( v42 + (v42 >> 31 << 31) >= *(_DWORD *)(v43 + 952)
            || (v44 = (v42 >> 21) & 0x3FF,
                (v45 = *(_DWORD *)(*(_DWORD *)(v43 + 956) + 4 * v44) + 20 * ((v42 >> 12) & 0x1FF)) == 0) )
          {
            JUMPOUT(0x7FF2B4);
          }
          if ( (v30 & 1) != 0 )
            HvpMapEntryReleaseBinAddress(v44, v45);
          HvpGetCellContextReinitialize(&v57);
          v46 = v9[13];
          ++v23;
          v20 = 0;
          v61 = v23;
          if ( v23 >= v46 )
            break;
          v21 = v64;
        }
      }
      (*(void (__fastcall **)(_DWORD, int *))(v9[5] + 8))(v9[5], v62);
      v16 = v9 + 8;
    }
  }
  if ( v20 )
    v47 = CmpQueryKeyValueData(v9, v58, v20, v65, a5, a6, a7);
  else
    v47 = -1073741772;
  if ( v20 )
    (*(void (__fastcall **)(_DWORD, unsigned int *))(v9[5] + 8))(v9[5], &v58);
  v48 = v9 + 7;
  if ( v9[8] == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    JUMPOUT(0x7FF2C6);
  __dmb(0xBu);
  do
    v49 = __ldrex(v16);
  while ( __strex(v49 - 1, v16) );
  __dmb(0xBu);
  __pld(v48);
  v50 = *v48;
  if ( (*v48 & 0xFFFFFFF0) > 0x10 )
    v51 = v50 - 16;
  else
    v51 = 0;
  if ( (v50 & 2) != 0 )
    goto LABEL_78;
  __dmb(0xBu);
  do
    v52 = __ldrex((unsigned int *)v48);
  while ( v52 == v50 && __strex(v51, (unsigned int *)v48) );
  if ( v52 != v50 )
LABEL_78:
    ExfReleasePushLock(v9 + 7, v50);
  KeAbPostRelease((unsigned int)(v9 + 7));
  if ( (v9[1] & 0x100000) != 0 )
    JUMPOUT(0x7FF2CE);
  if ( (v9[1] & 0x80000) != 0 )
    JUMPOUT(0x7FF2DA);
  if ( !CmpPuntBoot )
  {
    v53 = ExReleaseResourceLite((int)&CmpRegistryLock);
    v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v55 = *(_WORD *)(v54 + 0x134) + 1;
    *(_WORD *)(v54 + 308) = v55;
    if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
      KiCheckForKernelApcDelivery(v53);
    PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1);
  }
  return v47;
}
