// PiDmCmObjectMatchCallback 
 
int __fastcall PiDmCmObjectMatchCallback(int a1, _DWORD *a2, _BYTE *a3)
{
  if ( !*a2 )
    return sub_7C5BD4();
  *a3 = ((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD))*a2)(PiPnpRtlCtx, *(_DWORD *)(a1 + 12), a2[2], a2[1]);
  return 0;
}
