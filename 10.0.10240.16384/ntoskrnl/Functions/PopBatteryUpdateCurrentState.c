// PopBatteryUpdateCurrentState 
 
int PopBatteryUpdateCurrentState()
{
  unsigned __int64 v0; // r0
  unsigned int v1; // r6
  unsigned int v2; // r4
  __int64 v4[4]; // [sp+8h] [bp-20h] BYREF

  LODWORD(v0) = KeQueryInterruptTime();
  v1 = HIDWORD(v0);
  v2 = v0;
  v4[0] = qword_61EE80;
  if ( qword_61EE80 + 50000000 <= v0 )
  {
    do
    {
      PopBatteryQueueWork(1);
      LODWORD(v0) = ExBlockOnAddressPushLock(
                      (int)&dword_61EE88,
                      (unsigned __int64 *)&qword_61EE80,
                      (unsigned int *)v4,
                      8,
                      0);
      v4[0] = qword_61EE80;
    }
    while ( qword_61EE80 + 50000000 <= __PAIR64__(v1, v2) );
  }
  return v0;
}
