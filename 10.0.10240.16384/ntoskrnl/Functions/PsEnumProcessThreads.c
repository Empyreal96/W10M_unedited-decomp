// PsEnumProcessThreads 
 
int __fastcall PsEnumProcessThreads(int a1, int (__fastcall *a2)(int, _DWORD *, int), int a3)
{
  int v4; // r5
  int i; // r1
  _DWORD *v8; // r0
  _DWORD *v9; // r4

  v4 = 0;
  for ( i = 0; ; i = (int)v9 )
  {
    v8 = PsGetNextProcessThread(a1, i);
    v9 = v8;
    if ( !v8 )
      break;
    v4 = a2(a1, v8, a3);
    if ( v4 < 0 )
      return sub_7CFA7C();
  }
  return v4;
}
