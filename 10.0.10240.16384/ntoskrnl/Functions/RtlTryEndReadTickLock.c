// RtlTryEndReadTickLock 
 
BOOL __fastcall RtlTryEndReadTickLock(_QWORD *a1, __int64 a2)
{
  __dmb(0xBu);
  return *a1 == a2;
}
