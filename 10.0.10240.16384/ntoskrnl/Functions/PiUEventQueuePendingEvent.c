// PiUEventQueuePendingEvent 
 
int __fastcall PiUEventQueuePendingEvent(int a1, _QWORD *a2)
{
  unsigned int v3; // r3
  int result; // r0
  __int64 v5; // r4

  v3 = *(_DWORD *)(a1 + 72);
  result = 0;
  if ( v3 >= 0x10000 )
    return -1073741823;
  LODWORD(v5) = a1 + 64;
  HIDWORD(v5) = *(_DWORD *)(a1 + 68);
  *a2 = v5;
  if ( *(_DWORD *)HIDWORD(v5) != a1 + 64 )
    sub_7C9CA8(0);
  *(_DWORD *)HIDWORD(v5) = a2;
  *(_DWORD *)(a1 + 68) = a2;
  ++*(_DWORD *)(a1 + 72);
  return result;
}
