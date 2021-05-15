// -SmPerformStoreMaintenance@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAJPAU1@PAU-$SMKM_STORE@USM_TRAITS@@@@W4_ST_MAINTENANCE_TYPE@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmPerformStoreMaintenance(int a1, int a2, char a3)
{
  unsigned int *v6; // r0
  unsigned int *v7; // r5
  int v8; // r4
  int v10; // [sp+8h] [bp-28h] BYREF
  char v11[4]; // [sp+10h] [bp-20h] BYREF
  int v12; // [sp+14h] [bp-1Ch]
  int v13[6]; // [sp+18h] [bp-18h] BYREF

  v6 = (unsigned int *)ExAllocatePoolWithTag(512, 32);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 32);
  *v7 = *v7 & 0xFFFFFFF8 | 5;
  v7[1] = v7[1] & 0xFFFFFFF8 | a3 & 7;
  v11[0] = 0;
  v11[1] = 0;
  v11[2] = 4;
  v12 = 0;
  v13[1] = (int)v13;
  v13[0] = (int)v13;
  v8 = SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequest(a1, *(_DWORD *)(a2 + 3512), v7, v11, &v10);
  if ( v8 >= 0 )
  {
    v7 = 0;
    KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
    v8 = v10;
    if ( v10 < 0 )
      return v8;
    v8 = 0;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
