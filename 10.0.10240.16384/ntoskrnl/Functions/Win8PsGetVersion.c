// Win8PsGetVersion 
 
int __fastcall Win8PsGetVersion(_DWORD *a1, _DWORD *a2, _DWORD *a3, unsigned int a4)
{
  int v8; // r8

  v8 = PsGetVersion(a1, (int)a2, a3, 0);
  if ( a1 )
    *a1 = 6;
  if ( a2 )
    *a2 = 2;
  if ( a3 )
    *a3 = 9200;
  if ( a4 )
    RtlInitUnicodeString(a4, 0);
  return v8;
}
