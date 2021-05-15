// InsertChar 
 
__int16 __fastcall InsertChar(__int16 result, __int16 *a2, _DWORD *a3)
{
  __int16 *i; // r4
  __int16 v4; // t1

  for ( i = (__int16 *)(*a3 - 2); i >= a2; i[2] = v4 )
    v4 = *i--;
  *a2 = result;
  *a3 += 2;
  return result;
}
