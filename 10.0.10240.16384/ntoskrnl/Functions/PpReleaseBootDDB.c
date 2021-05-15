// PpReleaseBootDDB 
 
int PpReleaseBootDDB()
{
  int v0; // r2
  int v1; // r3
  int v2; // r1
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r1
  int v6; // r3
  int result; // r0

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(__int16 *)(v0 + 0x134) - 1;
  *(_WORD *)(v0 + 308) = v1;
  ExAcquireResourceExclusiveLite((int)&PiDDBLock, 1, v0, v1);
  if ( PpDDBHandle )
  {
    SdbReleaseDatabase(PpDDBHandle, v2);
    PpDDBHandle = 0;
    ExFreePoolWithTag(PpBootDDB);
    PpBootDDB = 0;
    v3 = 0;
  }
  else
  {
    v3 = -1073741823;
  }
  v4 = ExReleaseResourceLite((int)&PiDDBLock);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
  *(_WORD *)(v5 + 308) = v6;
  if ( v6 )
    result = v3;
  else
    result = sub_815D84(v4);
  return result;
}
