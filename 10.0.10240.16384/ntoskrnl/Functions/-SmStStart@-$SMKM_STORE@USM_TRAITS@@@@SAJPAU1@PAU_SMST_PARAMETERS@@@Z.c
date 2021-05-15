// -SmStStart@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@PAU_SMST_PARAMETERS@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStStart(int a1, int **a2)
{
  int *v3; // r6
  int v5; // r2
  unsigned int v6; // r3
  int v7; // r1
  int result; // r0
  int *v9; // r3
  volatile int v10; // r3
  __int16 v11; // r2
  _BYTE *v12; // r0
  int v13; // r4
  int v14; // r8
  _BYTE *v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  unsigned int v20; // [sp+0h] [bp-50h] BYREF
  int v21[18]; // [sp+8h] [bp-48h] BYREF

  v3 = *a2;
  v5 = **a2;
  if ( (unsigned __int8)v5 >= 2u )
    return -1073741811;
  if ( v3[5] )
    return -1073741811;
  v6 = v3[3];
  if ( !v6 )
    return -1073741811;
  if ( v6 > 0x40000 )
    return -1073741811;
  v7 = v3[2];
  if ( !v7 || ((v7 - 1) & v7) != 0 )
    return -1073741811;
  if ( (unsigned __int8)v5 == 1 )
    return sub_5111F0();
  if ( (v5 & 0x20000) != 0 && (v5 & 0x40000) == 0 )
    return -1073741811;
  *(_DWORD *)(a1 + 3944) = a2[4];
  v9 = a2[5];
  *(_DWORD *)(a1 + 3948) = v9;
  if ( !v9 )
  {
    v10 = SmStNormalPriority;
    __dmb(0xBu);
    *(_DWORD *)(a1 + 3948) = v10;
  }
  *(_BYTE *)(a1 + 3516) = *v3;
  v11 = (*(unsigned __int8 *)(a1 + 3517) ^ *((_WORD *)v3 + 1)) & 4 ^ *(unsigned __int8 *)(a1 + 3517);
  *(_BYTE *)(a1 + 3517) = v11;
  *(_BYTE *)(a1 + 3517) = (v11 ^ ((unsigned int)*v3 >> 14)) & 8 ^ v11;
  *(_DWORD *)(a1 + 3652) = v3[2];
  if ( *(_BYTE *)v3 )
  {
    SmKmFileInfoInit(a1 + 3660);
    *(_DWORD *)(a1 + 3656) = v3[3];
    v14 = v3[6];
    result = SmKmFileInfoDuplicate(a1 + 3660, v3[9]);
LABEL_36:
    if ( result < 0 )
      return result;
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(a1 + 3517) & 4) != 0 )
  {
    SmKmStoreHelperInitialize(a1 + 3668);
    SmKmStoreHelperInitialize(a1 + 3740);
    SMKM_STORE<SM_TRAITS>::SmStReadThreadCtxInitialize(a1 + 3812);
    result = SmKmStoreHelperStart(a1 + 3668);
    if ( result < 0 )
      return result;
    result = SmKmStoreHelperStart(a1 + 3740);
    if ( result < 0 )
      return result;
    if ( (*(_BYTE *)(a1 + 3517) & 8) != 0 )
      *(_DWORD *)(a1 + 3732) = &unk_636E00;
    *(_DWORD *)(a1 + 3808) = &unk_636E0C;
    v12 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 1817341299);
    *(_DWORD *)(a1 + 3664) = v12;
    if ( !v12 )
      return -1073741670;
    memset(v12, 0, 40);
    if ( !SmAcquireReleaseCharges(*(_DWORD *)(a1 + 3652), 1, 0) )
      return -1073741670;
    *(_BYTE *)(a1 + 3517) |= 0x10u;
  }
  v13 = v3[3];
  v14 = 0;
  *(_DWORD *)(a1 + 3656) = v13;
  v15 = (_BYTE *)ExAllocatePoolWithTag(512, 4 * v13, 1733455219);
  if ( !v15 )
    return -1073741670;
  *(_DWORD *)(a1 + 3660) = v15;
  memset(v15, 0, 4 * v13);
  if ( (*(_BYTE *)(a1 + 3517) & 4) == 0 )
  {
    v20 = (*(_DWORD *)(a1 + 3652) & 0xFFFF000 | 0x10000400u) >> 8;
    result = SmFpPreAllocate(a1 + 3880, &v20, 1);
    goto LABEL_36;
  }
LABEL_23:
  memset(v21, 0, 40);
  v16 = v3[1];
  v17 = v3[2];
  v18 = v3[3];
  v21[0] = *v3;
  v21[1] = v16;
  v21[2] = v17;
  v21[3] = v18;
  v21[3] = *(_DWORD *)(a1 + 3656);
  v21[4] = v14;
  v19 = (int)a2[3];
  v21[5] = a1;
  v21[8] = v19;
  if ( *(_BYTE *)v3 )
    v21[9] = v3[11];
  v21[6] = (int)a2[1];
  v21[7] = (int)a2[2];
  v21[0] ^= (LOWORD(v21[0]) ^ ((v21[7] == 0) << 11)) & 0x800;
  result = ST_STORE<SM_TRAITS>::StStart(a1, v21);
  if ( result >= 0 )
  {
    if ( (*(_BYTE *)(a1 + 3517) & 4) == 0
      || (result = SMKM_STORE<SM_TRAITS>::SmStWorkerThreadStartThread(
                     a1,
                     SMKM_STORE<SM_TRAITS>::SmStReadThread,
                     a1 + 3812),
          result >= 0) )
    {
      result = SMKM_STORE<SM_TRAITS>::SmStWorkerThreadStartThread(
                 a1,
                 SMKM_STORE<SM_TRAITS>::SmStWorkerThread,
                 a1 + 3648);
      if ( result >= 0 )
        result = 0;
    }
  }
  return result;
}
