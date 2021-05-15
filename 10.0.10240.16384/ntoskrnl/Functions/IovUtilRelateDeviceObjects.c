// IovUtilRelateDeviceObjects 
 
int __fastcall IovUtilRelateDeviceObjects(int result, int a2, int *a3)
{
  int v4; // r5
  int v6; // r0
  int v7; // r3
  int v8; // r2

  v4 = result;
  if ( result == a2 )
  {
    *a3 = 0;
  }
  else
  {
    v6 = KeAcquireQueuedSpinLock(10);
    if ( v4 == *(_DWORD *)(a2 + 16) )
    {
      v7 = 1;
    }
    else
    {
      v8 = *(_DWORD *)(v4 + 16);
      if ( v8 == a2 )
      {
        v7 = 2;
      }
      else
      {
        do
        {
          if ( v4 == a2 )
            break;
          v4 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 24);
        }
        while ( v4 );
        if ( v4 )
        {
          v7 = 3;
        }
        else
        {
          if ( !v8 )
            goto LABEL_16;
          do
          {
            if ( v8 == a2 )
              break;
            v8 = *(_DWORD *)(v8 + 16);
          }
          while ( v8 );
          if ( v8 )
            v7 = 4;
          else
LABEL_16:
            v7 = 5;
        }
      }
    }
    *a3 = v7;
    result = KeReleaseQueuedSpinLock(10, v6);
  }
  return result;
}
