// PfSnLogAsyncWorker 
 
int __fastcall PfSnLogAsyncWorker(int result, int a2)
{
  if ( result )
  {
    result = qword_637408;
    if ( qword_637408 )
    {
      result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), a2);
      if ( result )
        result = sub_808FA4();
    }
  }
  return result;
}
