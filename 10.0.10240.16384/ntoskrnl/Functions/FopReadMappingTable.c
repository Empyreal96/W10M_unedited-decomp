// FopReadMappingTable 
 
void __fastcall FopReadMappingTable(_DWORD *a1, int a2, int **a3)
{
  int v5; // r4
  int v6; // r7
  int v7; // r3
  int v8; // r9
  int *v9; // r0
  int *v10; // r5
  unsigned int v11; // r4
  int v12; // r0
  _WORD *v13; // r8
  unsigned int v14; // r6
  _WORD *v15; // r2
  int v16; // r3
  int v17; // [sp+0h] [bp-38h] BYREF
  int **v18; // [sp+4h] [bp-34h]
  unsigned __int16 v19[24]; // [sp+8h] [bp-30h] BYREF

  v18 = a3;
  v17 = 0;
  v5 = FopReadCmapTable(a1, a2, &v17);
  v6 = v17;
  if ( v5 >= 0 && *(_WORD *)(v17 + 2) )
  {
    if ( *(_WORD *)(v17 + 4) != 3 || *(_WORD *)(v17 + 6) != 1 )
    {
      sub_975F38();
      return;
    }
    v7 = *(_DWORD *)(v17 + 8);
    if ( v7 )
    {
      v8 = v7 + a2;
      if ( FopReadSegmentMapHeader(a1, v7 + a2, v19) >= 0 )
      {
        v9 = (int *)BgpFwAllocateMemory(0x1Cu);
        v10 = v9;
        if ( v9 )
        {
          memset(v9, 0, 28);
          *v10 = v19[3] >> 1;
          v11 = v19[1] - 14;
          v12 = BgpFwAllocateMemory(v11);
          v13 = (_WORD *)v12;
          if ( v12 )
          {
            v14 = v11 >> 1;
            v10[1] = v12;
            if ( FioFwReadBytesAtOffset(a1, v8 + 14, 2 * (v11 >> 1), v12) >= 0 )
            {
              if ( v14 )
              {
                v15 = v13;
                do
                {
                  --v14;
                  *v15 = __rev16((unsigned __int16)*v15);
                  ++v15;
                }
                while ( v14 );
              }
              v16 = *v10;
              v10[3] = (int)v13;
              v10[2] = (int)&v13[v16 + 1];
              v10[4] = (int)&v13[2 * v16 + 1];
              v10[5] = (int)&v13[3 * v16 + 1];
              v10[6] = (int)&v13[4 * v16 + 1];
              *v18 = v10;
              v10 = 0;
            }
          }
          if ( v10 )
            FopFreeMappingTable((int)v10);
        }
      }
    }
  }
  if ( v6 )
    BgpFwFreeMemory(v6);
}
