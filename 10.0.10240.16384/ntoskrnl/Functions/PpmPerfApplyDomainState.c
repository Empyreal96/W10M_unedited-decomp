// PpmPerfApplyDomainState 
 
int __fastcall PpmPerfApplyDomainState(int a1)
{
  int v1; // r5
  int *v2; // r3
  int v3; // r10
  int v4; // r3
  unsigned int v6; // r9
  unsigned int v7; // r3
  int v8; // r2
  int v9; // r7
  int *v10; // r6
  int v11; // r4
  unsigned int i; // r8
  unsigned int v13; // r7
  unsigned int v14; // r6
  unsigned int v15; // r9
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r3
  unsigned int v21; // lr
  unsigned int v22; // r3
  int v23; // r3
  char v24; // r8
  unsigned int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r3
  int v30; // r1
  int v31; // r3
  unsigned int v32; // r3
  unsigned int v33; // r3
  int v34; // [sp+10h] [bp-50h]
  __int64 v35; // [sp+18h] [bp-48h] BYREF
  unsigned int v36; // [sp+20h] [bp-40h] BYREF
  int v37; // [sp+24h] [bp-3Ch] BYREF
  int v38; // [sp+28h] [bp-38h]
  int v39[2]; // [sp+30h] [bp-30h] BYREF
  __int64 v40; // [sp+38h] [bp-28h] BYREF

  v1 = *(_DWORD *)(a1 + 3200);
  v38 = *(_DWORD *)(*(_DWORD *)(a1 + 3204) + 4);
  v2 = &PpmCurrentProfile[44 * dword_61EC0C];
  v3 = v2[20];
  v39[0] = (int)v2;
  v4 = *((unsigned __int8 *)v2 + 48);
  if ( v4 == 1 )
    JUMPOUT(0x51F3B2);
  if ( v4 == 2 )
    return sub_51F3A8();
  v6 = *(_DWORD *)(v1 + 92);
  v35 = *(_QWORD *)(v1 + 132);
  v7 = *(_DWORD *)(v1 + 88);
  if ( (unsigned int)v35 <= v7 )
    LODWORD(v35) = *(_DWORD *)(v1 + 88);
  if ( HIDWORD(v35) <= v7 )
    HIDWORD(v35) = v7;
  v36 = 100;
  v8 = PpmPerfApplyCapsAndFloors(&v35, (char *)&v35 + 4, &v36, v1);
  v34 = v8;
  v9 = dword_61633C;
  if ( !PpmPerfArtificialDomainEnabled || (*(_DWORD *)(v1 + 20) & dword_61633C) == *(_DWORD *)(v1 + 20) )
  {
    v10 = *(int **)v1;
    v11 = v1;
  }
  else
  {
    v11 = PpmPerfDomainHead;
    v10 = &PpmPerfDomainHead;
  }
  for ( i = 0; (int *)v11 != v10; v11 = *(_DWORD *)v11 )
  {
    if ( (v11 == v1 || (*(_DWORD *)(v11 + 20) & v9) != *(_DWORD *)(v11 + 20))
      && *(_DWORD *)(*(_DWORD *)(v1 + 8) + 2360) == *(_DWORD *)(*(_DWORD *)(v11 + 8) + 2360)
      && *(unsigned __int8 *)(v1 + 28) == *(unsigned __int8 *)(v11 + 28) )
    {
      if ( *(_DWORD *)(v11 + 128) > i )
        i = *(_DWORD *)(v11 + 128);
      v8 = (unsigned __int8)(v34 | PpmPerfApplyCapsAndFloors(&v35, (char *)&v35 + 4, &v36, v11));
      v34 = v8;
    }
    else
    {
      v8 = v34;
    }
  }
  v13 = v35;
  if ( (unsigned int)v35 <= v6 )
    v13 = v6;
  v14 = HIDWORD(v35);
  if ( HIDWORD(v35) <= v6 )
    v14 = v6;
  if ( v14 >= v13 )
    v14 = v13;
  v15 = v36;
  if ( v3 )
  {
    if ( v13 == 100 )
      v13 = *(_DWORD *)(v1 + 84);
  }
  else if ( PpmPerfBoostAtGuaranteed )
  {
    if ( v36 <= v13 )
    {
      v13 = v36;
      goto LABEL_28;
    }
    goto LABEL_67;
  }
  if ( v36 > v13 )
LABEL_67:
    v15 = v13;
LABEL_28:
  if ( v14 >= v15 )
    v14 = v15;
  v16 = 0;
  v17 = i;
  if ( i > v13 )
  {
    v17 = v13;
    if ( v8 )
      v16 = 2;
  }
  else if ( i < v14 )
  {
    v17 = v14;
  }
  if ( v3 == 2 || v3 == 4 )
  {
    v33 = PpmPerfBoostAtGuaranteed ? v15 : 100;
    if ( v17 >= v33 )
      v17 = v13;
  }
  v18 = (*(int (__fastcall **)(int, unsigned int, unsigned int, unsigned int, int, int *, __int64 *))(v1 + 68))(
          v38,
          v17,
          v14,
          v13,
          v16,
          &v37,
          &v40);
  v19 = v18;
  v20 = *(_DWORD *)(v39[0] + 84);
  if ( v20 >= i )
    v21 = 0;
  else
    v21 = i - v20;
  if ( v21 < v14 )
    v21 = v14;
  if ( v15 < v18 )
    v22 = v15;
  else
    v22 = v18;
  if ( v21 > v22 )
  {
    if ( v15 >= v18 )
      v21 = v18;
    else
      v21 = v15;
  }
  v23 = !*(_BYTE *)(v39[0] + 96) || !*(_BYTE *)(v1 + 116);
  v24 = v23;
  if ( !*(_BYTE *)(v1 + 180)
    && v23 == *(unsigned __int8 *)(v1 + 181)
    && v14 == *(_DWORD *)(v1 + 144)
    && v13 == *(_DWORD *)(v1 + 140)
    && v15 == *(_DWORD *)(v1 + 148)
    && (!v23 || v21 == *(_DWORD *)(v1 + 152) && v40 == *(_QWORD *)(v1 + 160)) )
  {
    return 0;
  }
  v25 = 0;
  if ( *(_DWORD *)(v1 + 24) )
  {
    v26 = 0;
    do
    {
      v27 = v26 + *(_DWORD *)(v1 + 32);
      v28 = *(_DWORD *)(v27 + 44);
      if ( v28 != v19 )
      {
        *(_DWORD *)(v27 + 56) = v28;
        v29 = *(_DWORD *)(v27 + 48);
        *(_DWORD *)(v27 + 44) = v19;
        *(_DWORD *)(v27 + 52) = v29;
        *(_DWORD *)(v27 + 48) = v37;
        *(_QWORD *)(v27 + 64) = v40;
      }
      ++v25;
      v26 += 80;
    }
    while ( v25 < *(_DWORD *)(v1 + 24) );
  }
  *(_BYTE *)(v1 + 180) = 0;
  *(_DWORD *)(v1 + 148) = v15;
  *(_DWORD *)(v1 + 120) = v19;
  *(_DWORD *)(v1 + 124) = v37;
  *(_DWORD *)(v1 + 160) = v40;
  v30 = HIDWORD(v40);
  *(_DWORD *)(v1 + 152) = v21;
  *(_DWORD *)(v1 + 164) = v30;
  KeQueryPerformanceCounter(v39, 0);
  v31 = v39[0];
  *(_DWORD *)(v1 + 172) = v39[1];
  *(_DWORD *)(v1 + 176) = 0;
  *(_BYTE *)(v1 + 181) = v24;
  *(_DWORD *)(v1 + 168) = v31;
  v32 = *(_DWORD *)(v1 + 24);
  *(_DWORD *)(v1 + 140) = v13;
  *(_DWORD *)(v1 + 144) = v14;
  if ( v32 > 1 )
    PpmEventDomainPerfStateChange(v1);
  return 1;
}
