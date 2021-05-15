// EtwpLogSessionWorkingSetInfo 
 
unsigned int __fastcall EtwpLogSessionWorkingSetInfo(int *a1)
{
  int v1; // r3
  unsigned int v3; // r4
  unsigned int result; // r0
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r2
  unsigned int v11; // r6
  _DWORD *v12; // r1
  _DWORD *v13; // r0
  int v14; // r3
  int v15; // r3
  int v16[2]; // [sp+8h] [bp-40h] BYREF
  int v17[14]; // [sp+10h] [bp-38h] BYREF

  v1 = 10;
  v16[0] = 10;
  v3 = 0;
  do
  {
    if ( v3 )
      return sub_80326C();
    result = ExAllocatePoolWithTag(512, 20 * v1, 1953985605);
    v3 = result;
    if ( !result )
      return result;
    v7 = MmQuerySessionWorkingSetInformation(result, v16, v5, v6);
    v1 = v16[0];
  }
  while ( v7 == -1073741820 );
  if ( v16[0] )
  {
    v8 = ExAllocatePoolWithTag(512, 36 * v16[0], 1953985605);
    v9 = v8;
    if ( v8 )
    {
      v10 = v16[0];
      v11 = 0;
      if ( v16[0] )
      {
        v12 = (_DWORD *)v8;
        v13 = (_DWORD *)v3;
        do
        {
          ++v11;
          *v12 = *v13;
          v12[1] = v13[1];
          v14 = v13[2];
          v12[8] = 0;
          v12[2] = v14;
          v12[3] = v13[3];
          v15 = v13[4];
          v12[6] = 0;
          v12[5] = 0;
          v12[4] = v15;
          v12[7] = 0;
          v10 = v16[0];
          v13 += 5;
          v12 += 9;
        }
        while ( v11 < v16[0] );
      }
      v17[0] = (int)v16;
      v17[1] = 0;
      v17[2] = 4;
      v17[3] = 0;
      v17[4] = v9;
      v17[5] = 0;
      v17[6] = 36 * v10;
      v17[7] = 0;
      if ( a1 )
      {
        EtwpLogKernelEvent(v17, *a1, 2, 638, (int)&dword_401804);
      }
      else
      {
        if ( (dword_682604 & 0x800000) != 0 )
          EtwTraceKernelEvent(v17, 2, 0x20800000u, 638, (int)&dword_401804);
        if ( (dword_61AD44 & 0x800000) != 0 )
          EtwWrite(EtwpMemoryProvRegHandle, unk_61A944, (int)KERNEL_MEM_EVENT_MEMINFO_SESSIONWS, 0);
      }
      ExFreePoolWithTag(v9);
    }
  }
  return ExFreePoolWithTag(v3);
}
