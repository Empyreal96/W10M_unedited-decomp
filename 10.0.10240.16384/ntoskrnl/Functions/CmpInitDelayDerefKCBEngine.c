// CmpInitDelayDerefKCBEngine 
 
int CmpInitDelayDerefKCBEngine()
{
  int v0; // r0
  int v1; // r1

  CmpDelayDerefKCBListHead = (int)&CmpDelayDerefKCBListHead;
  dword_63230C = (int)&CmpDelayDerefKCBListHead;
  v0 = KeInitializeGuardedMutex((int)CmpDelayDerefKCBLock);
  dword_632348 = (int)CmpDelayDerefKCBWorker;
  dword_63234C = 0;
  CmpDelayDerefKCBWorkItem = 0;
  if ( qword_641C50 )
    JUMPOUT(0x81C3D8);
  return sub_81C0C4(v0, v1, qword_641C50, HIDWORD(qword_641C50) | qword_641C50);
}
