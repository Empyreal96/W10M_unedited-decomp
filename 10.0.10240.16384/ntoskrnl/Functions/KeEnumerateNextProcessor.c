// KeEnumerateNextProcessor 
 
int __fastcall KeEnumerateNextProcessor(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v4; // r3

  v2 = *(_DWORD *)(a2 + 4);
  if ( !v2 )
    return -1073741275;
  v4 = __clz(__rbit(v2));
  *a1 = v4;
  *(_DWORD *)(a2 + 4) &= ~(1 << v4);
  return 0;
}
