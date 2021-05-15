// PpmEventIdleStateChange 
 
int *__fastcall PpmEventIdleStateChange(int *result, int a2)
{
  _DWORD v2[4]; // [sp+8h] [bp-30h] BYREF
  int v3[8]; // [sp+18h] [bp-20h] BYREF

  if ( (dword_682610 & 0x8000) != 0 )
  {
    v2[0] = result;
    v2[1] = a2;
    v2[2] = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x998);
    v2[3] = 0;
    v3[0] = (int)v2;
    v3[1] = 0;
    v3[2] = 16;
    v3[3] = 0;
    result = EtwTraceKernelEvent(v3, 1, 0x80008000, 4661, 1538);
  }
  return result;
}
