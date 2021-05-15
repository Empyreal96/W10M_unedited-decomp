// IopBuildSynchronousFsdRequest 
 
_DWORD *__fastcall IopBuildSynchronousFsdRequest(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7, int a8)
{
  _DWORD *v8; // r0
  _DWORD *v9; // r4

  v8 = IopBuildAsynchronousFsdRequest(a1, a2, a3, a4, a5, a7, a8);
  v9 = v8;
  if ( !v8 )
    return 0;
  v8[11] = a6;
  IopQueueThreadIrp((int)v8);
  return v9;
}
