// MiGetPrivatePageCount 
 
unsigned int __fastcall MiGetPrivatePageCount(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  _DWORD *v6; // r2
  int v7; // r3
  unsigned int v8; // r3
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  v5 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v10);
  v6 = *(_DWORD **)(a1 + 3516);
  while ( v6 != (_DWORD *)(a1 + 3516) )
  {
    v7 = v6[11];
    v6 = (_DWORD *)*v6;
    v8 = v7 + v5;
    if ( v8 > v5 )
      v5 = v8;
  }
  KeReleaseInStackQueuedSpinLock((int)v10);
  return v5;
}
