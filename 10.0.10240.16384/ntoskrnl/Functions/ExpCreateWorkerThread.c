// ExpCreateWorkerThread 
 
int __fastcall ExpCreateWorkerThread(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r6
  unsigned int v5; // r7
  unsigned int v6; // r5
  unsigned int v7; // r4
  int v8; // r4
  int v10; // [sp+8h] [bp-18h] BYREF
  int v11[5]; // [sp+Ch] [bp-14h] BYREF

  v10 = a3;
  v11[0] = a4;
  v4 = (unsigned int *)(a2 + 424);
  v5 = *(_DWORD *)(a2 + 424);
  __dmb(0xBu);
  do
  {
    v6 = v5;
    __dmb(0xBu);
    do
      v7 = __ldrex(v4);
    while ( v7 == v5 && __strex((v5 + 1) | 0x4000, v4) );
    v5 = v7;
    __dmb(0xBu);
  }
  while ( v7 != v6 );
  v8 = ExpCreateSystemThreadForNode(v11, a1, ExpWorkerThread, a2);
  if ( v8 < 0 )
    return sub_7BFB90();
  if ( ObReferenceObjectByHandle(v11[0], 32, PsThreadType, 0, &v10, 0) >= 0 )
  {
    KeBoostPriorityThread(v10, 8);
    ObfDereferenceObject(v10);
  }
  ZwClose();
  return v8;
}
