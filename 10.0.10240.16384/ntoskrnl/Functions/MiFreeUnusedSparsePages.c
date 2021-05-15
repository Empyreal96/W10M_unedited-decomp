// MiFreeUnusedSparsePages 
 
void MiFreeUnusedSparsePages()
{
  int v0; // r7
  unsigned int v1; // r6
  int v2; // r9
  unsigned int v3; // r10
  unsigned int v4; // r8
  unsigned int v5; // r0
  int *v6; // r5
  unsigned int v7; // r0
  unsigned int v8; // r10
  unsigned int v9; // r7
  int v10; // r4
  char *v11; // r7
  unsigned int v12; // r9
  int *v13; // r8
  int *v14; // r6
  int *v15; // r6
  int v16; // r7
  int v17; // r0
  unsigned int v18; // r3
  char *v19; // [sp+8h] [bp-40h]
  int v20; // [sp+Ch] [bp-3Ch] BYREF
  int *v21; // [sp+10h] [bp-38h]
  int v22; // [sp+14h] [bp-34h]
  int v23; // [sp+18h] [bp-30h]
  unsigned int v24; // [sp+1Ch] [bp-2Ch]
  unsigned int v25; // [sp+20h] [bp-28h]
  unsigned int v26; // [sp+24h] [bp-24h]

  v0 = MmPfnDatabase;
  v1 = MmPfnDatabase + 24 * dword_640504 + 23;
  v2 = 4194300;
  v3 = (((unsigned int)MmPfnDatabase >> 10) & 0x3FFFFC) - 0x40000000;
  v4 = ((v1 >> 10) & 0x3FFFFC) - 0x40000000;
  v26 = v4;
  v23 = 4194300;
  v24 = v1;
  if ( v3 > v4 )
  {
LABEL_34:
    while ( v0 != v1 )
      ;
  }
  else
  {
    while ( 1 )
    {
      v5 = MiGetNextPageTable(v3, v4, 1, 17, 1, &v20);
      if ( !v5 )
        break;
      v6 = (int *)(v5 << 10);
      v21 = (int *)(v5 << 10);
      while ( 1 )
      {
        v7 = v20 == 1 ? ((v2 & (v5 >> 10)) + 4) << 10 : v5 + 4;
        v8 = v7;
        v25 = v7;
        if ( v7 > v4 )
          break;
        v5 = MiGetNextPageTable(v7, v4, 1, 17, 1, &v20);
        if ( !v5 )
          break;
        if ( v5 != v8 )
        {
          v9 = v8 << 10;
          v10 = MmPfnDatabase;
          v22 = v8 << 10;
          goto LABEL_12;
        }
      }
      v10 = MmPfnDatabase;
      v9 = (MmPfnDatabase + 24 * (dword_640504 + 1)) & 0xFFFFF000;
      v22 = v9;
      v24 = v9;
      if ( (int *)v9 == v6 )
        return;
LABEL_12:
      v19 = (char *)(v9 - (_DWORD)v6);
      v11 = (char *)(v9 - (_DWORD)v6);
      do
      {
        v12 = (unsigned int)RtlCompareMemoryUlong(v6, v11, 0);
        if ( v12 < 0x1000 )
        {
          if ( !v12 )
            v12 = 4096;
        }
        else
        {
          v13 = v6;
          v14 = (int *)(v10 + 24 * (((int)v6 - v10) / 24));
          if ( v14 != v6 )
          {
            if ( MiIsAddressValid((unsigned int)v14, 0, (int)v6 - v10, 3 * (((int)v6 - v10) / 24)) == 1
              && RtlCompareMemoryUlong(v14, (char *)0x18, 0) != (char *)24 )
            {
              v13 = v6 + 1024;
            }
            v10 = MmPfnDatabase;
          }
          v15 = (int *)((char *)v6 + (v12 & 0xFFFFF000));
          if ( (v12 & 0xFFF) == 0 && (int *)(v10 + 24 * (((int)v15 - v10) / 24)) != v15 )
            v15 -= 1024;
          if ( v13 < v15 )
          {
            v16 = v23;
            do
            {
              if ( (*(_DWORD *)((((unsigned int)v13 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
                v17 = (((unsigned int)v13 >> 12) & 0x3FF)
                    + (*(_DWORD *)((((unsigned int)v13 >> 20) & 0xFFC) - 1070596096) >> 12);
              else
                v17 = *(_DWORD *)((v16 & ((unsigned int)v13 >> 10)) - 0x40000000) >> 12;
              *(_WORD *)(v10 + 24 * v17 + 16) = 0;
              MiAddExpansionNonPagedPool(v17, 1);
              v13 += 1024;
              v10 = MmPfnDatabase;
            }
            while ( v13 < v15 );
            v6 = v21;
            v11 = v19;
          }
        }
        v18 = (v12 + 4095) & 0xFFFFF000;
        v6 = (int *)((char *)v6 + v18);
        v11 -= v18;
        v21 = v6;
        v19 = v11;
      }
      while ( (unsigned int)v11 >= 0x1000 );
      v3 = v25;
      v4 = v26;
      v0 = v22;
      v2 = v23;
      if ( v25 > v26 )
      {
        v1 = v24;
        goto LABEL_34;
      }
    }
  }
}
