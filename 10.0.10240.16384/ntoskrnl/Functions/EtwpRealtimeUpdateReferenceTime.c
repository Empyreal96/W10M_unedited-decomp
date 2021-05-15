// EtwpRealtimeUpdateReferenceTime 
 
int __fastcall EtwpRealtimeUpdateReferenceTime(_DWORD *a1, int *a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r5
  int result; // r0
  _DWORD v8[13]; // [sp+0h] [bp-60h] BYREF
  __int16 v9; // [sp+34h] [bp-2Ch]
  int v10; // [sp+38h] [bp-28h]
  int v11; // [sp+3Ch] [bp-24h]
  int v12; // [sp+40h] [bp-20h]
  int v13; // [sp+44h] [bp-1Ch]

  EtwpInitializeBufferHeader(a1, (int)v8);
  EtwpResetBufferHeader((int)v8, 3);
  v8[11] = 3;
  v8[12] = 72;
  v9 = 1;
  v4 = a2[1];
  v5 = a2[2];
  v6 = a2[3];
  v10 = *a2;
  v11 = v4;
  v12 = v5;
  v13 = v6;
  if ( a1[82] )
    result = EtwpRealtimeSaveBuffer((int)a1, (int)v8);
  else
    result = EtwpRealtimeDeliverBuffer(a1, (int)v8);
  return result;
}
