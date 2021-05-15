// PopSnapStandbyNetworkingState 
 
int __fastcall PopSnapStandbyNetworkingState(int result, int a2)
{
  if ( qword_635388 )
    result = sub_7F10BC(result, a2, qword_635388, HIDWORD(qword_635388) | qword_635388);
  return result;
}
