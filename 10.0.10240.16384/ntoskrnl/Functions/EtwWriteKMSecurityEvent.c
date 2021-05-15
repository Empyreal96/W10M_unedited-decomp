// EtwWriteKMSecurityEvent 
 
int __fastcall EtwWriteKMSecurityEvent(unsigned __int16 *a1, int a2, unsigned int a3, int a4)
{
  int v7; // r5
  int v8; // r4
  int v10; // [sp+1Ch] [bp-34h]
  int v11[6]; // [sp+38h] [bp-18h] BYREF

  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v11);
  v10 = a4;
  v7 = v11[0];
  v8 = EtwpEventWriteFull(
         (_DWORD *)(v11[0] + 8),
         *(unsigned __int8 *)(v11[0] + 392),
         0,
         0,
         0,
         a1,
         0,
         0,
         0,
         0,
         a3,
         v10,
         0,
         0,
         0,
         0,
         0,
         0);
  PspDereferenceMonitorContextServerSilo(v7 - 48);
  return v8;
}
