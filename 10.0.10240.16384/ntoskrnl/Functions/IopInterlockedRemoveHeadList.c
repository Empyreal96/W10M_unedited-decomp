// IopInterlockedRemoveHeadList 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall IopInterlockedRemoveHeadList(_DWORD *a1)
{
  int v2; // r0
  _DWORD *v3; // r5
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 == a1 )
  {
    v3 = 0;
  }
  else
  {
    *(_QWORD *)&v5 = *(_QWORD *)v3;
    if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v6 != v3 )
      sub_51A0B0(v2);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
  }
  KeReleaseQueuedSpinLock(10, v2);
  return v3;
}
