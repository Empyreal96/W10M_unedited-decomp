// WmipPrepareWnodeSI 
 
int __fastcall WmipPrepareWnodeSI(int a1, _DWORD *a2, int *a3, int *a4, _BYTE *a5, _BYTE *a6)
{
  int v6; // r9
  _DWORD *v7; // r10
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r4
  int v11; // r5
  unsigned int v14; // r6
  int v15; // r7
  _DWORD *v16; // r4
  int v17; // r3
  _BYTE *v18; // r10
  int v19; // r3
  int v20; // r6
  unsigned int v21; // r7
  unsigned int v22; // r8
  unsigned __int16 *v23; // r1
  unsigned int v24; // r6
  _DWORD **v25; // r4
  int *v26; // r7
  int v27; // r6
  int v28; // t1
  int v29; // r3
  _DWORD *v30; // t1
  unsigned __int16 *v31; // [sp+8h] [bp-60h]
  int v32; // [sp+Ch] [bp-5Ch]
  int v33; // [sp+10h] [bp-58h]
  _DWORD *v34; // [sp+14h] [bp-54h] BYREF
  _BYTE *v35; // [sp+18h] [bp-50h]
  int v36; // [sp+1Ch] [bp-4Ch] BYREF
  int v37; // [sp+20h] [bp-48h]
  int *v38; // [sp+24h] [bp-44h]
  int *v39; // [sp+28h] [bp-40h]
  int v40; // [sp+2Ch] [bp-3Ch] BYREF
  _DWORD *v41; // [sp+30h] [bp-38h]
  _WORD v42[24]; // [sp+38h] [bp-30h] BYREF

  v38 = a3;
  v39 = a4;
  v37 = 0;
  v6 = 0;
  *a5 = 1;
  v7 = *(_DWORD **)(a1 + 40);
  v34 = a2;
  v35 = a5;
  v8 = 0;
  if ( !v7 || !v7[5] )
    return -1073741055;
  v33 = 0;
  v9 = v7[11];
  v10 = v7[12];
  v11 = v7[13];
  a2[6] = v7[10];
  a2[7] = v9;
  a2[8] = v10;
  a2[9] = v11;
  if ( (v7[2] & 1) != 0 )
    return sub_816498();
  *a6 = 0;
  v14 = WmipCountedToSz((char *)a2 + a2[12]);
  v31 = (unsigned __int16 *)v14;
  if ( v14 )
  {
    v15 = 0;
    v36 = *v39;
    v37 = v36;
    v8 = v36;
    v6 = 0;
    v34 = 0;
    v32 = 0;
    v40 = *v38;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    if ( v7[5] )
    {
      v16 = (_DWORD *)v7[8];
      v17 = (int)(v7 + 8);
      v18 = v35;
      v41 = (_DWORD *)v17;
      if ( v16 == (_DWORD *)v17 )
        goto LABEL_22;
      while ( 1 )
      {
        if ( v15 )
        {
LABEL_21:
          v8 = v36;
          v6 = (int)v34;
          goto LABEL_22;
        }
        v19 = v16[2];
        if ( (v19 & 0x89000) == 0 )
        {
          if ( (v19 & 1) != 0 )
          {
            v20 = v16[12];
            v21 = *(_DWORD *)v20;
            v22 = wcslen((unsigned __int16 *)(v20 + 4));
            if ( wcslen(v31) <= v22 )
              goto LABEL_29;
            v23 = (unsigned __int16 *)(v20 + 4);
            v14 = (unsigned int)v31;
            if ( wcsnicmp((int)v31, v23, v22) )
              goto LABEL_30;
            v24 = wtol((int)&v31[v22]);
            if ( !WmipIsNumber(&v31[v22]) )
              goto LABEL_29;
            if ( v24 < v21 )
              goto LABEL_29;
            if ( v24 >= v16[9] + v21 )
              goto LABEL_29;
            if ( v24 >= 0xF423F )
              goto LABEL_29;
            RtlStringCbPrintfW(v42, 0xEu, (int)L"%d", v24);
            if ( wcsicmp((int)v42, &v31[v22]) )
              goto LABEL_29;
            a2[11] |= 0x80u;
            a2[1] = v16[11];
            a2[13] = v24 - v21;
          }
          else
          {
            if ( (v19 & 2) == 0 )
            {
              WmipReferenceEntry((int)v16);
              v33 = WmipAddProviderIdToPIList(&v36, (int *)&v34, &v40, v37, (int)v16);
              if ( v33 < 0 )
              {
                v15 = 1;
                v32 = 1;
              }
              goto LABEL_20;
            }
            v26 = (int *)v16[12];
            v27 = 0;
            if ( !v16[9] )
            {
LABEL_29:
              v14 = (unsigned int)v31;
LABEL_30:
              v15 = v32;
              goto LABEL_20;
            }
            while ( 1 )
            {
              v28 = *v26++;
              if ( !wcsicmp(v28, v31) )
                break;
              if ( (unsigned int)++v27 >= v16[9] )
                goto LABEL_29;
            }
            a2[11] |= 0x80u;
            v29 = v16[11];
            a2[13] = v27;
            a2[1] = v29;
          }
          v15 = 1;
          v14 = (unsigned int)v31;
          v32 = 1;
          *v18 = 0;
        }
LABEL_20:
        v16 = (_DWORD *)*v16;
        if ( v16 == v41 )
          goto LABEL_21;
      }
    }
    v18 = v35;
    v33 = -1073741055;
LABEL_22:
    ExFreePoolWithTag(v14);
    KeReleaseMutex((int)&WmipSMMutex);
  }
  else
  {
    v18 = v35;
    v33 = -1073741670;
  }
  if ( *v18 )
  {
    *v38 = v6;
    *v39 = v8;
  }
  else if ( v8 )
  {
    if ( v6 )
    {
      v25 = (_DWORD **)v8;
      do
      {
        v30 = *v25++;
        WmipUnreferenceEntry((int *)&WmipISChunkInfo, v30);
        --v6;
      }
      while ( v6 );
    }
    if ( v8 != v37 )
      ExFreePoolWithTag(v8);
  }
  return v33;
}
