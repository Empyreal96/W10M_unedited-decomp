// KsepDbGetSdbString 
 
int __fastcall KsepDbGetSdbString(int a1, int a2, int a3, int a4)
{
  unsigned __int16 *v5; // r0
  int result; // r0

  v5 = (unsigned __int16 *)SdbGetStringTagPtr(a1, a2, a3, a4);
  if ( v5 )
    result = KsepStringDuplicate(a3, v5);
  else
    result = -1073741811;
  return result;
}
