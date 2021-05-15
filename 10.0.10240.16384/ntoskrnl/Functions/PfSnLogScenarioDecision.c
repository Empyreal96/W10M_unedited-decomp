// PfSnLogScenarioDecision 
 
int __fastcall PfSnLogScenarioDecision(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = qword_637408;
  if ( qword_637408 )
  {
    result = EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_ScenarioDecision_Info);
    if ( result )
      result = sub_80879C();
  }
  return result;
}
