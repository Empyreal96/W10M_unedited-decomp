// CmpUnlockHashEntry 
 
int __fastcall CmpUnlockHashEntry(int a1, unsigned int a2)
{
  _DWORD *v2; // r4

  v2 = (_DWORD *)(*(_DWORD *)(a1 + 1844)
                + 12
                * (((101027 * (a2 ^ (a2 >> 9))) ^ ((101027 * (a2 ^ (a2 >> 9))) >> 9)) & (*(_DWORD *)(a1 + 1848) - 1)));
  __pld(v2);
  v2[1] = 0;
  if ( (*v2 & 0xFFFFFFF0) <= 0x10 )
    JUMPOUT(0x7FDCF2);
  return sub_7FDCEC();
}
