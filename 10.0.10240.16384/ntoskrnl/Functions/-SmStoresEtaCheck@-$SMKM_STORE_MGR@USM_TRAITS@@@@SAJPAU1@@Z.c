// -SmStoresEtaCheck@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoresEtaCheck(int a1)
{
  unsigned int v1; // r5
  int v2; // r8
  int v3; // r7
  unsigned int v4; // r9
  int v5; // r4
  unsigned int *v6; // r6
  unsigned int v7; // r0
  unsigned int v8; // r1
  int v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r1
  unsigned int *v12; // r0
  unsigned int *v13; // r6
  _DWORD *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  int v17; // r5
  _DWORD *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1

  v1 = 0;
  v2 = a1;
  v3 = a1;
  while ( 1 )
  {
    v4 = v1 | (32 * (*(_WORD *)(v3 + 12) & 0x7FF));
    v5 = v2 + 96 * (v4 & 0x1F);
    v6 = (unsigned int *)(v5 + 4);
    __pld((void *)(v5 + 4));
    v7 = *(_DWORD *)(v5 + 4) & 0xFFFFFFFE;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 2, v6) );
    __dmb(0xBu);
    if ( v8 == v7 || ExfAcquireRundownProtection((_DWORD *)(v5 + 4)) )
    {
      if ( (*(_WORD *)(v5 + 12) & 0x7FF) == v4 >> 5 )
      {
        v9 = *(_DWORD *)v5;
        goto LABEL_15;
      }
      __pld(v6);
      v10 = *v6 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v11 = __ldrex(v6);
      while ( v11 == v10 && __strex(v10 - 2, v6) );
      if ( v11 != v10 )
        ExfReleaseRundownProtection((unsigned __int8 *)v6);
    }
    v9 = 0;
LABEL_15:
    if ( v9 )
      break;
LABEL_25:
    ++v1;
    v3 += 96;
    if ( v1 >= 0x20 )
    {
      v17 = 0;
      goto LABEL_27;
    }
  }
  if ( !StEtaCheckForRefresh(*(_DWORD *)(v9 + 1592), 0, 0, 0) )
  {
    v14 = (_DWORD *)(v2 + 96 * (*(_DWORD *)(v9 + 3512) & 0x1F) + 4);
    __pld(v14);
    v15 = *v14 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v14);
    goto LABEL_24;
  }
  v12 = (unsigned int *)ExAllocatePoolWithTag(512, 32);
  v13 = v12;
  if ( v12 )
  {
    memset(v12, 0, 32);
    *v13 = *v13 & 0xFFFFFFF8 | 5;
    v13[1] &= 0xFFFFFFF8;
    v13[6] = 0;
    SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(v9, (int)v13, 0);
LABEL_24:
    v9 = 0;
    goto LABEL_25;
  }
  v17 = -1073741670;
LABEL_27:
  if ( v9 )
  {
    v18 = (_DWORD *)(v2 + 96 * (*(_DWORD *)(v9 + 3512) & 0x1F) + 4);
    __pld(v18);
    v19 = *v18 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v20 = __ldrex(v18);
    while ( v20 == v19 && __strex(v19 - 2, v18) );
    if ( v20 != v19 )
      ExfReleaseRundownProtection((unsigned __int8 *)v18);
  }
  return v17;
}
