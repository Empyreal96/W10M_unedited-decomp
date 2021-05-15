// KiAbDeferredProcessingWorker 
 
int __fastcall KiAbDeferredProcessingWorker(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int result; // r0
  _DWORD *v7; // r4
  int v8; // r1
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a4;
  v9[0] = 0;
  v5 = a3 + 17408;
  result = KiAbProcessLocksWorker(a3 + 17412, a3 + 17408, v9, 1);
  *(_DWORD *)(v5 + 24) = 0;
  v7 = (_DWORD *)v9[0];
  while ( v7 )
  {
    v8 = (int)(v7 - 36);
    v7 = (_DWORD *)*v7;
    result = KiDeferredReadyThread(a3, v8);
  }
  return result;
}
