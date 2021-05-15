// sub_7CD1C0 
 
void sub_7CD1C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r5
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( KsepApplyShimsToDriver(v8, (unsigned __int16 *)va, a7, a8) >= 0 )
  {
    KsepEvntLogShimsApplied((unsigned __int16 *)va, a7, a8);
    JUMPOUT(0x770FB6);
  }
  JUMPOUT(0x770FBE);
}
