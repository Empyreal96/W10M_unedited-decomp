// MiUnlinkPageFromBadList 
 
int __fastcall MiUnlinkPageFromBadList(int *a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r5
  int v7; // r0
  unsigned int *v8; // r1
  int *v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // r3
  int var28[12]; // [sp+0h] [bp-28h] BYREF

  var28[0] = (int)a1;
  var28[2] = a3;
  var28[3] = a4;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640090, var28);
  v5 = *a1;
  v6 = a1[3] & 0xFFFFF;
  if ( *a1 == 0xFFFFF )
    dword_64008C = a1[3] & 0xFFFFF;
  else
    MiSetPfnBlink(MmPfnDatabase + 24 * v5, a1[3] & 0xFFFFF, 0);
  if ( v6 == 0xFFFFF )
    dword_640088 = v5;
  else
    *(_DWORD *)(MmPfnDatabase + 24 * v6) = v5;
  --dword_640080;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(var28, var28[11]);
    goto LABEL_17;
  }
  v7 = var28[0];
  if ( var28[0] )
    goto LABEL_15;
  v8 = (unsigned int *)var28[1];
  __dmb(0xBu);
  do
    v9 = (int *)__ldrex(v8);
  while ( v9 == var28 && __strex(0, v8) );
  if ( v9 != var28 )
  {
    v7 = KxWaitForLockChainValid(var28);
LABEL_15:
    var28[0] = 0;
    __dmb(0xBu);
    v10 = (unsigned int *)(v7 + 4);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 ^ 1, v10) );
  }
LABEL_17:
  v12 = a1[3];
  *a1 = 0;
  a1[1] = 0;
  a1[3] = v12 & 0xFFF00000;
  return var28[0];
}
