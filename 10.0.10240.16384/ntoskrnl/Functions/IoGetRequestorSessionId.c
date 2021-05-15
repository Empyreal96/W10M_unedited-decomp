// IoGetRequestorSessionId 
 
int __fastcall IoGetRequestorSessionId(int a1, int *a2)
{
  int v2; // r3
  int v5; // r0

  v2 = *(_DWORD *)(a1 + 80);
  if ( !v2 )
    return sub_554580();
  v5 = MmGetSessionIdEx(*(_DWORD *)(v2 + 336));
  if ( v5 == -1 )
    v5 = 0;
  *a2 = v5;
  return 0;
}
