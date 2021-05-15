// PpmPerfApplyDomainStates 
 
int PpmPerfApplyDomainStates()
{
  unsigned int v0; // r5
  unsigned int v2; // r2
  int v3; // r8
  __int64 v4; // r2

  v0 = dword_61749C;
  if ( PpmPerfArtificialDomainEnabled )
    return sub_5409A4();
  while ( v0 )
  {
    v2 = __clz(__rbit(v0));
    v0 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    if ( PpmPerfApplyDomainState(v3) )
    {
      HIDWORD(v4) = dword_616308 | *(_DWORD *)(*(_DWORD *)(v3 + 3200) + 20);
      word_616302 = 1;
      PpmPerfProcessorsToUpdate = 1;
      LODWORD(v4) = 0;
      *(_QWORD *)algn_616304 = v4;
    }
  }
  PpmPerfDomainsToUpdate = 1;
  word_617496 = 1;
  unk_617498 = 0;
  dword_61749C = 0;
  return 1;
}
