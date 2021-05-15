// PpmUpdateProcessorIdleAccounting 
 
unsigned __int64 *__fastcall PpmUpdateProcessorIdleAccounting(unsigned __int64 *result)
{
  int v1; // r6
  unsigned __int64 v2; // r4
  int v3; // r3
  int v4; // r1
  unsigned int i; // r2
  unsigned __int64 v6; // kr00_8
  int v7; // r3

  v1 = *(_DWORD *)result;
  if ( *(_BYTE *)(*(_DWORD *)result + 5) )
  {
    v2 = result[1];
    v3 = *((_DWORD *)result + 1);
    *((_DWORD *)result + 2) = 0;
    *((_DWORD *)result + 3) = 0;
    v4 = v3 + 984 * *(_DWORD *)(v1 + 16) + 40;
    result[2] += v2;
    *(_QWORD *)v4 += v2;
    if ( *(_DWORD *)(v1 + 52) == 3 )
    {
      if ( *(int *)(v1 + 48) < 0 )
        return (unsigned __int64 *)sub_55245C();
      result = (unsigned __int64 *)&PpmIdleIntervalLimits;
      ++*(_DWORD *)(v4 + 16);
      for ( i = 0; i < 0x1A; ++i )
      {
        if ( v2 < *result )
          break;
        result += 3;
      }
      if ( i >= 0x1A )
      {
        ++*(_DWORD *)(v4 + 20);
      }
      else
      {
        result = (unsigned __int64 *)(v4 + 32 * i);
        v6 = result[19];
        *((_DWORD *)result + 38) = v6 + v2;
        v7 = *((_DWORD *)result + 44);
        *((_DWORD *)result + 39) = (v6 + v2) >> 32;
        *((_DWORD *)result + 44) = v7 + 1;
        if ( v2 < result[20] )
          result[20] = v2;
        if ( v2 > result[21] )
          result[21] = v2;
      }
      if ( v2 < *(_QWORD *)(v4 + 24) )
        *(_QWORD *)(v4 + 24) = v2;
      if ( v2 > *(_QWORD *)(v4 + 32) )
        *(_QWORD *)(v4 + 32) = v2;
    }
    else
    {
      ++*(_DWORD *)(v4 + 8);
    }
  }
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 52) = 3;
  *(_BYTE *)(v1 + 5) = 0;
  return result;
}
