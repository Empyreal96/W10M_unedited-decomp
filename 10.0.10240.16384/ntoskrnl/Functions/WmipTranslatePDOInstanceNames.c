// WmipTranslatePDOInstanceNames 
 
int __fastcall WmipTranslatePDOInstanceNames(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r10
  int v5; // r4
  int v6; // r6
  int result; // r0
  char *v8; // r5
  unsigned int *v9; // r7
  unsigned int v10; // r9
  int v11; // r8
  unsigned int v12; // r3
  _DWORD *v13; // r4
  int v14; // r1
  unsigned int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r7
  unsigned int v18; // r10
  int v19; // r1
  char *v20; // r2
  int v21; // r5
  _WORD *v22; // r5
  unsigned int v23; // r6
  unsigned int v24; // r2
  unsigned int v25; // r5
  unsigned int v26; // r4
  int v27; // r1
  unsigned int v28; // r4
  _DWORD *v29; // r6
  unsigned int v30; // r2
  int v31; // r1
  unsigned int v32; // [sp+0h] [bp-60h]
  int v33; // [sp+4h] [bp-5Ch]
  int v34; // [sp+8h] [bp-58h]
  unsigned int v35; // [sp+Ch] [bp-54h]
  int v36; // [sp+10h] [bp-50h]
  unsigned int *v37; // [sp+14h] [bp-4Ch]
  char *v38; // [sp+18h] [bp-48h]
  int v39; // [sp+1Ch] [bp-44h]
  unsigned int *v43; // [sp+2Ch] [bp-34h]
  int v45; // [sp+38h] [bp-28h] BYREF
  int v46; // [sp+3Ch] [bp-24h]

  v4 = *(unsigned int **)(a1 + 12);
  v5 = *(_DWORD *)(a1 + 28);
  v43 = v4;
  v6 = 0;
  result = 0;
  v8 = 0;
  v9 = v4;
  v10 = (v5 + 1) & 0xFFFFFFFE;
  v36 = 0;
  v37 = v4;
  v32 = 0;
  v33 = 0;
  v11 = 0;
  v38 = 0;
  v34 = 1;
  v35 = 0;
  do
  {
    v39 = 0;
    if ( v9[4] )
    {
      v13 = v9 + 5;
      while ( 1 )
      {
        result = memcmp((unsigned int)v13, (unsigned int)WmipDataProviderPnpidGuid, 16);
        if ( !result
          || (result = memcmp((unsigned int)v13, (unsigned int)WmipDataProviderPnPIdInstanceNamesGuid, 16)) == 0 )
        {
          v34 = 0;
          if ( v11 )
            return sub_7D63E4();
        }
        v14 = v13[4];
        if ( (v14 & 0x20) != 0 )
          break;
LABEL_12:
        v13 += 7;
        if ( ++v39 >= v9[4] )
          goto LABEL_3;
      }
      if ( !v8 )
      {
        v15 = v4[1];
        v16 = v4;
        while ( v15 )
        {
          v16 = (unsigned int *)((char *)v16 + v15);
          v15 = v16[1];
        }
        v8 = (char *)v16 + ((*v16 + 1) & 0xFFFFFFFE);
        v32 = (char *)v4 - v8 + a3;
      }
      if ( v35 < v13[5] )
        v35 = v13[5];
      v6 = v13[6];
      if ( v6 == v36 )
      {
        v13[4] = v14 | 8;
        v13[6] = v38;
        goto LABEL_29;
      }
      result = IoGetDeviceInstanceName(v13[6], (int)&v45);
      if ( result < 0 )
        goto LABEL_29;
      if ( v34 )
      {
        if ( !v11 )
        {
          v11 = v6;
          ObfReferenceObject(v6);
          goto LABEL_25;
        }
        if ( v11 == v6 )
        {
LABEL_25:
          v17 = (unsigned __int16)v45;
          v18 = (unsigned __int16)v45 + 4;
          v10 += v18;
          if ( v33 || v18 > v32 )
          {
            v33 = 1;
          }
          else
          {
            v19 = v46;
            v36 = v6;
            v13[4] |= 8u;
            v20 = (char *)(v8 - (char *)v37);
            v13[6] = v8 - (char *)v37;
            *(_WORD *)v8 = v17 + 2;
            v21 = (int)(v8 + 2);
            v38 = v20;
            memmove(v21, v19, v17);
            v22 = (_WORD *)(v21 + v17);
            *v22 = 95;
            v8 = (char *)(v22 + 1);
            v32 -= v18;
          }
          result = RtlFreeAnsiString(&v45);
          v9 = v37;
          v4 = v43;
LABEL_29:
          if ( a2 == 11 )
            result = ObfDereferenceObject(v6);
          goto LABEL_12;
        }
      }
      v34 = 0;
      if ( v11 )
      {
        ObfDereferenceObject(v11);
        v11 = 0;
      }
      goto LABEL_25;
    }
LABEL_3:
    v36 = 0;
    v12 = v9[1];
    v9 = (unsigned int *)((char *)v9 + v12);
    v37 = v9;
  }
  while ( v12 );
  if ( v11 && v34 )
  {
    if ( IoGetDeviceInstanceName(v6, (int)&v45) >= 0 )
    {
      v23 = (unsigned int)(v8 + 7) & 0xFFFFFFF8;
      v24 = v23 - (_DWORD)v8;
      v25 = (unsigned __int16)v45;
      v26 = 2 * ((unsigned __int16)v45 + 42);
      v10 += v26 + v24;
      if ( v33 || v26 > v32 - v24 )
      {
        v33 = 1;
      }
      else if ( !*(_DWORD *)(a4 + 12) )
      {
        ObfReferenceObject(v11);
        *(_DWORD *)(a4 + 12) = v11;
        *(_DWORD *)(a4 + 28) = v35;
        v9[1] = v23 - (_DWORD)v9;
        memset((_BYTE *)v23, 0, 76);
        *(_DWORD *)(v23 + 16) = 2;
        *(_DWORD *)v23 = v26;
        *(_DWORD *)(v23 + 36) = 40;
        *(_DWORD *)(v23 + 40) = v35;
        *(_DWORD *)(v23 + 20) = -943770158;
        *(_DWORD *)(v23 + 24) = 298953435;
        *(_DWORD *)(v23 + 28) = -1610593601;
        *(_DWORD *)(v23 + 32) = 271124169;
        v27 = v46;
        *(_DWORD *)(v23 + 44) = 76;
        v28 = v23 + 78;
        *(_WORD *)(v23 + 76) = v25 + 2;
        memmove(v23 + 78, v27, v25);
        *(_WORD *)(v25 + v28) = 95;
        v29 = (_DWORD *)(v23 + 48);
        v29[4] = 4;
        v29[5] = 1;
        v30 = (unsigned __int16)v45;
        v31 = v46;
        *v29 = -943770157;
        v29[1] = 298953435;
        v29[2] = -1610593601;
        v29[3] = 271124169;
        v29[6] = v30 + 80;
        *(_WORD *)(v25 + v28 + 2) = v30;
        memmove(v25 + v28 + 4, v31, v30);
      }
      RtlFreeAnsiString(&v45);
    }
    result = ObfDereferenceObject(v11);
  }
  *v4 = v10;
  if ( v33 )
    *(_DWORD *)(a1 + 28) = 4;
  else
    *(_DWORD *)(a1 + 28) = v10;
  return result;
}
