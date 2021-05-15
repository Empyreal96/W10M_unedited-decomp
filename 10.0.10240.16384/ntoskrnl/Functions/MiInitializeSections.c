// MiInitializeSections 
 
_DWORD *__fastcall MiInitializeSections(int a1)
{
  _DWORD *result; // r0
  int v3; // r3

  *(_DWORD *)(a1 + 800) = a1 + 800;
  *(_DWORD *)(a1 + 804) = a1 + 800;
  KeInitializeSemaphore(a1 + 780, 0, 0x7FFFFFFF);
  *(_DWORD *)(a1 + 808) = a1 + 808;
  *(_DWORD *)(a1 + 812) = a1 + 808;
  *(_DWORD *)(a1 + 872) = a1 + 872;
  *(_DWORD *)(a1 + 876) = a1 + 872;
  *(_DWORD *)(a1 + 880) = a1 + 880;
  *(_DWORD *)(a1 + 884) = a1 + 880;
  KeInitializeEvent(a1 + 760, 0, 0);
  *(_DWORD *)(a1 + 888) = a1 + 888;
  *(_DWORD *)(a1 + 892) = a1 + 888;
  KeInitializeEvent(a1 + 744, 0, 0);
  KeInitializeEvent(a1 + 896, 1, 0);
  result = KeInitializeTimerEx((_DWORD *)(a1 + 816), 1);
  if ( (__int16 *)a1 == MiSystemPartition )
  {
    result = (_DWORD *)KeInitializeEvent((int)algn_6337A4, 0, 0);
    dword_6337B8 = 0;
    dword_6337BC = 0;
    if ( (BYTE2(MiFlags) & 3u) > 1 )
      v3 = 4;
    else
      v3 = 6;
    dword_632E1C = v3;
  }
  return result;
}
