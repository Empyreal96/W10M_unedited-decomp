// RaspCreateSegmentList 
 
int __fastcall RaspCreateSegmentList(int a1, int a2, unsigned int a3, _DWORD *a4, _DWORD *a5, int a6)
{
  _DWORD *v7; // lr
  int v8; // r10
  unsigned __int16 *v10; // r3
  int v11; // r2
  int v12; // r6
  unsigned int v13; // r8
  int v14; // r0
  int v15; // r4
  unsigned __int16 *v16; // r7
  unsigned int v17; // r5
  int v18; // r1
  _BYTE *v19; // r0
  _BYTE *v20; // r5
  _BYTE *v21; // r4
  unsigned int v22; // r5
  int v23; // r8
  unsigned int v24; // lr
  unsigned int v25; // r0
  int v26; // r1
  unsigned int v27; // r9
  unsigned __int16 *v28; // r2
  int v29; // r7
  int v30; // r7
  int v31; // r0
  int v32; // r9
  int v33; // r1
  int v34; // r0
  int v35; // r0
  int v36; // r0
  char v37; // r3
  int v38; // r4
  int v39; // r1
  char v40; // r3
  int v41; // r0
  char v42; // r3
  unsigned __int16 *v43; // r2
  int v44; // r0
  int v45; // r3
  _DWORD *v46; // r3
  unsigned __int16 *v47; // [sp+0h] [bp-30h]
  _BYTE *v49; // [sp+8h] [bp-28h]
  unsigned int v50; // [sp+10h] [bp-20h]

  v7 = a4;
  v8 = a2;
  if ( a3 < 2 )
    return sub_54DB80();
  v10 = *(unsigned __int16 **)(a1 + 26);
  v11 = 0;
  v12 = 0;
  v13 = a3 - 2;
  v47 = v10;
  v50 = a3 - 2;
  v14 = 0;
  if ( a3 == 2 )
    goto LABEL_57;
  v15 = a2;
  do
  {
    v16 = &v10[v11];
    v17 = v14 + 1;
    v18 = v14 + 1;
    if ( v14 == *v16 )
    {
      if ( v11 )
        v18 = *(v16 - 1) + 1;
      else
        v18 = 0;
      ++v11;
    }
    if ( (*(_BYTE *)(v15 + 16) & 1) != 0 || (*(_BYTE *)(17 * v18 + v8 + 16) & 1) == 0 )
      ++v12;
    v15 += 17;
    ++v14;
  }
  while ( v17 < v13 );
  v7 = a4;
  if ( !v12 )
  {
LABEL_57:
    *v7 = 0;
    v38 = 0;
  }
  else
  {
    v19 = (_BYTE *)RaspAllocateMemory(13 * v12);
    v20 = v19;
    v49 = v19;
    if ( v19 )
    {
      memset(v19, 0, 13 * v12);
      v21 = v20;
      v22 = 0;
      v23 = 0;
      while ( 1 )
      {
        v24 = v22 + 1;
        v25 = v22 - 1;
        v26 = v22 + 2;
        v27 = v22 + 1;
        if ( v22 )
        {
          if ( v23 )
          {
            v43 = &v47[v23];
            if ( v22 == *(v43 - 1) + 1 )
              v25 = *v43;
          }
        }
        else
        {
          v25 = *v47;
        }
        v28 = &v47[v23];
        v29 = *v28;
        if ( v22 == v29 - 1 )
        {
          if ( v23 )
            v26 = *(v28 - 1) + 1;
          else
            v26 = 0;
        }
        if ( v22 == v29 )
        {
          if ( v23 )
          {
            v45 = *(v28 - 1);
            v27 = v45 + 1;
            v26 = v45 + 2;
          }
          else
          {
            v27 = 0;
            v26 = 1;
          }
          ++v23;
        }
        v30 = 17 * v22 + v8;
        if ( (*(_BYTE *)(v30 + 16) & 1) != 0 )
        {
          v31 = 17 * v27 + v8;
          if ( (*(_BYTE *)(v31 + 16) & 1) != 0 )
          {
            *(_DWORD *)v21 = v30;
            *((_DWORD *)v21 + 1) = v31;
            *((_DWORD *)v21 + 2) = v31;
            v21[12] = 1;
          }
          else
          {
            v39 = 17 * v26 + v8;
            v40 = *(_BYTE *)(v39 + 16);
            *(_DWORD *)v21 = v30;
            *((_DWORD *)v21 + 1) = v31;
            if ( (v40 & 1) != 0 )
            {
              *((_DWORD *)v21 + 2) = v39;
              v42 = 2;
            }
            else
            {
              v41 = RaspInterpolatePoint(v31, v39, a6);
              *((_DWORD *)v21 + 2) = v41;
              if ( !v41 )
                goto LABEL_65;
              v24 = v22 + 1;
              v42 = 4;
            }
            v21[12] = v42;
            if ( v27 > v22 )
            {
              v22 = v24;
              if ( v24 == v47[v23] )
                ++v23;
            }
          }
        }
        else
        {
          if ( !v22 && (*(_BYTE *)(17 * v25 + v8 + 16) & 1) != 0
            || v23 && v22 == v47[v23 - 1] + 1 && (*(_BYTE *)(17 * v25 + v8 + 16) & 1) != 0 )
          {
            goto LABEL_29;
          }
          v32 = 17 * v27 + v8;
          v33 = 17 * v22 + v8;
          v34 = 17 * v25 + v8;
          if ( (*(_BYTE *)(v32 + 16) & 1) != 0 )
          {
            v44 = RaspInterpolatePoint(v34, v33, a6);
            *(_DWORD *)v21 = v44;
            if ( !v44 )
              goto LABEL_65;
            *((_DWORD *)v21 + 1) = v30;
            *((_DWORD *)v21 + 2) = v32;
            v37 = 3;
          }
          else
          {
            v35 = RaspInterpolatePoint(v34, v33, a6);
            *(_DWORD *)v21 = v35;
            if ( !v35
              || (*((_DWORD *)v21 + 1) = v30,
                  v36 = RaspInterpolatePoint(17 * v22 + v8, v32, a6),
                  (*((_DWORD *)v21 + 2) = v36) == 0) )
            {
LABEL_65:
              v38 = -1073741670;
              RaspDestroySegmentList(v49, v12, a6);
              *a5 = 0;
              v46 = a4;
              goto LABEL_59;
            }
            v37 = 5;
          }
          v21[12] = v37;
        }
        v21 += 13;
LABEL_29:
        if ( ++v22 >= v50 )
        {
          v38 = 0;
          *a5 = v12;
          *a4 = v49;
          return v38;
        }
      }
    }
    v38 = -1073741670;
  }
  v46 = a5;
LABEL_59:
  *v46 = 0;
  return v38;
}
