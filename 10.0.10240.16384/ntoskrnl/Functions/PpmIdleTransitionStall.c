// PpmIdleTransitionStall 
 
int __fastcall PpmIdleTransitionStall(int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-18h]
  int v7; // [sp+8h] [bp-10h] BYREF
  int v8; // [sp+Ch] [bp-Ch]

  v6 = a1;
  v7 = a3;
  v8 = a4;
  if ( *(_QWORD *)a1 )
    return sub_555B4C();
  KeQueryPerformanceCounter(&v7, 0);
  *(_DWORD *)a1 = v7;
  *(_DWORD *)(a1 + 4) = v8;
  if ( *(_BYTE *)(a1 + 24) )
    KiPollFreezeExecution();
  __dmb(0xAu);
  __yield();
  return v6;
}
