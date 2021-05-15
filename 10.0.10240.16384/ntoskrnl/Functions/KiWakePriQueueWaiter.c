// KiWakePriQueueWaiter 
 
int __fastcall KiWakePriQueueWaiter(int a1, int a2, int a3, int a4)
{
  __int64 *v4; // r1
  __int64 v5; // kr00_8
  int result; // r0

  v4 = *(__int64 **)(a2 + 12);
  v5 = *v4;
  if ( *(__int64 **)(*(_DWORD *)v4 + 4) != v4 || *(__int64 **)HIDWORD(v5) != v4 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v5) = v5;
  *(_DWORD *)(v5 + 4) = HIDWORD(v5);
  result = KiTryUnwaitThreadWithPriority(a1, v4, a3, a4);
  if ( !result )
    result = sub_515688();
  return result;
}
