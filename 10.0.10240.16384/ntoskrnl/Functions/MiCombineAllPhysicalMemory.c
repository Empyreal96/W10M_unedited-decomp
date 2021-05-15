// MiCombineAllPhysicalMemory 
 
int __fastcall MiCombineAllPhysicalMemory(int *a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v7; // r4
  int v8; // r7
  unsigned int v9; // r9
  int *v10; // r0
  int v11; // r3
  int v12; // r8
  int v13; // r2
  int v14; // r0
  int v15; // r7
  int v16; // r4
  unsigned int v17; // r0
  unsigned int v19; // lr
  unsigned int v20; // r0
  int v21; // r1
  unsigned __int8 *v22; // r2
  int v23; // t1
  unsigned int v24; // r7
  int v25; // r8
  int v26; // r5
  int v27; // r1
  int v28; // r3
  int v29; // r1
  int v30; // r4
  bool v31; // zf
  int v32; // r3
  unsigned int v33; // r2
  unsigned int v34; // [sp+10h] [bp-88h] BYREF
  int v35; // [sp+14h] [bp-84h]
  int v36; // [sp+18h] [bp-80h]
  int v37; // [sp+1Ch] [bp-7Ch]
  int v38; // [sp+20h] [bp-78h]
  int v39; // [sp+24h] [bp-74h]
  int v40; // [sp+28h] [bp-70h]
  int v41; // [sp+2Ch] [bp-6Ch]
  unsigned int v42; // [sp+30h] [bp-68h]
  int v43; // [sp+34h] [bp-64h]
  int v44; // [sp+38h] [bp-60h]
  int *v45; // [sp+3Ch] [bp-5Ch]
  int v46; // [sp+40h] [bp-58h]
  unsigned __int8 *v47; // [sp+44h] [bp-54h]
  int v48; // [sp+48h] [bp-50h]
  int v49; // [sp+4Ch] [bp-4Ch]
  int v50; // [sp+50h] [bp-48h]
  int v51[4]; // [sp+58h] [bp-40h] BYREF
  _DWORD v52[12]; // [sp+68h] [bp-30h] BYREF

  v4 = 0;
  v41 = 0;
  v39 = a4;
  v37 = a3;
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = *a1;
  v9 = v7 & 0xFFFFFFC0;
  v48 = v8;
  v10 = (int *)MiReferencePageRuns(v8, 1);
  v11 = *v10;
  v45 = v10;
  v43 = v11;
  v44 = 0;
  v35 = 0;
  v36 = 0;
  v12 = 0;
  if ( !KeNumberNodes )
    goto LABEL_30;
  v13 = 0;
  v50 = 1048574;
  v46 = 0;
  do
  {
    v34 = (24 * *(_DWORD *)(*(_DWORD *)(v8 + 24) + v13 + 68) + 4095) & 0xFFFFF000;
    v14 = MiAllocateCrcList(a1, &v34);
    v15 = v14;
    v40 = v14;
    if ( !v14 )
    {
      v4 = -1073741670;
      break;
    }
    v16 = v14;
    v38 = v14;
    v49 = v14 + 24 * (v34 / 0x18);
    v17 = KeQueryNodeActiveAffinity((unsigned __int16)v12, v51, 0);
    if ( v51[0] )
    {
      if ( v44 )
        return sub_54EFA8(v17);
      v44 = 1;
      KeSetSystemGroupAffinityThread((int)v51, v52);
    }
    v19 = v43;
    v20 = 0;
    v42 = 0;
    if ( !v43 )
      goto LABEL_24;
    v21 = (int)v45;
    v34 = (unsigned int)v45;
    v22 = (unsigned __int8 *)&v45[2 * v43 + 2];
    while ( 1 )
    {
      v23 = *v22;
      v22 += 2;
      v47 = v22;
      if ( v23 == v12 )
        break;
LABEL_21:
      ++v20;
      v21 += 8;
      v42 = v20;
      v34 = v21;
      if ( v20 >= v19 )
        goto LABEL_22;
    }
    v24 = *(_DWORD *)(v21 + 12);
    v25 = *(_DWORD *)(v21 + 8) - 1;
    v26 = MmPfnDatabase + 24 * v25;
    if ( !v24 )
    {
LABEL_19:
      v4 = v41;
      if ( v41 < 0 )
        goto LABEL_22;
      v12 = v36;
      v22 = v47;
      goto LABEL_21;
    }
    while ( (!a2 || !*(_DWORD *)(a2 + 4)) && (*(_DWORD *)(v9 + 960) & 1) == 0 )
    {
      v26 += 24;
      ++v25;
      for ( ; (*(_BYTE *)(v26 + 18) & 7u) <= 1; v25 += v33 )
      {
        if ( (*(_DWORD *)(v26 + 20) & 0xFFFFF) != v50 )
          break;
        v33 = 1024 - (v25 & 0x3FF);
        if ( v33 >= v24 )
          goto LABEL_18;
        v26 += 24 * v33;
        v24 -= v33;
      }
      if ( MiCombineCandidate(a1, v26) )
      {
        v28 = v35;
        if ( !v35 )
        {
          v28 = MiReservePtes(&dword_634D58, 1u);
          v35 = v28;
          if ( !v28 )
          {
            v4 = -1073741670;
            goto LABEL_47;
          }
        }
        v29 = v37;
        *(_DWORD *)(v37 + 32) = v26;
        *(_DWORD *)(v29 + 36) = v28;
        if ( MiMapArbitraryPage((int)a1, v29, 0, 0) )
        {
          if ( (*(_BYTE *)(v26 + 18) & 7) == 6 )
            ++*(_DWORD *)(v39 + 8);
          else
            ++*(_DWORD *)(v39 + 12);
          v30 = MiPerformCombineScan();
          MiReleaseArbitraryPage(v37);
          MiReleasePtes(&dword_634D58, v35, 1u);
          v31 = v30 == 1;
          v16 = v38;
          v35 = 0;
          if ( v31 )
          {
            *(_DWORD *)(v38 + 12) = 0;
            *(_DWORD *)(v16 + 16) = 0;
            v32 = v49;
            *(_DWORD *)(v16 + 8) = v25;
            v16 += 24;
            v38 = v16;
            if ( v16 == v32 )
            {
              MiProcessCrcList(a1, v40, (v16 - v40) / 24, v36, v37, a2, v39);
              v16 = v40;
              v38 = v40;
            }
          }
        }
      }
      if ( !--v24 )
      {
LABEL_18:
        v20 = v42;
        v19 = v43;
        v21 = v34;
        goto LABEL_19;
      }
    }
    v4 = -1073741248;
LABEL_47:
    v41 = v4;
LABEL_22:
    v15 = v40;
    v12 = v36;
    if ( v16 != v40 )
      MiProcessCrcList(a1, v40, (v16 - v40) / 24, v36, v37, a2, v39);
LABEL_24:
    ExFreePoolWithTag(v15, 0);
    if ( v4 < 0 )
      break;
    ++v12;
    v13 = v46 + 104;
    v8 = v48;
    v36 = v12;
    v46 += 104;
  }
  while ( v12 != (unsigned __int16)KeNumberNodes );
  v27 = v35;
  if ( v35 )
    MiReleasePtes(&dword_634D58, v35, 1u);
  if ( v44 == 1 )
    KeRevertToUserGroupAffinityThread((int)v52, v27, v13, 1);
LABEL_30:
  MiDereferencePageRuns((int)v45);
  return v4;
}
