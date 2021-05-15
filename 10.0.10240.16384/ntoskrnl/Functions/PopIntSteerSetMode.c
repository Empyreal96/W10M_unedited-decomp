// PopIntSteerSetMode 
 
int __fastcall PopIntSteerSetMode(int a1, int *a2, int a3)
{
  int v3; // r2
  int v4; // r0

  if ( a3 != 4 )
    return -1073741811;
  if ( *a2 == 4 )
  {
    v3 = 1;
  }
  else
  {
    PpmIntSteerMode = *a2;
    v3 = 0;
  }
  PpmIntSteerDisabled = v3;
  v4 = PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  PpmCheckReInit(v4);
  PpmCheckCustomRun(4);
  return 0;
}
