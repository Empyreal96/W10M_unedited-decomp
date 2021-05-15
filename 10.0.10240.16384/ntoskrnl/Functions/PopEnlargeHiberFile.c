// PopEnlargeHiberFile 
 
int __fastcall PopEnlargeHiberFile(bool *a1, __int64 a2)
{
  int v4; // r0
  unsigned __int64 v5; // kr08_8
  int v6; // r5
  __int64 v8[3]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a2;
  v4 = MmGetNumberOfPhysicalPages(0);
  v5 = (unsigned __int64)(unsigned int)v4 << 12;
  v6 = PopResizeHiberFile(v4 << 12, HIDWORD(v5), v8);
  if ( v6 >= 0 && a1 )
  {
    if ( !v8[0] )
      __brkdiv0();
    *a1 = (unsigned int)_rt_udiv64(v8[0], 100 * v5) < 0x28;
  }
  return v6;
}
