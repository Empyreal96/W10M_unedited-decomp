// IopCallBootDriverReinitializationRoutines 
 
int __fastcall IopCallBootDriverReinitializationRoutines(int a1, int a2, int a3)
{
  int v3; // r7
  _DWORD *v5; // r0
  unsigned int v6; // r5
  unsigned __int64 v7; // r4

  v3 = 0;
  if ( PnpEtwHandle )
    return sub_969548(a1, a2, a3, PnpEtwHandle | HIDWORD(PnpEtwHandle));
  while ( 1 )
  {
    v5 = IopInterlockedRemoveHeadList(IopBootDriverReinitializeQueueHead);
    v6 = (unsigned int)v5;
    if ( !v5 )
      break;
    v3 = 1;
    ++*(_DWORD *)(*(_DWORD *)(v5[2] + 24) + 8);
    *(_DWORD *)(v5[2] + 8) &= 0xFFFFFFDF;
    ((void (*)(void))v5[3])();
    ObfDereferenceObjectWithTag(*(_DWORD *)(v6 + 8));
    ExFreePoolWithTag(v6);
  }
  v7 = __PAIR64__(PnpEtwHandle, HIDWORD(PnpEtwHandle));
  IopBootDriverReinitCompleted = 1;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_BootDriverReinit_Stop) )
      EtwWrite(SHIDWORD(v7), v7, (int)KMPnPEvt_BootDriverReinit_Stop, 0);
  }
  return v3;
}
