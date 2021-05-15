// IoGetDriverObjectExtension 
 
_DWORD *__fastcall IoGetDriverObjectExtension(int a1, int a2)
{
  int v4; // r0
  _DWORD *i; // r4
  _DWORD *result; // r0

  v4 = KeAcquireQueuedSpinLock(10);
  for ( i = *(_DWORD **)(*(_DWORD *)(a1 + 24) + 20); i && i[1] != a2; i = (_DWORD *)*i )
    ;
  KeReleaseQueuedSpinLock(10, v4);
  if ( i )
    result = i + 2;
  else
    result = 0;
  return result;
}
