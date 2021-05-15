// ViCtxIsrMessageBased 
 
int __fastcall ViCtxIsrMessageBased(int a1, int a2, int a3)
{
  char *v6; // r7
  int v7; // r4

  v6 = ViCtxCaptureInitialIsrState();
  v7 = (*(int (__fastcall **)(int, _DWORD, int))(a2 + 8))(a1, *(_DWORD *)(a2 + 4), a3);
  if ( v6 )
    ViCtxCheckAndReleaseIsrState((int)v6, *(_DWORD *)(a2 + 8));
  return v7;
}
