// PspTerminateProcessesJobCallback 
 
int __fastcall PspTerminateProcessesJobCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v7; // r8
  int i; // r3
  int v9; // r0
  int v10; // r6
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[1] = a3;
  v12[2] = a4;
  v5 = 6;
  if ( (*(_BYTE *)(a2 + 4) & 1) != 0 )
    v5 = 14;
  v7 = __mrc(15, 0, 13, 0, 3);
  for ( i = 0; ; i = v10 )
  {
    v9 = PspGetNextJobProcess(a1, v7 & 0xFFFFFFC0, v12, i);
    v10 = v9;
    if ( !v9 )
      break;
    if ( (*(_DWORD *)(v9 + 188) & 0x800) == 0 )
      *(_BYTE *)(a2 + 4) |= 2u;
    PspRemoveProcessFromJobChain(v9, 0, v5, *(_DWORD *)a2);
  }
  return 0;
}
