// TraceLoggingRegisterEx 
 
int __fastcall TraceLoggingRegisterEx(int a1, __int64 a2)
{
  int v3; // r4
  int v4; // r3
  int v5; // r4
  int v7[8]; // [sp+8h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 4);
  v7[0] = *(_DWORD *)(v3 - 16);
  v7[1] = *(_DWORD *)(v3 - 12);
  v7[2] = *(_DWORD *)(v3 - 8);
  v4 = *(_DWORD *)(v3 - 4);
  *(_QWORD *)(a1 + 32) = a2;
  v7[3] = v4;
  v5 = EtwRegister((int)v7, (int)TlgEnableCallback, a1);
  if ( !v5 )
    EtwSetInformation(
      *(_DWORD *)(a1 + 24),
      *(_DWORD *)(a1 + 28),
      2,
      *(_DWORD *)(a1 + 4),
      **(unsigned __int16 **)(a1 + 4));
  return v5;
}
