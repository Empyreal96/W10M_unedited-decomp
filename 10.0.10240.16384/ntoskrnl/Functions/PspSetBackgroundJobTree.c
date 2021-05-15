// PspSetBackgroundJobTree 
 
int __fastcall PspSetBackgroundJobTree(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  unsigned __int8 *v8; // r3
  unsigned int v9; // r2
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2
  int _18; // [sp+18h] [bp+8h]
  int varsC; // [sp+1Ch] [bp+Ch] BYREF

  _18 = a1;
  varsC = a2;
  v5 = ExAcquireResourceExclusiveLite(a1 + 32, 1, a3, a4);
  v6 = *(_DWORD *)(a1 + 744);
  if ( (_BYTE)varsC )
  {
    if ( (v6 & 0x400) != 0 )
      return sub_7EA804(v5);
    __dmb(0xBu);
    v8 = (unsigned __int8 *)(a1 + 745);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 4, v8) );
  }
  else
  {
    if ( (v6 & 0x400) == 0 )
      return sub_7EA804(v5);
    __dmb(0xBu);
    v10 = (unsigned __int8 *)(a1 + 745);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0xFB, v10) );
  }
  __dmb(0xBu);
  PspEnumJobsAndProcessesInJobHierarchy(
    a1,
    (int)PspSetJobBackgroundCountCallback,
    0,
    (int)PspSetProcessBackgroundCountCallback,
    (int)&varsC,
    5u);
  ExReleaseResourceLite(a1 + 32);
  if ( !(_BYTE)varsC )
    PspEnumJobsAndProcessesInJobHierarchy(a1, 0, (int)PspBoostJobIoPriorityCallback, 0, 0, 0);
  return 0;
}
