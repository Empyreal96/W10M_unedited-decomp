// SmcStoreCreate 
 
int __fastcall SmcStoreCreate(int a1, int a2, int a3, unsigned int a4, int *a5)
{
  int v9; // r8
  int v10; // r0
  int v11; // r6
  int v12; // r5
  int v13; // r1
  int v14; // r7
  int v15; // r1
  int v16; // r2
  int v17; // r3
  __int16 v18; // r4
  int v19; // r3
  int v20; // r3
  int v21; // r4
  int v22; // r2
  int v23; // r4
  _DWORD *v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r1
  int v28; // [sp+0h] [bp-88h] BYREF
  unsigned int v29; // [sp+4h] [bp-84h]
  int v30; // [sp+8h] [bp-80h] BYREF
  int v31; // [sp+Ch] [bp-7Ch]
  _DWORD v32[2]; // [sp+10h] [bp-78h] BYREF
  int v33[8]; // [sp+18h] [bp-70h] BYREF
  int v34[20]; // [sp+38h] [bp-50h] BYREF

  v29 = a4;
  memset(v34, 0, 48);
  v28 = 0;
  v9 = 0;
  v10 = SmcCacheReference(a1, a4);
  v11 = v10;
  if ( !v10 )
    return -1073741672;
  v13 = *(_DWORD *)(a3 + 12);
  if ( !v13 )
  {
    v12 = -1073741811;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(v10 + 24) != *(_DWORD *)(a3 + 8) || *(_BYTE *)a3 != 1 )
  {
    v12 = -1073741637;
    goto LABEL_23;
  }
  v14 = SmcStoreSlotReserve(v10, v13, *(_DWORD *)(a3 + 12));
  if ( v14 )
  {
    v15 = *(_DWORD *)(a3 + 4);
    v16 = *(_DWORD *)(a3 + 8);
    v17 = *(_DWORD *)(a3 + 12);
    v34[0] = *(_DWORD *)a3;
    v34[1] = v15;
    v34[2] = v16;
    v34[3] = v17;
    v34[3] = *(_DWORD *)(v11 + 8);
    v34[6] = *(_DWORD *)(v11 + 4);
    v18 = (LOWORD(v34[0]) ^ (*(_WORD *)(v11 + 28) << 13)) & 0x6000 ^ LOWORD(v34[0]);
    v19 = *(_DWORD *)(v11 + 32);
    v34[0] ^= (LOWORD(v34[0]) ^ (unsigned __int16)(*(_WORD *)(v11 + 28) << 13)) & 0x6000;
    v34[4] = v19;
    memset(v33, 0, sizeof(v33));
    v33[0] = *(_DWORD *)(v11 + 40);
    v33[1] = *(_DWORD *)(v11 + 44);
    v33[2] = *(_DWORD *)(v11 + 48);
    v33[3] = *(_DWORD *)(v11 + 52);
    v33[6] = *(_DWORD *)(v11 + 64);
    v33[7] = *(_DWORD *)(v11 + 68);
    v34[9] = (int)v33;
    v12 = SmKmRegParamsLoad(&v30);
    if ( v12 >= 0 )
    {
      if ( (*(_DWORD *)(v11 + 28) & 1) == 0 )
      {
        v20 = v31 & 3;
        if ( v20 == 2 || v20 == 1 && (v18 & 0x800) != 0 )
        {
          v21 = 0;
          goto LABEL_19;
        }
      }
      v21 = v30;
      v9 = SmAlloc(v30, 1262841203);
      if ( v9 )
      {
        v12 = SmKmKeyGenGenerate(a1 + 256, v11 + 380, v9, v21);
        if ( v12 >= 0 )
        {
LABEL_19:
          v22 = *(_DWORD *)(v14 + 8);
          v32[0] = *(_DWORD *)(v11 + 8);
          v32[1] = v22;
          v34[11] = (int)v32;
          v34[10] = v11 + 72;
          v34[7] = v9;
          v34[8] = v21;
          v12 = SmStoreCreate(a2, (int)v34, &v28);
          if ( v12 >= 0 )
          {
            v23 = v28;
            SmcStoreSlotCommit(v11, v14, v28, a2);
            v14 = 0;
            v12 = 0;
            *a5 = v23;
          }
          goto LABEL_21;
        }
      }
      else
      {
        v12 = -1073741670;
      }
    }
LABEL_21:
    if ( v14 )
      SmcStoreSlotAbort(v11, v14, 0);
    goto LABEL_23;
  }
  v12 = -1073741697;
LABEL_23:
  v24 = (_DWORD *)(a1 + 16 * (v29 & 0xF) + 4);
  __pld(v24);
  v25 = *v24 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v26 = __ldrex(v24);
  while ( v26 == v25 && __strex(v25 - 2, v24) );
  if ( v26 != v25 )
    ExfReleaseRundownProtection((unsigned __int8 *)v24);
  if ( v9 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v9);
  return v12;
}
