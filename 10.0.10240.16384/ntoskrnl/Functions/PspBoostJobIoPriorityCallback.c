// PspBoostJobIoPriorityCallback 
 
int __fastcall PspBoostJobIoPriorityCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  int i; // r3
  int v7; // r0
  int v8; // r6
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  if ( !*(_DWORD *)(a1 + 412) )
  {
    v5 = __mrc(15, 0, 13, 0, 3);
    for ( i = 0; ; i = v8 )
    {
      v7 = PspGetNextJobProcess(a1, v5 & 0xFFFFFFC0, v10, i);
      v8 = v7;
      if ( !v7 )
        break;
      if ( PsGetNextProcessThread(v7, 0) )
        return sub_7C0374();
    }
  }
  return 0;
}
