// EtwTracePageFault 
 
int *__fastcall EtwTracePageFault(int *result, int a2, char a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r5
  int v6; // r3
  __int16 v7; // r3
  int v8; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+Ch] [bp-24h]
  int v10[8]; // [sp+10h] [bp-20h] BYREF

  if ( result == (int *)273 )
  {
    v4 = 523;
  }
  else if ( result == (int *)272 )
  {
    v4 = 522;
  }
  else if ( result == (int *)274 )
  {
    v4 = 524;
  }
  else if ( result == (int *)276 )
  {
    v4 = 526;
  }
  else if ( result == (int *)275 )
  {
    v4 = 525;
  }
  else
  {
    if ( result != (int *)-1073741819 )
      return result;
    v4 = 527;
  }
  v8 = a2;
  v9 = 0;
  if ( a4 )
    v9 = *(_DWORD *)(a4 + 128);
  v10[1] = 0;
  v10[2] = 8;
  v10[3] = 0;
  v10[0] = (int)&v8;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_BYTE *)(v5 + 0x3C8) & 0x10) != 0 )
    return EtwTraceKernelEvent(v10, 1, 0x1000u, v4, 33554690);
  --*(_WORD *)(v5 + 310);
  *(_BYTE *)(v5 + 968) |= 0x10u;
  if ( a3 )
    v6 = 33558786;
  else
    v6 = 50338050;
  result = EtwTraceKernelEvent(v10, 1, 0x1000u, v4, v6);
  *(_BYTE *)(v5 + 968) &= 0xEFu;
  v7 = *(_WORD *)(v5 + 310) + 1;
  *(_WORD *)(v5 + 310) = v7;
  if ( !v7 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    result = (int *)KiCheckForKernelApcDelivery((int)result);
  return result;
}
