// ObpIsObjectPoolTagTraced 
 
int __fastcall ObpIsObjectPoolTagTraced(int a1)
{
  int v3; // r0
  int *v4; // r2
  int v5; // t1

  if ( !a1 )
    return 0;
  if ( (ObpTraceFlags & 0x10) != 0 )
  {
    v3 = 0;
    v4 = (int *)ObpTracePoolTags;
    while ( 1 )
    {
      v5 = *v4++;
      if ( *(_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)(a1 + 12) ^ BYTE1(a1) ^ (unsigned __int8)ObHeaderCookie]
                     + 132) == v5 )
        break;
      if ( (unsigned int)++v3 >= 0x10 )
        return 0;
    }
  }
  return 1;
}
