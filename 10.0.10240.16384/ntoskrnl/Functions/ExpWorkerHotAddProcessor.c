// ExpWorkerHotAddProcessor 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpWorkerHotAddProcessor(unsigned int a1)
{
  int v2; // r5
  unsigned __int8 *v3; // r6
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r3
  unsigned int v7; // r3
  int (*v8)(); // r3
  int v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch] BYREF
  _DWORD v12[6]; // [sp+10h] [bp-18h] BYREF

  KeSynchronizeWithDynamicProcessors();
  v2 = *(_DWORD *)(a1 + 16);
  if ( !*(_DWORD *)(v2 + 260) )
    return ExFreePoolWithTag(a1);
  __dmb(0xBu);
  v3 = (unsigned __int8 *)(v2 + 1016);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 1, v3) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return ExFreePoolWithTag(a1);
  KeQueryNodeActiveAffinity(*(unsigned __int16 *)(v2 + 266), v12, 0);
  v5 = KeSelectIdealProcessor(v2, (int)v12, 0);
  v6 = *(unsigned __int16 *)(v2 + 266);
  *(_DWORD *)(v2 + 1012) = v5;
  if ( ExpCreateSystemThreadForNode(&v10, v2, ExpWorkerThreadBalanceManager, v6) >= 0 )
  {
    ObReferenceObjectByHandle(v10, 0x100000, 0, 0, &v11, 0);
    *(_DWORD *)(v2 + 1008) = v11;
    ZwClose();
    return ExFreePoolWithTag(a1);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex(v3);
  while ( __strex(v7 & 0xFE, v3) );
  __dmb(0xBu);
  v8 = ExpWorkerHotAddProcessor;
  *(_QWORD *)(a1 + 8) = *(_QWORD *)(&a1 - 1);
  *(_DWORD *)a1 = 0;
  return ExQueueWorkItemEx((_DWORD *)a1, 1, 0);
}
