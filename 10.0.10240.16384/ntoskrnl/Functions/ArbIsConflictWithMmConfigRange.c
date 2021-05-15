// ArbIsConflictWithMmConfigRange 
 
int __fastcall ArbIsConflictWithMmConfigRange(unsigned __int64 a1, unsigned __int64 a2)
{
  int result; // r0
  unsigned int i; // r2
  int v6; // r3
  unsigned __int64 v7; // kr00_8

  result = 0;
  if ( ArbMmConfigRange )
  {
    for ( i = ArbMmConfigRange + 8; i < ArbMmConfigRange + 32 * *(_DWORD *)(ArbMmConfigRange + 4) + 8; i += 32 )
    {
      v6 = *(unsigned __int8 *)(i + 1);
      if ( v6 == 3 || v6 == 7 )
      {
        v7 = *(_QWORD *)(i + 16);
        if ( (v7 >= a1 || *(_QWORD *)(i + 24) >= a1) && (a1 >= v7 || a2 >= v7) )
          return 1;
      }
    }
  }
  return result;
}
