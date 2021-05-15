// EtwpLogMemInfo 
 
int *__fastcall EtwpLogMemInfo(int *a1, int a2, int a3)
{
  char v6; // [sp+8h] [bp-A0h] BYREF
  int v7; // [sp+Ch] [bp-9Ch] BYREF
  char v8[88]; // [sp+10h] [bp-98h] BYREF
  char *v9; // [sp+68h] [bp-40h]
  int v10; // [sp+6Ch] [bp-3Ch]
  int v11; // [sp+70h] [bp-38h]
  int v12; // [sp+74h] [bp-34h]
  int v13[12]; // [sp+78h] [bp-30h] BYREF

  v6 = 8;
  v9 = &v6;
  v10 = 0;
  v11 = 1;
  v12 = 0;
  MmQueryMemoryListInformation((int)v8, 0x58u, a3, &v7);
  v13[0] = (int)v8;
  v13[1] = 0;
  v13[2] = 88;
  v13[3] = 0;
  v13[4] = a2;
  v13[5] = 0;
  v13[6] = 16;
  v13[7] = 0;
  if ( a1 )
    return (int *)EtwpLogKernelEvent(v13, *a1, 2, 624, 4200451);
  if ( (dword_61AD44 & 0x80000) != 0 )
    EtwWrite(EtwpMemoryProvRegHandle, unk_61A944, (int)&KERNEL_MEM_EVENT_MEMINFO, 0);
  return EtwTraceKernelEvent(v13, 2, 0x20080000u, 624, 4200451);
}
