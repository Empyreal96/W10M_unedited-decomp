// PiDqQueryCompletePendedIrp 
 
int __fastcall PiDqQueryCompletePendedIrp(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r1
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  v5 = a1[23];
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 96);
    __dmb(0xBu);
    v7 = (unsigned int *)(v5 + 56);
    do
      v8 = __ldrex(v7);
    while ( __strex(0, v7) );
    __dmb(0xBu);
    if ( v8 )
    {
      if ( (a1[29] & 1) != 0 )
        return sub_7F0114(v6);
      PiDqQueryGetNextIoctlInfo(a1, *(_DWORD *)(v6 + 8), 0, v10);
      PiDqIrpComplete((_DWORD *)a1[23], 0, 16, v10);
      a1[29] &= 0xFFFFFFEF;
      a1[23] = 0;
    }
  }
  return v10[0];
}
