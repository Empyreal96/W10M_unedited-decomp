// KiIntSteerLogState 
 
void __fastcall KiIntSteerLogState(int a1, int a2)
{
  if ( KiIntSteerEtwHandle )
  {
    if ( EtwEventEnabled(KiIntSteerEtwHandle, HIDWORD(KiIntSteerEtwHandle), a2) )
      sub_51FA78();
  }
}
