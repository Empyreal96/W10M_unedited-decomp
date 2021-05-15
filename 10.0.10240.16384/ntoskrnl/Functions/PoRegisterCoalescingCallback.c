// PoRegisterCoalescingCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PoRegisterCoalescingCallback(int a1, int a2, int *a3, int a4)
{
  int v8; // r0
  int v9; // r4 OVERLAPPED
  int (__fastcall *v10)(int, int, int); // r3
  _DWORD *v11; // r6
  unsigned int v12; // r5
  unsigned int v14; // r1

  v8 = ExAllocatePoolWithTag(512, 24, 1648586576);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  v10 = PopCoalescingCallback;
  *(_QWORD *)(v9 + 4) = *(_QWORD *)(&v9 - 1);
  *(_DWORD *)(v8 + 20) = a4;
  *(_BYTE *)(v8 + 16) = a2 != 0;
  v11 = PopCoalescingCallbackRoutine;
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 12) = a1;
  v12 = 0;
  while ( !ExCompareExchangeCallBack(v11, (int *)v9, 0) )
  {
    ++v12;
    ++v11;
    if ( v12 >= 8 )
      return sub_7F1FC4();
  }
  __dmb(0xBu);
  do
    v14 = __ldrex(&PopCoalescingCallbackRoutineCount);
  while ( __strex(v14 + 1, &PopCoalescingCallbackRoutineCount) );
  __dmb(0xBu);
  *a3 = v9;
  return 0;
}
