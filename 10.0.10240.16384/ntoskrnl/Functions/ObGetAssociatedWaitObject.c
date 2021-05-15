// ObGetAssociatedWaitObject 
 
int __fastcall ObGetAssociatedWaitObject(int a1)
{
  int v1; // r0
  int v2; // r4
  int v3; // r1
  int result; // r0

  v1 = a1 - 24;
  v2 = ObTypeIndexTable[*(unsigned __int8 *)(v1 + 12) ^ BYTE1(v1) ^ (unsigned __int8)ObHeaderCookie];
  v3 = v1 + 24;
  result = *(_DWORD *)(v2 + 16);
  if ( (result & 1) != 0 )
  {
    if ( (result & 2) != 0 )
    {
      if ( (*(_DWORD *)(*(unsigned __int16 *)(v2 + 124) + v3) & *(_DWORD *)(v2 + 120)) == *(_DWORD *)(v2 + 120) )
        return sub_52B074();
      result = result + v3 - 3;
    }
    else
    {
      result = *(_DWORD *)(result + v3 - 1);
    }
  }
  else if ( result >= 0 )
  {
    result += v3;
  }
  if ( (char *)result == &ObpDefaultObject )
    result = 0;
  return result;
}
