// PnprGetMillisecondCounter 
 
int __fastcall PnprGetMillisecondCounter(int a1)
{
  int v2; // r0
  int v3; // r4
  int result; // r0
  __int64 v5; // [sp+0h] [bp-20h] BYREF
  __int64 v6[3]; // [sp+8h] [bp-18h] BYREF

  KeQueryPerformanceCounter(&v5, v6);
  if ( !v6[0] )
    __brkdiv0();
  v2 = _rt_sdiv64(v6[0], 1000 * v5);
  v3 = v2;
  if ( a1 )
    result = 0;
  else
    result = dword_64B104 - dword_64B100 + v2;
  dword_64B104 = result;
  dword_64B100 = v3;
  return result;
}
