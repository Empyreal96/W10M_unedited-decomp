// SeMarkLogonSessionForTerminationNotificationEx 
 
int __fastcall SeMarkLogonSessionForTerminationNotificationEx(_DWORD *a1, int a2)
{
  int v4; // r5
  int v5; // r4
  int v6; // r2
  _DWORD *i; // r4
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  int result; // r0

  v4 = *a1 & 0xF;
  v5 = SepLogonSessions;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v4 & 3), 1, v6, v4 & 3);
  for ( i = *(_DWORD **)(v5 + 4 * v4); i; i = (_DWORD *)*i )
  {
    if ( (i[22] == a2 || !a2) && *a1 == i[1] && a1[1] == i[2] )
    {
      i[6] |= 1u;
      break;
    }
  }
  v8 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v4 & 3));
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  if ( i )
    result = 0;
  else
    result = -1073741275;
  return result;
}
