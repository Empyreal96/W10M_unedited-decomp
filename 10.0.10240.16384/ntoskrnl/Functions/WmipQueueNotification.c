// WmipQueueNotification 
 
int __fastcall WmipQueueNotification(int a1, int *a2, unsigned int *a3)
{
  unsigned int v4; // r5
  unsigned int v5; // r10
  int v6; // r6
  int v7; // r8
  unsigned int v8; // r7
  int v10; // r0
  _BYTE *v12; // r0
  unsigned int v13; // r0

  v4 = a2[2];
  v5 = *a3;
  v6 = *a2;
  v7 = a2[1];
  v8 = (a2[3] + *a3 + 7) & 0xFFFFFFF8;
  if ( !*a2 )
    goto LABEL_18;
  if ( v8 > v4 )
    v6 = 0;
  if ( !v6 )
  {
LABEL_18:
    if ( v8 > 0x80000 )
      return sub_7EFC10();
    if ( v8 > v4 )
      v4 = (v8 + 0x3FFF) & 0xFFFFC000;
    v12 = (_BYTE *)ExAllocatePoolWithTag(1, v4, 1885957463);
    v6 = (int)v12;
    if ( !v12 )
      return sub_7EFC10();
    memset(v12, 0, v4);
    if ( *a2 )
    {
      memmove(v6, *a2, a2[3]);
      v13 = *a2;
      v7 = v7 - *a2 + v6;
      a2[1] = v7;
      ExFreePoolWithTag(v13);
    }
    *a2 = v6;
    a2[2] = v4;
  }
  v10 = a2[3] + v6;
  if ( v7 )
    *(_DWORD *)(v7 + 12) = v10 - v7;
  a2[1] = v10;
  a2[3] = v8;
  memmove(v10, (int)a3, v5);
  KeSetEvent(a1, 0, 0);
  return 0;
}
