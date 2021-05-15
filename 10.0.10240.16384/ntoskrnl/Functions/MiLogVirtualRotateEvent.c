// MiLogVirtualRotateEvent 
 
int *__fastcall MiLogVirtualRotateEvent(int a1, int a2, char a3)
{
  int v4[6]; // [sp+8h] [bp-18h] BYREF

  v4[1] = a2;
  v4[2] = a3 & 0xF;
  v4[0] = a1;
  return MiLogPerfMemoryEvent(639, 0x20008000u, (int)v4, 12, 4200706);
}
