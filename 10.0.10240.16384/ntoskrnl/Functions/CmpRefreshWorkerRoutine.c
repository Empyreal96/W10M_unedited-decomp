// CmpRefreshWorkerRoutine 
 
int __fastcall CmpRefreshWorkerRoutine(int a1, int a2)
{
  int v3; // r0

  if ( *(_DWORD *)(a1 + 20) != a2 || (*(_WORD *)(a1 + 106) & 4) != 0 )
    return 0;
  CmpFlushNotifiesOnKeyBodyList(a1);
  v3 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 4) |= 0x20000u;
  CmpRemoveKeyHash(v3, (_DWORD *)(a1 + 12));
  *(_DWORD *)(a1 + 16) = -1;
  *(_DWORD *)(a1 + 24) = 0;
  return 2;
}
