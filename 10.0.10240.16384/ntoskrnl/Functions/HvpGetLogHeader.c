// HvpGetLogHeader 
 
int __fastcall HvpGetLogHeader(int a1, _QWORD *a2, int a3, int *a4, unsigned int *a5, _BYTE *a6, int a7)
{
  int v7; // r4
  int v8; // r8
  int v9; // r3
  int v10; // r1
  int v11; // r7
  int v12; // r6
  unsigned int v13; // r5
  unsigned int v14; // r9
  int v15; // r4
  int *v16; // r10
  _BYTE *v17; // r0
  int v18; // r5
  int v19; // r3
  __int64 v20; // kr00_8
  int v21; // r4
  unsigned int v22; // r3
  unsigned int v23; // r10
  int v24; // r0
  int v25; // r4
  int v26; // r0
  int v27; // r2
  __int64 v28; // kr08_8
  int v29; // r4
  unsigned int v30; // r3
  __int64 v31; // kr10_8
  int v32; // r4
  unsigned int v33; // r3
  unsigned int v34; // r1
  int v35; // r3
  int v36; // r3
  int *v37; // r3
  char v38; // r2
  int *v39; // r6
  int v40; // r5
  unsigned int v41; // r0
  unsigned int v42; // t1
  int v45; // [sp+Ch] [bp-64h]
  int v46; // [sp+10h] [bp-60h] BYREF
  int v47; // [sp+14h] [bp-5Ch]
  int v48; // [sp+18h] [bp-58h]
  _QWORD *v49; // [sp+1Ch] [bp-54h]
  int v50; // [sp+20h] [bp-50h]
  int *v51; // [sp+24h] [bp-4Ch]
  unsigned int v52; // [sp+28h] [bp-48h] BYREF
  unsigned int v53; // [sp+2Ch] [bp-44h]
  int v54; // [sp+30h] [bp-40h]
  int v55; // [sp+34h] [bp-3Ch]
  int v56[2]; // [sp+38h] [bp-38h] BYREF
  int v57; // [sp+40h] [bp-30h]

  v7 = *(_DWORD *)(a1 + 68);
  v50 = a3;
  v51 = a4;
  v47 = 0;
  v48 = 0;
  v56[0] = 0;
  v56[1] = 0;
  v8 = 0;
  v55 = 0;
  v9 = *(_DWORD *)(a1 + 96);
  v49 = a2;
  v10 = ((v7 << 9) + 4095) & ~((v7 << 9) - 1);
  v11 = 0;
  v12 = 0;
  if ( v9 == 1 )
    v13 = 1;
  else
    v13 = 2;
  v52 = 0;
  v53 = 0;
  v14 = 0;
  v15 = 0;
  v16 = v56;
  v45 = v10;
  v54 = 0;
  while ( 1 )
  {
    v17 = (_BYTE *)ExAllocatePoolWithTag(5, v10, 875777347);
    *v16++ = (int)v17;
    if ( !v17 )
    {
      v25 = 2;
      goto LABEL_83;
    }
    memset(v17, 0, v45);
    if ( ++v15 >= v13 )
      break;
    v10 = v45;
  }
  v18 = v56[0];
  v19 = *(_DWORD *)(a1 + 96);
  if ( v19 != 1 )
  {
    if ( v19 != 4 && v19 != 5 )
      goto LABEL_25;
    v46 = 0;
    v8 = v56[0];
    if ( (*(int (__fastcall **)(int, int, int *, int, int))(a1 + 24))(a1, 4, &v46, v56[0], v45) == 1
      && *(_DWORD *)v18 == 1718052210 )
    {
      v28 = *(_QWORD *)(v18 + 4);
      if ( (_DWORD)v28 == HIDWORD(v28) && *(_QWORD *)(v18 + 12) == *v49 )
      {
        v29 = *(_DWORD *)(v18 + 28);
        if ( v29 == 6 || v29 == 1 )
        {
          v30 = *(_DWORD *)(v18 + 40);
          if ( v30 )
          {
            if ( v30 <= 0x7FFFE000 && (v30 & 0xFFF) == 0 && *(_DWORD *)(v18 + 508) == HvpHeaderCheckSum((int *)v18) )
            {
              if ( v29 != 6 )
              {
                v11 = 4;
                goto LABEL_23;
              }
              if ( HvIsLogSequenceNumberAtLeastMinimum(v28, v50) )
              {
                v11 = 4;
                v54 = 4;
                v14 = v28;
                v52 = v28;
                v12 = 1;
              }
            }
          }
        }
      }
    }
    v8 = v56[v12];
    v46 = 0;
    if ( (*(int (__fastcall **)(int, int, int *, int, int))(a1 + 24))(a1, 5, &v46, v8, v45) != 1 )
      goto LABEL_25;
    if ( *(_DWORD *)v8 != 1718052210 )
      goto LABEL_25;
    v31 = *(_QWORD *)(v8 + 4);
    if ( (_DWORD)v31 != HIDWORD(v31) )
      goto LABEL_25;
    if ( *(_QWORD *)(v8 + 12) != *v49 )
      goto LABEL_25;
    v32 = *(_DWORD *)(v8 + 28);
    if ( v32 != 6 && (v32 != 1 || v12) )
      goto LABEL_25;
    v33 = *(_DWORD *)(v8 + 40);
    if ( !v33 || v33 > 0x7FFFE000 || (v33 & 0xFFF) != 0 || *(_DWORD *)(v8 + 508) != HvpHeaderCheckSum((int *)v8) )
      goto LABEL_25;
    if ( v32 == 6 )
    {
      if ( !HvIsLogSequenceNumberAtLeastMinimum(v31, v50) )
        goto LABEL_25;
      *(&v54 + v12) = 5;
      *(&v52 + v12) = v31;
      v11 = v54;
      v14 = v52;
      v23 = v53;
      ++v12;
      v47 = v55;
      goto LABEL_26;
    }
    v11 = 5;
    ++v12;
LABEL_24:
    v14 = 0;
    v52 = 0;
    v48 = 1;
    v54 = v11;
    goto LABEL_25;
  }
  v46 = 0;
  v8 = v56[0];
  if ( (*(int (__fastcall **)(int, int, int *, int, int))(a1 + 24))(a1, 1, &v46, v56[0], v45) != 1 )
    goto LABEL_25;
  if ( *(_DWORD *)v18 != 1718052210 )
    goto LABEL_25;
  v20 = *(_QWORD *)(v18 + 4);
  if ( (_DWORD)v20 != HIDWORD(v20) )
    goto LABEL_25;
  if ( *(_QWORD *)(v18 + 12) != *v49 )
    goto LABEL_25;
  v21 = *(_DWORD *)(v18 + 28);
  if ( v21 != 6 && v21 != 1 )
    goto LABEL_25;
  v22 = *(_DWORD *)(v18 + 40);
  if ( !v22 || v22 > 0x7FFFE000 || (v22 & 0xFFF) != 0 || *(_DWORD *)(v18 + 508) != HvpHeaderCheckSum((int *)v18) )
    goto LABEL_25;
  if ( v21 != 6 )
  {
    v11 = 1;
LABEL_23:
    v12 = 1;
    goto LABEL_24;
  }
  if ( HvIsLogSequenceNumberAtLeastMinimum(v20, v50) )
  {
    v11 = 1;
    v54 = 1;
    v14 = v20;
    v52 = v20;
    v12 = 1;
  }
LABEL_25:
  v23 = 0;
LABEL_26:
  if ( a7 )
  {
    if ( v12 == 2 )
    {
      v24 = HvpDetermineLatestLogFile(&v52);
      memmove(a7, v56[v24], 0x1000u);
      v25 = 3;
      goto LABEL_29;
    }
    if ( v12 == 1 )
    {
      memmove(a7, v18, 0x1000u);
      v25 = 3;
      goto LABEL_63;
    }
    if ( (CmpSelfHeal || (CmpBootType & 6) != 0) && ZwQueryInformationFile() >= 0 )
    {
      v34 = v57 - 4096;
      if ( v57 != 4096 && v34 <= 0x7FFFE000 && (v34 & 0xFFF) == 0 )
      {
        *(_DWORD *)(v8 + 40) = v34;
        *(_DWORD *)v8 = 1718052210;
        *(_DWORD *)(v8 + 4) = 1;
        *(_DWORD *)(v8 + 8) = 1;
        *(_DWORD *)(v8 + 44) = 1;
        *(_DWORD *)(v8 + 508) = HvpHeaderCheckSum((int *)v8);
        memmove(a7, v8, 0x1000u);
        v35 = 1;
        v25 = 6;
        goto LABEL_74;
      }
    }
LABEL_66:
    v25 = 1;
    goto LABEL_83;
  }
  if ( !v12 )
    goto LABEL_66;
  v25 = 3;
  v35 = 0;
LABEL_74:
  if ( v12 == 2 )
  {
    if ( v35 )
    {
LABEL_29:
      v26 = HvpDetermineLatestLogFile(&v52);
      v23 = *(&v52 + v26);
      v11 = *(&v54 + v26);
      v27 = 0;
      goto LABEL_81;
    }
    if ( v23 <= v14 )
    {
      v36 = v11;
      v11 = v47;
      v27 = v36;
      goto LABEL_81;
    }
LABEL_63:
    v23 = v14;
  }
  else
  {
    if ( v12 == 1 )
      goto LABEL_63;
    v23 = 0;
  }
  v27 = v47;
LABEL_81:
  v37 = v51;
  *v51 = v11;
  v37[1] = v27;
  v38 = v48;
  *a5 = v23;
  *a6 = v38;
LABEL_83:
  v39 = v56;
  v40 = 2;
  do
  {
    v42 = *v39++;
    v41 = v42;
    if ( v42 )
      ExFreePoolWithTag(v41);
    --v40;
  }
  while ( v40 );
  return v25;
}
