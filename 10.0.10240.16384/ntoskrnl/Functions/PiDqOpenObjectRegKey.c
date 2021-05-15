// PiDqOpenObjectRegKey 
 
int __fastcall PiDqOpenObjectRegKey(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, _DWORD *a7)
{
  *a7 = 0;
  if ( a1 == 1 )
    return PiDqOpenUserObjectRegKey(a2, a3, a4, a5, a6, a7, 0, 0);
  if ( a1 )
    return -1073741811;
  return PnpOpenObjectRegKey(PiPnpRtlCtx, a2, a3, a4, a5, (int)a7, 0, 0);
}
