// -SmHighMemPriorityWatchdogWorker@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAX@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmHighMemPriorityWatchdogWorker(int a1)
{
  unsigned int v1; // r6
  int v2; // r5
  char *v3; // r8
  int v4; // r9
  unsigned int v5; // r10
  int *v6; // r4
  unsigned int *v7; // r7
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r4
  unsigned int v12; // r1
  _DWORD *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r6
  unsigned int v17; // r4
  char *v18; // r7
  int v19; // r8
  int v20; // t1
  unsigned __int64 v21; // kr00_8
  unsigned int v22; // r3
  int v23; // r4
  unsigned int v24; // r7
  char *v25; // r9
  int v26; // r6
  int v27; // t1
  int v28; // r8
  unsigned int v29; // r0
  char *v30; // r6
  int v31; // t1
  _DWORD *v32; // r0
  unsigned int v33; // r4
  unsigned int v34; // r1
  int result; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r1
  int v38; // [sp+0h] [bp-A8h]
  char v40[160]; // [sp+8h] [bp-A0h] BYREF

  v1 = 0;
  v2 = 0;
  v3 = v40;
  v38 = a1 - 5872;
  v4 = a1 - 5872;
  do
  {
    v5 = v1 | (32 * (*(_WORD *)(v4 + 12) & 0x7FF));
    v6 = (int *)(v38 + 96 * (v5 & 0x1F));
    v7 = (unsigned int *)(v6 + 1);
    __pld(v6 + 1);
    v8 = v6[1] & 0xFFFFFFFE;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 2, v7) );
    __dmb(0xBu);
    if ( v9 == v8 || ExfAcquireRundownProtection(v6 + 1) )
    {
      if ( (v6[3] & 0x7FF) == v5 >> 5 )
      {
        v10 = *v6;
        goto LABEL_15;
      }
      __pld(v7);
      v11 = *v7 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v12 = __ldrex(v7);
      while ( v12 == v11 && __strex(v11 - 2, v7) );
      if ( v12 != v11 )
        ExfReleaseRundownProtection((unsigned __int8 *)v7);
    }
    v10 = 0;
LABEL_15:
    if ( v10 )
    {
      if ( *(_BYTE *)(v10 + 3519) )
      {
        *(_DWORD *)v3 = v1;
        v3 += 4;
        ++v2;
      }
      else
      {
        v13 = (_DWORD *)(v38 + 96 * (v1 & 0x1F) + 4);
        __pld(v13);
        v14 = *v13 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v15 = __ldrex(v13);
        while ( v15 == v14 && __strex(v14 - 2, v13) );
        if ( v15 != v14 )
          ExfReleaseRundownProtection((unsigned __int8 *)v13);
      }
    }
    ++v1;
    v4 += 96;
  }
  while ( v1 < 0x20 );
  if ( v2 )
  {
    v16 = 0;
    v17 = 0;
    v18 = v40;
    v19 = v2;
    do
    {
      v20 = *(_DWORD *)v18;
      v18 += 4;
      v21 = __PAIR64__(v17, v16)
          + (unsigned int)SMKM_STORE<SM_TRAITS>::SmStGetDataInUseKb(*(_DWORD *)(96 * (v20 & 0x1F) + v38));
      v17 = HIDWORD(v21);
      v16 = v21;
      --v19;
    }
    while ( v19 );
    v22 = 4 * (MEMORY[0xFFFF92E8] / 0x14u);
    if ( v22 >= 0x7D000 )
      v22 = 512000;
    if ( v21 >= v22 )
    {
      v23 = 0;
      v24 = 0;
      v25 = v40;
      v26 = v2;
      do
      {
        v27 = *(_DWORD *)v25;
        v25 += 4;
        v28 = *(_DWORD *)(96 * (v27 & 0x1F) + v38);
        v29 = SMKM_STORE<SM_TRAITS>::SmStGetDataInUseKb(v28);
        if ( v24 <= v29 )
        {
          v24 = v29;
          v23 = v28;
        }
        --v26;
      }
      while ( v26 );
      SMKM_STORE<SM_TRAITS>::SmStPrioritizeRegionsStore(v23, 0);
    }
    v30 = v40;
    do
    {
      v31 = *(_DWORD *)v30;
      v30 += 4;
      v32 = (_DWORD *)(v38 + 96 * (v31 & 0x1F) + 4);
      __pld(v32);
      v33 = *v32 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v34 = __ldrex(v32);
      while ( v34 == v33 && __strex(v33 - 2, v32) );
      if ( v34 != v33 )
        ExfReleaseRundownProtection((unsigned __int8 *)v32);
      --v2;
    }
    while ( v2 );
  }
  __dmb(0xBu);
  result = 0;
  v36 = (unsigned int *)(a1 + 12);
  do
    v37 = __ldrex(v36);
  while ( __strex(0, v36) );
  __dmb(0xBu);
  return result;
}
