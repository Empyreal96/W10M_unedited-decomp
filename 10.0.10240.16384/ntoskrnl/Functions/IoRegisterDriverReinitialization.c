// IoRegisterDriverReinitialization 
 
int __fastcall IoRegisterDriverReinitialization(int a1, int a2, int a3)
{
  _DWORD *v6; // r1

  ObfReferenceObject(a1);
  v6 = (_DWORD *)ExAllocatePoolWithTag(512, 20, 1767010121);
  if ( !v6 )
    return sub_8192F4();
  *(_DWORD *)(a1 + 8) |= 8u;
  v6[2] = a1;
  v6[3] = a2;
  v6[4] = a3;
  return IopInterlockedInsertTailList((int)IopDriverReinitializeQueueHead, v6);
}
