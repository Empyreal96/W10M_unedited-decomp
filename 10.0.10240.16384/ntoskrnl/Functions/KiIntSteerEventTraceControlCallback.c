// KiIntSteerEventTraceControlCallback 
 
void __fastcall KiIntSteerEventTraceControlCallback(int a1, int a2)
{
  if ( a2 == 2 || !a2 )
    KiIntSteerLogStatus(1);
}
