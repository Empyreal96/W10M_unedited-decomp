// _PnpObjectListCallback 
 
int __fastcall PnpObjectListCallback(int a1, int a2, unsigned __int16 *a3, int a4)
{
  unsigned int v7; // r5
  unsigned int v8; // r1

  v7 = wcslen(a3) + 1;
  if ( !*(_DWORD *)a4
    || (*(int (__fastcall **)(int, unsigned __int16 *, _DWORD, _DWORD))a4)(a1, a3, 0, *(_DWORD *)(a4 + 4)) )
  {
    *(_DWORD *)(a4 + 16) += v7;
    v8 = *(_DWORD *)(a4 + 12);
    if ( v8 > v7 )
    {
      RtlStringCchCopyExW(*(_WORD **)(a4 + 8), v8, a3);
      *(_DWORD *)(a4 + 8) += 2 * v7;
      *(_DWORD *)(a4 + 12) -= v7;
    }
  }
  return 0;
}
