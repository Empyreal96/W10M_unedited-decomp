// PopIdleInitAoAcDozeS4Timer 
 
int PopIdleInitAoAcDozeS4Timer()
{
  int result; // r0

  PopIdleAoAcDozeS4Lock = 0;
  result = KeInitializeTimer2((int)&PopIdleAoAcDozeS4Timer, (int)PopIdleAoAcDozeS4TimerCallback, 0, 2);
  dword_61DD68 = (int)PopIdleAoAcDozeToS4;
  dword_61DD6C = 0;
  PopIdleAoAcDozeS4WorkItem = 0;
  return result;
}
