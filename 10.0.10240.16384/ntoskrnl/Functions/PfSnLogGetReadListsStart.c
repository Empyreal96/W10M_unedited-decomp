// PfSnLogGetReadListsStart 
 
int __fastcall PfSnLogGetReadListsStart(int result, int a2)
{
  int _74; // [sp+74h] [bp+8h]

  _74 = result;
  if ( result )
  {
    result = qword_637408;
    if ( qword_637408 )
    {
      result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_GetReadLists_Start);
      if ( result )
        result = sub_80919C();
    }
  }
  return result;
}
