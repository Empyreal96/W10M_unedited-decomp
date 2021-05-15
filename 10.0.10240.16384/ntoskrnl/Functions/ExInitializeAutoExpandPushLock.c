// ExInitializeAutoExpandPushLock 
 
_DWORD *__fastcall ExInitializeAutoExpandPushLock(_DWORD *result, char a2)
{
  *result = 0;
  result[1] = 0;
  result[2] = 0;
  if ( (a2 & 1) == 0 )
    return (_DWORD *)sub_522F60();
  *result = 0;
  return result;
}
