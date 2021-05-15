// EtwGetNotifyRoutine 
 
int *__fastcall EtwGetNotifyRoutine(int a1)
{
  int *result; // r0

  result = 0;
  switch ( a1 )
  {
    case 0x200000:
      return (int *)EtwpTdiIoNotify;
    case 0x100000:
      return &EtwpDiskIoNotifyRoutines;
    case 0x400000:
      return (int *)&EtwpFileIoNotifyRoutines;
    case 0x800000:
      result = &EtwpSplitIoNotifyRoutines;
      break;
  }
  return result;
}
