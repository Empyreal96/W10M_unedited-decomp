// RtlpIsNameInExpressionPrivate 
 
int __fastcall RtlpIsNameInExpressionPrivate(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v5; // r7
  int v8; // r5
  __int64 v10; // kr00_8
  unsigned int v11; // r4
  unsigned int v12; // r9
  unsigned int v13; // r6
  unsigned int v14; // r1
  __int16 *v15; // r4
  char *v16; // r2
  int v17; // r1
  unsigned int v18; // r0
  int v19; // r5
  unsigned int v20; // r7
  unsigned int v21; // r10
  unsigned int v22; // r9
  int v23; // r3
  unsigned int v24; // r4
  __int16 v25; // r9
  int v26; // r1
  int v27; // r0
  int v28; // r5
  __int16 v29; // r2
  unsigned __int16 v30; // r3
  bool v31; // zf
  char *v32; // r3
  char *v33; // r1
  unsigned int v34; // r0
  unsigned int v35; // t1
  __int16 *v36; // r2
  unsigned int v37; // t1
  int v38; // r2
  unsigned int v39; // r7
  unsigned int v40; // r1
  unsigned int v41; // r2
  char *v42; // [sp+0h] [bp-98h]
  int v43; // [sp+4h] [bp-94h]
  __int16 *v44; // [sp+8h] [bp-90h]
  int v45; // [sp+10h] [bp-88h]
  int v46; // [sp+14h] [bp-84h]
  unsigned int v47; // [sp+18h] [bp-80h]
  int v48[2]; // [sp+20h] [bp-78h] BYREF
  unsigned int v49; // [sp+28h] [bp-70h]
  int v50; // [sp+2Ch] [bp-6Ch]
  int v51; // [sp+30h] [bp-68h]
  __int16 v52[16]; // [sp+38h] [bp-60h] BYREF
  char v53[64]; // [sp+58h] [bp-40h] BYREF

  v5 = *a2;
  v50 = a3;
  v51 = a4;
  v46 = 0;
  v43 = 0;
  if ( !v5 || (v8 = *a1) == 0 )
    return !(*a1 + v5);
  if ( v8 == 2 && **((_WORD **)a1 + 1) == 42 )
    return 1;
  if ( **((_WORD **)a1 + 1) == 42 )
  {
    v10 = *(_QWORD *)a1;
    v48[0] = *(_DWORD *)a1;
    v11 = HIDWORD(v10) + 2;
    v12 = (unsigned __int16)(LOWORD(v48[0]) - 2);
    LOWORD(v48[0]) -= 2;
    v48[1] = HIDWORD(v10) + 2;
    if ( !RtlDoesNameContainWildCards(v48) )
    {
      if ( v5 < (unsigned __int16)(v8 - 2) )
        return 0;
      v13 = (v5 - v12) >> 1;
      if ( v50 )
      {
        v14 = 0;
        if ( v12 >> 1 )
        {
          while ( *(unsigned __int16 *)(a4 + 2 * *(unsigned __int16 *)(*((_DWORD *)a2 + 1) + 2 * (v14 + v13))) == *(unsigned __int16 *)(v11 + 2 * v14) )
          {
            v14 = (unsigned __int16)(v14 + 1);
            if ( v14 >= v12 >> 1 )
              return 1;
          }
          return 0;
        }
      }
      else if ( memcmp(v11, *((_DWORD *)a2 + 1) + 2 * v13, v12) )
      {
        return 0;
      }
      return 1;
    }
  }
  v52[0] = 0;
  v15 = v52;
  v16 = v53;
  v17 = 1;
  v18 = 0;
  v19 = (unsigned __int16)(2 * v8);
  v45 = v19;
  v44 = v52;
  v42 = v53;
  v49 = 1;
  v47 = 0;
  while ( 2 )
  {
    if ( v18 >= *a2 )
    {
      v43 = 1;
      if ( (unsigned __int16)v15[v17 - 1] == v19 )
        break;
    }
    else
    {
      v16 = v42;
      v46 = *(unsigned __int16 *)(*((_DWORD *)a2 + 1) + 2 * (v18 >> 1));
      v47 = (unsigned __int16)(v18 + 2);
    }
    v20 = 0;
    v21 = 0;
    v22 = 0;
    while ( 2 )
    {
      v23 = ((unsigned __int16)v44[v22] + 1) >> 1;
      v48[0] = v22 + 1;
      v24 = (unsigned __int16)v23;
      v25 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v26 = *a1;
            if ( v24 == v26 )
              goto LABEL_47;
            v24 = (unsigned __int16)(v25 + v24);
            v27 = 2 * v24;
            v25 = 2;
            if ( v24 == v26 )
            {
              *(_WORD *)&v16[2 * v20++] = v45;
              goto LABEL_47;
            }
            v28 = *(unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * (v24 >> 1));
            if ( v20 >= 0xE )
              return sub_51C458(v27);
            if ( v28 != 42 )
              break;
LABEL_43:
            v16 = v42;
            *(_WORD *)&v42[2 * v20] = v27;
            v39 = v20 + 1;
            *(_WORD *)&v42[2 * v39] = v27 + 3;
            v20 = v39 + 1;
          }
          if ( v28 != 60 )
            break;
          v38 = 0;
          if ( v46 != 46 || v43 )
            goto LABEL_43;
          v40 = *a2;
          if ( v47 < v40 )
          {
            v41 = v47;
            while ( *(_WORD *)(*((_DWORD *)a2 + 1) + 2 * (v41 >> 1)) != 46 )
            {
              v41 = (unsigned __int16)(v41 + 2);
              if ( v41 >= v40 )
              {
                v38 = 0;
                goto LABEL_56;
              }
            }
            v38 = 1;
          }
LABEL_56:
          if ( v38 )
            goto LABEL_43;
          v16 = v42;
          *(_WORD *)&v42[2 * v20++] = v27 + 3;
        }
        v29 = v27 + 4;
        if ( v28 == 62 )
          JUMPOUT(0x51C4D4);
        if ( v28 != 34 )
        {
          if ( !v43 )
            goto LABEL_28;
LABEL_47:
          v32 = v42;
          goto LABEL_33;
        }
        if ( !v43 )
          break;
        v16 = v42;
      }
      if ( v46 == 46 )
      {
        v32 = v42;
        *(_WORD *)&v42[2 * v20++] = v29;
      }
      else
      {
LABEL_28:
        if ( v28 == 63 )
          JUMPOUT(0x51C4F0);
        if ( v50 )
          v30 = *(_WORD *)(v51 + 2 * v46);
        else
          v30 = v46;
        v31 = v28 == v30;
        v32 = v42;
        if ( v31 )
          *(_WORD *)&v42[2 * v20++] = v29;
      }
LABEL_33:
      v22 = v48[0];
      if ( v48[0] < v49 )
      {
        v33 = &v32[2 * v21];
        while ( v21 < v20 )
        {
          v35 = *(unsigned __int16 *)v33;
          v33 += 2;
          v34 = v35;
          v36 = &v44[v22];
          do
          {
            v37 = (unsigned __int16)*v36++;
            if ( v37 >= v34 )
              break;
            ++v22;
          }
          while ( v22 < v49 );
          ++v21;
          if ( v22 >= v49 )
            goto LABEL_39;
        }
        v16 = v42;
        continue;
      }
      break;
    }
LABEL_39:
    if ( !v20 )
      return 0;
    v15 = (__int16 *)v42;
    v17 = v20;
    v16 = (char *)v44;
    v19 = v45;
    v42 = (char *)v44;
    v44 = v15;
    v49 = v20;
    if ( !v43 )
    {
      v18 = v47;
      continue;
    }
    break;
  }
  return (unsigned __int16)v15[v17 - 1] == v19;
}
