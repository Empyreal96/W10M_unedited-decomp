// EtwpRealtimeSendEmptyMarker 
 
int __fastcall EtwpRealtimeSendEmptyMarker(_DWORD *a1)
{
  _DWORD v3[13]; // [sp+0h] [bp-50h] BYREF
  __int16 v4; // [sp+34h] [bp-1Ch]

  EtwpInitializeBufferHeader(a1, (int)v3);
  EtwpResetBufferHeader((int)v3, 6);
  v3[11] = 3;
  v3[12] = 72;
  v4 = 1;
  return EtwpRealtimeDeliverBuffer(a1, (int)v3);
}
