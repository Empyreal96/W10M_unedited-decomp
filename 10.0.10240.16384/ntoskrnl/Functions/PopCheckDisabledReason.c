// PopCheckDisabledReason 
 
int __fastcall PopCheckDisabledReason(int a1)
{
  int result; // r0

  if ( PopGetReasonListByReasonCode(a1) )
    result = sub_7F1450();
  else
    result = 0;
  return result;
}
