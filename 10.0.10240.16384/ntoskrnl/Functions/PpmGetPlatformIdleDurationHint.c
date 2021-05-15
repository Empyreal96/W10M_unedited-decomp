// PpmGetPlatformIdleDurationHint 
 
// local variable allocation has failed, the output may be wrong!
int PpmGetPlatformIdleDurationHint()
{
  int result; // r0
  unsigned int v1; // r5 OVERLAPPED
  unsigned int v2; // r6 OVERLAPPED
  unsigned int v3; // r2
  unsigned __int64 v4; // kr00_8

  result = 0;
  __pld(&PpmPlatformIdleHint);
  *(_QWORD *)&v1 = PpmPlatformIdleHint;
  if ( (_WORD)PpmPlatformIdleHint )
  {
    __dmb(0xBu);
    v3 = v1 & 0xFFFF0000 | (unsigned __int16)(v1 - 1);
    do
      v4 = __ldrexd(&PpmPlatformIdleHint);
    while ( v4 == __PAIR64__(v2, v1) && __strexd(__PAIR64__(v2, v3), &PpmPlatformIdleHint) );
    if ( v4 == __PAIR64__(v2, v1) )
      result = (v2 << 16) | HIWORD(v1);
    else
      result = sub_54227C(0, 0, v3);
  }
  return result;
}
