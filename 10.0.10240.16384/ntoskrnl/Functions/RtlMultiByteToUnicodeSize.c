// RtlMultiByteToUnicodeSize 
 
int __fastcall RtlMultiByteToUnicodeSize(_DWORD *a1, unsigned __int8 *a2, int a3)
{
  int v3; // r4
  int v4; // t1

  v3 = 0;
  if ( !NlsMbCodePageTag )
  {
    *a1 = 2 * a3;
    return 0;
  }
  if ( !a3 )
    goto LABEL_9;
  while ( 1 )
  {
    v4 = *a2++;
    --a3;
    if ( NlsLeadByteInfoTable[v4] )
      break;
LABEL_6:
    v3 += 2;
    if ( !a3 )
      goto LABEL_9;
  }
  if ( a3 )
  {
    --a3;
    ++a2;
    goto LABEL_6;
  }
  v3 += 2;
LABEL_9:
  *a1 = v3;
  return 0;
}
