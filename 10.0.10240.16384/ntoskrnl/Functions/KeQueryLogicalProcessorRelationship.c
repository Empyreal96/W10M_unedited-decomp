// KeQueryLogicalProcessorRelationship 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeQueryLogicalProcessorRelationship(int a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r7
  int v6; // r10
  int v7; // lr
  unsigned int v8; // r2
  unsigned int v9; // r1
  char *v10; // r3
  int v11; // r0
  unsigned int v12; // r0
  int v13; // r9
  void **v14; // r6
  _DWORD *v15; // r8
  unsigned int v16; // r2
  void **v17; // r6
  unsigned int v18; // r4 OVERLAPPED
  int v19; // r3
  int v20; // t1
  unsigned int v21; // r8
  __int16 v22; // r10
  int v23; // r3
  int result; // r0
  int v25; // r4
  __int64 v26; // r2
  unsigned int v27; // r6
  int *v28; // r8
  unsigned int v29; // r2
  char v30; // r3
  int v31; // t1
  unsigned int v32; // r9
  char *v33; // r1
  int v34; // r4
  _DWORD *v35; // r6
  int v36; // r3
  char *v37; // r1
  int v38; // r0
  int v39; // r2
  char v40; // r1
  int v41; // r2
  int v42; // r3
  unsigned int v43; // r6
  int v44; // r2
  int v45; // r3
  unsigned __int16 v46; // r1
  unsigned int v47; // r4
  int v48; // r1
  _DWORD *v49; // r2
  unsigned __int16 i; // r0
  int v51; // r3
  int v52; // [sp+0h] [bp-A8h]
  unsigned int v53; // [sp+4h] [bp-A4h]
  void **v54; // [sp+8h] [bp-A0h]
  unsigned int v55; // [sp+8h] [bp-A0h]
  int v56; // [sp+Ch] [bp-9Ch]
  int v58; // [sp+14h] [bp-94h]
  unsigned int v59; // [sp+18h] [bp-90h]
  int v60; // [sp+1Ch] [bp-8Ch]
  int v61; // [sp+20h] [bp-88h]
  int v62; // [sp+24h] [bp-84h]
  _DWORD v64[4]; // [sp+30h] [bp-78h] BYREF
  char v65[104]; // [sp+40h] [bp-68h] BYREF

  v62 = a2;
  v4 = 0;
  v52 = 0;
  v53 = *a4;
  v6 = a2;
  v7 = a1;
  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 3) )
      return sub_5167CC();
    if ( *(_WORD *)a1 )
      return sub_5167CC();
    v59 = *(unsigned __int8 *)(a1 + 2);
    if ( v59 >= KeNumberProcessors_0 )
      return sub_5167CC();
    v8 = *(unsigned __int8 *)(a1 + 2);
    v9 = v8;
  }
  else
  {
    LOBYTE(v59) = 0;
    v8 = 0;
    v9 = KeNumberProcessors_0 - 1;
  }
  v10 = v65;
  v11 = 6;
  do
  {
    *(_WORD *)v10 = 1;
    *((_WORD *)v10 + 1) = 1;
    *((_DWORD *)v10 + 1) = 0;
    *((_DWORD *)v10 + 2) = 0;
    v10 += 12;
    --v11;
  }
  while ( v11 );
  v12 = 0;
  v56 = 0;
  v13 = 0;
  v58 = 0;
  if ( v8 > v9 )
    goto LABEL_14;
  v61 = v9 - v8 + 1;
  v14 = &KiProcessorBlock + v8;
  do
  {
    v15 = *v14;
    v54 = v14 + 1;
    if ( v6 == 0xFFFF || v6 == 3 )
    {
      v41 = v15[845];
      v42 = v15[846];
      v64[0] = v15[844];
      v64[1] = v41;
      v64[2] = v42;
      if ( (v42 & v13) == 0 || v7 )
      {
        v43 = LOWORD(v64[0]);
        v13 |= v42;
        v44 = 0;
        v45 = 0;
        v58 = v13;
        if ( LOWORD(v64[0]) )
        {
          v46 = 0;
          do
          {
            if ( v64[v45 + 2] )
              v44 = (unsigned __int16)(v44 + 1);
            v45 = ++v46;
          }
          while ( v46 < (unsigned int)LOWORD(v64[0]) );
        }
        v47 = (12 * (v44 - 1) + 47) & 0xFFFFFFFC;
        v4 += v47;
        if ( v4 <= v53 )
        {
          *(_DWORD *)a3 = 3;
          *(_DWORD *)(a3 + 4) = v47;
          *(_WORD *)(a3 + 30) = v44;
          *(_BYTE *)(a3 + 8) = 0;
          *(_BYTE *)(a3 + 9) = 0;
          memset((_BYTE *)(a3 + 10), 0, 20);
          v48 = 0;
          v49 = (_DWORD *)(a3 + 32);
          if ( v43 )
          {
            for ( i = 0; i < v43; v48 = ++i )
            {
              v51 = v64[v48 + 2];
              if ( v51 )
              {
                *v49 = 0;
                v49[1] = 0;
                v49[2] = 0;
                *((_WORD *)v49 + 2) = v48;
                *v49 = v51;
                v49 += 3;
              }
            }
          }
          v7 = a1;
          a3 += v47;
        }
        else
        {
          v52 = -1073741820;
        }
      }
      v12 = v56;
    }
    if ( !v6 || v6 == 0xFFFF )
    {
      v39 = v15[867];
      v40 = 0;
      if ( (v12 & v39) == 0 || v7 )
      {
        v56 = v12 | v39;
        if ( v15[262] != v39 )
          v40 = 1;
        v4 += 44;
        if ( v4 > v53 )
        {
          v52 = -1073741820;
        }
        else
        {
          *(_DWORD *)a3 = 0;
          *(_DWORD *)(a3 + 4) = 44;
          *(_BYTE *)(a3 + 8) = v40;
          *(_BYTE *)(a3 + 9) = *((_BYTE *)v15 + 2986);
          *(_WORD *)(a3 + 30) = 1;
          memset((_BYTE *)(a3 + 10), 0, 20);
          *(_DWORD *)(a3 + 32) = 0;
          *(_DWORD *)(a3 + 36) = 0;
          *(_DWORD *)(a3 + 40) = 0;
          *(_WORD *)(a3 + 36) = *((unsigned __int8 *)v15 + 1052);
          *(_DWORD *)(a3 + 32) = v15[867];
          a3 += 44;
        }
      }
    }
    if ( v6 != 2 && v6 != 0xFFFF )
      goto LABEL_13;
    v32 = 0;
    if ( !*((_BYTE *)v15 + 3576) )
      goto LABEL_48;
    v33 = (char *)(v65 - (char *)v15);
    v34 = (int)v15;
    v35 = v15;
    do
    {
      v36 = v35[870];
      v60 = v15[262];
      if ( !v36 )
        goto LABEL_44;
      v37 = &v33[v34];
      v38 = *((_DWORD *)v37 + 2);
      v60 = v35[870];
      if ( (v38 & v36) == 0 || a1 )
      {
        *((_DWORD *)v37 + 2) = v36 | v38;
LABEL_44:
        v4 += 52;
        if ( v4 > v53 )
        {
          v52 = -1073741820;
        }
        else
        {
          *(_DWORD *)a3 = 2;
          *(_DWORD *)(a3 + 4) = 52;
          *(_BYTE *)(a3 + 8) = *(_BYTE *)(v34 + 3504);
          *(_BYTE *)(a3 + 9) = *(_BYTE *)(v34 + 3505);
          *(_WORD *)(a3 + 10) = *(_WORD *)(v34 + 3506);
          *(_DWORD *)(a3 + 12) = *(_DWORD *)(v34 + 3508);
          *(_DWORD *)(a3 + 16) = *(_DWORD *)(v34 + 3512);
          memset((_BYTE *)(a3 + 20), 0, 20);
          *(_DWORD *)(a3 + 40) = 0;
          *(_DWORD *)(a3 + 44) = 0;
          *(_DWORD *)(a3 + 48) = 0;
          *(_WORD *)(a3 + 44) = *((unsigned __int8 *)v15 + 1052);
          *(_DWORD *)(a3 + 40) = v60;
          a3 += 52;
        }
      }
      ++v32;
      v33 = (char *)(v65 - (char *)v15);
      ++v35;
      v34 += 12;
    }
    while ( v32 < *((unsigned __int8 *)v15 + 3576) );
    v6 = v62;
LABEL_48:
    v13 = v58;
LABEL_13:
    v12 = v56;
    v7 = a1;
    v14 = v54;
    --v61;
  }
  while ( v61 );
