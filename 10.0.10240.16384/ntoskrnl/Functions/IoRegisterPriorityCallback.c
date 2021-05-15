// IoRegisterPriorityCallback 
 
int __fastcall IoRegisterPriorityCallback(int a1, int a2)
{
  __int64 v3; // r4
  _DWORD *v4; // r0
  int result; // r0
  unsigned int v6; // r1

  HIDWORD(v3) = a2;
  if ( (*(_DWORD *)(a1 + 8) & 0x200) != 0 )
    return -1073740008;
  v4 = (_DWORD *)ExAllocatePoolWithTag(512, 20);
  LODWORD(v3) = v4;
  if ( !v4 )
    return -1073741670;
  *(_QWORD *)(v3 + 8) = v3;
  v4[1] = IopBoostThreadCallback;
  *v4 = 0;
  v4[4] = a1;
  if ( !ExCompareExchangeCallBack(IopUpdatePriorityCallbackRoutine, v4, 0) )
    return sub_528F0C();
  __dmb(0xBu);
  do
    v6 = __ldrex(&IopUpdatePriorityCallbackRoutineCount);
  while ( __strex(v6 + 1, &IopUpdatePriorityCallbackRoutineCount) );
  __dmb(0xBu);
  result = 0;
  *(_DWORD *)(a1 + 8) |= 0x200u;
  return result;
}
