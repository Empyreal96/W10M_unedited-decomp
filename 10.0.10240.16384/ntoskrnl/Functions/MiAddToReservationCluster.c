// MiAddToReservationCluster 
 
unsigned int __fastcall MiAddToReservationCluster(int a1, unsigned int *a2, unsigned int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v8; // r2
  unsigned int v9; // r8
  int v11; // r7
  unsigned int v12; // r5
  int v13; // r4
  int v14; // r9
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned __int8 *v17; // r1
  int v18; // r3
  unsigned int v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r2
  __int16 v24; // r3
  unsigned int v25; // r0
  unsigned int v26; // r7
  bool v27; // zf
  int *v28; // r1
  int *v29; // r0
  unsigned int v30; // r2
  int v31; // t1
  bool i; // zf
  int v33; // t1
  int v35; // r7
  unsigned int *v36; // r2
  unsigned int v37; // r4
  unsigned int *v38; // r2
  unsigned int v39; // r0
  unsigned int *v40; // r2
  unsigned int v41; // r4
  unsigned int v43; // [sp+0h] [bp-30h]
  int v44; // [sp+4h] [bp-2Ch]
  int v46; // [sp+Ch] [bp-24h]

  v8 = *(_DWORD *)(a1 + 128) + 20 * ((*(_WORD *)(a1 + 96) & 0xF) + 96);
  v43 = a3;
  v44 = v8;
  v9 = 0;
  if ( a3 )
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)(v8 + 8);
      v46 = v11;
      if ( v11 == 0xFFFFF )
        return v9;
      v12 = 0;
      v13 = MmPfnDatabase + 24 * v11;
      v14 = KfRaiseIrql(2);
      v15 = (unsigned __int8 *)(v13 + 15);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
      {
        v17 = (unsigned __int8 *)(v13 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v18 = *(_DWORD *)(v13 + 12);
            __dmb(0xBu);
          }
          while ( v18 < 0 );
          do
            v19 = __ldrex(v17);
          while ( __strex(v19 | 0x80, v17) );
          __dmb(0xBu);
        }
        while ( v19 >> 7 );
      }
      if ( v11 == *(_DWORD *)(v44 + 8) )
      {
        v22 = *(_DWORD *)(v13 + 8);
        v23 = v22 >> 13;
        if ( v22 >> 13 != a4 )
        {
          v12 = v23 - a4;
          v24 = *(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * ((v22 >> 2) & 1) + 1800] + 96);
          if ( (v24 & 0x10) == 0 && ((v24 & 0x20) == 0 || (*(_DWORD *)(v13 + 8) & 8) == 0) )
            goto LABEL_49;
          if ( v23 < a4 || v12 > 0x1F || v12 + v9 >= v43 )
            goto LABEL_49;
        }
        v25 = a2[1];
        if ( ((*(int *)(v25 + 4 * (v23 >> 5)) >> (v23 & 0x1F)) & 1) != 0 )
        {
          __dmb(0xBu);
          v40 = (unsigned int *)(v13 + 12);
          do
            v41 = __ldrex(v40);
          while ( __strex(v41 & 0x7FFFFFFF, v40) );
          goto LABEL_54;
        }
        if ( v12 )
        {
          v26 = v12 + a4 - 1;
          if ( v26 >= *a2 )
            goto LABEL_49;
          if ( v12 > 1 )
          {
            v28 = (int *)(v25 + 4 * ((unsigned int)a4 >> 5));
            v29 = (int *)(v25 + 4 * (v26 >> 5));
            if ( v28 != v29 )
            {
              v31 = *v28++;
              for ( i = (v31 & (-1 << (a4 & 0x1F))) == 0; i; i = v33 == 0 )
              {
                if ( v28 == v29 )
                {
                  v30 = 0xFFFFFFFF >> (31 - (v26 & 0x1F));
                  goto LABEL_34;
                }
                v33 = *v28++;
              }
LABEL_49:
              __dmb(0xBu);
              v38 = (unsigned int *)(v13 + 12);
              do
                v39 = __ldrex(v38);
              while ( __strex(v39 & 0x7FFFFFFF, v38) );
LABEL_54:
              KfLowerIrql(v14);
              return v9;
            }
            v30 = 0xFFFFFFFF >> (32 - v12) << (a4 & 0x1F);
LABEL_34:
            v27 = (*v28 & v30) == 0;
          }
          else
          {
            v27 = ((*(unsigned __int8 *)((a4 >> 3) + v25) >> (a4 & 7)) & 1) == 0;
          }
          if ( !v27 )
            goto LABEL_49;
        }
        v35 = MiReferencePageForModifiedWrite(v13, 0);
        __dmb(0xBu);
        v36 = (unsigned int *)(v13 + 12);
        do
          v37 = __ldrex(v36);
        while ( __strex(v37 & 0x7FFFFFFF, v36) );
        KfLowerIrql(v14);
        if ( !v35 )
          return v9;
        if ( v12 )
        {
          a4 += v12;
          v9 += v12;
          *a6 += v12;
          do
          {
            --v12;
            *a5++ = dword_6348F4;
          }
          while ( v12 );
        }
        ++a4;
        ++v9;
        *a5++ = v46;
        if ( v35 == 3 && v9 >= 0x10 )
          return v9;
      }
      else
      {
        __dmb(0xBu);
        v20 = (unsigned int *)(v13 + 12);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 & 0x7FFFFFFF, v20) );
        KfLowerIrql(v14);
      }
      if ( v9 == v43 )
        return v9;
      v8 = v44;
    }
  }
  return v9;
}
