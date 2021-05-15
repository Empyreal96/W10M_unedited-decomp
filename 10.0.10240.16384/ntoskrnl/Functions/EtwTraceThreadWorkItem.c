// EtwTraceThreadWorkItem 
 
int *__fastcall EtwTraceThreadWorkItem(int *result, int a2)
{
  int v2[7]; // [sp+8h] [bp-28h] BYREF
  int v3[2]; // [sp+28h] [bp-8h] BYREF

  v3[1] = a2;
  v3[0] = (int)result;
  if ( result != (int *)IopProcessWorkItem )
  {
    v2[0] = (int)v3;
    v2[1] = 0;
    v2[2] = 4;
    v2[3] = 0;
    result = EtwTraceKernelEvent(v2, 1, 0x48000000u, a2, 273684738);
  }
  return result;
}
