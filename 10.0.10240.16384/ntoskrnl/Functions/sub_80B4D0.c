// sub_80B4D0 
 
void sub_80B4D0(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r5
  int v5; // r2
  int v6; // r3
  __int64 v7; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  __int64 v9; // [sp+8h] [bp+8h] BYREF
  va_list va1; // [sp+8h] [bp+8h]
  __int64 v11; // [sp+10h] [bp+10h] BYREF
  va_list va2; // [sp+10h] [bp+10h]
  va_list va3; // [sp+18h] [bp+18h] BYREF

  va_start(va3, a4);
  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v7 = va_arg(va1, __int64);
  va_copy(va2, va1);
  v9 = va_arg(va2, _QWORD);
  va_copy(va3, va2);
  v11 = va_arg(va3, __int64);
  KeQuerySystemTime((__int64 *)va);
  if ( !ExpRealTimeIsUniversal )
  {
    if ( v4 )
    {
      ExLocalTimeToSystemTime((__int64 *)va2, (__int64 *)va1);
      KeSetSystemTime((int)va1, (int)va, 0);
      goto LABEL_6;
    }
    ExSystemTimeToLocalTime((__int64 *)va, (int *)va2);
    RtlTimeToTimeFields((int)va2, va3, v5, v6);
    HalSetRealTimeClock(va3);
  }
  v9 = v7;
LABEL_6:
  PoNotifySystemTimeSet();
  JUMPOUT(0x78F8CC);
}
