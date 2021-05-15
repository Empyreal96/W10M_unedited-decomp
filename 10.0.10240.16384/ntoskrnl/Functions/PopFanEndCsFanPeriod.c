// PopFanEndCsFanPeriod 
 
// local variable allocation has failed, the output may be wrong!
int PopFanEndCsFanPeriod()
{
  unsigned int v0; // r7 OVERLAPPED
  unsigned int v1; // r8 OVERLAPPED
  int v2; // r5
  unsigned int v3; // r1
  unsigned int v4; // r6
  int v5; // r4
  int v6; // r0

  *(_QWORD *)&v0 = *(_QWORD *)&algn_61E666[2];
  if ( *(_QWORD *)&algn_61E666[2] < (unsigned __int64)qword_61E670 )
  {
    v1 = HIDWORD(qword_61E670);
    v0 = qword_61E670;
  }
  v2 = KeQueryInterruptTime();
  v4 = v3;
  v5 = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v1, v0) - qword_61E670);
  v6 = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v4, v2) - __PAIR64__(v1, v0));
  return PopDiagTraceCsFanPerfTrack(v6, v5);
}
