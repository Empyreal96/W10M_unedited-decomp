// CmListGetPrevElement 
 
int __fastcall CmListGetPrevElement(int a1, _DWORD *a2)
{
  int result; // r0

  if ( !*a2 )
    *a2 = *(_DWORD *)(a1 + 4);
  if ( a1 == *a2 )
    result = 0;
  else
    result = sub_8057C4();
  return result;
}
