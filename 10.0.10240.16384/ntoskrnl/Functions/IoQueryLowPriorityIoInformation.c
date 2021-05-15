// IoQueryLowPriorityIoInformation 
 
int __fastcall IoQueryLowPriorityIoInformation(int a1, _DWORD *a2, unsigned int a3, _DWORD *a4)
{
  int result; // r0

  *a4 = 0;
  if ( a3 < 0x28 )
  {
    result = -1073741789;
  }
  else
  {
    *a2 = IoLowPriorityReadOperationCount;
    a2[1] = IoLowPriorityWriteOperationCount;
    a2[2] = IoKernelIssuedIoBoostedCount;
    a2[3] = IoPagingReadLowPriorityCount;
    a2[4] = IoPagingReadLowPriorityBumpedCount;
    a2[5] = IoPagingWriteLowPriorityCount;
    a2[6] = IoPagingWriteLowPriorityBumpedCount;
    a2[7] = IoBoostedThreadedIrpCount;
    a2[8] = IoBoostedPagingIrpCount;
    a2[9] = IoBlanketBoostCount;
    result = 0;
  }
  *a4 = 40;
  return result;
}
