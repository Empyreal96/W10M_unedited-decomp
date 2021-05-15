// SmWdStartMonitoring 
 
__int64 __fastcall SmWdStartMonitoring(int a1)
{
  __int64 v2; // [sp+0h] [bp-10h]

  KiSetTimerEx(a1, 0x3E8u, -10000000i64, 1000, 0, a1 + 48);
  return v2;
}
