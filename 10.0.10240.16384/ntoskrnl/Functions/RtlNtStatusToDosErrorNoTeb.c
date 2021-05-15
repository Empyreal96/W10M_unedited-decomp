// RtlNtStatusToDosErrorNoTeb 
 
unsigned int __fastcall RtlNtStatusToDosErrorNoTeb(unsigned int result)
{
  unsigned int v1; // r1
  unsigned int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r3
  unsigned int v5; // r6
  int *v6; // r2
  int v7; // r3

  if ( !result )
    return 0;
  if ( result == 259 )
    return 997;
  if ( (result & 0x20000000) == 0 )
  {
    if ( (result & 0xFF0000) == 458752 )
    {
      result = sub_521B88();
    }
    else
    {
      if ( (result & 0xF0000000) == -805306368 )
        result &= 0xCFFFFFFF;
      v1 = 0;
      v2 = 271;
      do
      {
        v3 = (v2 + v1) >> 1;
        v4 = RtlpRunTable[2 * v3];
        v5 = result - v4;
        if ( result < v4 )
        {
          v2 = v3 - 1;
        }
        else
        {
          if ( v5 < LOBYTE(RtlpRunTable[2 * v3 + 1]) )
          {
            v6 = &RtlpRunTable[2 * v3];
            v7 = *((unsigned __int16 *)v6 + 3);
            if ( *((_BYTE *)v6 + 5) == 1 )
              result = *((unsigned __int16 *)RtlpStatusTable + v7 + v5);
            else
              result = *((unsigned __int16 *)&RtlpStatusTable[v5] + v7) | (*((unsigned __int16 *)&RtlpStatusTable[v5]
                                                                           + v7
                                                                           + 1) << 16);
            return result;
          }
          v1 = v3 + 1;
        }
      }
      while ( v1 <= v2 );
      if ( (result & 0xFFFF0000) == -1073676288 )
        JUMPOUT(0x521B94);
      result = 317;
    }
  }
  return result;
}
