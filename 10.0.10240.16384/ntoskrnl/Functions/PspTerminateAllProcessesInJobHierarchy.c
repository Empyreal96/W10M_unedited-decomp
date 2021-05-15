// PspTerminateAllProcessesInJobHierarchy 
 
int __fastcall PspTerminateAllProcessesInJobHierarchy(int a1, int a2, int a3)
{
  unsigned int *v4; // r4
  unsigned int v5; // r6
  int v6; // r4
  int v8; // [sp+8h] [bp-20h] BYREF
  char v9; // [sp+Ch] [bp-1Ch]

  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 744);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  v9 = 0;
  v8 = a2;
  if ( a3 )
    return sub_7C0344(a1, a2, a3, 0);
  ((void (__fastcall *)(int, _DWORD, int (*)(), _DWORD, int *, int))PspEnumJobsAndProcessesInJobHierarchy)(
    a1,
    0,
    PspTerminateProcessesJobCallback,
    0,
    &v8,
    2);
  if ( (v9 & 2) != 0 )
  {
    v6 = 1;
  }
  else
  {
    v6 = 0;
    PspEvaluateAndNotifyEmptyJob(a1, 0, 0);
  }
  if ( (PerfGlobalGroupMask & 0x80000) != 0 )
    EtwTraceJob(a1, 0);
  return v6;
}
