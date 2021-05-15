// PopFxScheduleDeviceIdleTimer 
 
int __fastcall PopFxScheduleDeviceIdleTimer(int a1)
{
  int v2; // r8
  unsigned int *v3; // r0
  unsigned int v4; // r1
  __int64 v5; // kr00_8
  __int64 v6; // r0
  unsigned int v7; // r10
  unsigned int v8; // r9
  int v10; // r0
  int v11; // r1
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned __int64 v14[5]; // [sp+10h] [bp-28h] BYREF

  v2 = 0;
  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 16);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4, v3) );
  __dmb(0xBu);
  if ( (v4 & 8) == 0 )
  {
    v5 = *(_QWORD *)(a1 + 272);
    v6 = KeQueryInterruptTime(v3);
    v7 = HIDWORD(v6);
    v8 = v6;
    if ( RtlULongLongAdd(*(_DWORD *)(a1 + 280), *(_DWORD *)(a1 + 284), v5, HIDWORD(v5), v14) >= 0
      && __PAIR64__(v7, v8) < v14[0]
      && RtlULongLongSub(v14[0], __PAIR64__(v7, v8), v14) >= 0 )
    {
      v10 = _rt_udiv64(100000i64, v14[0]);
      RtlULongLongToULong(v10, v11, v14);
      KeSetCoalescableTimer(a1 + 192);
      __dmb(0xBu);
      v12 = (unsigned int *)(a1 + 16);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 | 4, v12) );
      __dmb(0xBu);
      v2 = 1;
    }
  }
  return v2;
}
