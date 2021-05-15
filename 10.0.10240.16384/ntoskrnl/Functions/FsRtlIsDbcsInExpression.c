// FsRtlIsDbcsInExpression 
 
int __fastcall FsRtlIsDbcsInExpression(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r2
  unsigned int v3; // r4
  int v5; // r5
  unsigned int v7; // lr
  __int16 *v8; // r1
  char *v9; // r6
  int v10; // r5
  unsigned int v11; // r8
  int v12; // r3
  unsigned __int16 v13; // r2
  int v14; // r0
  __int16 v16; // r3
  unsigned int v17; // r7
  unsigned int v18; // r4
  int v19; // r3
  int v20; // r10
  __int16 i; // r3
  int v22; // lr
  int v23; // r3
  unsigned __int16 v24; // r2
  int v25; // r0
  int v27; // r5
  __int16 v28; // r3
  __int16 v29; // r3
  int v30; // r2
  int v31; // r4
  unsigned int v33; // r5
  char *v34; // r2
  __int16 *v35; // r1
  unsigned int v36; // t1
  int v37; // r5
  __int16 v38; // r3
  __int64 v39; // kr00_8
  int v40; // r7
  unsigned int v41; // r1
  unsigned int v42; // lr
  unsigned int v43; // r3
  int v44; // r2
  unsigned __int16 v45; // r1
  unsigned int v46; // r0
  int v48; // r3
  __int16 v49; // r2
  unsigned __int16 v50; // r1
  int v51; // r3
  unsigned int v52; // r2
  unsigned int v53; // r3
  int v55; // r3
  __int16 v56; // [sp+0h] [bp-98h]
  int v57; // [sp+4h] [bp-94h]
  __int16 *v58; // [sp+8h] [bp-90h]
  int v60; // [sp+10h] [bp-88h]
  int v61; // [sp+14h] [bp-84h]
  __int16 v62; // [sp+18h] [bp-80h]
  unsigned int v63; // [sp+1Ch] [bp-7Ch]
  int v64; // [sp+20h] [bp-78h]
  int v65[2]; // [sp+28h] [bp-70h] BYREF
  unsigned int v66; // [sp+30h] [bp-68h]
  unsigned int v67; // [sp+34h] [bp-64h]
  __int16 v68[16]; // [sp+38h] [bp-60h] BYREF
  char v69; // [sp+58h] [bp-40h] BYREF

  v2 = a2;
  v3 = *a2;
  v60 = 0;
  v57 = 0;
  v61 = 0;
  if ( !*a2 || (v5 = *a1) == 0 )
    return *a1 + v3 == 0;
  if ( v5 == 1 )
    return sub_7D6D50();
  if ( **((_BYTE **)a1 + 1) != 42 )
    goto LABEL_6;
  v39 = *(_QWORD *)a1;
  v65[0] = *(_DWORD *)a1;
  v65[1] = HIDWORD(v39) + 1;
  v40 = (unsigned __int16)--LOWORD(v65[0]);
  if ( !FsRtlDoesDbcsContainWildCards(v65) )
  {
    if ( v3 < (unsigned __int16)(v5 - 1) )
      return 0;
    v41 = v3 - v40;
    if ( NlsMbOemCodePageTag )
    {
      v52 = 0;
      if ( v41 )
      {
        do
        {
          v53 = *(unsigned __int8 *)(*((_DWORD *)a2 + 1) + v52);
          if ( v53 >= 0x80 && NlsOemLeadByteInfoTable[v53] )
            v55 = 2;
          else
            v55 = 1;
          v52 += v55;
        }
        while ( v52 < v41 );
        if ( v52 > v41 )
          return 0;
      }
    }
    return memcmp(HIDWORD(v39) + 1, v41 + *((_DWORD *)a2 + 1), v40) == 0;
  }
  v2 = a2;
LABEL_6:
  v68[0] = 0;
  v7 = 0;
  v63 = 0;
  v8 = v68;
  v9 = &v69;
  v10 = (unsigned __int16)(2 * v5);
  v64 = v10;
  v58 = v68;
  v11 = 1;
  while ( 2 )
  {
    if ( v7 >= *v2 )
    {
      v60 = 1;
      if ( (unsigned __int16)v8[v11 - 1] == v10 )
      {
LABEL_39:
        v31 = (unsigned __int16)v8[v11 - 1];
        if ( v61 )
          ExFreePoolWithTag(v61);
        return v31 == v10;
      }
    }
    else
    {
      v12 = *((_DWORD *)v2 + 1);
      v13 = *(char *)(v7 + v12);
      v14 = v7 + v12;
      if ( (unsigned __int8)v13 >= 0x80u && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[(unsigned __int8)v13] )
      {
        v57 = (unsigned __int16)(v13 + (*(unsigned __int8 *)(v14 + 1) << 8));
        v16 = 2;
      }
      else
      {
        v57 = v13;
        v16 = 1;
      }
      v8 = v58;
      v63 = (unsigned __int16)(v16 + v7);
    }
    v17 = 0;
    v18 = 0;
    v67 = 0;
    while ( 2 )
    {
      v19 = (unsigned __int16)v8[v17++];
      v20 = (unsigned __int16)((v19 + 1) >> 1);
      for ( i = 0; ; i = v56 )
      {
        v22 = *a1;
        if ( v20 == v22 )
          goto LABEL_36;
        v20 = (unsigned __int16)(i + v20);
        v62 = 2 * v20;
        if ( v20 == v22 )
        {
          v29 = v64;
LABEL_83:
          *(_WORD *)&v9[2 * v18++] = v29;
          goto LABEL_36;
        }
        if ( v20 == v22 - 1
          && ((v50 = *(char *)(*((_DWORD *)a1 + 1) + v20), (unsigned __int8)v50 < 0x80u)
           || !NlsMbOemCodePageTag
           || !NlsOemLeadByteInfoTable[(unsigned __int8)v50] ? (v51 = 0) : (v51 = 1),
              v51) )
        {
          v27 = v50;
        }
        else
        {
          v23 = *((_DWORD *)a1 + 1);
          v24 = *(char *)(v23 + v20);
          v25 = v23 + v20;
          if ( (unsigned __int8)v24 >= 0x80u && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[(unsigned __int8)v24] )
          {
            v27 = (unsigned __int16)(v24 + (*(unsigned __int8 *)(v25 + 1) << 8));
            v28 = 2;
            goto LABEL_27;
          }
          v27 = v24;
        }
        v28 = 1;
LABEL_27:
        v56 = v28;
        if ( v18 >= 0xE && !v61 )
        {
          v61 = ExAllocatePoolWithTag(17, 8 * (v22 + 1), 1685214022);
          memmove(v61, (int)v9, 0x20u);
          v9 = (char *)v61;
          memmove(v61 + 4 * *a1 + 4, (int)v58, 0x20u);
          v58 = (__int16 *)(v61 + 4 * (*a1 + 1));
        }
        if ( v27 == 42 )
          goto LABEL_52;
        if ( v27 == 60 )
        {
          v37 = 0;
          if ( v60 || v57 != 46 )
            goto LABEL_52;
          v42 = *a2;
          v43 = v63;
          v66 = v63;
          if ( v63 < v42 )
          {
            v44 = *((_DWORD *)a2 + 1);
            v65[0] = v44;
            while ( 1 )
            {
              v45 = *(char *)(v43 + v44);
              v46 = v43 + v44;
              if ( (unsigned __int8)v45 >= 0x80u && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[(unsigned __int8)v45] )
              {
                v49 = 2;
                v48 = (unsigned __int16)(v45 + (*(unsigned __int8 *)(v46 + 1) << 8));
              }
              else
              {
                v48 = v45;
                v49 = 1;
              }
              if ( v48 == 46 )
                break;
              v43 = (unsigned __int16)(v66 + v49);
              v44 = v65[0];
              v66 = v43;
              if ( v43 >= v42 )
                goto LABEL_70;
            }
            v37 = 1;
          }
LABEL_70:
          if ( v37 )
          {
LABEL_52:
            *(_WORD *)&v9[2 * v18++] = v62;
            v38 = v62 + 1;
          }
          else
          {
            v38 = v62 + 1;
          }
          *(_WORD *)&v9[2 * v18++] = v38;
          continue;
        }
        v29 = v62 + 2 * v56;
        if ( v27 == 62 )
        {
          if ( !v60 && v57 != 46 )
            goto LABEL_83;
          continue;
        }
        if ( v27 != 34 )
        {
          if ( v60 )
            goto LABEL_36;
          v30 = v57;
          goto LABEL_34;
        }
        if ( !v60 )
          break;
      }
      v30 = v57;
      if ( v57 == 46 )
        goto LABEL_83;
LABEL_34:
      if ( v27 == 63 || v27 == v30 )
        goto LABEL_83;
LABEL_36:
      if ( v17 < v11 )
      {
        v33 = v67;
        v34 = &v9[2 * v67];
        do
        {
          if ( v33 >= v18 )
            break;
          if ( v17 < v11 )
          {
            v35 = &v58[v17];
            do
            {
              v36 = (unsigned __int16)*v35++;
              if ( v36 >= *(unsigned __int16 *)v34 )
                break;
              ++v17;
            }
            while ( v17 < v11 );
          }
          ++v33;
          v34 += 2;
        }
        while ( v17 < v11 );
        v67 = v33;
        if ( v17 < v11 )
        {
          v8 = v58;
          continue;
        }
      }
      break;
    }
    if ( v18 )
    {
      v2 = a2;
      v8 = (__int16 *)v9;
      v10 = v64;
      v9 = (char *)v58;
      v7 = v63;
      v11 = v18;
      v58 = v8;
      if ( v60 )
        goto LABEL_39;
      continue;
    }
    break;
  }
  if ( v61 )
    ExFreePoolWithTag(v61);
  return 0;
}
