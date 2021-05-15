// CcPerfLogCanWriteFail 
 
int *__fastcall CcPerfLogCanWriteFail(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v6[4]; // [sp+8h] [bp-30h] BYREF
  int v7[8]; // [sp+18h] [bp-20h] BYREF

  if ( a1 )
    v4 = *(_DWORD *)(a1 + 12);
  else
    v4 = 0;
  v6[1] = a3;
  v6[2] = a4;
  v6[3] = a2;
  v7[0] = (int)v6;
  v7[1] = 0;
  v7[2] = 16;
  v7[3] = 0;
  v6[0] = v4;
  return EtwTraceKernelEvent(v7, 1, 0x80020000, 5638, 4200706);
}
