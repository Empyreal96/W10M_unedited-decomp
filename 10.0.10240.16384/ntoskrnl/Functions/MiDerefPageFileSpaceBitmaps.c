// MiDerefPageFileSpaceBitmaps 
 
int *__fastcall MiDerefPageFileSpaceBitmaps(int a1, int **a2, int a3, int a4)
{
  int *v5; // r4
  int v6; // r5
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  v5 = *a2;
  if ( !a3 )
    KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 116), (unsigned int)v8);
  v6 = *v5 - 1;
  *v5 = v6;
  if ( !a3 )
    KeReleaseInStackQueuedSpinLock((int)v8);
  if ( v6 )
    v5 = 0;
  return v5;
}
