// MiRemoveUnusedSegments 
 
int __fastcall MiRemoveUnusedSegments(int a1)
{
  unsigned int v2; // r5
  int result; // r0
  int v4; // r1
  int v5; // r3

  v2 = 0;
  while ( 1 )
  {
    result = MiFreeExcessSegments(0);
    if ( !result && !dword_632E18 )
      break;
    if ( dword_632E18 )
      --dword_632E18;
    if ( (++v2 & 0x3F) == 0 )
    {
      MiProcessDereferenceList((__int16 *)a1);
      if ( v2 >= 0x80 )
        CcUnmapInactiveViews(0x32u, 0, 0);
      KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
    }
    v5 = *(_DWORD *)(a1 + 872);
    if ( v5 == a1 + 872 )
    {
      if ( *(_DWORD *)(a1 + 880) == a1 + 880 )
      {
        dword_632E18 = 0;
        result = CcUnmapInactiveViews(0x32u, 0, 0);
        if ( !result )
          return result;
      }
      else
      {
        MiDeleteCachedSubsection(a1);
      }
    }
    else
    {
      MiDeleteCachedSegment(a1, v4, a1 + 872, v5);
    }
  }
  return result;
}
