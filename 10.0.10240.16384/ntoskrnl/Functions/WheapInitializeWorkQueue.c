// WheapInitializeWorkQueue 
 
_BYTE *WheapInitializeWorkQueue()
{
  __int64 v0; // r3
  _BYTE *result; // r0

  HIDWORD(v0) = WheapWorkQueue;
  result = memset(WheapWorkQueue, 0, 68);
  WheapWorkQueue[0] = WheapWorkQueue;
  WheapWorkQueue[1] = WheapWorkQueue;
  dword_619848 = 0;
  byte_619850 = 19;
  byte_619851 = 1;
  word_619852 = 0;
  LODWORD(v0) = WheapWorkQueueDpcRoutine;
  *(_QWORD *)(HIDWORD(v0) + 28) = v0;
  dword_61986C = 0;
  dword_619858 = 0;
  LODWORD(v0) = WheapWorkQueueWorkerRoutine;
  *(_QWORD *)(HIDWORD(v0) + 56) = v0;
  dword_619870 = 0;
  dword_619880 = (int)WheapProcessWorkQueueItem;
  return result;
}
