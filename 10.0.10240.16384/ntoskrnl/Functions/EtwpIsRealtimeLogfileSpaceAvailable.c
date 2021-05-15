// EtwpIsRealtimeLogfileSpaceAvailable 
 
BOOL __fastcall EtwpIsRealtimeLogfileSpaceAvailable(int a1)
{
  return *(_QWORD *)(a1 + 320) - *(_QWORD *)(a1 + 312) > (unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 164)
                                                                                        * *(_DWORD *)(a1 + 4));
}
