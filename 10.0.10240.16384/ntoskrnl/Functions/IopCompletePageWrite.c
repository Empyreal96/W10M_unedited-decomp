// IopCompletePageWrite 
 
int __fastcall IopCompletePageWrite(int a1)
{
  _DWORD *v2; // r2
  __int64 v3; // kr00_8
  int v4; // r4

  if ( !*(_BYTE *)(a1 - 31) )
    return sub_524E0C();
  v2 = *(_DWORD **)(a1 - 24);
  *v2 = *(_DWORD *)(a1 - 40);
  v2[1] = *(_DWORD *)(a1 - 36);
  v3 = *(_QWORD *)(a1 - 16);
  v4 = *(_DWORD *)(a1 - 24);
  pIoFreeIrp(a1 - 64);
  return ((int (__fastcall *)(_DWORD, int, _DWORD))v3)(HIDWORD(v3), v4, 0);
}
