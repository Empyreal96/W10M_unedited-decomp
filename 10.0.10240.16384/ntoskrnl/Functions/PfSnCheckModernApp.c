// PfSnCheckModernApp 
 
int __fastcall PfSnCheckModernApp(int *a1, int *a2)
{
  int v2; // r5
  int v3; // r7
  int v4; // r8
  int v5; // r9
  int v6; // r0
  int v7; // r4
  int v9; // r1
  unsigned int v10; // r6
  unsigned __int8 *v11; // r5
  int v12; // r4
  unsigned int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // t1
  unsigned __int8 *v17; // r0
  unsigned int v18; // r5
  int v19; // t1
  int v20; // t1
  int v21; // t1
  int v22; // t1
  int v23; // t1
  unsigned int v24; // r6
  int v25; // r2
  int v26; // r3
  int v27; // t1
  int v28; // t1
  int v29; // t1
  int v30; // t1
  int v31; // [sp+8h] [bp-1B8h] BYREF
  int v32; // [sp+Ch] [bp-1B4h] BYREF
  int *v33; // [sp+10h] [bp-1B0h]
  int *v34; // [sp+14h] [bp-1ACh]
  char v35[136]; // [sp+18h] [bp-1A8h] BYREF
  char v36[288]; // [sp+A0h] [bp-120h] BYREF

  v33 = a2;
  v34 = a1;
  v2 = 0;
  v3 = 0;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v31 = 256;
  v32 = 130;
  v5 = PsReferencePrimaryToken(v4);
  v6 = RtlQueryPackageIdentity(v5, (int)v36, (int)&v31, (int)v35, (int)&v32, 0);
  v7 = v6;
  if ( v6 < 0 )
  {
    if ( v6 != -1073741275 )
    {
LABEL_4:
      ObFastDereferenceObject((_DWORD *)(v4 + 244), v5);
      return v7;
    }
LABEL_3:
    v7 = 0;
    *v33 = v2;
    *v34 = v3;
    goto LABEL_4;
  }
  v9 = 314159;
  v10 = v31 - 2;
  v3 = 1;
  v11 = (unsigned __int8 *)v36;
  v12 = 314159;
  if ( v31 - 2 >= 8 )
  {
    v13 = v10 >> 3;
    v10 -= 8 * (v10 >> 3);
    do
    {
      v14 = 37 * (37 * (37 * (37 * (37 * (37 * v11[1] + v11[2]) + v11[3]) + v11[4]) + v11[5]) + v11[6])
          + 442596621 * *v11
          - 803794207 * v12;
      v15 = v11[7];
      v11 += 8;
      v12 = v14 + v15;
      --v13;
    }
    while ( v13 );
  }
  switch ( v10 )
  {
    case 2u:
      goto LABEL_9;
    case 6u:
      v27 = *v11++;
      v12 = 37 * v12 + v27;
      goto LABEL_32;
    case 4u:
LABEL_33:
      v29 = *v11++;
      v12 = 37 * v12 + v29;
LABEL_34:
      v30 = *v11++;
      v12 = 37 * v12 + v30;
LABEL_9:
      v16 = *v11++;
      v12 = 37 * v12 + v16;
LABEL_10:
      v12 = 37 * v12 + *v11;
      goto LABEL_11;
    case 1u:
      goto LABEL_10;
    case 3u:
      goto LABEL_34;
    case 5u:
LABEL_32:
      v28 = *v11++;
      v12 = 37 * v12 + v28;
      goto LABEL_33;
  }
  if ( v10 != 7 )
  {
LABEL_11:
    v17 = (unsigned __int8 *)v35;
    v18 = v32 - 2;
    if ( v32 - 2 >= 8 )
    {
      v24 = v18 >> 3;
      v18 -= 8 * (v18 >> 3);
      do
      {
        v25 = 37 * (37 * (37 * (37 * (37 * (37 * v17[1] + v17[2]) + v17[3]) + v17[4]) + v17[5]) + v17[6])
            + 442596621 * *v17
            - 803794207 * v9;
        v26 = v17[7];
        v17 += 8;
        v9 = v25 + v26;
        --v24;
      }
      while ( v24 );
    }
    if ( v18 == 4 )
      goto LABEL_16;
    if ( v18 != 6 )
    {
      switch ( v18 )
      {
        case 2u:
          goto LABEL_18;
        case 1u:
          goto LABEL_19;
        case 3u:
LABEL_17:
          v22 = *v17++;
          v9 = 37 * v9 + v22;
LABEL_18:
          v23 = *v17++;
          v9 = 37 * v9 + v23;
LABEL_19:
          v9 = 37 * v9 + *v17;
LABEL_20:
          v2 = v9 + v12;
          goto LABEL_3;
        case 5u:
          goto LABEL_15;
      }
      if ( v18 != 7 )
        goto LABEL_20;
      v9 = 37 * v9 + *v17++;
    }
    v19 = *v17++;
    v9 = 37 * v9 + v19;
LABEL_15:
    v20 = *v17++;
    v9 = 37 * v9 + v20;
LABEL_16:
    v21 = *v17++;
    v9 = 37 * v9 + v21;
    goto LABEL_17;
  }
  return sub_80885C();
}
