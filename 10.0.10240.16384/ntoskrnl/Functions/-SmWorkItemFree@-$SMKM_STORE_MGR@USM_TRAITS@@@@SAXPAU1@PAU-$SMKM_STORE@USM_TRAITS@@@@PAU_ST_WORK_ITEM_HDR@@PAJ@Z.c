// -SmWorkItemFree@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@PAU_ST_WORK_ITEM_HDR@@PAJ@Z 
 
unsigned __int8 *__fastcall SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFree(int a1, int a2, _DWORD *a3, int *a4)
{
  int v5; // r0
  unsigned int v6; // r6
  int v8; // r1
  int v9; // r7
  int v10; // r9
  int v12; // r4
  int v13; // r5
  int v14; // r6
  int v15; // r4
  int v16; // r5
  int v17; // r6
  int v18; // r4
  _DWORD *v19; // r0
  int v20; // r3
  unsigned __int8 *result; // r0
  unsigned int v22; // r4
  unsigned int v23; // r1
  int v24; // [sp+0h] [bp-48h]
  unsigned int v25; // [sp+4h] [bp-44h]
  _DWORD v26[16]; // [sp+8h] [bp-40h] BYREF

  v5 = *a3;
  v6 = a3[6];
  v8 = 7;
  v9 = 1;
  v10 = v5 & 7;
  v24 = a2;
  v25 = v6;
  if ( a4 )
  {
    v12 = a3[1];
    v13 = a3[2];
    v14 = a3[3];
    v26[0] = *a3;
    v26[1] = v12;
    v26[2] = v13;
    v26[3] = v14;
    v15 = a3[5];
    v16 = a3[6];
    v17 = a3[7];
    v26[4] = a3[4];
    v26[5] = v15;
    v26[6] = v16;
    v26[7] = v17;
    v6 = v25;
    v9 = 1;
  }
  if ( (v5 & 7u) < 4 )
  {
    if ( v10 == 2 && (a3[1] & 0x4000000) != 0 )
    {
      if ( (unsigned __int16)word_636B94 >= 0x1000u )
        ExFreePoolWithTag(a3);
      else
        RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_636B90, a3);
    }
    else
    {
      SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource((int)SmGlobals, a3, v6);
      if ( v10 == 1 )
      {
        v18 = 1;
        goto LABEL_16;
      }
    }
    v18 = 0;
LABEL_16:
    a2 = v24;
    goto LABEL_24;
  }
  if ( v10 == 5 )
  {
    v19 = a3;
    if ( (a3[1] & 7) != 0 )
    {
      v18 = 0;
      ExFreePoolWithTag(a3);
      goto LABEL_16;
    }
LABEL_14:
    ExFreePoolWithTag(v19);
LABEL_31:
    result = (unsigned __int8 *)&SmGlobals[24 * (*(_DWORD *)(v24 + 3512) & 0x1F) + 1];
    __pld(result);
    v22 = *(_DWORD *)result & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)result);
    while ( v23 == v22 && __strex(v22 - 2, (unsigned int *)result) );
    if ( v23 != v22 )
      result = ExfReleaseRundownProtection(result);
    return result;
  }
  v18 = 0;
  v20 = a3[1] & 7;
  if ( v20 )
  {
    if ( v20 == 3 )
    {
      v19 = a3;
      goto LABEL_14;
    }
    if ( v20 == 1 || v20 == 2 )
      v9 = 0;
  }
  else
  {
    a3[6] = 0;
  }
LABEL_24:
  if ( a4 )
    result = (unsigned __int8 *)SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxWorkItemComplete(v26, v8, a2, *a4);
  else
    result = (unsigned __int8 *)1;
  if ( result && v18 )
    result = (unsigned __int8 *)SmFpFree((int)&unk_636B98, 0, v6, v6);
  if ( v9 )
    goto LABEL_31;
  return result;
}
