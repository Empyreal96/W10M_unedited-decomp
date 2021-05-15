// -SmPickStoreForWrite@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAPAU-$SMKM_STORE@USM_TRAITS@@@@PAU1@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmPickStoreForWrite(int a1)
{
  int v1; // r10
  unsigned int v2; // r8
  unsigned int v3; // r5
  int v4; // r7
  unsigned int v5; // r9
  int v6; // r8
  int *v7; // r4
  unsigned int *v8; // r6
  unsigned int v9; // r0
  unsigned int v10; // r1
  int v11; // r6
  unsigned int v12; // r4
  unsigned int v13; // r1
  int v14; // r3
  char v15; // r4
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r3
  bool v21; // cf
  int v22; // r1
  __int64 v23; // r0
  unsigned int v24; // r1
  int v25; // r6
  unsigned int i; // r5
  int v27; // r3
  _DWORD *v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int v32; // [sp+0h] [bp-80h]
  unsigned int v33; // [sp+4h] [bp-7Ch]
  int v34; // [sp+8h] [bp-78h]
  unsigned int v35; // [sp+Ch] [bp-74h]
  char *v36; // [sp+10h] [bp-70h]
  int v37; // [sp+14h] [bp-6Ch] BYREF
  int v38; // [sp+18h] [bp-68h] BYREF
  unsigned int v39; // [sp+1Ch] [bp-64h]
  unsigned __int8 v40[32]; // [sp+20h] [bp-60h] BYREF
  char v41[64]; // [sp+40h] [bp-40h] BYREF

  v1 = *(_DWORD *)(a1 + 3180);
  v2 = 0;
  v3 = 0;
  v4 = a1;
  v32 = 0;
  v33 = 0;
  v35 = 0;
  v5 = 0;
  if ( !v1 )
    goto LABEL_41;
  v36 = v41;
  v6 = a1;
  v34 = v40[0];
  while ( v5 < 0x20 )
  {
    if ( !*(_DWORD *)v6 )
      goto LABEL_32;
    --v1;
    if ( *(_DWORD *)(v6 + 36) )
      goto LABEL_32;
    v39 = v5 | (32 * (*(_WORD *)(v6 + 12) & 0x7FF));
    v7 = (int *)(v4 + 96 * (v39 & 0x1F));
    v8 = (unsigned int *)(v7 + 1);
    __pld(v7 + 1);
    v9 = v7[1] & 0xFFFFFFFE;
    do
      v10 = __ldrex(v8);
    while ( v10 == v9 && __strex(v9 + 2, v8) );
    __dmb(0xBu);
    if ( v10 == v9 || ExfAcquireRundownProtection(v7 + 1) )
    {
      if ( (v7[3] & 0x7FF) == v39 >> 5 )
      {
        v11 = *v7;
        goto LABEL_19;
      }
      __pld(v8);
      v12 = *v8 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v13 = __ldrex(v8);
      while ( v13 == v12 && __strex(v12 - 2, v8) );
      if ( v13 != v12 )
        ExfReleaseRundownProtection((unsigned __int8 *)v8);
    }
    v11 = 0;
LABEL_19:
    if ( v11 )
    {
      ++v32;
      v14 = *(_DWORD *)(v11 + 28);
      *v36++ = v5;
      v15 = v14 - 6;
      ST_STORE<SM_TRAITS>::StDmGetSpaceStats(v11 + 56, &v38, &v37);
      v16 = *(_DWORD *)(v11 + 184);
      v17 = ((v16 << v15) - 16 * ((unsigned int)(v37 + 1023) >> 10)) >> 10;
      v18 = (unsigned int)((v16 - v38) << v15) >> 10;
      if ( !v3 )
        goto LABEL_31;
      if ( v18 )
      {
        if ( !v33 || (v19 = *(_DWORD *)(v6 + 16), v20 = *(_DWORD *)(v4 + 96 * v34 + 16), v21 = v19 >= v20, v19 > v20) )
        {
LABEL_27:
          v3 = 0;
LABEL_31:
          v40[v3] = v5;
          v34 = v40[0];
          v35 = v17;
          v33 = v18;
          ++v3;
          goto LABEL_32;
        }
LABEL_29:
        if ( !v21 )
          goto LABEL_32;
        goto LABEL_31;
      }
      if ( !v33 )
      {
        if ( v17 > v35 )
          goto LABEL_27;
        v21 = v17 >= v35;
        goto LABEL_29;
      }
    }
LABEL_32:
    ++v5;
    v6 += 96;
    if ( !v1 )
      break;
  }
  if ( !v3 )
  {
    v2 = v32;
LABEL_41:
    v25 = 0;
    goto LABEL_42;
  }
  if ( v3 == 1 )
  {
    v22 = 0;
  }
  else
  {
    LODWORD(v23) = ReadTimeStampCounter();
    v24 = v23 >> 4;
    if ( v3 == 2 )
      v22 = v24 & 1;
    else
      v22 = v24 % v3;
  }
  v2 = v32;
  v25 = *(_DWORD *)(96 * (v40[v22] & 0x1F) + v4);
LABEL_42:
  for ( i = 0; i < v2; ++i )
  {
    v27 = *(_DWORD *)(96 * (v41[i] & 0x1F) + v4);
    if ( v27 != v25 )
    {
      v28 = (_DWORD *)(v4 + 96 * (*(_DWORD *)(v27 + 3512) & 0x1F) + 4);
      __pld(v28);
      v29 = *v28 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v30 = __ldrex(v28);
      while ( v30 == v29 && __strex(v29 - 2, v28) );
      if ( v30 != v29 )
        ExfReleaseRundownProtection((unsigned __int8 *)v28);
    }
  }
  return v25;
}
