// ObpRemoveObjectRoutine 
 
int __fastcall ObpRemoveObjectRoutine(int a1, int a2)
{
  int v4; // r5

  v4 = ObTypeIndexTable[(unsigned __int8)ObHeaderCookie ^ BYTE1(a1) ^ *(unsigned __int8 *)(a1 + 12)];
  if ( v4 == ObpTypeObjectType )
    sub_7FB0A4();
  if ( *(_DWORD *)(a1 + 20) )
    (*(void (__fastcall **)(int, int))(v4 + 108))(a1 + 24, 2);
  if ( *(_DWORD *)(v4 + 100) )
  {
    if ( !a2 )
      *(_BYTE *)(a1 + 15) |= 0x80u;
    (*(void (__fastcall **)(int))(v4 + 100))(a1 + 24);
  }
  return ObpFreeObject(a1);
}
