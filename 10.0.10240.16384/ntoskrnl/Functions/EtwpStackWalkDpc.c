// EtwpStackWalkDpc 
 
int __fastcall EtwpStackWalkDpc(int a1, unsigned int a2, unsigned __int64 a3)
{
  int v3; // r1
  unsigned __int8 *v4; // r4
  int result; // r0
  unsigned int v6; // r3
  unsigned __int64 v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+8h] [bp-8h]

  v7 = __PAIR64__(a3, a2);
  v8 = HIDWORD(a3);
  v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
  v7 = a3;
  v4 = (unsigned __int8 *)(v3 + 912);
  result = EtwpQueueStackWalkApc(*(_DWORD *)(v3 + 920), 2u, *(_DWORD *)(v3 + 916), &v7);
  __dmb(0xBu);
  do
    v6 = __ldrex(v4);
  while ( __strex(v6 & 0xFD, v4) );
  __dmb(0xBu);
  return result;
}
