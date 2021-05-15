// ObInheritObjectHandle 
 
int __fastcall ObInheritObjectHandle(int a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v6; // r7
  unsigned int v7; // r5
  int v8; // r5
  unsigned int v9; // r6
  int v11; // r4
  unsigned int v12[8]; // [sp+10h] [bp-20h] BYREF

  v6 = *a4 & 0xFFFFFFF8;
  do
  {
    v7 = __ldrex((unsigned int *)v6);
    v8 = v7 + 1;
  }
  while ( __strex(v8, (unsigned int *)v6) );
  __dmb(0xBu);
  if ( v8 <= 1 )
    KeBugCheckEx(24, 0, v6 + 24, 16, v8);
  v12[0] = a4[1] & 0x1FFFFFF;
  __dmb(0xBu);
  do
    v9 = __ldrex(a4);
  while ( __strex(v9 + 1, a4) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a3 + 32) )
    return sub_7DDF70();
  v11 = ObpIncrementHandleCountEx(3, v12, a1, v6 + 24, 0, 0, 0);
  if ( v11 < 0 )
  {
    ObfDereferenceObject(v6 + 24);
  }
  else if ( (dword_682610 & 0x40) != 0 )
  {
    EtwTraceDuplicateHandle(
      a2,
      a2,
      v6 + 24,
      *(_DWORD *)(a1 + 312),
      *(_DWORD *)(a1 + 176),
      ObTypeIndexTable[*(unsigned __int8 *)(v6 + 12) ^ BYTE1(v6) ^ (unsigned __int8)ObHeaderCookie]);
  }
  return v11;
}
