// IoBuildSynchronousFsdRequest 
 
_DWORD *__fastcall IoBuildSynchronousFsdRequest(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7)
{
  _DWORD *v7; // r0
  _DWORD *v8; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v7 = IopBuildAsynchronousFsdRequest(a1, a2, a3, a4, a5, a7, vars4);
  v8 = v7;
  if ( !v7 )
    return 0;
  v7[11] = a6;
  IopQueueThreadIrp((int)v7);
  return v8;
}
