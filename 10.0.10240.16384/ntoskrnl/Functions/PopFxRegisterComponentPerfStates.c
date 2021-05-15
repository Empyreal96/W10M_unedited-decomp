// PopFxRegisterComponentPerfStates 
 
int __fastcall PopFxRegisterComponentPerfStates(int a1, int a2, int a3, int a4, int a5, unsigned int *a6, unsigned int *a7)
{
  char v7; // r4
  int v8; // r4
  unsigned int *v9; // r6
  unsigned int v10; // r5
  unsigned int v11; // r10
  unsigned int v12; // r8
  unsigned int v13; // r7
  unsigned int v14; // r9
  unsigned int *v15; // r8
  unsigned int v16; // r2
  unsigned int v17; // r1
  unsigned __int16 *v18; // r0
  int v19; // r3
  int v20; // t1
  unsigned int v21; // r3
  unsigned int v22; // r9
  char *v23; // r7
  _BYTE *v24; // r0
  _BYTE *v25; // r5
  _DWORD *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // r1
  _BYTE *i; // r2
  _DWORD *v30; // r7
  unsigned int v31; // r9
  int v32; // r10
  _DWORD *v33; // r8
  bool v34; // zf
  int v35; // r3
  _BYTE *v36; // r8
  unsigned int v37; // r10
  _BYTE *v38; // r9
  unsigned __int16 *v39; // r7
  unsigned int v40; // t1
  int v41; // r7
  int v42; // r8
  unsigned int v44; // [sp+0h] [bp-48h] BYREF
  unsigned int v45; // [sp+4h] [bp-44h]
  int v46; // [sp+8h] [bp-40h]
  int v47; // [sp+Ch] [bp-3Ch]
  int v48; // [sp+10h] [bp-38h]
  unsigned int v49; // [sp+14h] [bp-34h]
  unsigned int v50; // [sp+18h] [bp-30h]
  unsigned int v51; // [sp+1Ch] [bp-2Ch]
  int v52; // [sp+20h] [bp-28h]
  int v53; // [sp+24h] [bp-24h]

  v7 = a3;
  v53 = a4;
  v46 = a2;
  v47 = a3;
  v48 = a1;
  v44 = 0;
  if ( a6 )
  {
    if ( !a7 )
    {
      v9 = a6;
      goto LABEL_8;
    }
    return -1073741811;
  }
  if ( !a7 )
    return -1073741811;
  v8 = PopFxPepPerfInfoQuery(a1, *(_DWORD *)(a2 + 16), (unsigned int **)&v44, 0);
  v9 = (unsigned int *)v44;
  if ( v8 < 0 )
  {
LABEL_56:
    PopFxPepPerfInfoFree(v9);
    return v8;
  }
  a2 = v46;
  v7 = v47;
  a1 = v48;
LABEL_8:
  if ( !*v9 )
  {
    v8 = -1073741811;
    goto LABEL_55;
  }
  v52 = PopPluginRegisterComponentPerfStates(a1, *(_DWORD *)(a2 + 16), (int)v9);
  if ( !v52 && (v7 & 1) == 0 )
  {
    v8 = -1073741822;
    goto LABEL_55;
  }
  v10 = *v9;
  v8 = RtlULongLongToULong(32 * *v9, *v9 >> 27, &v44);
  if ( v8 >= 0 )
  {
    if ( v44 >= 0xFFFFFFA0 )
      goto LABEL_54;
    v11 = (v44 + 103) & 0xFFFFFFF8;
    v12 = v11 + 8;
    v45 = v11 + 8;
    if ( v11 + 8 < v11 )
      goto LABEL_54;
    v8 = RtlULongLongToULong(40 * v10, (40 * (unsigned __int64)v10) >> 32, &v44);
    if ( v8 < 0 )
      goto LABEL_55;
    if ( v44 + v12 < v12 )
      goto LABEL_54;
    v13 = (v44 + v12 + 7) & 0xFFFFFFF8;
    v49 = v13;
    v14 = 0;
    if ( v10 )
    {
      v15 = v9 + 2;
      do
      {
        if ( !v15[5] )
        {
          v8 = RtlULongLongToULong(16 * v15[6], v15[6] >> 28, &v44);
          if ( v8 < 0 )
            goto LABEL_55;
          if ( v44 + v13 < v13 )
            goto LABEL_54;
          v13 += v44;
        }
        ++v14;
        v15 += 10;
      }
      while ( v14 < v10 );
      v12 = v45;
    }
    v16 = (v13 + 1) & 0xFFFFFFFE;
    v17 = 0;
    v50 = v16;
    if ( v10 )
    {
      v18 = (unsigned __int16 *)(v9 + 2);
      do
      {
        v20 = *v18;
        v18 += 20;
        v19 = v20;
        if ( v20 )
        {
          v21 = v19 + 2 + v16;
          if ( v21 < v16 )
            goto LABEL_54;
          v16 = v21;
        }
        ++v17;
      }
      while ( v17 < v10 );
    }
    v22 = (v16 + 7) & 0xFFFFFFF8;
    v51 = v22;
    v8 = RtlULongLongToULong(16 * v10, v10 >> 28, &v44);
    if ( v8 >= 0 )
    {
      v23 = (char *)(v44 + v22);
      if ( v44 + v22 >= v22 )
      {
        v8 = 0;
        v24 = (_BYTE *)ExAllocatePoolWithTag(512, v44 + v22, 1297630800);
        v25 = v24;
        if ( v24 )
        {
          memset(v24, 0, (int)v23);
          v26 = v25 + 96;
          *((_DWORD *)v25 + 5) = a5;
          *((_DWORD *)v25 + 21) = *v9;
          *((_DWORD *)v25 + 22) = v25 + 96;
          v27 = *v9;
          v44 = (unsigned int)&v25[v11];
          v28 = 0;
          *(_DWORD *)v44 = v27;
          for ( i = &v25[v12]; v28 < *v9; i += 40 )
          {
            *v26 = i;
            v26 += 8;
            ++v28;
          }
          v30 = &v25[v12];
          v31 = 0;
          v32 = (int)&v25[v49];
          if ( *v9 )
          {
            v33 = v9 + 2;
            do
            {
              v30[2] = v33[2];
              v30[3] = v33[3];
              v30[4] = v33[4];
              v30[5] = v33[5];
              v34 = v33[5] == 0;
              v35 = v33[6];
              v30[6] = v35;
              if ( v34 )
              {
                v30[7] = v32;
                memmove(v32, v33[7], 16 * v35);
                v32 += 16 * v30[6];
              }
              else
              {
                v30[7] = v33[7];
                v30[8] = v33[8];
                v30[9] = v33[9];
              }
              ++v31;
              v30 += 10;
              v33 += 10;
            }
            while ( v31 < *v9 );
            v12 = v45;
          }
          v36 = &v25[v12];
          v37 = 0;
          v38 = &v25[v50];
          if ( *v9 )
          {
            v39 = (unsigned __int16 *)(v9 + 2);
            do
            {
              if ( *v39 )
              {
                *((_DWORD *)v36 + 1) = v38;
                *(_WORD *)v36 = *v39;
                *((_WORD *)v36 + 1) = *v39 + 2;
                RtlCopyUnicodeString((unsigned __int16 *)v36, v39);
              }
              v40 = *v39;
              v39 += 20;
              ++v37;
              v36 += 40;
              v38 += 2 * (v40 >> 1) + 2;
            }
            while ( v37 < *v9 );
          }
          v41 = v46;
          *((_DWORD *)v25 + 7) = &v25[v51];
          *(_DWORD *)v25 = v41;
          KeInitializeEvent((int)(v25 + 4), 0, 1);
          v42 = v47;
          if ( (v47 & 6) != 0 )
            v25[50] = 1;
          v25[49] = v52;
          *((_DWORD *)v25 + 16) = PopFxComponentPerfWork;
          *((_DWORD *)v25 + 17) = v25;
          *((_DWORD *)v25 + 14) = 0;
          PopFxTracePerfRegistration(v25, 0);
          PopPepRegisterComponentPerfStates(*(_DWORD *)(v48 + 32), *(_DWORD *)(v41 + 16), v42, v53);
          __dmb(0xBu);
          *(_DWORD *)(v41 + 184) = v25;
          if ( a7 )
            *a7 = v44;
        }
        else
        {
          v8 = -1073741670;
        }
        goto LABEL_55;
      }
LABEL_54:
      v8 = -1073741675;
      goto LABEL_55;
    }
  }
LABEL_55:
  if ( !a6 )
    goto LABEL_56;
  return v8;
}
