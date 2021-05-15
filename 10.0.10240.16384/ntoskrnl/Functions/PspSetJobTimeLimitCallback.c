// PspSetJobTimeLimitCallback 
 
int __fastcall PspSetJobTimeLimitCallback(_DWORD *a1, _QWORD *a2, int a3, int a4)
{
  unsigned int v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  if ( (a1[47] & 2) == 0 )
  {
    PsQueryRuntimeProcess(a1, v6);
    *a2 += (unsigned int)KeMaximumIncrement * (unsigned __int64)v6[0];
  }
  return 0;
}
