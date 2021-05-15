// MiRemoveMdlPages 
 
unsigned int __fastcall MiRemoveMdlPages(unsigned int a1, int a2)
{
  unsigned int v2; // r5
  int *v4; // r7
  unsigned int v5; // r1
  int v6; // r6
  int v7; // r9
  int v8; // r1
  int v9; // r0
  int v10; // r10
  int v11; // r3
  int v12; // r8
  int *v13; // r2
  bool v14; // zf
  int v15; // r4
  int v16; // r5
  int v17; // r0
  unsigned int v19; // [sp+0h] [bp-38h]
  int v20; // [sp+4h] [bp-34h]
  int v21; // [sp+8h] [bp-30h]
  int v22; // [sp+Ch] [bp-2Ch]
  unsigned int v24; // [sp+14h] [bp-24h]

  v2 = a1;
  v4 = (int *)(a1 + 28);
  v5 = *(_DWORD *)(a1 + 20) >> 12;
  v19 = a1 + 28 + 4 * v5;
  v24 = v5;
  qsort(a1 + 28, v5, 4u, (int (__fastcall *)(unsigned int, _BYTE *))MiPartitionMdlPageSort);
  v6 = 0;
  v7 = -1;
  v8 = 0;
  v9 = 0;
  v10 = -1;
  v11 = -1;
  v20 = 0;
  v21 = 0;
  v12 = 0;
  v22 = 0;
  if ( (a2 & 0x100000) != 0 )
  {
    v9 = 8;
    v22 = 8;
  }
  v13 = (int *)v19;
  if ( (unsigned int)v4 <= v19 )
  {
    v14 = v4 == (int *)v19;
    do
    {
      if ( v14 || (v7 = *v4, *v4 != v11) )
      {
        if ( v6 )
        {
          if ( v8 < 0 || (v8 = MiRemovePhysicalMemory(v10, v6, v9), v21 = v8, v8 < 0) )
          {
            v15 = 24 * v10;
            v16 = v6;
            do
            {
              v17 = v15 + MmPfnDatabase;
              *(_DWORD *)(v17 + 20) &= 0xF7FFFFFF;
              MiSetPfnOwnedAndActive(v17, -4, *(unsigned __int8 *)(v17 + 18) >> 6, 2);
              v15 += 24;
              --v16;
            }
            while ( v16 );
            MiFreeContiguousPages((int)MiSystemPartition, v10, v6);
            v12 = v20 + v6;
            v8 = v21;
            v20 += v6;
          }
          v13 = (int *)v19;
        }
        v10 = v7;
        v6 = 1;
      }
      else
      {
        ++v6;
      }
      ++v4;
      v9 = v22;
      v14 = v4 == v13;
      v11 = v7 + 1;
    }
    while ( v4 <= v13 );
    v2 = a1;
    if ( v12 )
    {
      if ( v12 == v24 )
      {
        ExFreePoolWithTag(a1);
        v2 = 0;
      }
      else
      {
        *(_DWORD *)(a1 + 20) -= v12 << 12;
      }
    }
  }
  return v2;
}
