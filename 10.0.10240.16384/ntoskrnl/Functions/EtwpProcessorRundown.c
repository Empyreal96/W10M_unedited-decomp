// EtwpProcessorRundown 
 
int __fastcall EtwpProcessorRundown(int a1)
{
  char *v1; // r5
  unsigned int v2; // r1
  unsigned int i; // r2
  char *v5; // r4
  unsigned int v6; // r0
  unsigned int v7; // r5
  unsigned int v8; // r4
  char *v9; // r6
  int v10; // r0
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r5
  char *v14; // r4
  unsigned int v16; // [sp+8h] [bp-110h] BYREF
  unsigned int v17; // [sp+Ch] [bp-10Ch] BYREF
  unsigned int v18; // [sp+10h] [bp-108h] BYREF
  char v19[192]; // [sp+18h] [bp-100h] BYREF
  int *v20; // [sp+D8h] [bp-40h] BYREF
  int v21; // [sp+DCh] [bp-3Ch]
  int v22; // [sp+E0h] [bp-38h]
  int v23; // [sp+E4h] [bp-34h]
  char *v24; // [sp+E8h] [bp-30h]
  int v25; // [sp+ECh] [bp-2Ch]
  unsigned int v26; // [sp+F0h] [bp-28h]
  int v27; // [sp+F4h] [bp-24h]

  v1 = v19;
  v2 = KeNumberProcessors_0;
  v16 = KeNumberProcessors_0;
  if ( (unsigned int)KeNumberProcessors_0 > 0x20 )
  {
    v1 = (char *)ExAllocatePoolWithTag(1, 4 * KeNumberProcessors_0, 1953985605);
    if ( !v1 )
      goto LABEL_14;
    v2 = v16;
  }
  for ( i = 0; i < v2; ++i )
  {
    v5 = &v1[4 * i];
    if ( i )
    {
      if ( i >= 0x20 )
        continue;
      v6 = KiProcessorIndexToNumberMappingTable[i];
      if ( !v6 )
        continue;
      *(_WORD *)v5 = v6 >> 6;
      v5[2] = v6 & 0x3F;
    }
    else
    {
      *(_WORD *)v5 = 0;
      v5[2] = 0;
    }
    v5[3] = 0;
    v2 = v16;
  }
  v20 = (int *)&v16;
  v21 = 0;
  v22 = 4;
  v23 = 0;
  v24 = v1;
  v25 = 0;
  v26 = 4 * v2;
  v27 = 0;
  EtwpLogKernelEvent((int *)&v20, a1, 2, 2843, 4200450);
  if ( v1 != v19 )
    ExFreePoolWithTag((unsigned int)v1);
LABEL_14:
  v7 = KeQueryActiveGroupCount();
  v8 = 0;
  v18 = v7;
  if ( v7 )
  {
    v9 = v19;
    do
    {
      v10 = KeQueryGroupAffinity((unsigned __int16)v8++);
      *(_DWORD *)v9 = v10;
      v9 += 4;
    }
    while ( v8 < v7 );
  }
  v20 = (int *)&v18;
  v21 = 0;
  v22 = 4;
  v23 = 0;
  v25 = 0;
  v26 = 4 * v7;
  v27 = 0;
  v24 = v19;
  EtwpLogKernelEvent((int *)&v20, a1, 2, 2842, 4200450);
  v11 = KeQueryHighestNodeNumber();
  v12 = v11 + 1;
  v17 = v11 + 1;
  v13 = 0;
  if ( v11 != -1 )
  {
    v14 = v19;
    do
    {
      KeQueryNodeActiveAffinity((unsigned __int16)v13, v14, 0);
      v12 = v17;
      ++v13;
      v14 += 12;
    }
    while ( v13 < v17 );
  }
  v20 = (int *)&v17;
  v21 = 0;
  v22 = 4;
  v23 = 0;
  v24 = v19;
  v25 = 0;
  v26 = 12 * v12;
  v27 = 0;
  return EtwpLogKernelEvent((int *)&v20, a1, 2, 2840, 4200450);
}
