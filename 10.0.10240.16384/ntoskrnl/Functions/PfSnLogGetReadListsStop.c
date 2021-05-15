// PfSnLogGetReadListsStop 
 
int __fastcall PfSnLogGetReadListsStop(int result)
{
  if ( result )
  {
    result = qword_637408;
    if ( qword_637408 )
    {
      result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_GetReadLists_Stop);
      if ( result )
        result = sub_809170();
    }
  }
  return result;
}
