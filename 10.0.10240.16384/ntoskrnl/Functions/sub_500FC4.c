// sub_500FC4 
 
_DWORD *__fastcall sub_500FC4(int a1)
{
  _DWORD *result; // r0
  int v3; // r5
  int v4; // r3
  int (__fastcall *v5)(int, _DWORD, _DWORD, _DWORD); // r4

  KeAcquireSpinLockAtDpcLevel((unsigned int *)&KdpSecondaryFreezeLock);
  result = KeReleaseSpinLockFromDpcLevel(&KdpSecondaryFreezeLock);
  v3 = *(_DWORD *)(a1 + 16);
  if ( *(_DWORD *)v3 )
  {
    v4 = *(_DWORD *)v3 - 1;
    *(_DWORD *)v3 = v4;
    if ( !v4 )
    {
      memset((_BYTE *)(v3 + 4), 0, 32);
      result = (_DWORD *)(*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(v3 + 36) + 12))(
                           *(_DWORD *)(v3 + 36),
                           *(_DWORD *)(*(_DWORD *)(v3 + 36) + 16),
                           *(_DWORD *)(*(_DWORD *)(v3 + 36) + 20),
                           *(_DWORD *)(*(_DWORD *)(v3 + 36) + 24));
    }
  }
  v5 = *(int (__fastcall **)(int, _DWORD, _DWORD, _DWORD))(v3 + 16);
  if ( v5 )
    result = (_DWORD *)v5(v3 + 4, *(_DWORD *)(v3 + 20), *(_DWORD *)(v3 + 24), *(_DWORD *)(v3 + 28));
  return result;
}
