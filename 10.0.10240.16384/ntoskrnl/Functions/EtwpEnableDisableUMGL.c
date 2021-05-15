// EtwpEnableDisableUMGL 
 
int __fastcall EtwpEnableDisableUMGL(int a1, unsigned int a2, char a3, int a4)
{
  int v8; // r4
  __int16 v10; // [sp+8h] [bp-20h]

  v8 = 0;
  if ( PsIsCurrentThreadInServerSilo() )
    return -1073741727;
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  if ( a2 < 0x40 && a2 )
  {
    if ( a1 )
    {
      LOBYTE(v10) = a2;
      HIBYTE(v10) = a3;
      *(_WORD *)(2 * a4 - 27776) = v10;
    }
    else if ( *(unsigned __int8 *)(2 * a4 - 27776) == (unsigned __int8)a2 )
    {
      *(_WORD *)(2 * a4 - 27776) = 0;
    }
    else if ( *(_BYTE *)(2 * a4 - 27776) )
    {
      v8 = -1073741734;
    }
    else
    {
      v8 = -1073741054;
    }
  }
  else
  {
    v8 = -1073741816;
  }
  KeReleaseMutex((int)&EtwpNotificationMutex);
  return v8;
}