LABEL_14:
  if ( v6 == 1 || v6 == 0xFFFF )
  {
    v16 = (unsigned __int16)KeNumberNodes;
    v17 = &KeNodeBlock;
    v55 = (unsigned __int16)KeNumberNodes;
    v18 = 0;
    do
    {
      v20 = (int)*v17++;
      v19 = v20;
      v21 = *(_DWORD *)(v20 + 260);
      if ( v21 )
      {
        v22 = *(_WORD *)(v19 + 264);
        if ( !v7 || ((v21 >> v59) & 1) != 0 )
        {
          v4 += 44;
          if ( v4 > v53 )
          {
            v52 = -1073741820;
          }
          else
          {
            *(_DWORD *)a3 = 1;
            v23 = 44;
            *(_QWORD *)(a3 + 4) = *(_QWORD *)(&v18 - 1);
            v12 = (unsigned int)memset((_BYTE *)(a3 + 12), 0, 20);
            *(_DWORD *)(a3 + 32) = 0;
            *(_DWORD *)(a3 + 36) = 0;
            *(_DWORD *)(a3 + 40) = 0;
            v16 = v55;
            v7 = a1;
            *(_WORD *)(a3 + 36) = v22;
            *(_DWORD *)(a3 + 32) = v21;
            a3 += 44;
          }
        }
      }
      ++v18;
    }
    while ( v18 < v16 );
    v6 = v62;
  }
  if ( v6 == 4 || v6 == 0xFFFF && !v7 )
  {
    v25 = (unsigned __int16)KiActiveGroups;
    HIDWORD(v26) = (44 * ((unsigned __int16)KiActiveGroups - 1) + 79) & 0xFFFFFFFC;
    v4 += HIDWORD(v26);
    if ( v4 <= v53 )
    {
      LODWORD(v26) = 4;
      *(_QWORD *)a3 = v26;
      *(_WORD *)(a3 + 8) = KeQueryMaximumGroupCount(v12);
      *(_WORD *)(a3 + 10) = v25;
      memset((_BYTE *)(a3 + 12), 0, 20);
      v27 = 0;
      if ( v25 )
      {
        v28 = dword_681D78;
        do
        {
          *(_BYTE *)(a3 + 32) = KeQueryMaximumProcessorCountEx((unsigned __int16)v27);
          if ( (unsigned __int16)v27 == 0xFFFF )
          {
            v30 = KeNumberProcessors_0;
          }
          else if ( (unsigned __int16)v27 >= (unsigned int)(unsigned __int16)KiActiveGroups )
          {
            v30 = 0;
          }
          else
          {
            v29 = ~dword_681D78[(unsigned __int16)v27];
            v30 = *((_BYTE *)RtlpBitsClearTotal + BYTE2(v29))
                + *((_BYTE *)RtlpBitsClearTotal + HIBYTE(v29))
                + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v29))
                + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v29);
          }
          *(_BYTE *)(a3 + 33) = v30;
          v31 = *v28++;
          *(_DWORD *)(a3 + 72) = v31;
          memset((_BYTE *)(a3 + 34), 0, 38);
          ++v27;
          a3 += 44;
        }
        while ( v27 < (unsigned __int16)KiActiveGroups );
      }
      goto LABEL_24;
    }
    result = -1073741820;
  }
  else
  {
LABEL_24:
    result = v52;
  }
  if ( !v4 && !result )
    result = -1073741823;
  *a4 = v4;
  return result;
}
