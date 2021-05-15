// CsrShutdownSynchronization 
 
int CsrShutdownSynchronization(int a1, ...)
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r4
  char v6[8]; // [sp+28h] [bp-100h] BYREF
  char v7[24]; // [sp+38h] [bp-F0h] BYREF
  unsigned __int16 v8[108]; // [sp+50h] [bp-D8h] BYREF
  int varg_r1; // [sp+134h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+134h] [bp+Ch]
  int varg_r2; // [sp+138h] [bp+10h]
  va_list varg_r3; // [sp+13Ch] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r1;
  v2 = varg_r2;
  v3 = PsAttachSiloToCurrentThread(a1);
  swprintf_s((int)v8, 100, (int)L"\\Sessions\\%ld\\BaseNamedObjects\\EventRitExited", varg_r1);
  RtlInitUnicodeString((unsigned int)v6, v8);
  ZwCreateEvent();
  swprintf_s((int)v8, 100, (int)L"\\Sessions\\%ld\\BaseNamedObjects\\EventShutDownCSRSS", v1, 0);
  RtlInitUnicodeString((unsigned int)v6, v8);
  v4 = ZwOpenEvent();
  PsDetachSiloFromCurrentThread(v3);
  if ( v4 >= 0 )
  {
    if ( v2 )
    {
      KiStackAttachProcess(v2, 0, (int)v7);
      PsInvokeWin32Callout(31, 0, 1, (int *)varg_r1a);
      KiUnstackDetachProcess((unsigned int)v7, 0);
    }
    v4 = ZwSetEvent();
  }
  return v4;
}
