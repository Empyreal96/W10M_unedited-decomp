// PspSetCpuRateControlJobPostCallback 
 
int __fastcall PspSetCpuRateControlJobPostCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r7
  int i; // r3
  int v8; // r0
  int v9; // r6
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a1;
  v11[1] = a2;
  v11[2] = a3;
  v11[3] = a4;
  if ( a2 )
    v5 = a2 + 128;
  else
    v5 = 0;
  v6 = __mrc(15, 0, 13, 0, 3);
  for ( i = 0; ; i = v9 )
  {
    v8 = PspGetNextJobProcess(a1, v6 & 0xFFFFFFC0, v11, i);
    v9 = v8;
    if ( !v8 )
      break;
    PspSetProcessSchedulingGroup(v8, v5);
  }
  return 0;
}
