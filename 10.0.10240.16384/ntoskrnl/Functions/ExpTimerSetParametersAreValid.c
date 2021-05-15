// ExpTimerSetParametersAreValid 
 
int __fastcall ExpTimerSetParametersAreValid(int *a1)
{
  int v2; // r3
  int result; // r0
  __int64 v4; // kr00_8

  v2 = *a1;
  result = 1;
  if ( v2 || (v4 = *((_QWORD *)a1 + 1), v4 < 0) && (HIDWORD(v4) & (unsigned int)v4) != -1 )
    result = 0;
  return result;
}
