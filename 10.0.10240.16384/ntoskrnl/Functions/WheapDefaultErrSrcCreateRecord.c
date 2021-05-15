// WheapDefaultErrSrcCreateRecord 
 
int __fastcall WheapDefaultErrSrcCreateRecord(int a1, unsigned int *a2, int a3, unsigned int a4)
{
  int result; // r0

  if ( a2[14] == 7 )
    result = WheapCreateRecordFromGenericErrorData(a1, a2, a3, a4);
  else
    result = -1073741822;
  return result;
}
