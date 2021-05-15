// -SmProcessAddCompletion@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAU_SM_WORK_ITEM@1@KPAU-$SMKM_STORE@USM_TRAITS@@@@J@Z 
 
__int64 __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmProcessAddCompletion(__int64 a1, int a2, _DWORD *a3, int a4)
{
  int *v4; // r5
  int v5; // r6
  int v6; // r9
  int v8; // r4
  int v9; // r1
  int v10; // r8
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a2;
  v13[1] = (int)a3;
  v4 = *(int **)(HIDWORD(a1) + 24);
  v5 = *(_DWORD *)(HIDWORD(a1) + 12);
  v6 = a3[878];
  v8 = (*(_DWORD *)(HIDWORD(a1) + 4) >> 3) & 0x7FFFFFF;
  v9 = a4;
  v10 = a1;
  *v4 = a4;
  if ( a4 >= 0 && (*a3 & 0x100) != 0 )
    v4[1] |= 1u;
  if ( v8 )
  {
    v13[0] = v5;
    SMKM_STORE_MGR<SM_TRAITS>::SmFeAddComplete(a1, v13, v8, v6 & 0x1F, a4 >= 0);
    v9 = -1073741823;
  }
  if ( v8 != a2 )
  {
    v13[0] = v5 + v8;
    SMKM_STORE_MGR<SM_TRAITS>::SmFeAddComplete(v10, v13, a2 - v8, v6 & 0x1F, v9 >= 0);
  }
  return a1;
}
