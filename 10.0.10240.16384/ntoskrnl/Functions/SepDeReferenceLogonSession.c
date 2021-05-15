// SepDeReferenceLogonSession 
 
int __fastcall SepDeReferenceLogonSession(_DWORD *a1, int a2)
{
  int v4; // r4
  _DWORD *v5; // r9
  int v6; // r2
  int v7; // r5
  _DWORD *i; // r4
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v4 = *a1 & 0xF;
  v5 = (_DWORD *)(SepLogonSessions + 4 * v4);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = 7 * (v4 & 3);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v4 & 3), 1, v6, v4 & 3);
  for ( i = (_DWORD *)*v5; ; i = (_DWORD *)*i )
  {
    if ( !i )
    {
      v10 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v7);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = *(_WORD *)(v11 + 0x134) + 1;
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
        KiCheckForKernelApcDelivery(v10);
      KeBugCheckEx(70, 0, 0, 0, 0);
    }
    if ( i[22] == a2 && *a1 == i[1] && a1[1] == i[2] )
      break;
  }
  return sub_7BEFC8();
}
