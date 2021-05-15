// CmpProcessForSimpleStringSub 
 
int __fastcall CmpProcessForSimpleStringSub(int a1, _BYTE *a2)
{
  char *v3; // r0
  int result; // r0

  v3 = strlen((unsigned int)a2);
  if ( *a2 == 37 && (unsigned int)v3 > 2 && a2[(_DWORD)v3 - 1] == 37 )
    result = sub_96BE64();
  else
    result = (int)a2;
  return result;
}
