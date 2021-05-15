// CmpGetKeyName 
 
int __fastcall CmpGetKeyName(int a1, int a2, int a3)
{
  int v4; // r0
  int v5; // r0
  int result; // r0

  v4 = CmpSearchSectionByName();
  if ( v4 && (v5 = CmpSearchLineInSectionByIndex(v4, a3)) != 0 )
    result = *(_DWORD *)(v5 + 4);
  else
    result = 0;
  return result;
}
