// PfTAccessTracingInitialize 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfTAccessTracingInitialize(int a1, _DWORD *a2, int a3)
{
  int v3; // r4 OVERLAPPED
  int v4; // r3

  v3 = 0;
  if ( !a3 )
  {
    v4 = 3;
    *(_QWORD *)(a1 + 8) = *(_QWORD *)(&v3 - 1);
  }
  a2[7] = 0;
  if ( a3 )
    return sub_694800();
  a2[2] = 0;
  a2[8] = 0;
  a2[9] = 0;
  return KeInitializeEvent((int)(a2 + 3), 0, 0);
}
