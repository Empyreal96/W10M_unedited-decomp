// FsRtlpCallerIsAtomicRequestor 
 
int __fastcall FsRtlpCallerIsAtomicRequestor(int a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  int v4; // r5

  v3 = *(_DWORD **)(a1 + 60);
  v4 = 0;
  while ( v3 != (_DWORD *)(a1 + 60) )
  {
    if ( a2 == *(v3 - 4) )
    {
      v4 = 1;
      if ( a3 )
        *a3 = v3 - 7;
      return v4;
    }
    v3 = (_DWORD *)*v3;
  }
  return v4;
}
