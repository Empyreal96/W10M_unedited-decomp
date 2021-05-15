// ViCtxIsr 
 
int __fastcall ViCtxIsr(int a1, int *a2)
{
  char *v4; // r6
  int v5; // r4

  v4 = ViCtxCaptureInitialIsrState();
  v5 = ((int (__fastcall *)(int, int))*a2)(a1, a2[1]);
  if ( v4 )
    ViCtxCheckAndReleaseIsrState((int)v4, *a2);
  return v5;
}
