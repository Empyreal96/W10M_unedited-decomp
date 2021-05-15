// IoRegisterBootDriverReinitialization 
 
int __fastcall IoRegisterBootDriverReinitialization(int result, int a2, int a3)
{
  int v5; // r4
  _DWORD *v6; // r1

  v5 = result;
  if ( IopBootDriverReinitCompleted != 1 )
  {
    ObfReferenceObject(result);
    v6 = (_DWORD *)ExAllocatePoolWithTag(512, 20, 1767010121);
    if ( v6 )
    {
      *(_DWORD *)(v5 + 8) |= 0x20u;
      v6[2] = v5;
      v6[3] = a2;
      v6[4] = a3;
      result = IopInterlockedInsertTailList((int)&IopBootDriverReinitializeQueueHead, v6);
    }
    else
    {
      result = sub_8192E8();
    }
  }
  return result;
}
