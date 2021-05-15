// PoClearBroadcast 
 
unsigned int PoClearBroadcast()
{
  unsigned int v0; // r5
  int v1; // r1
  unsigned int result; // r0

  v0 = dword_61E84C;
  if ( dword_61E84C )
  {
    PopResumeDeviceIdle();
    *(_DWORD *)&PopCurrentBroadcast = 0;
    dword_61E844 = 0;
    dword_61E848 = 0;
    dword_61E84C = 0;
    IoFreePoDeviceNotifyList((_BYTE *)(v0 + 28));
    PpmEndHighPerfRequest(2, v1);
    result = ExFreePoolWithTag(v0);
  }
  return result;
}
