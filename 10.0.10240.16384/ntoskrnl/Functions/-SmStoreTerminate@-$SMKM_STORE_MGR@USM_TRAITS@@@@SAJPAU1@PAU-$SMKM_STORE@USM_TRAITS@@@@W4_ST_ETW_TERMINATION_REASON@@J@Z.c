// -SmStoreTerminate@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@W4_ST_ETW_TERMINATION_REASON@@J@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreTerminate(int a1, int a2, int a3, int a4)
{
  int v7; // r5
  int v8; // r4
  unsigned int v9; // r7
  int *v10; // r4
  unsigned int *v11; // r6
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  unsigned int v15; // r4
  unsigned int v16; // r1
  int v17; // r3

  v7 = ExAllocatePoolWithTag(512, 40);
  if ( !v7 )
    return -1073741670;
  v9 = *(_DWORD *)(a2 + 3512);
  v10 = (int *)(a1 + 96 * (v9 & 0x1F));
  v11 = (unsigned int *)(v10 + 1);
  __pld(v10 + 1);
  v12 = v10[1] & 0xFFFFFFFE;
  do
    v13 = __ldrex(v11);
  while ( v13 == v12 && __strex(v12 + 2, v11) );
  __dmb(0xBu);
  if ( v13 != v12 && !ExfAcquireRundownProtection(v10 + 1) )
    goto LABEL_15;
  if ( (v10[3] & 0x7FF) != v9 >> 5 )
  {
    __pld(v11);
    v15 = *v11 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v11);
    while ( v16 == v15 && __strex(v15 - 2, v11) );
    if ( v16 != v15 )
      ExfReleaseRundownProtection((unsigned __int8 *)v11);
LABEL_15:
    v14 = 0;
    goto LABEL_16;
  }
  v14 = *v10;
LABEL_16:
  if ( v14 )
  {
    memset((_BYTE *)v7, 0, 40);
    *(_DWORD *)(v7 + 8) = SmKmStoreTerminateWorker;
    *(_DWORD *)(v7 + 12) = v7;
    *(_DWORD *)v7 = 0;
    *(_DWORD *)(v7 + 16) = a1;
    *(_DWORD *)(v7 + 20) = a2 + 3660;
    *(_DWORD *)(v7 + 24) = *(_DWORD *)(a2 + 3512);
    v17 = *(_DWORD *)(a1 + 5888);
    *(_DWORD *)(v7 + 36) = a4;
    *(_DWORD *)(v7 + 28) = (v17 & 1) != 0;
    *(_DWORD *)(v7 + 32) = a3;
    ExQueueWorkItem((_DWORD *)v7, 0);
    v7 = 0;
    v8 = 0;
  }
  else
  {
    v8 = -1073741431;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
