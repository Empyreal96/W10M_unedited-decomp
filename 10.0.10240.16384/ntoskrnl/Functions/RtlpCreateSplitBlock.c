// RtlpCreateSplitBlock 
 
int __fastcall RtlpCreateSplitBlock(int a1, int a2, unsigned __int16 *a3, char a4, char a5, __int16 a6, int a7)
{
  unsigned __int16 *v10; // r4
  unsigned int v11; // r1
  _DWORD *v12; // r4
  _DWORD *v13; // r0
  _DWORD *v14; // r3
  _DWORD *v15; // r4
  _DWORD *v16; // r1
  unsigned int j; // r3
  _DWORD *v18; // r3
  int v19; // r1
  __int64 v20; // r8
  _DWORD *v21; // r1
  unsigned int v22; // r2
  unsigned int k; // r3
  _DWORD *v24; // r3
  unsigned int v25; // r3
  int v26; // r3
  unsigned int v27; // r7
  int v28; // r0
  int v29; // r3
  int v30; // r1
  unsigned int v31; // r7
  _DWORD *v32; // r4
  _DWORD *v33; // r0
  int v34; // r1
  int v35; // r2
  unsigned int v36; // r3
  _DWORD *v37; // r3
  _DWORD *v38; // r4
  _DWORD *v39; // r1
  unsigned int m; // r3
  _DWORD *v41; // r3
  _DWORD *v42; // r4
  _DWORD *v43; // r0
  int v44; // r1
  int v45; // r2
  unsigned int v46; // r3
  _DWORD *v47; // r3
  _DWORD *v48; // r4
  _DWORD *v49; // r1
  unsigned int l; // r3
  _DWORD *v51; // r3
  int v52; // r2
  unsigned int v53; // r3
  _DWORD *v54; // r4
  _DWORD *v55; // r0
  int v56; // r1
  int v57; // r2
  unsigned int v58; // r3
  _DWORD *v59; // r3
  _DWORD *v60; // r4
  _DWORD *v61; // r1
  unsigned int i; // r3
  _DWORD *v63; // r3
  int v64; // [sp+8h] [bp-28h]
  int v65; // [sp+8h] [bp-28h]
  int v66; // [sp+8h] [bp-28h]
  int v67; // [sp+8h] [bp-28h]
  int v68; // [sp+8h] [bp-28h]

  *((_BYTE *)a3 + 2) = a4;
  *((_BYTE *)a3 + 7) = 0;
  v64 = 0;
  a3[2] = a6 ^ *(_WORD *)(a1 + 84);
  if ( *(_DWORD *)(a2 + 24) != a2 )
    return sub_52868C();
  *((_BYTE *)a3 + 6) = 0;
  *((_BYTE *)a3 + 3) = 0;
  *a3 = a7;
  v10 = &a3[4 * a7];
  while ( 1 )
  {
    v11 = *(_DWORD *)(a1 + 76);
    if ( ((*((unsigned __int8 *)v10 + 2) ^ *(unsigned __int8 *)(a1 + 82) & (v11 >> 20)) & 1) != 0 )
    {
      v10[2] = *(_WORD *)(a1 + 84) ^ a7;
      if ( a5 )
      {
        *((_BYTE *)a3 + 2) &= 0xF0u;
        *((_BYTE *)a3 + 7) = 0;
        if ( (*(_DWORD *)(a1 + 64) & 0x40) != 0 )
        {
          RtlFillMemoryUlong((_DWORD *)a3 + 4, 8 * (unsigned __int16)a7 - 16, -17891602);
          *((_BYTE *)a3 + 2) |= 4u;
        }
        v54 = (_DWORD *)(a1 + 192);
        if ( *(_DWORD *)(a1 + 180) )
          v55 = (_DWORD *)RtlpFindEntry(a1, (unsigned __int16)a7);
        else
          v55 = (_DWORD *)*v54;
        if ( v54 != v55 )
        {
          v56 = *(_DWORD *)(a1 + 76);
          do
          {
            if ( v56 )
            {
              v57 = *(v55 - 2);
              v56 = *(_DWORD *)(a1 + 76);
              LOWORD(v68) = v57;
              if ( (v56 & v57) != 0 )
                v68 = *(_DWORD *)(a1 + 80) ^ v57;
              v58 = (unsigned __int16)v68;
            }
            else
            {
              v58 = *((unsigned __int16 *)v55 - 4);
            }
            if ( (unsigned __int16)a7 <= v58 )
              break;
            v55 = (_DWORD *)*v55;
          }
          while ( v54 != v55 );
        }
        v59 = (_DWORD *)v55[1];
        v60 = a3 + 4;
        if ( (_DWORD *)*v59 == v55 )
        {
          *v60 = v55;
          *((_DWORD *)a3 + 3) = v59;
          *v59 = v60;
          v55[1] = v60;
        }
        else
        {
          RtlpLogHeapFailure(12, 0);
        }
        v61 = *(_DWORD **)(a1 + 180);
        *(_DWORD *)(a1 + 116) += *a3;
        if ( v61 )
        {
          for ( i = v61[1]; *a3 >= i; i = v63[1] )
          {
            v63 = (_DWORD *)*v61;
            if ( !*v61 )
              break;
            v61 = (_DWORD *)*v61;
          }
          goto LABEL_15;
        }
      }
      else
      {
        *((_BYTE *)a3 + 2) = 0;
        *((_BYTE *)a3 + 7) = 0;
        v12 = (_DWORD *)(a1 + 192);
        if ( *(_DWORD *)(a1 + 180) )
          v13 = (_DWORD *)RtlpFindEntry(a1, (unsigned __int16)a7);
        else
          v13 = (_DWORD *)*v12;
        if ( v12 != v13 )
        {
          v19 = *(_DWORD *)(a1 + 76);
          do
          {
            if ( v19 )
            {
              v52 = *(v13 - 2);
              v19 = *(_DWORD *)(a1 + 76);
              LOWORD(v67) = v52;
              if ( (v19 & v52) != 0 )
                v67 = *(_DWORD *)(a1 + 80) ^ v52;
              v53 = (unsigned __int16)v67;
            }
            else
            {
              v53 = *((unsigned __int16 *)v13 - 4);
            }
            if ( (unsigned __int16)a7 <= v53 )
              break;
            v13 = (_DWORD *)*v13;
          }
          while ( v12 != v13 );
        }
        v14 = (_DWORD *)v13[1];
        v15 = a3 + 4;
        if ( (_DWORD *)*v14 == v13 )
        {
          *v15 = v13;
          *((_DWORD *)a3 + 3) = v14;
          *v14 = v15;
          v13[1] = v15;
        }
        else
        {
          RtlpLogHeapFailure(12, 0);
        }
        v16 = *(_DWORD **)(a1 + 180);
        *(_DWORD *)(a1 + 116) += *a3;
        if ( v16 )
        {
          for ( j = v16[1]; *a3 >= j; j = v18[1] )
          {
            v18 = (_DWORD *)*v16;
            if ( !*v16 )
              break;
            v16 = (_DWORD *)*v16;
          }
          goto LABEL_15;
        }
      }
      goto LABEL_16;
    }
    if ( v11 )
    {
      *(_DWORD *)v10 ^= *(_DWORD *)(a1 + 80);
      if ( *((unsigned __int8 *)v10 + 3) != (*((unsigned __int8 *)v10 + 2) ^ *((unsigned __int8 *)v10 + 1) ^ *(unsigned __int8 *)v10) )
        RtlpAnalyzeHeapFailure(a1, &a3[4 * a7]);
    }
    v20 = *((_QWORD *)v10 + 1);
    if ( *(_DWORD *)HIDWORD(v20) == *(_DWORD *)(v20 + 4) && *(unsigned __int16 **)HIDWORD(v20) == v10 + 4 )
    {
      v21 = *(_DWORD **)(a1 + 180);
      *(_DWORD *)(a1 + 116) -= *v10;
      if ( v21 )
      {
        v22 = *v10;
        for ( k = v21[1]; ; k = v24[1] )
        {
          if ( v22 < k )
          {
            v25 = *v10;
            goto LABEL_37;
          }
          v24 = (_DWORD *)*v21;
          if ( !*v21 )
            break;
          v21 = (_DWORD *)*v21;
        }
        v25 = v21[1] - 1;
LABEL_37:
        RtlpHeapRemoveListEntry(a1, v21, v22, (_DWORD *)v10 + 2, v25);
      }
      *(_DWORD *)HIDWORD(v20) = v20;
      *(_DWORD *)(v20 + 4) = HIDWORD(v20);
      if ( a5 && (v10[1] & 4) != 0 )
      {
        v26 = 8 * *v10;
        v27 = v26 - 16;
        if ( (v10[1] & 2) != 0 && v27 > 4 )
          v27 = v26 - 20;
        v28 = RtlCompareMemoryUlong(v10 + 8, v27, -17891602);
        if ( v28 != v27 )
        {
          DbgPrint("HEAP: Free Heap block %p modified at %p after it was freed\n", &a3[4 * a7], (char *)v10 + v28 + 16);
          if ( KdDebuggerEnabled )
            __debugbreak();
        }
      }
      *((_BYTE *)a3 + 2) = *((_BYTE *)v10 + 2);
      v29 = *v10;
      v30 = v29 + a7;
      if ( (unsigned int)(v29 + a7) > 0xFE00 )
      {
        RtlpInsertFreeBlock(a1, a3, v29 + a7);
      }
      else
      {
        v31 = (unsigned __int16)v30;
        *a3 = v30;
        a3[4 * v30 + 2] = *(_WORD *)(a1 + 84) ^ v30;
        if ( a5 )
        {
          *((_BYTE *)a3 + 2) &= 0xF0u;
          *((_BYTE *)a3 + 7) = 0;
          if ( (*(_DWORD *)(a1 + 64) & 0x40) != 0 )
          {
            RtlFillMemoryUlong((_DWORD *)a3 + 4, 8 * (unsigned __int16)v30 - 16, -17891602);
            *((_BYTE *)a3 + 2) |= 4u;
          }
          v42 = (_DWORD *)(a1 + 192);
          if ( *(_DWORD *)(a1 + 180) )
            v43 = (_DWORD *)RtlpFindEntry(a1, v31);
          else
            v43 = (_DWORD *)*v42;
          if ( v42 != v43 )
          {
            v44 = *(_DWORD *)(a1 + 76);
            do
            {
              if ( v44 )
              {
                v45 = *(v43 - 2);
                v44 = *(_DWORD *)(a1 + 76);
                LOWORD(v66) = v45;
                if ( (v45 & v44) != 0 )
                  v66 = *(_DWORD *)(a1 + 80) ^ v45;
                v46 = (unsigned __int16)v66;
              }
              else
              {
                v46 = *((unsigned __int16 *)v43 - 4);
              }
              if ( v31 <= v46 )
                break;
              v43 = (_DWORD *)*v43;
            }
            while ( v42 != v43 );
          }
          v47 = (_DWORD *)v43[1];
          v48 = a3 + 4;
          if ( (_DWORD *)*v47 == v43 )
          {
            *v48 = v43;
            *((_DWORD *)a3 + 3) = v47;
            *v47 = v48;
            v43[1] = v48;
          }
          else
          {
            RtlpLogHeapFailure(12, 0);
          }
          v49 = *(_DWORD **)(a1 + 180);
          *(_DWORD *)(a1 + 116) += *a3;
          if ( v49 )
          {
            for ( l = v49[1]; *a3 >= l; l = v51[1] )
            {
              v51 = (_DWORD *)*v49;
              if ( !*v49 )
                break;
              v49 = (_DWORD *)*v49;
            }
LABEL_15:
            RtlpHeapAddListEntry(a1);
          }
        }
        else
        {
          *((_BYTE *)a3 + 2) = 0;
          *((_BYTE *)a3 + 7) = 0;
          v32 = (_DWORD *)(a1 + 192);
          if ( *(_DWORD *)(a1 + 180) )
            v33 = (_DWORD *)RtlpFindEntry(a1, (unsigned __int16)v30);
          else
            v33 = (_DWORD *)*v32;
          if ( v32 != v33 )
          {
            v34 = *(_DWORD *)(a1 + 76);
            do
            {
              if ( v34 )
              {
                v35 = *(v33 - 2);
                v34 = *(_DWORD *)(a1 + 76);
                LOWORD(v65) = v35;
                if ( (v35 & v34) != 0 )
                  v65 = *(_DWORD *)(a1 + 80) ^ v35;
                v36 = (unsigned __int16)v65;
              }
              else
              {
                v36 = *((unsigned __int16 *)v33 - 4);
              }
              if ( v31 <= v36 )
                break;
              v33 = (_DWORD *)*v33;
            }
            while ( v32 != v33 );
          }
          v37 = (_DWORD *)v33[1];
          v38 = a3 + 4;
          if ( (_DWORD *)*v37 == v33 )
          {
            *v38 = v33;
            *((_DWORD *)a3 + 3) = v37;
            *v37 = v38;
            v33[1] = v38;
          }
          else
          {
            RtlpLogHeapFailure(12, 0);
          }
          v39 = *(_DWORD **)(a1 + 180);
          *(_DWORD *)(a1 + 116) += *a3;
          if ( v39 )
          {
            for ( m = v39[1]; *a3 >= m; m = v41[1] )
            {
              v41 = (_DWORD *)*v39;
              if ( !*v39 )
                break;
              v39 = (_DWORD *)*v39;
            }
            goto LABEL_15;
          }
        }
LABEL_16:
        if ( *(_DWORD *)(a1 + 76) )
        {
          *((_BYTE *)a3 + 3) = *(_BYTE *)a3 ^ *((_BYTE *)a3 + 2) ^ *((_BYTE *)a3 + 1);
          *(_DWORD *)a3 ^= *(_DWORD *)(a1 + 80);
        }
      }
      return 1;
    }
    RtlpLogHeapFailure(12, a1);
    if ( v64 )
      return 0;
    v64 = 1;
  }
}
