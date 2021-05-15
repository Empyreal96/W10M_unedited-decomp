// RtlRaiseStatus 
 
void __fastcall __noreturn RtlRaiseStatus(int a1)
{
  int v2; // r0
  _DWORD v3[20]; // [sp+0h] [bp-1F8h] BYREF
  char v4[64]; // [sp+50h] [bp-1A8h] BYREF
  int v5; // [sp+90h] [bp-168h]

  RtlpCaptureContext((int)v4);
  v3[2] = 0;
  v3[4] = 0;
  v3[0] = a1;
  v3[1] = 1;
  v3[3] = v5;
  RtlDispatchException((int)v3, (int)v4);
  v2 = ZwRaiseException();
  RtlRaiseStatus(v2);
}
