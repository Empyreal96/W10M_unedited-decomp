// sub_969070 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_969070(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, int a9, int a10, int *a11, int a12, int a13, int a14, int *a15, int a16, int a17, int a18, char *a19, int a20, int a21, int a22)
{
  int v22; // r5
  int v23; // r5 OVERLAPPED
  int v24; // r6 OVERLAPPED

  a7 = v22;
  a9 = a3;
  *(_QWORD *)&v23 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_EarlyLaunch_PolicyCheck) )
    {
      a11 = &a9;
      a12 = 0;
      a13 = 4;
      a14 = 0;
      a15 = &a7;
      a16 = 0;
      a17 = 4;
      a18 = 0;
      a19 = &a8;
      a20 = 0;
      a21 = 4;
      a22 = 0;
      EtwWrite(v23, v24, (int)KMPnPEvt_EarlyLaunch_PolicyCheck, 0);
    }
  }
  JUMPOUT(0x951432);
}
