// PfSnPrefetchSections 
 
int __fastcall PfSnPrefetchSections(_DWORD *a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r9
  _DWORD *v6; // r7
  unsigned int v7; // r5
  int v8; // r10
  char v10; // r4
  unsigned int v11; // r5
  int v12; // r8
  int v13; // r6
  int v14; // r7
  int v15; // r10
  unsigned int v16; // r1
  int v17; // r4
  unsigned int v18; // r3
  int v19; // r2
  unsigned int v20; // r4
  unsigned int v21; // r1
  unsigned int v22; // r0
  char v23; // [sp+Ch] [bp-17Ch] BYREF
  int v24; // [sp+10h] [bp-178h]
  int v25; // [sp+14h] [bp-174h] BYREF
  int v26; // [sp+18h] [bp-170h]
  unsigned int v27; // [sp+1Ch] [bp-16Ch]
  int v28; // [sp+20h] [bp-168h]
  _DWORD *v29; // [sp+24h] [bp-164h] BYREF
  _BYTE *v30; // [sp+28h] [bp-160h]
  unsigned int v31; // [sp+2Ch] [bp-15Ch] BYREF
  _DWORD v32[4]; // [sp+30h] [bp-158h] BYREF
  unsigned int v33[8]; // [sp+40h] [bp-148h] BYREF
  int v34[2]; // [sp+60h] [bp-128h] BYREF
  char v35[64]; // [sp+68h] [bp-120h] BYREF
  int *v36; // [sp+A8h] [bp-E0h]
  int v37; // [sp+ACh] [bp-DCh]
  int v38; // [sp+B0h] [bp-D8h]
  int v39; // [sp+B4h] [bp-D4h]
  _DWORD *v40; // [sp+B8h] [bp-D0h]
  int v41; // [sp+BCh] [bp-CCh]
  int v42; // [sp+C0h] [bp-C8h]
  int v43; // [sp+C4h] [bp-C4h]
  char *v44; // [sp+C8h] [bp-C0h]
  int v45; // [sp+CCh] [bp-BCh]
  int v46; // [sp+D0h] [bp-B8h]
  int v47; // [sp+D4h] [bp-B4h]
  int *v48; // [sp+D8h] [bp-B0h]
  int v49; // [sp+DCh] [bp-ACh]
  int v50; // [sp+E0h] [bp-A8h]
  int v51; // [sp+E4h] [bp-A4h]
  int *v52; // [sp+E8h] [bp-A0h]
  int v53; // [sp+ECh] [bp-9Ch]
  int v54; // [sp+F0h] [bp-98h]
  int v55; // [sp+F4h] [bp-94h]

  v5 = *a1;
  v6 = a1;
  v26 = a3;
  v27 = a5;
  v7 = 0;
  v28 = 0;
  v29 = a1;
  v8 = a2;
  v24 = a2;
  v25 = a2;
  v32[1] = a3;
  if ( v5 && qword_637408 && EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_PrefetchSections_Start) )
    return sub_80901C();
  if ( v26 >= 1 << *(_DWORD *)(*v6 + 124) )
    goto LABEL_37;
  if ( !v8 )
  {
    v10 = 0;
    goto LABEL_9;
  }
  if ( v8 != 1 )
  {
LABEL_37:
    v17 = -1073741811;
    goto LABEL_29;
  }
  v10 = 1;
LABEL_9:
  v11 = *(_DWORD *)(v5 + 88);
  v30 = (_BYTE *)v6[27];
  memset(v30, 0, 4 * v11);
  v12 = v6[30];
  memset((_BYTE *)v12, 0, 896);
  memset(v33, 0, sizeof(v33));
  v33[0] = 0;
  v33[1] = (unsigned int)v6;
  v33[5] = v11;
  v33[2] = v27;
  v24 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( v11 > 0x20 )
    v11 = 32;
  PfSnLogGetReadListsStart(v5, v11);
  if ( v11 )
  {
    v13 = v26;
    v14 = v24;
    v15 = v10 & 1;
    do
    {
      *(_DWORD *)(v12 + 16) = v33;
      *(_DWORD *)(v12 + 20) = v13;
      *(_DWORD *)(v12 + 24) = *(_DWORD *)(v12 + 24) & 0xFFFFFFFE | v15;
      *(_DWORD *)(v12 + 8) = PfSnPopulateReadList;
      *(_DWORD *)(v12 + 12) = v12;
      *(_DWORD *)v12 = 0;
      v12 += 28;
      __pld(v33);
      v20 = v33[0] & 0xFFFFFFFE;
      v21 = (v33[0] & 0xFFFFFFFE) + 2;
      do
        v22 = __ldrex(v33);
      while ( v22 == v20 && __strex(v21, v33) );
      __dmb(0xBu);
      if ( v22 != v20 )
        ExfAcquireRundownProtection(v33);
      ExQueueWorkItem((_DWORD *)(v12 - 28), v14 + 32);
      --v11;
    }
    while ( v11 );
    v6 = v29;
    v8 = v25;
  }
  do
    v16 = __ldrex(v33);
  while ( !v16 && __strex(1u, v33) );
  __dmb(0xBu);
  if ( v16 && v16 != 1 )
    ExfWaitForRundownProtectionRelease(v33, v16);
  PfSnLogGetReadListsStop(v5);
  v7 = v33[3];
  __dmb(0xBu);
  v17 = v33[7];
  if ( (v33[7] & 0x80000000) != 0 )
    goto LABEL_25;
  v18 = v33[6];
  v28 = v33[6];
  __dmb(0xBu);
  if ( v7 )
  {
    if ( v18 )
    {
      v17 = MmPrefetchPagesEx(v7, (int)v30, v6 + 33);
      if ( v17 >= 0 && !v6[33] )
        v17 = -2147483622;
    }
    else
    {
      v17 = -1073741823;
    }
LABEL_25:
    if ( v7 )
    {
      if ( v7 > 0x20 )
        v19 = 32;
      else
        v19 = v7;
      PfSnPrefetchSectionsCleanup((unsigned int)v6, v7, v19, v27);
    }
    goto LABEL_29;
  }
  v17 = 0;
LABEL_29:
  v23 = 0;
  v31 = v7;
  v32[0] = v8;
  v25 = v26;
  v34[0] = v28;
  v34[1] = 0;
  if ( v5 && qword_637408 )
  {
    if ( EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_PrefetchSections_Stop) )
    {
      PfSnBuildScenarioEventDescriptors(v5 + 16, v5 + 80, &v29, v35);
      v36 = &v25;
      v37 = 0;
      v38 = 4;
      v39 = 0;
      v40 = v32;
      v41 = 0;
      v42 = 4;
      v43 = 0;
      v44 = &v23;
      v45 = 0;
      v46 = 1;
      v47 = 0;
      v48 = v34;
      v49 = 0;
      v50 = 8;
      v51 = 0;
      v52 = (int *)&v31;
      v53 = 0;
      v54 = 4;
      v55 = 0;
      EtwWrite(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_PrefetchSections_Stop, 0);
    }
  }
  return v17;
}
