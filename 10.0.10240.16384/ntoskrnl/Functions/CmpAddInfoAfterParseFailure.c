// CmpAddInfoAfterParseFailure 
 
int __fastcall CmpAddInfoAfterParseFailure(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  __int16 v6; // r3
  int v10; // r0
  int v11; // r7
  __int64 v13; // kr00_8
  unsigned int v14; // r2
  _DWORD *v15; // r0
  int v16; // r9
  int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r10
  unsigned __int16 *v20; // r0
  unsigned __int16 *v21; // r6
  unsigned int v22; // r8
  int v23; // r3
  int v24; // r2
  unsigned __int16 *v25; // r3
  int v26; // r1
  unsigned int v27; // r3
  int v28; // r3
  int v29; // r6
  int (__fastcall *v30)(int, int, int *); // r3
  int v31; // r1
  unsigned __int16 *v32; // r0
  int v33; // r2
  int v34; // r6
  int v35; // r1
  int v36; // r3
  int v37; // r0
  unsigned int v38; // r0
  int v39; // r0
  unsigned int v40; // r0
  int v41; // r3
  int v42; // [sp+8h] [bp-40h] BYREF
  int v43; // [sp+Ch] [bp-3Ch] BYREF
  int v44; // [sp+10h] [bp-38h] BYREF
  int v45; // [sp+14h] [bp-34h] BYREF
  int v46[2]; // [sp+18h] [bp-30h] BYREF
  __int16 v47; // [sp+20h] [bp-28h] BYREF
  int v48; // [sp+24h] [bp-24h]

  v5 = a4;
  v6 = *(_WORD *)(a4 + 106);
  v44 = -1;
  if ( (v6 & 0x200) != 0 )
    return v5;
  v10 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v44);
  v11 = v10;
  if ( !v10 )
    return sub_80510C();
  v13 = *(_QWORD *)(v10 + 20);
  v14 = HIDWORD(v13) + v13;
  if ( HIDWORD(v13) + (int)v13 < (unsigned int)v13 )
    goto LABEL_27;
  if ( !v14 )
  {
    v28 = *(_DWORD *)(v5 + 4) | 1;
LABEL_24:
    *(_WORD *)(v5 + 4) = v28;
    *(_WORD *)(v5 + 4) = *(_DWORD *)(v5 + 4) & 0xFFBF;
    goto LABEL_25;
  }
  if ( v14 == 1 )
  {
    if ( (*(_DWORD *)(v5 + 4) & 2) != 0 )
      goto LABEL_41;
    v30 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
    v42 = -1;
    v43 = -1;
    if ( (_DWORD)v13 == 1 )
      v31 = *(_DWORD *)(v10 + 28);
    else
      v31 = *(_DWORD *)(v10 + 32);
    v32 = (unsigned __int16 *)v30(a1, v31, &v42);
    if ( !v32 )
    {
LABEL_59:
      v5 = 0;
      goto LABEL_27;
    }
    v33 = *v32;
    if ( v33 == 26994 )
    {
LABEL_58:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v42);
      goto LABEL_59;
    }
    v34 = 0;
    if ( v33 == 26732 )
    {
      v34 = *((_DWORD *)v32 + 2);
    }
    else if ( v33 == 26220 )
    {
      v35 = *((_DWORD *)v32 + 1);
LABEL_51:
      v39 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v35, &v43);
      if ( v39 )
      {
        if ( (*(_WORD *)(v39 + 2) & 0x20) != 0 )
        {
          v40 = CmpComputeHashKeyForCompressedName(0, v39 + 76, *(unsigned __int16 *)(v39 + 72));
        }
        else
        {
          v46[1] = v39 + 76;
          LOWORD(v46[0]) = *(_WORD *)(v39 + 72);
          v40 = CmpComputeHashKey(0, v46);
        }
        v41 = *(_DWORD *)(v5 + 4);
        *(_DWORD *)(v5 + 60) = v40;
        *(_WORD *)(v5 + 4) = v41 | 2;
        *(_WORD *)(v5 + 4) = *(_DWORD *)(v5 + 4) & 0xFFBF;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v43);
        goto LABEL_40;
      }
      goto LABEL_58;
    }
    v35 = *((_DWORD *)v32 + 1);
    if ( v34 )
    {
      v36 = *(_DWORD *)(v5 + 4);
      *(_DWORD *)(v5 + 60) = v34;
      *(_WORD *)(v5 + 4) = v36 | 2;
      *(_WORD *)(v5 + 4) = *(_DWORD *)(v5 + 4) & 0xFFBF;
LABEL_40:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v42);
      goto LABEL_25;
    }
    goto LABEL_51;
  }
  if ( v14 >= 0xE || (*(_DWORD *)(v5 + 4) & 4) != 0 )
  {
LABEL_41:
    v29 = v5;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v44);
    v11 = 0;
    v5 = CmpCreateKeyControlBlock(a1, a2, v5, 3, a5);
    if ( v5 )
    {
      CmpDereferenceKeyControlBlockWithLock(v29, 0);
      CmpUnlockAndLockKcbs(a3, v29, v5, 0);
      goto LABEL_25;
    }
    goto LABEL_26;
  }
  v43 = -1;
  v45 = -1;
  v15 = (_DWORD *)ExAllocatePoolWithTag(1, 4 * (v14 + 1), 1850297667);
  *(_DWORD *)(v5 + 60) = v15;
  v16 = 1;
  if ( !v15 )
    goto LABEL_25;
  *v15 = *(_DWORD *)(v11 + 20) + *(_DWORD *)(v11 + 24);
  v42 = 0;
  v17 = *(_DWORD *)(a1 + 144);
  v18 = 0;
  v46[0] = 0;
  if ( !v17 )
    goto LABEL_23;
  do
  {
    v19 = v11 + 4 * v18;
    if ( !*(_DWORD *)(v19 + 20) )
      goto LABEL_21;
    v20 = (unsigned __int16 *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v19 + 28), &v43);
    v21 = v20;
    if ( !v20 )
      goto LABEL_59;
    if ( *v20 == 26994 )
    {
      v16 = 0;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v43);
      break;
    }
    v22 = 0;
    if ( !*(_DWORD *)(v19 + 20) )
      goto LABEL_20;
    while ( 1 )
    {
      v23 = *v21;
      v24 = 0;
      if ( v23 == 26732 )
      {
        v25 = &v21[4 * v22];
        v24 = *((_DWORD *)v25 + 2);
        goto LABEL_17;
      }
      if ( v23 == 26220 )
        break;
      v25 = &v21[2 * v22];
LABEL_17:
      v26 = *((_DWORD *)v25 + 1);
      if ( !v24 )
        goto LABEL_45;
      *(_DWORD *)(*(_DWORD *)(v5 + 60) + 4 * v42 + 4) = v24;
LABEL_19:
      ++v42;
      v22 = (unsigned __int16)(v22 + 1);
      if ( v22 >= *(_DWORD *)(v19 + 20) )
        goto LABEL_20;
    }
    v26 = *(_DWORD *)&v21[4 * v22 + 2];
