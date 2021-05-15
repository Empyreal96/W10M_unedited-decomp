// PopCreateDynamicIrpWorker 
 
int __fastcall PopCreateDynamicIrpWorker(int a1)
{
  _DWORD *v2; // r5

  v2 = (_DWORD *)ExAllocateFromNPagedLookasideList(&PopDynamicIrpWorkerLookaside);
  if ( !v2 )
    return sub_510900();
  *v2 = a1;
  if ( PopCreatePowerThread(PopIrpWorker, v2) < 0 )
    JUMPOUT(0x510904);
  return 0;
}
