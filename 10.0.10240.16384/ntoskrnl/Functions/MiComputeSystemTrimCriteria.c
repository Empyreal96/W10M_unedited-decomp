// MiComputeSystemTrimCriteria 
 
int __fastcall MiComputeSystemTrimCriteria(_DWORD *a1, int a2)
{
  int v2; // r4
  int v3; // r8
  _DWORD *v4; // r10
  unsigned int v5; // r6
  unsigned int v6; // r0
  unsigned int v7; // r3
  unsigned int v8; // lr
  unsigned int v9; // r3
  unsigned int v10; // r0
  int v11; // r7
  unsigned int v12; // r5
  int v13; // r1
  unsigned int v14; // r2
  int v15; // r9
  unsigned int v16; // r3
  int v18; // r0
  int v19; // r10
  unsigned int v20; // r9
  int v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r2
  int v25; // r5
  unsigned int v26; // r2
  int v27; // r5
  unsigned int v28; // r0
  unsigned int v29; // r3
  unsigned int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r2
  int v33; // r1
  unsigned int v34; // r2
  unsigned int v35; // r2
  unsigned int v36; // r2
  int v39; // [sp+Ch] [bp-24h]

  v2 = a1[878];
  v3 = *(_DWORD *)(v2 + 32);
  v4 = a1;
  v39 = 0;
  v5 = MiGetAvailablePagesBelowPriority();
  v6 = MiGetStandbyRepurposed(v4, 1);
  v7 = *(_DWORD *)(v2 + 36);
  if ( v6 > v7 )
    v8 = v6 - v7;
  else
    v8 = 0;
  v9 = *(_DWORD *)(v2 + 1248);
  *(_DWORD *)(v2 + 36) = v6;
  if ( v5 <= v9 )
    v10 = v9 - v5;
  else
    v10 = v5 - v9;
  v11 = 0;
  v12 = 0;
  v13 = v2 + 4 * (*(_DWORD *)(v2 + 88) & 7);
  *(_DWORD *)(v2 + 1140) += (v10 >> 3) - (*(_DWORD *)(v13 + 1144) >> 3);
  *(_DWORD *)(v13 + 1144) = v10;
  if ( *(_DWORD *)(v2 + 64) == 4 && *(_WORD *)(v2 + 1220) && *(_BYTE *)(v2 + 1222) && *(_BYTE *)(v2 + 1223) )
  {
    v14 = *(_DWORD *)(v2 + 1248);
    v15 = 1;
    v16 = v14;
  }
  else
  {
    v14 = *(_DWORD *)(v2 + 1248);
    v15 = 0;
    v16 = v14 >> 2;
  }
  if ( v5 < v16 )
    JUMPOUT(0x5171B6);
  if ( v5 < 4 * v14 )
    return sub_5171A8();
  if ( v8 >= v5 >> 2 )
  {
    v31 = v8 - (v5 >> 2);
    if ( v31 )
    {
      if ( !v15 )
      {
        v12 = v8 - (v5 >> 2);
        if ( v31 > 0x2000 )
          v12 = 0x2000;
        v11 = 3;
      }
    }
  }
  v18 = MiGetStandbyRepurposed(v4, 4);
  v19 = v18;
  if ( v12 )
  {
    v21 = (int)a1;
    v20 = v8;
    if ( v12 < 0x1000 )
      v12 = 4096;
  }
  else
  {
    if ( v15 )
    {
      v20 = v8;
LABEL_17:
      v21 = (int)a1;
      goto LABEL_18;
    }
    v29 = v18 - *(_DWORD *)(v2 + 40);
    if ( v29 > 0x20000 )
    {
      v21 = (int)a1;
      v32 = a1[928];
      if ( v32 >= 0x100000 || v32 >= a1[898] >> 2 )
      {
        *(_DWORD *)(v2 + 40) = v19;
      }
      else
      {
        v12 = 0x8000;
        v11 = 2;
      }
      v20 = v8;
    }
    else
    {
      v20 = v8;
      if ( !v8 || v29 <= 0x18000 )
        goto LABEL_17;
      v21 = (int)a1;
      if ( *(_DWORD *)(v2 + 1252) < 0x20000u )
        v39 = 1;
    }
  }
LABEL_18:
  v22 = *(_DWORD *)(v2 + 1248);
  if ( v5 >= 4 * v22 )
  {
    if ( v5 <= 16 * v22 )
      goto LABEL_20;
    v30 = *(_DWORD *)(v2 + 1244);
    goto LABEL_51;
  }
  v33 = *(_DWORD *)(v2 + 1140);
  v34 = 4 * v33;
  if ( 4 * v33 < v22 )
  {
    v30 = *(_DWORD *)(v2 + 1236);
    *(_DWORD *)(v2 + 1248) = v34;
    if ( v34 >= v30 )
      goto LABEL_20;
    goto LABEL_51;
  }
  v35 = 2 * v33;
  if ( 2 * v33 > v22 )
  {
    v30 = *(_DWORD *)(v2 + 1240);
    *(_DWORD *)(v2 + 1248) = v35;
    if ( v35 > v30 )
    {
LABEL_51:
      *(_DWORD *)(v2 + 1248) = v30;
      goto LABEL_20;
    }
  }
LABEL_20:
  v23 = *(_DWORD *)(v2 + 48);
  *(_DWORD *)(v2 + 1232) = v5;
  if ( v23 && v12 < v23 )
  {
    v12 = v23;
    v11 = 5;
  }
  if ( v12 )
  {
    MiPulseLowAvailableEvent(v21);
    if ( v11 == 3 || v11 == 2 )
      *(_DWORD *)(v2 + 1228) = v12;
    v36 = v12;
    v27 = a2;
    v3 |= 1u;
    MiInitializeTrimCriteria(a2, a1, v36, v11);
    *(_DWORD *)(v2 + 40) = v19;
    ++*(_DWORD *)(v2 + 4 * v11 + 1284);
    goto LABEL_36;
  }
  v24 = *(_DWORD *)(v2 + 1228);
  v25 = 0;
  if ( v24 )
  {
    if ( v24 > *(_DWORD *)(v2 + 1252) )
    {
      v25 = 11;
      if ( *(unsigned __int16 *)(v2 + 1218) < 0xFAu )
        *(_WORD *)(v2 + 1218) = 250;
      goto LABEL_28;
    }
    *(_DWORD *)(v2 + 1228) = 0;
  }
  if ( *(_DWORD *)(v2 + 1252) < (unsigned int)(4 * *(_DWORD *)(v2 + 1240)) )
  {
    if ( !*(_WORD *)(v2 + 1218) )
      goto LABEL_25;
    v28 = MiComputeAgeDistribution(v21, 1);
    if ( v28 )
      v25 = 12;
    *(_WORD *)(v2 + 1218) = v28;
    if ( !v25 )
    {
LABEL_25:
      if ( v20 >= v5 >> 4 )
      {
        v25 = 10;
      }
      else if ( v39 == 1 )
      {
        v25 = 9;
      }
    }
  }
LABEL_28:
  v26 = *(unsigned __int16 *)(v2 + 1220);
  if ( *(_WORD *)(v2 + 1220) )
  {
    if ( *(unsigned __int16 *)(v2 + 1218) < v26 )
      *(_WORD *)(v2 + 1218) = v26;
    if ( !v25 )
      v25 = 13;
  }
  MiInitializeTrimCriteria(a2, a1, 0, v25);
  if ( v25 )
  {
    v3 |= 2u;
    ++*(_DWORD *)(v2 + 4 * v25 + 1284);
  }
  else if ( *(_BYTE *)(v2 + 47) == 1 )
  {
    *(_WORD *)(v2 + 1218) = 10;
    v3 |= 0x80u;
  }
  else if ( !v3 )
  {
    v3 = 64;
  }
  v27 = a2;
LABEL_36:
  if ( v5 && v20 < v5 )
    *(_BYTE *)(v27 + 3) = 100 * v20 / v5;
  else
    *(_BYTE *)(v27 + 3) = 100;
  return v3;
}
