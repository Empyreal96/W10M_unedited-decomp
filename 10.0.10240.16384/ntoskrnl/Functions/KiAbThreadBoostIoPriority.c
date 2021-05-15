// KiAbThreadBoostIoPriority 
 
int __fastcall KiAbThreadBoostIoPriority(int a1, int a2, _DWORD *a3)
{
  unsigned int *v6; // r5
  unsigned int v8; // r2

  *a3 = 0;
  PsBoostThreadIoEx(a1, 0, 0);
  __dmb(0xFu);
  v6 = (unsigned int *)(a1 + 804);
  if ( *(_DWORD *)(a1 + 804) )
    goto LABEL_7;
  if ( !a2 )
  {
    *a3 = 1;
    IoBoostThreadIoPriority(a1, 2, 0x80000000);
LABEL_7:
    __dmb(0xBu);
    do
      v8 = __ldrex(v6);
    while ( __strex(v8 + 1, v6) );
    __dmb(0xBu);
    return 1;
  }
  PsBoostThreadIoEx(a1, 1, 0);
  if ( KiAbThreadInsertList(a1, a2, a1 + 780) )
    KiAbQueueAutoBoostDpc(a2 - 17408);
  return 0;
}
