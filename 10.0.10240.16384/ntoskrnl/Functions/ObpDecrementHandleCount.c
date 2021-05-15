// ObpDecrementHandleCount 
 
int __fastcall ObpDecrementHandleCount(int a1, int a2)
{
  int v4; // r7
  unsigned int *v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r9
  int result; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r6
  char v13[56]; // [sp+8h] [bp-38h] BYREF

  v4 = ObTypeIndexTable[*(unsigned __int8 *)(a2 + 12) ^ BYTE1(a2) ^ (unsigned __int8)ObHeaderCookie];
  if ( (*(_BYTE *)(v4 + 42) & 0x10) != 0 || (*(_BYTE *)(a2 + 15) & 8) != 0 )
    return sub_7C466C(a1);
  __dmb(0xBu);
  v5 = (unsigned int *)(a2 + 4);
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 - 1;
  }
  while ( __strex(v7, v5) );
  __dmb(0xBu);
  v8 = v7 + 1;
  if ( *(_DWORD *)(v4 + 96) )
  {
    v12 = 0;
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
    {
      v12 = 1;
      KiStackAttachProcess(a1, 0, (int)v13);
    }
    (*(void (__fastcall **)(int, int, _DWORD, unsigned int, _DWORD))(v4 + 96))(a1, a2 + 24, 0, v8, 0);
    if ( v12 )
      KiUnstackDetachProcess((unsigned int)v13, 0);
  }
  result = ObpDeleteNameCheck(a2);
  __dmb(0xBu);
  v10 = (unsigned int *)(v4 + 28);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 - 1, v10) );
  __dmb(0xBu);
  return result;
}
