// -StDmStart@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_DATA_MGR@1@PAU_STDM_PARAMETERS@@PAU_RTL_BITMAP@@PAKK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmStart(int a1, int a2, _DWORD *a3, unsigned int *a4, unsigned int *a5, int a6)
{
  unsigned int *v6; // r8
  int v7; // r7
  _DWORD *v8; // r10
  unsigned int v10; // r6
  int v11; // r2
  int result; // r0
  int v13; // r0
  int v14; // r3
  int v15; // r4
  int v16; // r3
  unsigned int v17; // r8
  int i; // r9
  unsigned int v19; // lr
  unsigned int v20; // r0
  unsigned int v21; // r10
  unsigned int v22; // r1
  _DWORD *v23; // r4
  int j; // r3
  unsigned int v25; // r1
  unsigned int v26; // r9
  _BYTE *v27; // r0
  _BYTE *v28; // r8
  int v29; // r0
  int v30; // r8
  int v31; // r9
  _BYTE *v32; // r0
  _BYTE *v33; // r4
  int v34; // r0
  int v35; // r8
  _BYTE *v36; // r0
  _BYTE *v37; // r4
  unsigned int v38; // r3
  int v40[8]; // [sp+8h] [bp-78h] BYREF
  _DWORD *v41; // [sp+28h] [bp-58h]
  int v42; // [sp+2Ch] [bp-54h]
  unsigned int v43; // [sp+3Ch] [bp-44h]

  v6 = a5;
  v7 = a1;
  v8 = a3;
  v41 = a3;
  v42 = a1;
  v10 = -1;
  memmove(a2 + 72, a1, 0x2Cu);
  v11 = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(a2 + 116) = *v8;
  *(_DWORD *)(a2 + 240) = *(_DWORD *)(v7 + 1648);
  *(_DWORD *)(a2 + 764) = v7 + 3272;
  *(_DWORD *)(a2 + 276) = *(_DWORD *)(v7 + 1592);
  *(_DWORD *)(a2 + 288) = v7 + 1672;
  *(_DWORD *)(a2 + 664) = *(_DWORD *)(v7 + 1768);
  *(_DWORD *)(a2 + 760) = v7 + 3280;
  if ( (unsigned __int8)v11 == 1 )
    return sub_510AF4();
  *(_WORD *)(a2 + 272) = *(_WORD *)(v7 + 1656);
  *(_DWORD *)(a2 + 248) = *(_DWORD *)(a2 + 240);
  *(_DWORD *)(a2 + 252) = a2 + 12;
  *(_DWORD *)(a2 + 256) = a2 + 48;
  if ( (unsigned __int8)v11 == 1 || (v11 & 0x40000) != 0 )
  {
    v13 = ExAllocatePoolWithTag(512, 4 * ((unsigned int)(*(_DWORD *)(v7 + 12) + 31) >> 5), 1951624563);
    if ( !v13 )
      return -1073741670;
    *(_DWORD *)(a2 + 120) = *(_DWORD *)(v7 + 12);
    *(_DWORD *)(a2 + 124) = v13;
  }
  v14 = *(_DWORD *)(a2 + 72);
  v15 = a6;
  if ( (v14 & 0x40000) != 0 )
  {
    RtlSetAllBits(a2 + 120);
    goto LABEL_9;
  }
  if ( (unsigned __int8)v14 == 1 )
  {
    RtlClearAllBits(a2 + 120);
    v17 = *a5;
    v10 = -1;
    for ( i = a6; i; --i )
    {
      v19 = *a4;
      if ( v17 < *a4 )
        v20 = v17;
      else
        v20 = 0;
      v21 = a4[1];
      v22 = v19 - 1;
      while ( 1 )
      {
        if ( v22 - v20 == -1 )
          goto LABEL_29;
        v23 = (_DWORD *)(v21 + 4 * (v20 >> 5));
        for ( j = ~*v23 | ((1 << (v20 & 0x1F)) - 1); j == -1; j = ~*v23 )
        {
          if ( (unsigned int)++v23 > v21 + 4 * (v22 >> 5) )
            goto LABEL_29;
        }
        v10 = __clz(__rbit(~j)) + 32 * ((int)((int)v23 - v21) >> 2);
        if ( v10 > v22 )
        {
LABEL_29:
          v10 = -1;
        }
        else if ( v10 != -1 )
        {
          break;
        }
        if ( !v20 )
          break;
        v25 = v17 + 1;
        if ( v17 + 1 > v19 )
          v25 = *a4;
        v22 = v25 - 1;
        v20 = 0;
      }
      v17 = v10 + 1;
      *(_BYTE *)((v10 >> 3) + *(_DWORD *)(a2 + 124)) |= 1 << (v10 & 7);
    }
    v8 = v41;
    v7 = v42;
    if ( (*v41 & 2) == 0 )
      goto LABEL_45;
    v26 = (unsigned int)(*(_DWORD *)(a2 + 112) + 4111) >> 4;
    v27 = (_BYTE *)ExAllocatePoolWithTag(512, 16 * v26, 1951624563);
    v28 = v27;
    if ( v27 )
    {
      memset(v27, 0, 16 * v26);
      v29 = *(_DWORD *)(a2 + 88);
      *(_DWORD *)(a2 + 668) = v28;
      v30 = ((v29 - 1) & 0xFFF0) - ((((v29 - 1) & 0xFFF0) + v29 + 4111) & (v29 - 1)) + v29 + 4111;
      v31 = v29 + v30;
      v32 = (_BYTE *)ExAllocatePoolWithTag(512, v29 + v30 + 28, 1951624563);
      v33 = v32;
      if ( v32 )
      {
        memset(v32, 0, v31 + 28);
        v34 = *(_DWORD *)(a2 + 92);
        *(_DWORD *)(a2 + 672) = v33;
        v35 = SmCalcIoWorkItemSize(v34, 4095, v30);
        v36 = (_BYTE *)ExAllocatePoolWithTag(512, v35, 1951624563);
        v37 = v36;
        if ( v36 )
        {
          memset(v36, 0, v35);
          *(_DWORD *)(a2 + 676) = v37;
LABEL_45:
          v6 = a5;
          v15 = a6;
          goto LABEL_9;
        }
      }
    }
    return -1073741670;
  }
LABEL_9:
  if ( (*(_DWORD *)(a2 + 72) & 0x100) != 0 )
  {
    memset(v40, 0, sizeof(v40));
    v40[3] = 0x8000;
    v40[4] = -1;
    v40[0] = 0x10000000;
    v40[1] = 0;
    v40[5] = (int)ST_STORE<SM_TRAITS>::StDmSparseBitmapAlloc;
    v40[6] = (int)ST_STORE<SM_TRAITS>::StDmSparseBitmapFree;
    RtlSparseBitmapCtxStart(a2 + 160, v40);
  }
  *(_DWORD *)(a2 + 304) = *(_DWORD *)(v7 + 44);
  *(_DWORD *)(a2 + 308) = *(_DWORD *)(v7 + 48);
  v16 = *(_DWORD *)(v7 + 52);
  *(_DWORD *)(a2 + 128) = v15;
  *(_DWORD *)(a2 + 312) = v16;
  v40[0] = 0;
  v40[1] = 0;
  v40[2] = 0;
  v40[3] = 0;
  v40[4] = 0;
  v40[5] = 0;
  if ( (*v8 & 8) != 0 )
  {
    result = ZwQuerySystemInformation();
    if ( result < 0 )
      return result;
    v38 = v43 >> 9;
    if ( v43 >> 9 <= 0x10 )
      v38 = 16;
    v40[0] = v38;
    v40[1] = 4;
  }
  else
  {
    v40[0] = -1;
  }
  v40[2] = (int)ST_STORE<SM_TRAITS>::StNpEnumBTreeNodes;
  v40[3] = (int)ST_STORE<SM_TRAITS>::StNpLeafPageOut;
  v40[4] = (int)ST_STORE<SM_TRAITS>::StNpLeafPageIn;
  v40[5] = (int)ST_STORE<SM_TRAITS>::StNpLeafDelete;
  result = NP_CONTEXT::NpStart((struct NP_CONTEXT *)(a2 + 488), (struct NP_CONTEXT::_NP_PARAMETERS *)v40);
  if ( result >= 0 )
  {
    result = NP_CONTEXT::NpStart((struct NP_CONTEXT *)(a2 + 576), (struct NP_CONTEXT::_NP_PARAMETERS *)v40);
    if ( result >= 0 )
    {
      if ( *(_BYTE *)(a2 + 72) == 1 )
        *v6 = v10;
      result = 0;
    }
  }
  return result;
}
