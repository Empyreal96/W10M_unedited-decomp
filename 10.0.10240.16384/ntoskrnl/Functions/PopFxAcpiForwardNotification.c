// PopFxAcpiForwardNotification 
 
int __fastcall PopFxAcpiForwardNotification(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  unsigned int *v6; // r0
  unsigned int v7; // r4
  int v8; // r4
  char v9; // r6
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r2

  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 136);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  if ( *(_BYTE *)(a1 + 132) )
  {
    __dmb(0xBu);
    do
    {
      v13 = __ldrex(v6);
      v14 = v13 - 1;
    }
    while ( __strex(v14, v6) );
    __dmb(0xBu);
    if ( !v14 )
      KeSetEvent(a1 + 140, 0, 0);
    v8 = -1073741738;
  }
  else
  {
    v8 = 0;
    v9 = (*(int (__fastcall **)(int, int))(*(_DWORD *)(a1 + 44) + 72))(a2, a3);
    __dmb(0xBu);
    v10 = (unsigned int *)(a1 + 136);
    do
    {
      v11 = __ldrex(v10);
      v12 = v11 - 1;
    }
    while ( __strex(v12, v10) );
    __dmb(0xBu);
    if ( !v12 )
      KeSetEvent(a1 + 140, 0, 0);
    *a5 = v9;
  }
  return v8;
}
