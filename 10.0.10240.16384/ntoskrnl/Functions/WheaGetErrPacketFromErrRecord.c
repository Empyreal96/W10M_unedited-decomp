// WheaGetErrPacketFromErrRecord 
 
int __fastcall WheaGetErrPacketFromErrRecord(int a1)
{
  int v2; // r4
  unsigned int v3; // r7
  unsigned int v4; // r9
  unsigned __int8 *v5; // r6
  unsigned int v6; // r8
  int v7; // r2

  v2 = 0;
  if ( *(_DWORD *)a1 == 1380274243 )
  {
    v3 = *(unsigned __int16 *)(a1 + 10);
    v4 = *(_DWORD *)(a1 + 20);
    if ( v4 >= 72 * v3 + 128 )
    {
      v5 = (unsigned __int8 *)(a1 + 128);
      v6 = 0;
      if ( *(_WORD *)(a1 + 10) )
      {
        while ( RtlCompareMemory(v5 + 16, (int)WHEA_ERROR_PACKET_SECTION_GUID, 16) != 16 )
        {
          ++v6;
          v5 += 72;
          if ( v6 >= v3 )
            return v2;
        }
        v7 = *(_DWORD *)v5;
        if ( v4 >= *((_DWORD *)v5 + 1) + *(_DWORD *)v5 )
        {
          v2 = v7 + a1;
          if ( *(_DWORD *)(v7 + a1) != 1095059543 )
            v2 = 0;
        }
      }
    }
  }
  return v2;
}
