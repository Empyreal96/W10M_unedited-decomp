// KeSetIntervalProfile 
 
int *__fastcall KeSetIntervalProfile(int *result, int a2)
{
  int *v2; // r6
  int v4; // r7
  int v5; // [sp+0h] [bp-48h]
  _DWORD v6[2]; // [sp+8h] [bp-40h] BYREF
  _DWORD v7[4]; // [sp+10h] [bp-38h] BYREF
  int v8[10]; // [sp+20h] [bp-28h] BYREF

  v2 = 0;
  v4 = (int)result;
  if ( (dword_682604 & 0x402) != 0 )
  {
    result = (int *)KeQueryIntervalProfile(a2);
    v2 = result;
  }
  if ( a2 == 1 )
  {
    KiProfileAlignmentFixupInterval = v4;
  }
  else
  {
    v6[0] = a2;
    v6[1] = v4;
    result = (int *)KeGenericProcessorCallback(&KeActiveProcessors, (int)KiSetIntervalWorker, (int)v6, 1, v5);
  }
  if ( (dword_682604 & 0x402) != 0 )
  {
    result = (int *)KeQueryIntervalProfile(a2);
    if ( result != v2 )
    {
      v8[0] = (int)v7;
      v8[1] = 0;
      v8[2] = 12;
      v8[3] = 0;
      v7[0] = a2;
      v7[1] = result;
      v7[2] = v2;
      result = EtwTraceKernelEvent(v8, 1, 0x20000402u, 3912, 4200706);
    }
  }
  return result;
}
