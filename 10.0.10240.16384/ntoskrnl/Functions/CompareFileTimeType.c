// CompareFileTimeType 
 
int __fastcall CompareFileTimeType(unsigned __int64 *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // kr00_8
  unsigned __int64 v3; // kr08_8
  int result; // r0

  v2 = *a1;
  v3 = *a2;
  if ( *((_DWORD *)a1 + 1) > *((_DWORD *)a2 + 1) )
    goto LABEL_6;
  if ( HIDWORD(v2) < HIDWORD(v3) || (unsigned int)v2 < (unsigned int)v3 )
    return -1;
  if ( v2 <= v3 )
    result = 0;
  else
LABEL_6:
    result = 1;
  return result;
}
