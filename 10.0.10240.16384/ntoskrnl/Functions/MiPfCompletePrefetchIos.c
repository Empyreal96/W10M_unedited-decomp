// MiPfCompletePrefetchIos 
 
int __fastcall MiPfCompletePrefetchIos(_DWORD *a1, int a2)
{
  _DWORD *v3; // r0
  __int64 v4; // kr00_8
  int v5; // r0

  if ( a2 )
    MiPfCoalesceAndIssueIOs(a2, a1, 0);
  while ( 1 )
  {
    v3 = (_DWORD *)*a1;
    if ( (_DWORD *)*a1 == a1 )
      break;
    v4 = *(_QWORD *)v3;
    if ( (_DWORD *)v3[1] != a1 || *(_DWORD **)(v4 + 4) != v3 )
      __fastfail(3u);
    *a1 = v4;
    *(_DWORD *)(v4 + 4) = a1;
    if ( (*((_BYTE *)v3 + 115) & 0x40) != 0 )
      v5 = MiPfCompleteCoalescedIo();
    else
      v5 = MiPfCompleteInPageSupport();
    if ( v5 < 0 )
      return sub_54A92C();
  }
  return 0;
}
