// PopFlushAndHold 
 
int PopFlushAndHold()
{
  int v1[6]; // [sp+18h] [bp-28h] BYREF

  memset(v1, 0, sizeof(v1));
  v1[4] = 1;
  v1[5] = -1;
  return ZwDeviceIoControlFile();
}
