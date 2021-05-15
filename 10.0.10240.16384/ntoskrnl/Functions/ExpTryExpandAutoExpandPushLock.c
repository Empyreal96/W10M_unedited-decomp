// ExpTryExpandAutoExpandPushLock 
 
int __fastcall ExpTryExpandAutoExpandPushLock(int result)
{
  int v1; // r6
  unsigned int *v2; // r5
  int v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r3

  v1 = result;
  v2 = (unsigned int *)(result + 4);
  __pld((void *)(result + 4));
  v3 = *(_DWORD *)(result + 4);
  if ( (v3 & 3) == 0 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex(v2);
    while ( v4 == v3 && __strex(v3 | 2, v2) );
    __dmb(0xBu);
    if ( v4 == v3 )
    {
      result = ExpAllocateFannedOutPushLock(result, (v3 & 4) == 0);
      if ( result == -1 )
      {
        *(_DWORD *)(v1 + 8) = (*(_DWORD *)(v1 + 8) >> 2) & 0x3FF33FFF;
        __dmb(0xBu);
        v5 = v3 & 0xFFFFFFFD;
      }
      else
      {
        __dmb(0xBu);
        v5 = ((unsigned __int8)v3 ^ (unsigned __int8)result) & 4 ^ result | 1;
      }
      *v2 = v5;
    }
  }
  return result;
}
