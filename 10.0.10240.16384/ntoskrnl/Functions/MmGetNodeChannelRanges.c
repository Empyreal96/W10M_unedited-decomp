// MmGetNodeChannelRanges 
 
int __fastcall MmGetNodeChannelRanges(unsigned int **a1, int *a2)
{
  unsigned int **v2; // r10
  int *v3; // r9
  unsigned int *v4; // r4
  int v5; // r8
  unsigned int *v6; // r0
  unsigned int *v7; // r5
  _DWORD *v8; // r1
  int v9; // r6
  unsigned int v10; // r0
  _DWORD *v11; // r7
  unsigned __int8 *v12; // lr
  int v13; // r3
  int v14; // r2
  int *v16; // [sp+4h] [bp-24h]

  v2 = a1;
  v16 = a2;
  v3 = a2;
  v4 = (unsigned int *)MiReferencePageRuns((int)MiSystemPartition, 1);
  v5 = 32 * (*v4 - 1) + 48;
  v6 = (unsigned int *)ExAllocatePoolWithTag(512, v5, 1750101325);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 4;
    v9 = 0;
    *v6 = *v4;
    v6[1] = 0;
    v10 = 0;
    v11 = v4 + 2;
    v7[2] = (unsigned __int16)KeNumberNodes;
    v7[3] = 1;
    v12 = (unsigned __int8 *)&v4[2 * *v4 + 2];
    if ( *v4 )
    {
      do
      {
        v8[2] = *v11;
        v8[3] = 0;
        v8[4] = v11[1];
        v8[5] = 0;
        v13 = *v12;
        *v8 = v13;
        v14 = v12[1];
        v8[1] = v14;
        v8[6] = *(unsigned __int8 *)(dword_63F718 + v14 + 104 * v13 + 99) == 1;
        ++v10;
        v11 += 2;
        v8 += 8;
        v12 += 2;
      }
      while ( v10 < *v4 );
      v3 = v16;
      v2 = a1;
      v9 = 0;
    }
  }
  else
  {
    v9 = -1073741670;
  }
  MiDereferencePageRuns((int)v4);
  *v2 = v7;
  *v3 = v5;
  return v9;
}
