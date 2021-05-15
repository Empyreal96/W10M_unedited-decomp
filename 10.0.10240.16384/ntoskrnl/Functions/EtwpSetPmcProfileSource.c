// EtwpSetPmcProfileSource 
 
int __fastcall EtwpSetPmcProfileSource(unsigned int *a1, unsigned int a2)
{
  int v2; // r5
  int v3; // r4
  int v5; // r7
  unsigned int v6; // t1

  v2 = a2;
  v3 = 0;
  if ( !a2 || a2 > 4 )
    return -1073741811;
  KeWaitForSingleObject((unsigned int)&EtwpGroupMaskMutex, 0, 0, 0, 0);
  if ( (dword_682604 & 0x400) != 0 )
  {
    v3 = -1073741053;
  }
  else
  {
    if ( dword_61AA64 )
    {
      ExFreePoolWithTag(dword_61AA64);
      EtwpPmcProfile = 0;
      dword_61AA64 = 0;
    }
    v5 = ExAllocatePoolWithTag(512, 52 * v2, 1484223557);
    dword_61AA64 = v5;
    if ( v5 )
    {
      for ( EtwpPmcProfile = v2; v2; --v2 )
      {
        v6 = *a1++;
        KeInitializeProfileCallback(v5, (unsigned int)EtwpPmcInterrupt, v6, v6);
        v5 += 52;
      }
    }
    else
    {
      v3 = -1073741801;
    }
  }
  KeReleaseMutex((int)&EtwpGroupMaskMutex);
  return v3;
}
