// ViCtxSetPrivateConnectParameters 
 
int __fastcall ViCtxSetPrivateConnectParameters(int *a1, int a2, _DWORD *a3)
{
  int *v5; // r6
  int v6; // r3
  int *v8; // r4
  int v9; // r2
  _DWORD *v10; // r0

  *a3 = 0;
  v5 = 0;
  memmove((int)a1, a2, 0x30u);
  v6 = *a1;
  if ( *a1 == 1 )
  {
    v8 = a1 + 3;
  }
  else
  {
    if ( v6 == 2 )
    {
      v8 = a1 + 3;
LABEL_7:
      v9 = 0;
      goto LABEL_8;
    }
    if ( v6 != 3 )
      return -1073741637;
    v8 = a1 + 7;
    v5 = a1 + 3;
  }
  if ( !v5 )
    goto LABEL_7;
  v9 = *v5;
LABEL_8:
  v10 = ViCtxAllocateIsrContext(*v8, a1[4], v9);
  *a3 = v10;
  if ( !v10 )
    return -1073741670;
  a1[4] = (int)v10;
  if ( !v5 || (*v5 = (int)ViCtxIsrMessageBased, *v8) )
    *v8 = (int)ViCtxIsr;
  return 0;
}
