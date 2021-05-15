// PfSnLogOpenVolumesForPrefetch 
 
int __fastcall PfSnLogOpenVolumesForPrefetch(int result, int a2)
{
  int *v2; // r4

  if ( a2 )
    v2 = PfSnEvt_OpenVolumes_Start;
  else
    v2 = PfSnEvt_OpenVolumes_Stop;
  if ( result )
  {
    result = qword_637408;
    if ( qword_637408 )
    {
      result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)v2);
      if ( result )
        result = sub_7EA3F8();
    }
  }
  return result;
}
