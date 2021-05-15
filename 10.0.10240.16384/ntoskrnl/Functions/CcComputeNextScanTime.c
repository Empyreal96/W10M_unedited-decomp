// CcComputeNextScanTime 
 
int __fastcall CcComputeNextScanTime(__int64 *a1, _DWORD *a2, unsigned int a3, int a4)
{
  __int64 v6; // r0
  __int64 v7; // kr00_8
  unsigned int v8; // r2
  __int64 v10; // [sp+0h] [bp-28h] BYREF
  int v11; // [sp+8h] [bp-20h]

  v10 = __PAIR64__(a3, (unsigned int)a2);
  v11 = a4;
  *a2 = 0;
  a2[1] = 0;
  LODWORD(v6) = CcIsWriteBehindThreadpoolAtLowPriority();
  if ( (_DWORD)v6 )
  {
    KeQueryTickCount(&v10);
    if ( !KeMaximumIncrement )
      __brkdiv0();
    LODWORD(v6) = _rt_sdiv64((unsigned int)KeMaximumIncrement, 160000000i64);
    v7 = *a1;
    v8 = ++CcConsecutiveWorklessLazyScanCount;
    if ( v7 != 0x7FFFFFFFFFFFFFFFi64 && v7 + v6 > v10 )
    {
      *(_QWORD *)a2 = v7 - v10 + v6;
      v8 = 0;
      CcConsecutiveWorklessLazyScanCount = 0;
    }
    if ( v8 >= CcMaxWorklessLazywriteScans )
    {
      CcConsecutiveWorklessLazyScanCount = 0;
      *a2 = -1;
      a2[1] = 0x7FFFFFFF;
    }
  }
  return v6;
}
