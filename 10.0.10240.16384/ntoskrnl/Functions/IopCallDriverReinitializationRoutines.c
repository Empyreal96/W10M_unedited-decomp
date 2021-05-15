// IopCallDriverReinitializationRoutines 
 
int __fastcall IopCallDriverReinitializationRoutines(int a1)
{
  int v1; // r5
  int v2; // r4
  _DWORD *v3; // r7

  v1 = a1;
  v2 = 0;
  if ( !a1 && !IopInitSystemCompletedEnoughForReInitRoutines )
    return 0;
  while ( 1 )
  {
    v3 = IopInterlockedRemoveHeadList(IopDriverReinitializeQueueHead);
    if ( v3 )
    {
      v2 = 1;
      do
      {
        ++*(_DWORD *)(*(_DWORD *)(v3[2] + 24) + 8);
        *(_DWORD *)(v3[2] + 8) &= 0xFFFFFFF7;
        ((void (*)(void))v3[3])();
        ObfDereferenceObject(v3[2]);
        ExFreePoolWithTag((unsigned int)v3);
        v3 = IopInterlockedRemoveHeadList(IopDriverReinitializeQueueHead);
      }
      while ( v3 );
    }
    if ( v1 != 1 )
      break;
    IopInitSystemCompletedEnoughForReInitRoutines = 1;
    v1 = 0;
  }
  return v2;
}
