// PnpCmResourcesToIoResources 
 
int __fastcall PnpCmResourcesToIoResources(int a1, int *a2, int a3)
{
  int v4; // r1
  int v5; // r4
  _DWORD *v6; // r0
  int v8; // lr
  int v9; // r5
  int v11; // r4
  int v12; // r6
  int v13; // r4
  _DWORD *v14; // r8
  unsigned int v15; // r9
  int v16; // r2
  unsigned __int8 *v17; // r5
  int v18; // r10
  __int16 v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  __int64 v23; // r0
  int v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // [sp+4h] [bp-2Ch]
  int v28[10]; // [sp+8h] [bp-28h] BYREF

  v4 = *a2;
  v5 = 0;
  v6 = a2 + 1;
  if ( !v4 )
    return 0;
  v8 = v4;
  do
  {
    v9 = v6[3];
    v6 += 4;
    v5 += v9;
    if ( v9 )
    {
      while ( *(_BYTE *)v6 != 5 )
      {
        v6 += 4;
        if ( !--v9 )
          goto LABEL_7;
      }
      return sub_80E678();
    }
LABEL_7:
    --v8;
  }
  while ( v8 );
  if ( !v5 )
    return 0;
  v11 = v5 + v4;
  v12 = ExAllocatePoolWithTag(1, 32 * v11 + 72, 1970499664);
  if ( !v12 )
    return 0;
  *(_DWORD *)(v12 + 4) = a2[1];
  *(_DWORD *)(v12 + 8) = a2[2];
  *(_DWORD *)(v12 + 12) = 0;
  *(_DWORD *)(v12 + 16) = 0;
  *(_DWORD *)(v12 + 20) = 0;
  *(_DWORD *)(v12 + 24) = 0;
  *(_DWORD *)(v12 + 28) = 1;
  *(_DWORD *)(v12 + 36) = v11;
  *(_WORD *)(v12 + 32) = 1;
  *(_WORD *)(v12 + 34) = 1;
  *(_BYTE *)(v12 + 40) = 1;
  *(_BYTE *)(v12 + 41) = 0x80;
  *(_BYTE *)(v12 + 42) = 3;
  *(_WORD *)(v12 + 44) = 0;
  *(_BYTE *)(v12 + 43) = 0;
  *(_WORD *)(v12 + 46) = 0;
  *(_DWORD *)(v12 + 48) = a3;
  v13 = v12 + 72;
  v14 = a2 + 1;
  v15 = 0;
  if ( *a2 )
  {
    v16 = PnpDefaultInterfaceType;
    v27 = PnpDefaultInterfaceType;
    while ( 1 )
    {
      if ( v15 )
      {
        *(_BYTE *)(v13 + 1) = -16;
        *(_BYTE *)v13 = 1;
        *(_BYTE *)(v13 + 2) = 0;
        *(_WORD *)(v13 + 4) = 0;
        *(_BYTE *)(v13 + 3) = 0;
        *(_WORD *)(v13 + 6) = 0;
        if ( *v14 == -1 )
          *(_DWORD *)(v13 + 8) = v16;
        else
          *(_DWORD *)(v13 + 8) = *v14;
        *(_DWORD *)(v13 + 12) = v14[1];
        *(_DWORD *)(v13 + 16) = 0;
        v13 += 32;
      }
      v17 = (unsigned __int8 *)(v14 + 4);
      v18 = 0;
      if ( v14[3] )
        break;
LABEL_22:
      ++v15;
      v14 = v17;
      if ( v15 >= *a2 )
        goto LABEL_23;
    }
    while ( 2 )
    {
      *(_BYTE *)v13 = 1;
      *(_BYTE *)(v13 + 1) = *v17;
      *(_BYTE *)(v13 + 2) = v17[1];
      v19 = *((_WORD *)v17 + 1);
      *(_BYTE *)(v13 + 3) = 0;
      *(_WORD *)(v13 + 6) = 0;
      *(_WORD *)(v13 + 4) = v19;
      v20 = *v17;
      if ( v20 == 2 )
      {
        if ( (*((_WORD *)v17 + 1) & 2) == 0 )
        {
          v21 = *((_DWORD *)v17 + 2);
          *(_DWORD *)(v13 + 12) = v21;
          goto LABEL_17;
        }
        *(_DWORD *)(v13 + 12) = -2;
        v26 = *((unsigned __int16 *)v17 + 3);
        *(_DWORD *)(v13 + 20) = 0;
        *(_DWORD *)(v13 + 8) = -1 - v26;
        *(_WORD *)(v13 + 16) = 4;
        *(_WORD *)(v13 + 18) = *((_WORD *)v17 + 2);
        *(_DWORD *)(v13 + 24) = *((_DWORD *)v17 + 3);
LABEL_18:
        v13 += 32;
LABEL_19:
        v22 = 0;
LABEL_20:
        v17 += v22 + 16;
        if ( (unsigned int)++v18 >= v14[3] )
        {
          v16 = v27;
          goto LABEL_22;
        }
        continue;
      }
      break;
    }
    if ( v20 != 3 && v20 != 1 )
    {
      switch ( v20 )
      {
        case 4:
          if ( (*((_WORD *)v17 + 1) & 0x80) != 0 )
          {
            *(_DWORD *)(v13 + 8) = *((_DWORD *)v17 + 2);
            *(_DWORD *)(v13 + 12) = *((_DWORD *)v17 + 2);
            *(_DWORD *)(v13 + 16) = *((_DWORD *)v17 + 1);
            *(_DWORD *)(v13 + 20) = v17[12];
          }
          else
          {
            *(_DWORD *)(v13 + 8) = *((_DWORD *)v17 + 1);
            *(_DWORD *)(v13 + 12) = *((_DWORD *)v17 + 1);
          }
          goto LABEL_18;
        case 5:
          v22 = *((_DWORD *)v17 + 1);
          goto LABEL_20;
        case 6:
          *(_DWORD *)(v13 + 12) = *((_DWORD *)v17 + 1);
          *(_DWORD *)(v13 + 16) = *((_DWORD *)v17 + 1) + *((_DWORD *)v17 + 2) - 1;
          v21 = *((_DWORD *)v17 + 2);
LABEL_17:
          *(_DWORD *)(v13 + 8) = v21;
          goto LABEL_18;
      }
      if ( v20 != 7 )
      {
        *(_DWORD *)(v13 + 8) = *((_DWORD *)v17 + 1);
        *(_DWORD *)(v13 + 12) = *((_DWORD *)v17 + 2);
        *(_DWORD *)(v13 + 16) = *((_DWORD *)v17 + 3);
        goto LABEL_18;
      }
    }
    LODWORD(v23) = RtlCmDecodeMemIoResource((int)v17, v28);
    v24 = v28[1];
    *(_DWORD *)(v13 + 8) = *((_DWORD *)v17 + 3);
    *(_DWORD *)(v13 + 12) = 1;
    v25 = v28[0];
    *(_DWORD *)(v13 + 16) = v28[0];
    *(_DWORD *)(v13 + 20) = v24;
    *(_QWORD *)(v13 + 24) = __PAIR64__(v24, v25) + v23 - 1;
    v13 += 32;
    goto LABEL_19;
  }
LABEL_23:
  *(_DWORD *)v12 = v13 - v12;
  return v12;
}
