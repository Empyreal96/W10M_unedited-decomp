// KiMarkTrapFrameLog 
 
int KiMarkTrapFrameLog()
{
  int result; // r0

  if ( KiTrapFrameLogEnable )
  {
    IoAddTriageDumpDataBlock((int)&KiTrapFrameLog, 6144);
    result = IoAddTriageDumpDataBlock((int)KiTrapFrameLogIndex, 16);
  }
  return result;
}
