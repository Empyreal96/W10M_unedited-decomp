// -NpiGetReservedBuffer@NP_CONTEXT@@SAPAXPAU1@PAUNP_CTX@1@@Z 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall NP_CONTEXT::NpiGetReservedBuffer(struct NP_CONTEXT *a1, struct NP_CONTEXT::NP_CTX *a2)
{
  char *v4; // r4 OVERLAPPED
  char *v5; // r2
  _DWORD *v6; // r5
  bool v7; // zf
  int v8; // r3

  v4 = (char *)a1 + 44;
  while ( 1 )
  {
    v5 = (char *)*((_DWORD *)v4 + 1);
    if ( v5 != v4 )
      break;
    v6 = 0;
    if ( NP_CONTEXT::NpiPerformPageOut(a1, a2) < 0 )
      return v6;
  }
  v6 = *(_DWORD **)v4;
  v7 = *(_DWORD *)v4 == (_DWORD)v5;
  *(_DWORD *)v4 = **(_DWORD **)v4;
  if ( v7 )
  {
    v8 = 0;
    *(_QWORD *)v4 = *(_QWORD *)(&v4 - 1);
  }
  else
  {
    --*(_DWORD *)v5;
  }
  return v6;
}
