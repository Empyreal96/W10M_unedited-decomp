// KeAbThreadAreAllEntriesFree 
 
BOOL __fastcall KeAbThreadAreAllEntriesFree(int a1)
{
  char v1; // r2

  v1 = *(_BYTE *)(a1 + 484);
  __dmb(0xBu);
  return (char)(*(_BYTE *)(a1 + 810) | v1) == 63;
}
