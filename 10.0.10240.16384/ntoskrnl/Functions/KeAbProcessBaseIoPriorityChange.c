// KeAbProcessBaseIoPriorityChange 
 
int __fastcall KeAbProcessBaseIoPriorityChange(int result, int a2, int a3)
{
  int v5; // r4
  int v6; // r8
  int v7; // r6

  v5 = result;
  if ( KiAbEnabled )
  {
    v6 = KfRaiseIrql(2);
    v7 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    if ( *(_BYTE *)(v5 + 811) && a3 < 2 && a2 >= 2 )
    {
      if ( KiAbThreadInsertList(v5, (_DWORD *)(v7 + 17408), (_DWORD *)(v5 + 780)) )
        KiAbQueueAutoBoostDpc(v7);
    }
    else if ( *(_BYTE *)(v5 + 485) )
    {
      return sub_50DD44();
    }
    result = KfLowerIrql(v6);
  }
  return result;
}
