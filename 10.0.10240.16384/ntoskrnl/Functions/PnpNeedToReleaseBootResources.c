// PnpNeedToReleaseBootResources 
 
int __fastcall PnpNeedToReleaseBootResources(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int *v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r7
  _DWORD *v6; // r3
  unsigned int v7; // lr
  unsigned __int8 *v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // r2
  int v11; // r6
  unsigned int v12; // r7
  unsigned __int8 *v13; // r4
  int v14; // r3
  int v16; // r1
  unsigned int v17; // r6
  unsigned __int64 v18; // r2
  unsigned int v19; // r5
  unsigned int v20; // r0
  unsigned int v21; // lr
  unsigned int v22; // r8
  unsigned int v23; // r9
  __int64 v24; // r0
  int v25; // r0
  int v26; // kr00_4
  unsigned int v27; // r1
  int v28; // [sp+0h] [bp-60h]
  unsigned __int8 *v29; // [sp+4h] [bp-5Ch]
  unsigned int v30; // [sp+8h] [bp-58h]
  unsigned int v31; // [sp+Ch] [bp-54h]
  int v32; // [sp+10h] [bp-50h]
  unsigned int v33; // [sp+14h] [bp-4Ch]
  _DWORD *v34; // [sp+1Ch] [bp-44h]
  unsigned int v35; // [sp+20h] [bp-40h]
  unsigned int v36; // [sp+24h] [bp-3Ch]
  __int64 v38; // [sp+30h] [bp-30h] BYREF
  __int64 v39; // [sp+38h] [bp-28h] BYREF

  v3 = *(unsigned int **)(a1 + 360);
  *a3 = 0;
  v34 = a2;
  if ( !v3 )
    return 0;
  if ( *a2 != 1 )
    return 0;
  v4 = *v3;
  v36 = *v3;
  if ( !*v3 )
    return 0;
  v5 = 0;
  v6 = v3 + 1;
  v32 = 0;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v7 = v6[3];
    v8 = (unsigned __int8 *)(v6 + 4);
    v9 = 0;
    v35 = v7;
    v29 = (unsigned __int8 *)(v6 + 4);
    v31 = 0;
    if ( v7 )
      break;
LABEL_30:
    v32 = ++v5;
    v6 = v8;
    if ( v5 >= v4 )
      return 0;
  }
  while ( 1 )
  {
    v10 = *v8;
    v11 = 0;
    v30 = v10;
    if ( *v8 )
    {
      if ( v10 == 5 )
      {
        v11 = *((_DWORD *)v8 + 1);
        goto LABEL_28;
      }
      if ( v10 < 8 )
        break;
    }
LABEL_28:
    v8 += v11 + 16;
    ++v9;
    v29 = v8;
    v31 = v9;
    if ( v9 >= v7 )
    {
      v4 = v36;
      v5 = v32;
      goto LABEL_30;
    }
  }
  v28 = 0;
  v12 = 0;
  v13 = (unsigned __int8 *)(a2 + 5);
  v33 = a2[4];
  if ( v33 )
  {
    do
    {
      v14 = *v13;
      if ( v14 == 5 )
        return sub_80E710();
      if ( v10 == v14 )
      {
        v16 = 1;
        v28 = 1;
        if ( v10 != 2 )
        {
          switch ( v10 )
          {
            case 1u:
            case 3u:
            case 7u:
              LODWORD(v24) = RtlCmDecodeMemIoResource((int)v8, &v38);
              v22 = HIDWORD(v38);
              v23 = v38;
              v19 = (unsigned __int64)(v24 + v38 - 1) >> 32;
              v17 = v24 + v38 - 1;
              v25 = RtlCmDecodeMemIoResource((int)v13, &v39);
              v21 = v39;
              v26 = v25;
              v20 = HIDWORD(v39);
              v18 = __PAIR64__(v27, v26) + v39 - 1;
              v16 = 1;
              goto LABEL_16;
            case 4u:
              v17 = *((_DWORD *)v8 + 1);
              LODWORD(v18) = *((_DWORD *)v13 + 1);
              v16 = 1;
              goto LABEL_15;
            case 6u:
              v23 = *((_DWORD *)v8 + 1);
              v21 = *((_DWORD *)v13 + 1);
              v22 = 0;
              v17 = *((_DWORD *)v8 + 2) + v23 - 1;
              v20 = 0;
              v16 = 1;
              v19 = 0;
              v18 = *((_DWORD *)v13 + 2) + v21 - 1;
              v38 = v23;
              v39 = v21;
              goto LABEL_16;
            default:
              v16 = 1;
              v38 = 0i64;
              v39 = 0i64;
              goto LABEL_25;
          }
        }
        v17 = *((_DWORD *)v8 + 2);
        LODWORD(v18) = *((_DWORD *)v13 + 2);
LABEL_15:
        v19 = 0;
        HIDWORD(v18) = 0;
        v39 = (unsigned int)v18;
        v20 = 0;
        v21 = v18;
        v38 = v17;
        v22 = 0;
        v23 = v17;
LABEL_16:
        if ( v22 < v20 || v22 <= v20 && v23 < v21 || v19 > HIDWORD(v18) )
        {
          v8 = v29;
          v10 = v30;
        }
        else
        {
          v8 = v29;
          if ( v19 < HIDWORD(v18) || v17 <= (unsigned int)v18 )
          {
LABEL_25:
            if ( v8[1] == v13[1] && *((unsigned __int16 *)v8 + 1) == *((unsigned __int16 *)v13 + 1) )
            {
              v9 = v31;
              v11 = 0;
              a2 = v34;
              v7 = v35;
              goto LABEL_28;
            }
          }
          v10 = v30;
        }
      }
      else
      {
        v16 = v28;
      }
      v13 += 16;
      ++v12;
    }
    while ( v12 < v33 );
    if ( v16 )
    {
      *a3 = 1;
      return 0;
    }
  }
  return 1;
}
