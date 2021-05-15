// ViSettingsEnableKernelHandleChecking 
 
unsigned int __fastcall ViSettingsEnableKernelHandleChecking(int a1, int a2, int a3, int a4)
{
  unsigned int result; // r0
  int *v5; // r1
  int v6; // [sp+0h] [bp-8h] BYREF
  int v7; // [sp+4h] [bp-4h]

  v6 = a3;
  v7 = a4;
  if ( a1 )
  {
    if ( VfHandleTracingEntries )
    {
      v6 = 0;
      v7 = VfHandleTracingEntries;
      v5 = &v6;
    }
    else
    {
      v5 = 0;
    }
    PsSetProcessHandleTracingInformation(PsInitialSystemProcess, (int)v5);
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&NtGlobalFlag);
    while ( __strex(result | 0x40000000, (unsigned int *)&NtGlobalFlag) );
  }
  else
  {
    PsSetProcessHandleTracingInformation(PsInitialSystemProcess, 0);
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&NtGlobalFlag);
    while ( __strex(result & 0xBFFFFFFF, (unsigned int *)&NtGlobalFlag) );
  }
  __dmb(0xBu);
  return result;
}
