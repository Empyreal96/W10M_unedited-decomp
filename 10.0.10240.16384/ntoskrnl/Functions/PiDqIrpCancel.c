// PiDqIrpCancel 
 
int __fastcall PiDqIrpCancel(int a1, int a2)
{
  int v3; // r6
  int v4; // r4
  int v5; // r3
  int result; // r0

  v3 = 0;
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 96) + 28) + 16);
  KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  PiDqQueryLock(v4);
  if ( *(_DWORD *)(v4 + 92) )
  {
    v5 = *(_DWORD *)(v4 + 116);
    v3 = 1;
    *(_DWORD *)(v4 + 92) = 0;
    *(_DWORD *)(v4 + 116) = v5 & 0xFFFFFFEF;
  }
  result = PiDqQueryUnlock(v4);
  if ( v3 )
  {
    *(_DWORD *)(a2 + 24) = -1073741536;
    *(_DWORD *)(a2 + 28) = 0;
    result = pIofCompleteRequest(a2, 0);
  }
  return result;
}
