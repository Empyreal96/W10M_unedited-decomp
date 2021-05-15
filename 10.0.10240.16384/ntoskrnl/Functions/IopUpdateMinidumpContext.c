// IopUpdateMinidumpContext 
 
int *__fastcall IopUpdateMinidumpContext(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r7
  int v8; // r8
  int *result; // r0
  int v12; // r1
  int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r2
  __int16 v23; // r3
  int v24; // r2
  int v25; // r7
  unsigned int v26; // r10
  unsigned int v27; // r4
  int v28; // r2
  unsigned int v29; // r7
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r4
  int *i; // r4
  int v34; // [sp+0h] [bp-30h]
  unsigned int v35; // [sp+4h] [bp-2Ch]
  int v37; // [sp+Ch] [bp-24h]

  v7 = a4;
  v37 = 0;
  v8 = a3;
  v35 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( a1 == 126 && a5 )
  {
    v37 = 1;
    v34 = a5;
  }
  else
  {
    v34 = a6;
  }
  IoAddTriageDumpDataBlock(a2 & 0xFFFFF000, 4096);
  IoAddTriageDumpDataBlock(v8 & 0xFFFFF000, 4096);
  IoAddTriageDumpDataBlock(v7 & 0xFFFFF000, 4096);
  result = (int *)IoAddTriageDumpDataBlock(a5 & 0xFFFFF000, 4096);
  if ( a1 == 205 || a1 == 214 || a1 == 209 && (result = (int *)MmIsSpecialPoolAddress(a2, v12, v13)) != 0 )
    result = (int *)IoAddTriageDumpDataBlock((a2 - 4096) & 0xFFFFF000, 4096);
  v14 = *(_DWORD *)(v34 + 56);
  v15 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC40) + 16;
  if ( v15 - KeKernelStackSize <= v14 && v14 < v15 )
  {
    v16 = v15 - v14;
    if ( v15 - v14 >= 0x3FFF )
      v16 = 0x3FFF;
    v17 = IopGetMaxValidMemorySize(*(_DWORD *)(v34 + 56), v16, v15);
    result = (int *)IoAddTriageDumpDataBlock(v14, v17);
  }
  v18 = v35;
  if ( *(unsigned __int8 *)(v35 + 2329) > 2u )
  {
    v19 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574);
    if ( v19 - 12288 <= v14 && v14 < v19 )
    {
      v20 = v19 - v14;
      if ( v19 - v14 >= 0x3FFF )
        v20 = 0x3FFF;
      v21 = IopGetMaxValidMemorySize(v14, v20, v19);
      result = (int *)IoAddTriageDumpDataBlock(v14, v21);
      v18 = v35;
    }
  }
  if ( a1 == 307 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v22 = 0;
    }
    else
    {
      __disable_irq();
      v22 = 1;
    }
    v23 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v22 )
      __enable_irq();
    if ( (v23 & 1) == 0 )
      goto LABEL_52;
    v24 = *(_DWORD *)(v18 + 12);
    if ( a7 == v24 )
      goto LABEL_52;
    v25 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1574);
    v26 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC40) + 16;
    v27 = v26 - KeKernelStackSize;
    if ( IopIsAddressRangeValid(v25 - 4, 4, v24) )
    {
      v29 = *(_DWORD *)(v25 - 4);
      if ( IopIsAddressRangeValid(v29, 4, v28) )
      {
        if ( v27 <= v29 && v29 < v26 )
          v27 = v29;
      }
    }
    v30 = v26 - v27;
    if ( v26 - v27 >= 0x3FFF )
      v30 = 0x3FFF;
    v31 = IopGetMaxValidMemorySize(v27, v30, v28);
    result = (int *)IoAddTriageDumpDataBlock(v27, v31);
    v7 = a4;
  }
  if ( a1 == 335 || a1 == 348 )
  {
    if ( a5 )
    {
      IoAddTriageDumpDataBlock(a5, 8);
      result = *(int **)(a5 + 4);
      if ( result )
        result = (int *)IopAddBugcheckTriageThread();
    }
  }
  if ( a1 == 159 )
  {
    if ( a2 == 4 )
    {
      if ( v7 )
        result = (int *)IopAddBugcheckPnpTriageData(v7, a5);
      goto LABEL_52;
    }
    if ( a2 != 3 )
      goto LABEL_52;
    v32 = a3;
    result = (int *)IopAddBugcheckPowerTriageData(a3, v7, a5);
  }
  else
  {
    v32 = a3;
  }
  if ( a1 == 160 && a2 == 1561 )
    result = (int *)IopAddBugcheckTriageDeviceNode(*(_DWORD *)(v32 + 28));
LABEL_52:
  for ( i = (int *)PopThermal; i != &PopThermal; i = (int *)*i )
    result = (int *)IoAddTriageDumpDataBlock((int)i, 704);
  if ( v37 )
  {
    result = &CrashdmpDumpBlock;
    if ( CrashdmpDumpBlock )
    {
      *(_DWORD *)(CrashdmpDumpBlock + 16) |= 0x10000000u;
      result = (int *)memmove(CrashdmpDumpBlock + 40, v34, 0x1A0u);
    }
  }
  return result;
}
