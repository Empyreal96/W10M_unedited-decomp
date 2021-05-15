// MmIdentifyPhysicalMemory 
 
int __fastcall MmIdentifyPhysicalMemory(int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int *v5; // r0
  unsigned int *v6; // r5
  unsigned int v7; // r6
  unsigned int *v8; // r7
  unsigned int v9; // t1
  unsigned int v10; // r4
  unsigned int v11; // r9
  unsigned int *v14; // [sp+10h] [bp-58h]
  int v16[4]; // [sp+18h] [bp-50h] BYREF
  int v17[4]; // [sp+28h] [bp-40h] BYREF
  int *v18; // [sp+38h] [bp-30h] BYREF
  int v19; // [sp+3Ch] [bp-2Ch]
  int v20; // [sp+40h] [bp-28h]
  int v21; // [sp+44h] [bp-24h]

  v3 = a1;
  v5 = (unsigned int *)MiReferencePageRuns((int)MiSystemPartition, 0);
  v6 = v5;
  v7 = 0;
  v14 = v5;
  if ( *v5 )
  {
    v8 = v5;
    do
    {
      v9 = v8[2];
      v8 += 2;
      v10 = MmPfnDatabase + 24 * v9;
      v11 = v10 + 24 * v8[1];
      if ( v10 < v11 )
      {
        do
        {
          if ( !a3 || (*(_BYTE *)(v10 + 18) & 7) == 6 )
          {
            v17[0] = 0;
            v17[1] = 0;
            v17[2] = 0;
            v17[3] = 0;
            MiIdentifyPfnWrapper((int *)v10, v17);
            v18 = v17;
            v19 = 0;
            v20 = 16;
            v21 = 0;
            EtwpLogKernelEvent((int *)&v18, a1, 1, a2, 4200450);
          }
          v10 += 24;
        }
        while ( v10 < v11 );
        v6 = v14;
      }
      ++v7;
    }
    while ( v7 < *v6 );
    v3 = a1;
  }
  MiDereferencePageRuns((int)v6);
  if ( !a3 )
  {
    v16[1] = MmPfnDatabase;
    v16[0] &= 0xFFFFFFE0;
    v16[2] = MxPfnAllocation;
    v18 = v16;
    v19 = 0;
    v20 = 12;
    v21 = 0;
    EtwpLogKernelEvent((int *)&v18, v3, 1, 635, 4200450);
  }
  return 0;
}
