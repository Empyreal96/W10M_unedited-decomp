// -SmStoreRequest@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@KPAU_SM_WORK_ITEM@1@PAU_KEVENT@@PAU_IO_STATUS_BLOCK@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequest(int a1, unsigned int a2)
{
  int *v2; // r8
  unsigned int *v3; // r7
  unsigned int v5; // r6
  unsigned int v6; // r5
  int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r1
  int v10; // r5
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1

  v2 = (int *)(a1 + 96 * (a2 & 0x1F));
  v3 = (unsigned int *)(v2 + 1);
  __pld(v2 + 1);
  v5 = v2[1] & 0xFFFFFFFE;
  do
    v6 = __ldrex(v3);
  while ( v6 == v5 && __strex(v5 + 2, v3) );
  __dmb(0xBu);
  if ( v6 == v5 || ExfAcquireRundownProtection(v2 + 1) )
  {
    if ( (v2[3] & 0x7FF) == a2 >> 5 )
    {
      v7 = *v2;
      goto LABEL_14;
    }
    __pld(v3);
    v8 = *v3 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v3);
    while ( v9 == v8 && __strex(v8 - 2, v3) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)v2 + 4);
  }
  v7 = 0;
LABEL_14:
  if ( !v7 )
    return -1073741811;
  v10 = SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequestEx();
  if ( v10 >= 0 )
    v7 = 0;
  if ( v7 )
  {
    v11 = (unsigned int *)(v2 + 1);
    __pld(v2 + 1);
    v12 = v2[1] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v13 = __ldrex(v11);
    while ( v13 == v12 && __strex(v12 - 2, v11) );
    if ( v13 != v12 )
      ExfReleaseRundownProtection((unsigned __int8 *)v11);
  }
  return v10;
}
