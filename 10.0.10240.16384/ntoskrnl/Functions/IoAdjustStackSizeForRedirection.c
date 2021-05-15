// IoAdjustStackSizeForRedirection 
 
int __fastcall IoAdjustStackSizeForRedirection(int a1, int a2, _BYTE *a3)
{
  int v6; // r6
  int v7; // r0
  int v8; // r3
  int v9; // r2
  int v10; // r8
  unsigned __int16 v11; // r4
  int v12; // r0

  v6 = 0;
  v7 = KeAcquireQueuedSpinLock(10);
  v8 = *(char *)(a1 + 48);
  v9 = *(char *)(a2 + 48);
  v10 = v7;
  if ( v8 < v9 )
  {
    v11 = (char)(v9 - v8);
    v12 = IoGetAttachedDevice(a1);
    if ( v11 + (unsigned __int16)*(char *)(v12 + 48) < 125 )
    {
      while ( v12 != a1 )
      {
        *(_BYTE *)(v12 + 48) += v11;
        v12 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 24);
      }
      *(_BYTE *)(a1 + 48) += v11;
    }
    else
    {
      v6 = -1073741811;
    }
  }
  else
  {
    LOBYTE(v11) = 0;
  }
  KeReleaseQueuedSpinLock(10, v10);
  if ( v6 >= 0 && a3 )
    *a3 = v11;
  return v6;
}
