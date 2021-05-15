// MdlInvariantPreProcessing1 
 
int __fastcall MdlInvariantPreProcessing1(__int64 a1, int a2)
{
  int v2; // r9
  int v4; // r8
  int v5; // r6
  unsigned int v6; // r5
  _DWORD *v7; // r2
  int v8; // r1
  int *v9; // lr
  int v10; // r4
  int v11; // t1
  int v12; // r4
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r2
  int v16; // r2
  int v17; // r1
  int v18; // r2
  _DWORD *v19; // r4
  int v20; // r2
  int v21; // t1
  int v22; // r5
  int v24; // [sp+8h] [bp-40h]
  int v25; // [sp+Ch] [bp-3Ch]
  __int64 v26; // [sp+10h] [bp-38h]
  unsigned int v27; // [sp+18h] [bp-30h]
  int v28; // [sp+1Ch] [bp-2Ch]
  int v29; // [sp+20h] [bp-28h]
  int v30; // [sp+24h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 100);
  v4 = HIDWORD(a1);
  v5 = a1;
  if ( !**(_DWORD **)(v2 + 4) )
  {
    LODWORD(a1) = KeGetCurrentIrql(a1);
    if ( (unsigned int)a1 >= 2 || *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 100) + 4) + 20) != -1 )
    {
      LODWORD(a1) = MmMdlPageContentsState(*(_DWORD *)(*(_DWORD *)(v5 + 100) + 4), 2);
      if ( (_DWORD)a1 == 1 )
      {
        LODWORD(a1) = *(_DWORD *)(*(_DWORD *)(v5 + 100) + 4);
        if ( (*(_WORD *)(a1 + 6) & 5) != 0 )
        {
          v6 = *(_DWORD *)(a1 + 12);
        }
        else
        {
          LODWORD(a1) = MmMapLockedPagesSpecifyCache(a1, 0, 1, 0, 0, 32);
          v6 = a1;
        }
        if ( v6 )
        {
          v7 = *(_DWORD **)(v4 + 132);
          if ( !v7 )
            goto LABEL_36;
          v8 = 0;
          if ( *v7 )
          {
            v9 = (int *)v7[1];
            while ( 1 )
            {
              v11 = *v9;
              v9 += 8;
              v10 = v11;
              if ( v11 )
              {
                if ( v10 == *(_DWORD *)(*(_DWORD *)(v5 + 100) + 4) )
                  break;
              }
              if ( (unsigned int)++v8 >= *v7 )
                goto LABEL_15;
            }
            v12 = v7[1] + 32 * v8;
          }
          else
          {
LABEL_15:
            v12 = 0;
          }
          if ( !v12 )
            goto LABEL_36;
          v13 = *(_DWORD *)(v5 + 100);
          v14 = *(char *)(v13 + 35);
          if ( v14 == *(char *)(v13 + 34) || *(char *)(v12 + 24) == v14 )
          {
            memset((_BYTE *)v12, 0, 32);
            v12 = 0;
            *(_DWORD *)(*(_DWORD *)(v4 + 132) + 8) = 0;
          }
          if ( v12 )
          {
            HIDWORD(a1) = *(_DWORD *)(v12 + 20);
            LODWORD(a1) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 100) + 4) + 20);
            if ( HIDWORD(a1) != (_DWORD)a1 )
            {
              v15 = *(_DWORD *)(v12 + 16);
              if ( v6 < v15 || (unsigned int)a1 + v6 > HIDWORD(a1) + v15 )
              {
                v16 = *(_DWORD *)(a2 + 24);
                if ( *(_BYTE *)a2 != 4 )
                {
LABEL_25:
                  v17 = 4113;
LABEL_32:
                  LODWORD(a1) = VerifierBugCheckIfAppropriate(196, v17, v16);
                  return a1;
                }
                goto LABEL_31;
              }
            }
            if ( (MmVerifierData & 0x4000) != 0 )
            {
              LODWORD(a1) = RtlpComputeCrcInternal(v6, a1, 0, 0, &Crc64Ctrl);
              if ( *(_QWORD *)(v12 + 8) != a1 )
              {
                if ( *(_BYTE *)a2 != 4 )
                {
                  if ( *(_DWORD *)(*(_DWORD *)(v2 + 96) + 8) != *(_DWORD *)(a2 + 8) )
                  {
                    *(_QWORD *)(v12 + 8) = a1;
                    return a1;
                  }
                  v16 = *(_DWORD *)(a2 + 24);
                  goto LABEL_25;
                }
                v16 = *(_DWORD *)(a2 + 24);
LABEL_31:
                v17 = 4112;
                goto LABEL_32;
              }
            }
          }
          else
          {
LABEL_36:
            LODWORD(a1) = RtlpComputeCrcInternal(
                            v6,
                            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 100) + 4) + 20),
                            0,
                            0,
                            &Crc64Ctrl);
            v18 = *(_DWORD *)(v5 + 100);
            v19 = *(_DWORD **)(v4 + 132);
            v26 = a1;
            v27 = v6;
            v24 = *(_DWORD *)(v18 + 4);
            v28 = *(_DWORD *)(v24 + 20);
            LOBYTE(v29) = *(_BYTE *)(v18 + 35);
            if ( !v19 )
            {
              LODWORD(a1) = ExAllocatePoolWithTag(512, 76);
              v19 = (_DWORD *)a1;
              if ( !(_DWORD)a1 )
                return a1;
              LODWORD(a1) = memset((_BYTE *)a1, 0, 76);
              *v19 = 2;
              v19[1] = v19 + 3;
              *(_DWORD *)(v4 + 132) = v19;
            }
            v20 = 0;
            if ( *v19 )
            {
              LODWORD(a1) = v19[1];
              while ( 1 )
              {
                v21 = *(_DWORD *)a1;
                LODWORD(a1) = a1 + 32;
                if ( !v21 )
                  break;
                if ( (unsigned int)++v20 >= *v19 )
                  return a1;
              }
              v22 = v19[1] + 32 * v20;
              *(_DWORD *)v22 = v24;
              *(_DWORD *)(v22 + 4) = v25;
              *(_QWORD *)(v22 + 8) = v26;
              v22 += 16;
              LODWORD(a1) = v27;
              *(_DWORD *)v22 = v27;
              *(_DWORD *)(v22 + 4) = v28;
              *(_DWORD *)(v22 + 8) = v29;
              *(_DWORD *)(v22 + 12) = v30;
            }
          }
        }
      }
    }
  }
  return a1;
}
