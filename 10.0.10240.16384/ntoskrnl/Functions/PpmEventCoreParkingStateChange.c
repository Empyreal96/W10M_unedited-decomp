// PpmEventCoreParkingStateChange 
 
void __fastcall PpmEventCoreParkingStateChange(int a1, int a2)
{
  int *v2; // r2

  if ( PpmEtwRegistered )
  {
    if ( a2 )
      v2 = PPM_ETW_PARK_CORE;
    else
      v2 = PPM_ETW_UNPARK_CORE;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, v2) )
      sub_52B508();
  }
}
