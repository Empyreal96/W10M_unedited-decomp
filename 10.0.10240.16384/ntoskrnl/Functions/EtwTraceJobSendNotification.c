// EtwTraceJobSendNotification 
 
int *__fastcall EtwTraceJobSendNotification(int a1, int a2)
{
  char v4[16]; // [sp+8h] [bp-30h] BYREF
  int v5; // [sp+18h] [bp-20h]
  int v6[6]; // [sp+20h] [bp-18h] BYREF

  EtwpCopyJobGuidSafe(v4, a1);
  v6[0] = (int)v4;
  v6[1] = 0;
  v6[2] = 20;
  v6[3] = 0;
  v5 = a2;
  return EtwTraceKernelEvent(v6, 1, 0x80000u, 1834, (int)off_501904);
}
