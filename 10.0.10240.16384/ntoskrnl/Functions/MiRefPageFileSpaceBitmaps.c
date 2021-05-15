// MiRefPageFileSpaceBitmaps 
 
int __fastcall MiRefPageFileSpaceBitmaps(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v6; // r6
  int v7; // r3
  int v8; // r4
  int v9; // r5
  int v10; // r4
  int result; // r0
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[1] = a3;
  v12[2] = a4;
  KeAcquireInStackQueuedSpinLock(a1 + 29, (unsigned int)v12);
  v6 = (_DWORD *)a1[16];
  ++*v6;
  v7 = v6[1];
  v8 = v6[2];
  v9 = v6[3];
  *a2 = *v6;
  a2[1] = v7;
  a2[2] = v8;
  a2[3] = v9;
  a2[4] = v6[4];
  v10 = *a1;
  result = KeReleaseInStackQueuedSpinLock((int)v12);
  *a2 = v6;
  a2[1] = v10;
  a2[3] = v10;
  return result;
}
