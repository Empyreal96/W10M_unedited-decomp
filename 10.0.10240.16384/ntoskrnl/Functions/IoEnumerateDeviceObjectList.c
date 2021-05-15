// IoEnumerateDeviceObjectList 
 
int __fastcall IoEnumerateDeviceObjectList(int a1, int *a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v8; // r5
  int v9; // r7
  int v10; // r3
  int v11; // r2
  unsigned int v12; // r6
  int v13; // r4
  int v15; // [sp+0h] [bp-20h]

  v8 = 0;
  v9 = 0;
  v10 = KeAcquireQueuedSpinLock(10);
  v11 = *(_DWORD *)(a1 + 4);
  v15 = v10;
  v12 = a3 >> 2;
  while ( v11 )
  {
    v11 = *(_DWORD *)(v11 + 12);
    ++v8;
  }
  *a4 = v8;
  if ( v8 > v12 )
    v9 = -1073741789;
  v13 = *(_DWORD *)(a1 + 4);
  if ( v12 )
  {
    do
    {
      if ( !v13 )
        break;
      ObfReferenceObjectWithTag(v13);
      *a2++ = v13;
      v13 = *(_DWORD *)(v13 + 12);
      --v12;
    }
    while ( v12 );
    v10 = v15;
  }
  KeReleaseQueuedSpinLock(10, v10);
  return v9;
}
