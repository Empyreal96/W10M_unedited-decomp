// ExpSetSystemTime 
 
int __fastcall ExpSetSystemTime(int a1, int a2, int a3, int a4, __int64 a5, int a6)
{
  int v6; // r5
  int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r3
  __int64 v14; // [sp+0h] [bp-30h] BYREF
  _WORD v15[20]; // [sp+8h] [bp-28h] BYREF
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a6;
  if ( ExpRealTimeIsUniversal )
    v14 = a5;
  else
    ExSystemTimeToLocalTime(&a5, (int *)&v14);
  if ( a2 )
    v9 = 3;
  else
    v9 = 0;
  v10 = KeSetSystemTime((int)&a5, v6, v9);
  if ( a1 )
  {
    ExpRefreshTimeZoneInformation(v10);
    if ( !ExpSystemIsInCmosMode )
    {
      if ( ExpRealTimeIsUniversal )
      {
        v12 = HIDWORD(a5);
        v14 = a5;
      }
      else
      {
        ExSystemTimeToLocalTime(&a5, (int *)&v14);
      }
      RtlTimeToTimeFields((int)&v14, v15, v11, v12);
      HalSetRealTimeClock(v15);
    }
  }
  return PoNotifySystemTimeSet();
}
