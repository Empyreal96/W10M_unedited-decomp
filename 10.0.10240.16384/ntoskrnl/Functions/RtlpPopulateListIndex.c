// RtlpPopulateListIndex 
 
int __fastcall RtlpPopulateListIndex(int result, _DWORD *a2)
{
  int v3; // r6
  _DWORD *v4; // r8
  _DWORD *v5; // r4
  unsigned int v6; // r2
  unsigned int v7; // r1
  _DWORD *v8; // r7
  _DWORD *v9; // r3
  int v10; // r9
  unsigned int v11; // r3
  int v12; // r0

  *(_DWORD *)(result + 180) = a2;
  v3 = result;
  if ( *a2 )
    return sub_553D7C();
  v4 = (_DWORD *)(result + 192);
  v5 = *(_DWORD **)(result + 196);
  if ( (_DWORD *)(result + 192) != v5 )
  {
    do
    {
      if ( *(_DWORD *)(v3 + 76) )
      {
        *(v5 - 2) ^= *(_DWORD *)(v3 + 80);
        if ( *((unsigned __int8 *)v5 - 5) != (*((unsigned __int8 *)v5 - 6) ^ *((unsigned __int8 *)v5 - 7) ^ *((unsigned __int8 *)v5 - 8)) )
          RtlpAnalyzeHeapFailure(v3, v5 - 2);
      }
      v6 = *((unsigned __int16 *)v5 - 4);
      v7 = a2[1];
      v8 = a2;
      if ( v6 < v7 )
      {
LABEL_16:
        v10 = *((unsigned __int16 *)v5 - 4);
      }
      else
      {
        while ( 1 )
        {
          v9 = (_DWORD *)*v8;
          if ( !*v8 )
            break;
          v8 = (_DWORD *)*v8;
          if ( v6 < v9[1] )
            goto LABEL_16;
        }
        v10 = v8[1] - 1;
      }
      if ( *a2 )
      {
        if ( v6 < v7 )
          v11 = *((unsigned __int16 *)v5 - 4);
        else
          v11 = v7 - 1;
        RtlpHeapRemoveListEntry(v3, a2, v6, v5, v11);
      }
      result = RtlpHeapAddListEntry(v3, v8, v6, (int)v5, v10);
      if ( RtlpHeapErrorHandlerThreshold >= 1
        && ((1 << ((v10 - *((_BYTE *)v8 + 20)) & 0x1F)) & *(_DWORD *)(v8[7] + 4 * ((unsigned int)(v10 - v8[5]) >> 5))) == 0 )
      {
        v12 = DbgPrint("RtlpGetBitState(LookupTable, (ULONG)(LookupIndex - LookupTable->BaseIndex))");
        RtlpHeapHandleError(v12);
      }
      if ( *(_DWORD *)(v3 + 76) )
      {
        *((_BYTE *)v5 - 5) = *((_BYTE *)v5 - 8) ^ *((_BYTE *)v5 - 6) ^ *((_BYTE *)v5 - 7);
        *(v5 - 2) ^= *(_DWORD *)(v3 + 80);
      }
      v5 = (_DWORD *)v5[1];
    }
    while ( v4 != v5 );
  }
  return result;
}
