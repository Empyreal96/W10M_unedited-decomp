// ExpDebuggerWorker 
 
int ExpDebuggerWorker()
{
  int v0; // r6
  int v1; // r7
  int v2; // r8
  int v3; // r3
  _DWORD *v4; // r1
  unsigned int v5; // r1
  int result; // r0
  int v7; // [sp+0h] [bp-40h]

  v0 = ExpDebuggerProcessAttach;
  __dmb(0xBu);
  v1 = ExpDebuggerProcessKill;
  __dmb(0xBu);
  v2 = (unsigned __int8)EtwWmitraceWork;
  __dmb(0xBu);
  MmGetDefaultPagePriority();
  v3 = ExpDebuggerPageIn;
  __dmb(0xBu);
  v7 = v3;
  __dmb(0xBu);
  *v4 = 0;
  __dmb(0xBu);
  ExpDebuggerProcessAttach = 0;
  __dmb(0xBu);
  ExpDebuggerPageIn = 0;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&ExpDebuggerWork);
  while ( __strex(0, (unsigned int *)&ExpDebuggerWork) );
  __dmb(0xBu);
  result = MmDbgMarkPfnModifiedWorker();
  if ( v0 || v1 )
    JUMPOUT(0x903F16);
  if ( v7 )
    JUMPOUT(0x903F48);
  if ( v2 )
    JUMPOUT(0x903F86);
  return result;
}
