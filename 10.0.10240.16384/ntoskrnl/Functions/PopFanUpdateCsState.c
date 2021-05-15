// PopFanUpdateCsState 
 
int __fastcall PopFanUpdateCsState(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  __int16 v10; // r3
  __int64 v11; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopFanLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&PopFanLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&PopFanLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7F2674(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_61E624 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 )
  {
    if ( byte_61E665 )
    {
      if ( byte_61E664 )
        PopFanEndCsFanPeriod();
      byte_61E665 = 0;
      dword_61E670 = 0;
      dword_61E674 = 0;
    }
  }
  else if ( !byte_61E665 )
  {
    byte_61E665 = 1;
    LODWORD(v11) = KeQueryInterruptTime();
    *(_QWORD *)&dword_61E670 = v11;
  }
  dword_61E624 = 0;
  __pld(&PopFanLock);
  v6 = PopFanLock;
  if ( (PopFanLock & 0xFFFFFFF0) > 0x10 )
    v7 = PopFanLock - 16;
  else
    v7 = 0;
  if ( (PopFanLock & 2) != 0 )
    goto LABEL_27;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopFanLock);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&PopFanLock) );
  if ( v8 != v6 )
LABEL_27:
    ExfReleasePushLock(&PopFanLock, v6);
  result = KeAbPostRelease((unsigned int)&PopFanLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
