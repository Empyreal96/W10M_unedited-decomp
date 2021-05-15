// MmGetImageBase 
 
int __fastcall MmGetImageBase(unsigned int a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r4
  int v7; // r7
  int v8; // r5
  int v9; // r3
  int v10; // r6
  _DWORD *v11; // r0

  if ( a1 > MmHighestUserAddress )
    return -1073741811;
  v6 = 0;
  v7 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_DWORD *)(v8 + 0x3C8);
  v10 = *(_DWORD *)(v8 + 116);
  if ( (v9 & 3) == 0 )
  {
    v7 = 1;
    LOCK_ADDRESS_SPACE_SHARED(v8, *(_DWORD *)(v8 + 116));
  }
  v11 = MiCheckForConflictingVad(v10, a1, a1, v9);
  if ( v11 )
  {
    if ( (v11[7] & 7) == 2 )
    {
      *a2 = v11[3] << 12;
      *a3 = (v11[4] - v11[3] + 1) << 12;
    }
    else
    {
      v6 = -1073741751;
    }
  }
  else
  {
    v6 = -1073741800;
  }
  if ( v7 == 1 )
    UNLOCK_ADDRESS_SPACE_SHARED(v8, v10);
  return v6;
}
