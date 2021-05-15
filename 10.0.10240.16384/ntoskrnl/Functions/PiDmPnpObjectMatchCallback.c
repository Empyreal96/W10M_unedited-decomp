// PiDmPnpObjectMatchCallback 
 
int __fastcall PiDmPnpObjectMatchCallback(int a1, int a2, _BYTE *a3)
{
  if ( *(_DWORD *)a2 )
    *a3 = (*(int (__fastcall **)(int, _DWORD, _DWORD, _DWORD))a2)(
            PiPnpRtlCtx,
            *(_DWORD *)(a1 + 12),
            *(_DWORD *)(a1 + 20),
            *(_DWORD *)(a2 + 4));
  else
    *a3 = 1;
  return 0;
}
