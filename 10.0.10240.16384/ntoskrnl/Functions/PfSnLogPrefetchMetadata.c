// PfSnLogPrefetchMetadata 
 
int __fastcall PfSnLogPrefetchMetadata(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  int varg_r0; // [sp+74h] [bp+8h]

  varg_r0 = result;
  if ( a3 )
    v4 = ThreadStart;
  else
    v4 = PfSnEvt_PrefetchMetadata_Stop;
  if ( result )
  {
    result = qword_637408;
    if ( qword_637408 )
    {
      result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)v4);
      if ( result )
        result = sub_809334();
    }
  }
  return result;
}
