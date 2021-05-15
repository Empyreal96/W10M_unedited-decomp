// PopAudioAccountingCallback 
 
int __fastcall PopAudioAccountingCallback(int a1)
{
  int result; // r0
  int v3; // r1
  int v4; // r6
  int v5; // r1
  int v6; // r2

  result = KeQueryInterruptTime();
  v4 = v3;
  if ( a1 )
  {
    *(_DWORD *)algn_6353D8 = result;
    *(_DWORD *)&algn_6353D8[4] = v3;
  }
  else
  {
    if ( qword_635388 )
    {
      if ( (unsigned __int64)qword_635388 > *(_QWORD *)algn_6353D8 )
      {
        v6 = (unsigned __int64)(qword_6353E0 - qword_635388) >> 32;
        v5 = qword_6353E0 - qword_635388;
      }
      else
      {
        v6 = (unsigned __int64)(qword_6353E0 - *(_QWORD *)algn_6353D8) >> 32;
        v5 = qword_6353E0 - *(_DWORD *)algn_6353D8;
      }
      LODWORD(qword_6353E0) = v5 + result;
      HIDWORD(qword_6353E0) = v4 + __CFADD__(v5, result) + v6;
    }
    *(_DWORD *)algn_6353D8 = 0;
    *(_DWORD *)&algn_6353D8[4] = 0;
  }
  return result;
}
