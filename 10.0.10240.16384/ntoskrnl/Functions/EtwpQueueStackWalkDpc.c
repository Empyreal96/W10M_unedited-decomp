// EtwpQueueStackWalkDpc 
 
int __fastcall EtwpQueueStackWalkDpc(int result, int a2, int *a3)
{
  int v3; // r5
  unsigned int v4; // r4

  v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C) + 912;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v4 | 2, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( !((unsigned __int8)(v4 & 2) >> 1) )
  {
    *(_DWORD *)(v3 + 4) = a2;
    *(_DWORD *)(v3 + 8) = result;
    result = KiInsertQueueDpc(v3 + 12, *a3, a3[1], 0, 0);
  }
  return result;
}
