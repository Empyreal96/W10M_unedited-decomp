// _RegRtlIsPredefinedKey 
 
BOOL __fastcall RegRtlIsPredefinedKey(int a1)
{
  return a1 == -2147483646
      || a1 == 0x80000000
      || a1 == -2147483647
      || a1 == -2147483645
      || a1 == -2147483644
      || a1 == -2147483643
      || a1 == -2147483642
      || a1 == -2147483641;
}
