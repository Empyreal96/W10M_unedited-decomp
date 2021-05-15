// PpProfileIncludeInHardwareProfileTransition 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PpProfileIncludeInHardwareProfileTransition(int result, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // r7
  _QWORD *v6; // r5
  int v7; // r6
  int v8; // r9
  unsigned int v9; // r2
  int *v10; // r2
  int v11; // r1 OVERLAPPED
  unsigned __int8 v12; // r5
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = result;
  if ( a2 == 2 )
  {
    v6 = (_QWORD *)(result + 376);
    if ( *(_DWORD *)(result + 376) == result + 376 )
    {
      v7 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
      v8 = KfRaiseIrql(1);
      do
        v9 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
      while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
      __dmb(0xBu);
      if ( (v9 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v7);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      v10 = &PiProfileDeviceListHead;
      dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = PiProfileDeviceListHead;
      dword_62FB5C = v8;
      *v6 = *(_QWORD *)&v11;
      if ( *(int **)(v11 + 4) != &PiProfileDeviceListHead )
        __fastfail(3u);
      *(_DWORD *)(v11 + 4) = v6;
      PiProfileDeviceListHead = (int)v6;
      ++PiProfileDeviceCount;
      dword_62FB44 = 0;
      v12 = dword_62FB5C;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
      while ( !v13 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
      if ( v13 )
        ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v13);
      KfLowerIrql(v12);
      KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
    }
    result = PnpIrpQueryID(*(_DWORD *)(v5 + 16), 4, v15);
    if ( result >= 0 )
    {
      result = v15[0];
      if ( v15[0] )
        result = ExFreePoolWithTag(v15[0]);
    }
  }
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&PiProfileDevicesInTransition);
  while ( __strex(v14 + 1, (unsigned int *)&PiProfileDevicesInTransition) );
  __dmb(0xBu);
  *(_DWORD *)(v5 + 372) = a2;
  return result;
}
