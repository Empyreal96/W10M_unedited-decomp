// PopHiberInitializeResources 
 
char *__fastcall PopHiberInitializeResources(_DWORD *a1)
{
  unsigned int v1; // r9
  unsigned int v3; // r6
  unsigned int v4; // r8
  unsigned int v5; // r2
  unsigned int v6; // r10
  unsigned int v7; // r7
  unsigned int v8; // r1
  int v9; // r5
  int v10; // r10
  int v11; // r2
  unsigned int v12; // r0
  unsigned int *v13; // r2
  int v14; // lr
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r8
  const void *v18; // r2
  char *result; // r0
  int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // [sp+8h] [bp-48h]
  unsigned int v23; // [sp+Ch] [bp-44h] BYREF
  int v24; // [sp+10h] [bp-40h]
  int v25; // [sp+14h] [bp-3Ch]
  unsigned int v26; // [sp+18h] [bp-38h]
  unsigned int v27; // [sp+1Ch] [bp-34h]
  int v28; // [sp+20h] [bp-30h] BYREF
  unsigned int v29; // [sp+24h] [bp-2Ch]
  __int64 v30[5]; // [sp+28h] [bp-28h] BYREF

  v23 = 0;
  v24 = 0;
  v28 = 0;
  v1 = 0;
  v3 = KeNumberProcessors_0;
  if ( (PopSimulate & 0x10000000) != 0 )
    goto LABEL_22;
  v4 = (112 * KeNumberProcessors_0 + 4095) & 0xFFFFF000;
  if ( RtlGetCompressionWorkSpaceSize(260) < 0 )
    goto LABEL_22;
  v5 = v22;
  if ( v27 > v22 )
  {
    v5 = v27;
    v22 = v27;
  }
  v6 = v4 + v5 * v3;
  IoGetDumpStackTransferSizes(&v28, &v23);
  v7 = v23 >> 12;
  if ( v23 >> 12 < 0x10 )
    v7 = 16;
  if ( v7 > 0x100 )
    v7 = 256;
  v8 = v7 << 12;
  if ( PopHiberChecksummingEnabledReg )
  {
    v1 = (v6 + 4095) & 0xFFFFF000;
    PopCalculateHiberFileSize(v30, 0);
    v24 = 2 * (v30[0] >> 9);
    v6 = v24 + v1;
    v8 = v7 << 12;
  }
  LODWORD(v30[0]) = (17 * v8 + 65604 * v3 - 1) & ~(v8 - 1);
  v29 = LODWORD(v30[0]) + ((v6 + 4095) & 0xFFFFF000);
  v25 = (v29 + (v3 << 17) + 4095) & 0xFFFFF000;
  v26 = (v6 + 4095) & 0xFFFFF000;
  v9 = ExAllocatePoolWithTag(512, v25, 1919052136);
  if ( !v9 )
    goto LABEL_22;
  v10 = MmAllocateDumpHibernateResources(v3 << 16);
  if ( !v10 )
  {
    ExFreePoolWithTag(v9);
LABEL_22:
    v9 = dword_61EF08;
    v3 = 1;
    v7 = 1;
    v26 = 1;
    memset((_BYTE *)dword_61EF08, 0, 112);
    v17 = 12288;
    *(_DWORD *)(v9 + 4) = dword_61EEBC;
    v18 = (const void *)dword_61EF04;
    v24 = dword_61EF04;
    goto LABEL_23;
  }
  if ( PopHiberChecksummingEnabledReg )
  {
    v11 = v24;
    a1[74] = v1 + v9;
    a1[75] = v11;
    memset((_BYTE *)(v1 + v9), 0, v11);
  }
  v24 = v26 + v9;
  v26 = 16;
  memset((_BYTE *)v9, 0, 112 * v3);
  v12 = 0;
  if ( v3 )
  {
    v13 = (unsigned int *)v9;
    v14 = v10;
    v15 = v29 + v9;
    do
    {
      v13[3] = v15 + 0x10000;
      *v13 = v15;
      v13[1] = v14;
      if ( v22 )
        v13[2] = v4 + v12 * v22 + v9;
      ++v12;
      v13 += 28;
      v15 += 0x20000;
      v14 += 0x10000;
    }
    while ( v12 < v3 );
  }
  MmMarkHiberRange((int)a1, v10, v3 << 16);
  PoSetHiberRange((int)a1, 0x8000, (const void *)(v4 + v9), (const void *)(v25 - v4), 1919052136);
  v16 = v25;
  a1[45] = v9;
  a1[46] = v16;
  a1[47] = v10;
  v17 = v30[0];
  v18 = (const void *)dword_61EF04;
LABEL_23:
  result = PoSetHiberRange((int)a1, 0x8000, v18, (const void *)0x3000, 1919052136);
  v20 = v24;
  a1[40] = v3;
  a1[41] = v9;
  a1[42] = v20;
  a1[43] = v17;
  v21 = v26;
  a1[68] = v7;
  a1[44] = v21;
  return result;
}
