// EtwpAddNotificationEvent 
 
int __fastcall EtwpAddNotificationEvent(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int result; // r0
  int v6; // r0
  unsigned int *v7; // r2
  int v8; // r1
  unsigned int v9; // r4
  int v10; // [sp+8h] [bp-8h] BYREF

  v10 = a4;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( *(_DWORD *)(v4 + 348) )
    return -1073741823;
  result = ObReferenceObjectByHandle(a1, 2, ExEventObjectType, 1, &v10);
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v6 = v10;
    v7 = (unsigned int *)(v4 + 348);
    v8 = v10 | 1;
    do
      v9 = __ldrex(v7);
    while ( !v9 && __strex(v8, v7) );
    __dmb(0xBu);
    if ( v9 )
      result = sub_7E9550(v6, v8);
    else
      result = 0;
  }
  return result;
}
