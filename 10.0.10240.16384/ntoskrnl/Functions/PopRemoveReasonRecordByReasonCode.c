// PopRemoveReasonRecordByReasonCode 
 
int PopRemoveReasonRecordByReasonCode()
{
  int result; // r0

  result = PopGetReasonListByReasonCode();
  if ( result )
    result = sub_7BDDF4();
  return result;
}
