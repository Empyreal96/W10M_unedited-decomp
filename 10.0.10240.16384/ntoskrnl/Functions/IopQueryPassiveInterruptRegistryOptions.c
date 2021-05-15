// IopQueryPassiveInterruptRegistryOptions 
 
int IopQueryPassiveInterruptRegistryOptions()
{
  int result; // r0
  char v1; // r3
  int v2; // [sp-4h] [bp-98h]
  int v3; // [sp+4h] [bp-90h] BYREF
  int v4; // [sp+8h] [bp-8Ch] BYREF
  int v5[2]; // [sp+Ch] [bp-88h] BYREF
  int v6; // [sp+14h] [bp-80h] BYREF
  int v7[27]; // [sp+18h] [bp-7Ch] BYREF

  v6 = 0;
  memset(v7, 0, sizeof(v7));
  v5[0] = (unsigned __int8)PassiveInterruptForceCriticalWorker;
  v4 = (unsigned __int8)PassiveInterruptRealtimeWorkerCount;
  v3 = (unsigned __int8)PassiveInterruptRealtimeWorkerPriority;
  v7[0] = 32;
  v7[1] = (int)L"PassiveIntRealTimeWorkerCount";
  v7[2] = (int)&v4;
  v7[3] = 4;
  v7[4] = (int)&v4;
  v7[5] = 0;
  v7[7] = 32;
  v7[8] = (int)L"PassiveIntRealTimeWorkerPriority";
  v7[9] = (int)&v3;
  v7[10] = 4;
  v7[11] = (int)&v3;
  v7[12] = 0;
  v7[14] = 32;
  v7[15] = (int)L"PassiveIntForceCriticalWorker";
  v7[16] = (int)v5;
  v7[17] = 4;
  v7[18] = (int)v5;
  v7[19] = 0;
  result = RtlpQueryRegistryValues(2, L"Session Manager\\I/O System", &v6, 0, v2, 1u);
  if ( result >= 0 )
  {
    v1 = v4;
    if ( (_BYTE)v4 )
    {
      if ( (unsigned __int8)v4 > 0x10u )
        v1 = 16;
      PassiveInterruptRealtimeWorkerCount = v1;
    }
    if ( (unsigned __int8)v3 > 0x10u )
      result = sub_819BE8();
  }
  return result;
}
