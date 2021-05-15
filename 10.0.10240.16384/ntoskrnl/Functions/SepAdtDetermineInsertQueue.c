// SepAdtDetermineInsertQueue 
 
int __fastcall SepAdtDetermineInsertQueue(int a1)
{
  int v1; // r4

  v1 = 0;
  if ( SepCrashOnAuditFail || *(_DWORD *)(*(_DWORD *)(a1 + 16) + 4) == 4612 )
    return 1;
  if ( SepAdtDiscardingAudits )
    return sub_554F28();
  if ( dword_6418D4 < (unsigned int)SepAdtMaxListLength )
    return 1;
  SepAdtDiscardingAudits = 1;
  SepAdtCountEventsDiscarded = 1;
  return v1;
}
