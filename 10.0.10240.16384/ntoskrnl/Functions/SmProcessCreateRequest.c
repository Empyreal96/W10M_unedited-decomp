// SmProcessCreateRequest 
 
int __fastcall SmProcessCreateRequest(int a1, unsigned int a2, int a3, int a4)
{
  int v6; // r8
  int v7; // r10
  int v8; // r9
  _BYTE *v9; // r0
  int v10; // r6
  int v11; // r4
  int *v12; // r4
  int v13; // r2
  int v14; // r0
  int v15; // r4
  _DWORD *v16; // r0
  unsigned int v17; // r5
  unsigned int v18; // r4
  int v21; // [sp+4h] [bp-94h] BYREF
  int v22; // [sp+8h] [bp-90h]
  int v23; // [sp+Ch] [bp-8Ch]
  int v24; // [sp+10h] [bp-88h]
  int v25; // [sp+14h] [bp-84h]
  int v26; // [sp+18h] [bp-80h]
  int v27; // [sp+1Ch] [bp-7Ch]
  unsigned int v28; // [sp+20h] [bp-78h]
  int *v29[6]; // [sp+28h] [bp-70h] BYREF
  _DWORD anonymous0[27]; // [sp+40h] [bp-58h] BYREF
  int varg_r3; // [sp+ACh] [bp+14h]

  anonymous0[24] = a1;
  anonymous0[25] = a2;
  anonymous0[26] = a3;
  varg_r3 = a4;
  v23 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v27 = a1;
  v28 = a2;
  v6 = 0;
  v25 = 0;
  v22 = 0;
  v24 = 0;
  v7 = -1;
  v26 = -1;
  v8 = 0;
  v21 = 0;
  v9 = memset(anonymous0, 0, 56);
  if ( a3 != 56 )
  {
    v10 = -1073741306;
LABEL_30:
    v15 = a1;
    goto LABEL_31;
  }
  v11 = v23;
  if ( v23 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 52) = *(_BYTE *)(a2 + 52);
  }
  memmove((int)anonymous0, a2, 0x38u);
  memset(v29, 0, sizeof(v29));
  v10 = SmKmStoreCreatePrepare(anonymous0, v11, &v21, v29);
  if ( v10 < 0 )
    goto LABEL_29;
  v12 = v29[0];
  v13 = *v29[0];
  if ( (unsigned __int8)*v29[0] || (v13 & 0x40000) == 0 || (v13 & 0x300) != 0 )
  {
    v10 = -1073741637;
    goto LABEL_16;
  }
  if ( (v13 & 0x20000) != 0 && !SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, v23) )
  {
    v10 = -1073741790;
LABEL_16:
    v8 = v21;
    goto LABEL_30;
  }
  v14 = SmAlloc(3960, 1951624563);
  v6 = v14;
  if ( !v14 )
  {
    v10 = -1073741670;
    goto LABEL_16;
  }
  SMKM_STORE<SM_TRAITS>::SmStInitialize(v14);
  v29[4] = SmGlobals;
  *v12 |= 0x8000u;
  v10 = SMKM_STORE<SM_TRAITS>::SmStStart(v6, v29);
  if ( v10 < 0 || (v10 = SmFirstTimeInit(v29[0][2]), v10 < 0) )
  {
LABEL_29:
    v15 = a1;
  }
  else
  {
    v29[2] = 0;
    v29[0] = &anonymous0[1];
    v29[1] = *(int **)(v6 + 3648);
    v29[3] = (int *)anonymous0[5];
    if ( (anonymous0[0] & 0x200) != 0 )
      v29[2] = *(int **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v15 = a1;
    v10 = SmKmStoreAdd(a1, v6, v29, v6 + 3512);
    if ( v10 >= 0 )
    {
      v7 = *(_DWORD *)(v6 + 3512);
      v26 = v7;
      __dmb(0xFu);
      dword_636CB4 = 5;
      v6 = 0;
      v25 = 0;
      v22 = 1;
      v24 = 1;
      v10 = 0;
      *(_DWORD *)(a2 + 52) = v7;
      SmpUpdateCacheStatsBucketIndex();
      if ( (anonymous0[0] & 0x100) != 0 )
        v7 = -1;
      v22 = 0;
    }
  }
  v8 = v21;
LABEL_31:
  if ( v7 != -1 )
  {
    v16 = (_DWORD *)(v15 + 96 * (v7 & 0x1F) + 4);
    __pld(v16);
    v17 = *v16 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v18 = __ldrex(v16);
    while ( v18 == v17 && __strex(v17 - 2, v16) );
    if ( v18 != v17 )
      ExfReleaseRundownProtection((unsigned __int8 *)v16);
  }
  if ( v6 )
  {
    SMKM_STORE<SM_TRAITS>::SmStCleanup(v6);
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v6);
  }
  if ( v22 )
    SmKmStoreDelete(a1);
  if ( v8 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v8);
  return v10;
}
