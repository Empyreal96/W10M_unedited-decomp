// ExAcquireAutoExpandPushLockExclusive 
 
int __fastcall ExAcquireAutoExpandPushLockExclusive(int result, int a2, int a3)
{
  int v3; // r4
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r3

  v3 = 0;
  v4 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_52182C(result, a2, a3, a2 & 0xFFFFFFFC);
  if ( (a2 & 2) == 0 )
  {
    result = KeAbPreAcquire(result, 0, 0);
    v3 = result;
  }
  do
    v5 = __ldrex((unsigned __int8 *)v4);
  while ( __strex(v5 | 1, (unsigned __int8 *)v4) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v4, v3, v4);
  v6 = *(_DWORD *)(v4 + 4);
  if ( (v6 & 1) != 0 )
    result = ExpAcquireFannedOutPushLockExclusive(v6 & 0xFFFFFFF8, v3, v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  return result;
}
