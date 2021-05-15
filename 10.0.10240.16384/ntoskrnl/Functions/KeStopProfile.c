// KeStopProfile 
 
int __fastcall KeStopProfile(int a1)
{
  int v3[10]; // [sp+0h] [bp-28h] BYREF

  memset(v3, 0, 32);
  v3[3] = 65537;
  v3[1] = KeNumberProcessors_0;
  v3[2] = KeNumberProcessors_0;
  v3[0] = a1;
  v3[4] = 0;
  v3[5] = 0;
  if ( (unsigned int)KeNumberProcessors_0 <= 1 )
    KiStopProfileTarget(v3);
  else
    KeIpiGenericCall(KiStopProfileTarget, (int)v3, 0, KeNumberProcessors_0);
  if ( v3[6] )
    ExFreePoolWithTag(v3[6]);
  return LOBYTE(v3[7]);
}
