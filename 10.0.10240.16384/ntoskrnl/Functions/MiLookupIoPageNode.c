// MiLookupIoPageNode 
 
_DWORD *__fastcall MiLookupIoPageNode(unsigned int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r4
  int v6; // r0
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a1;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634880, (unsigned int)v8);
  v5 = (_DWORD *)dword_634888;
  while ( v5 )
  {
    v6 = MiIoPfnCompare(a1, (int)v5);
    if ( v6 >= 0 )
    {
      if ( v6 <= 0 )
        break;
      v5 = (_DWORD *)v5[1];
    }
    else
    {
      v5 = (_DWORD *)*v5;
    }
  }
  KeReleaseInStackQueuedSpinLock((int)v8);
  return v5;
}
