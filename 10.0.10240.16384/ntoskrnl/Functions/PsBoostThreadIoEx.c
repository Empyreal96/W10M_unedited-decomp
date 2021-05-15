// PsBoostThreadIoEx 
 
int __fastcall PsBoostThreadIoEx(int result, int a2, int a3)
{
  int v3; // r8
  unsigned int *v4; // r2
  unsigned int v5; // r4
  unsigned int v6; // r4
  bool v7; // zf
  unsigned int *v8; // r2
  unsigned int v9; // r4
  unsigned int v10; // r4
  int v11; // r5
  int v12; // r4

  v3 = result;
  if ( PspAlwaysTrackIoBoosting )
    return sub_50C48C();
  if ( a3 )
    JUMPOUT(0x50C48E);
  if ( a2 )
  {
    if ( *(_DWORD *)(result + 1000) )
    {
      __dmb(0xBu);
      v4 = (unsigned int *)(result + 1000);
      do
      {
        v5 = __ldrex(v4);
        v6 = v5 - 1;
      }
      while ( __strex(v6, v4) );
      __dmb(0xBu);
    }
    else
    {
      v6 = 0;
    }
    v7 = v6 == 0;
  }
  else
  {
    __dmb(0xBu);
    v8 = (unsigned int *)(result + 1000);
    do
    {
      v9 = __ldrex(v8);
      v10 = v9 + 1;
    }
    while ( __strex(v10, v8) );
    __dmb(0xBu);
    v7 = v10 == 1;
  }
  if ( v7 && !a2 && KiAbEnabled && *(_BYTE *)(result + 485) )
  {
    v11 = KfRaiseIrql(2);
    v12 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    if ( KiAbThreadInsertList(v3, (_DWORD *)(v12 + 17412), (_DWORD *)(v3 + 776)) )
      KiAbQueueAutoBoostDpc(v12);
    result = KfLowerIrql(v11);
  }
  return result;
}
