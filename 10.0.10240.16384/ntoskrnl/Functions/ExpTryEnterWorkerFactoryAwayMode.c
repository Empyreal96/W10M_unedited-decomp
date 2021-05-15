// ExpTryEnterWorkerFactoryAwayMode 
 
int __fastcall ExpTryEnterWorkerFactoryAwayMode(_DWORD *a1)
{
  int v2; // r5
  int v4; // r2

  v2 = a1[1];
  if ( a1[16] >= a1[15] || *(_DWORD *)(v2 + 16) )
    return 0;
  if ( !a1[21] )
    return 1;
  v4 = a1[22] | 0x200;
  a1[22] = v4;
  if ( *(_DWORD *)(*(_DWORD *)(v2 + 4) + 4) )
    return 1;
  if ( (v4 & 0x400) == 0 )
  {
    a1[22] = v4 | 0x400;
    ObfReferenceObjectWithTag(a1, 1953261124);
    KeRegisterObjectNotification(*(_DWORD *)(v2 + 4), &ExpWorkerFactoryManagerQueue, a1 + 55);
  }
  return 0;
}
