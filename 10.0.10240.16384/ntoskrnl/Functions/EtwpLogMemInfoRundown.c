// EtwpLogMemInfoRundown 
 
int *__fastcall EtwpLogMemInfoRundown(int a1, int a2)
{
  int v2; // r2
  int v4[7]; // [sp+0h] [bp-28h] BYREF
  int v5[2]; // [sp+20h] [bp-8h] BYREF

  v5[0] = a1;
  v5[1] = a2;
  MmQuerySystemMemoryInformation(v4);
  EtwpLogMemInfo(v5, (int)v4, v2);
  return EtwpLogMemInfoWs(v5, v4[0]);
}
