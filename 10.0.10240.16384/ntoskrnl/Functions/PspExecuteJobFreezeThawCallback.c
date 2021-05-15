// PspExecuteJobFreezeThawCallback 
 
int __fastcall PspExecuteJobFreezeThawCallback(int a1, int *a2, int a3, int a4)
{
  int v6; // r7
  int i; // r3
  int v8; // r0
  int v9; // r0
  int v10; // r4
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = a1;
  v12[1] = a2;
  v12[2] = a3;
  v12[3] = a4;
  v6 = __mrc(15, 0, 13, 0, 3);
  for ( i = 0; ; i = v10 )
  {
    v9 = PspGetNextJobProcess(a1, v6 & 0xFFFFFFC0, v12, i);
    v10 = v9;
    if ( !v9 )
      break;
    v8 = PspChangeProcessExecutionState(v9);
    if ( v8 < 0 )
      *a2 = v8;
  }
  return 0;
}
