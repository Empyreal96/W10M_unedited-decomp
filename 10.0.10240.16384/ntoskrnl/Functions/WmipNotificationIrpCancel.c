// WmipNotificationIrpCancel 
 
int __fastcall WmipNotificationIrpCancel(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r0
  int v7; // r0
  unsigned int *v8; // r1
  int *v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // [sp+0h] [bp-20h] BYREF
  unsigned int *v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h]
  int v15; // [sp+Ch] [bp-14h]

  v12 = a1;
  v13 = (unsigned int *)a2;
  v14 = a3;
  v15 = a4;
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&WmipCancelSpinLock, &v12);
  v5 = WmipClearIrpObjectList((_DWORD *)a2);
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_5549E0(v5);
  v7 = v12;
  if ( !v12 )
  {
    v8 = v13;
    __dmb(0xBu);
    do
      v9 = (int *)__ldrex(v8);
    while ( v9 == &v12 && __strex(0, v8) );
    if ( v9 == &v12 )
      goto LABEL_8;
    v7 = KxWaitForLockChainValid(&v12);
  }
  v12 = 0;
  __dmb(0xBu);
  v10 = (unsigned int *)(v7 + 4);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 ^ 1, v10) );
LABEL_8:
  KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  *(_DWORD *)(a2 + 24) = -1073741536;
  *(_DWORD *)(a2 + 28) = 0;
  pIofCompleteRequest(a2, 0);
  return v12;
}
