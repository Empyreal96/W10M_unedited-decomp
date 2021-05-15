// ViDeadlockCheckStackLimits 
 
int __fastcall ViDeadlockCheckStackLimits(int a1, int *a2, int a3, unsigned int a4)
{
  int result; // r0
  int *v5; // r2
  int *v6; // r2
  int v7; // r3
  int *v8; // [sp+0h] [bp-10h] BYREF
  unsigned int v9; // [sp+4h] [bp-Ch] BYREF
  unsigned int v10; // [sp+8h] [bp-8h] BYREF

  v8 = a2;
  v9 = a3;
  v10 = a4;
  __dmb(0xBu);
  v8 = (int *)&v8;
  result = RtlpGetStackLimits((int)&v9, (int)&v10, a3, (int)&v8);
  if ( !result )
  {
    v9 = 0;
    v10 = 0;
  }
  v5 = v8;
  __dmb(0xBu);
  if ( (unsigned int)v5 < v9 || (v6 = v8, __dmb(0xBu), (unsigned int)v6 > v10) )
  {
    if ( VfVerifyMode > 2 )
    {
      v7 = ViStackSwitchAlreadyReported;
      __dmb(0xBu);
      if ( !v7 )
      {
        result = DbgPrintEx(93, 0, (int)"DVRF: Driver switched stacks using an unsupported method!\n", 0);
        __dmb(0xBu);
        ViStackSwitchAlreadyReported = 1;
      }
    }
  }
  return result;
}
