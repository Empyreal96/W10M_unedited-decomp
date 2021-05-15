// MiAttachThreadDone 
 
int __fastcall MiAttachThreadDone(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int result; // r0
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  __dmb(0xBu);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  KeAcquireInStackQueuedSpinLock(&dword_634980, &v7);
  v5 = *(_DWORD *)(a1 + 4);
  *(_BYTE *)(a1 + 113) = *(_BYTE *)(a1 + 113) & 0xF | (16 * ((*(_BYTE *)(a1 + 113) >> 4) - 1));
  if ( v5 )
    result = sub_512330();
  else
    result = KeReleaseInStackQueuedSpinLock(&v7);
  return result;
}
