// SdbFindNextStringIndexedTag 
 
int __fastcall SdbFindNextStringIndexedTag(int a1, int *a2, int a3, int a4)
{
  int v6; // r0
  int result; // r0

  v6 = SdbpGetNextIndexedRecord(a1, *a2, a2, a4);
  if ( v6 )
    result = SdbpFindMatchingName(a1, v6, (int)a2);
  else
    result = 0;
  return result;
}
