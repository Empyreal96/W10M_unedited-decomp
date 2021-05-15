// PerfLogExecutiveResourceSetOwnerPointer 
 
int *__fastcall PerfLogExecutiveResourceSetOwnerPointer(int a1, int a2)
{
  unsigned int v4; // r3
  unsigned int v5; // r5
  int *result; // r0
  _DWORD v7[12]; // [sp+8h] [bp-50h] BYREF
  int v8[8]; // [sp+38h] [bp-20h] BYREF

  v4 = (unsigned int)KeGetPcr();
  v5 = (v4 & 0xFFFFF000) + 1408;
  ++*(_DWORD *)((v4 & 0xFFFFF000) + 0x14B0);
  v7[0] = 0;
  v7[1] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[2] = 0;
  v7[3] = 0;
  v7[4] = 0;
  v7[9] = a1;
  v7[10] = 0;
  v7[8] = a2;
  v7[7] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
  v8[0] = (int)v7;
  v8[1] = 0;
  v8[2] = 48;
  v8[3] = 0;
  result = EtwTraceKernelEvent(v8, 1, 0x20020000u, 1323, 22026242);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x404) )
  {
    result = EtwpGetTrackingLockSlotForThread(a2, a1 & 0xFFFF0000);
    if ( result )
    {
      if ( result[7] )
      {
        ++*(_DWORD *)(v5 + 3892);
        result[3] = 0;
        result[4] = 0;
        result[7] = 0;
        result[8] = 0;
        *result = 0;
        result[1] = 0;
        result[2] = 0;
        *((_WORD *)result + 10) = 0;
        *((_BYTE *)result + 22) = 0;
        *((_BYTE *)result + 23) = 0;
        result[10] = 0;
      }
      result[6] = 0;
    }
  }
  return result;
}
