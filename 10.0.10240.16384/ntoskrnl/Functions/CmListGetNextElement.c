// CmListGetNextElement 
 
char *__fastcall CmListGetNextElement(_DWORD *a1, _DWORD *a2, int a3)
{
  _DWORD *v3; // r3
  char *result; // r0

  if ( !*a2 )
    *a2 = *a1;
  v3 = (_DWORD *)*a2;
  if ( a1 == (_DWORD *)*a2 )
    return 0;
  result = (char *)v3 - a3;
  *a2 = *v3;
  return result;
}
