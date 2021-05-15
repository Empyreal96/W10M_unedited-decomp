// CmpInitializeDelayedCloseTable 
 
int CmpInitializeDelayedCloseTable()
{
  int result; // r0

  dword_6322D8 = (int)CmpDelayCloseWorker;
  dword_6322DC = 0;
  CmpDelayCloseWorkItem = 0;
  result = KeInitializeGuardedMutex((int)&CmpDelayedCloseTableLock);
  CmpDelayedLRUListHead = (int)&CmpDelayedLRUListHead;
  dword_632304 = (int)&CmpDelayedLRUListHead;
  return result;
}