LABEL_45:
    v37 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v26, &v45);
    if ( v37 )
    {
      if ( (*(_WORD *)(v37 + 2) & 0x20) != 0 )
      {
        v38 = CmpComputeHashKeyForCompressedName(0, v37 + 76, *(unsigned __int16 *)(v37 + 72));
      }
      else
      {
        v48 = v37 + 76;
        v47 = *(_WORD *)(v37 + 72);
        v38 = CmpComputeHashKey(0, &v47);
      }
      *(_DWORD *)(*(_DWORD *)(v5 + 60) + 4 * v42 + 4) = v38;
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v45);
      goto LABEL_19;
    }
    v16 = 0;
LABEL_20:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v43);
    LOWORD(v18) = v46[0];
LABEL_21:
    v18 = (unsigned __int16)(v18 + 1);
    v27 = *(_DWORD *)(a1 + 144);
    v46[0] = v18;
  }
  while ( v18 < v27 );
  if ( v16 )
  {
LABEL_23:
    v28 = *(_DWORD *)(v5 + 4) | 4;
    goto LABEL_24;
  }
  ExFreePoolWithTag(*(_DWORD *)(v5 + 60));
LABEL_25:
  v29 = v5;
LABEL_26:
  v5 = v29;
LABEL_27:
  if ( v11 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v44);
  return v5;
}
