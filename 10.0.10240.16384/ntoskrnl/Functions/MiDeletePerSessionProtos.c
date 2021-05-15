// MiDeletePerSessionProtos 
 
int __fastcall MiDeletePerSessionProtos(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r5
  int v5; // r4
  int v6; // r9
  int v7; // r8
  unsigned int v8; // r6
  unsigned int v9; // t1
  int v10; // r0
  int v11; // r3
  int v12; // r7
  int v13; // r2
  int v14; // r3
  int v16; // [sp+0h] [bp-28h] BYREF
  unsigned int v17; // [sp+4h] [bp-24h]
  int v18; // [sp+8h] [bp-20h]

  v16 = a2;
  v17 = a3;
  v18 = a4;
  v4 = *(_DWORD *)(a1 + 16);
  v5 = 17;
  v6 = 0;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 28);
  LOBYTE(v16) = 17;
  v17 = v4 + 4 * v7;
  while ( v4 < v17 )
  {
    if ( (v4 & 0xFFF) == 0 || v5 == 17 )
    {
      if ( v5 != 17 )
        MiUnlockProtoPoolPage(v6, v5);
      while ( 1 )
      {
        v6 = MiLockProtoPoolPage(v4, &v16);
        if ( v6 )
          break;
        MmAccessFault(1, v4, 0, 0);
      }
      v5 = (unsigned __int8)v16;
    }
    v9 = *(_DWORD *)v4;
    v4 += 4;
    v8 = v9;
    if ( !v9 )
      break;
    if ( (v8 & 0x400) == 0 )
    {
      v10 = MiLockTransitionLeafPage((unsigned int *)(v4 - 4), 0);
      v12 = v10;
      if ( v10 )
      {
        if ( (MiFlags & 0x30000) != 0 && (MiFlags & 0x80000) != 0 && (*(_BYTE *)(v10 + 23) & 7) == 3 )
        {
          MiRemoveLockedPageChargeAndDecRef(v10);
          MiClearPfnImageVerified(v12, 4, v13, v14);
        }
        if ( MiDeleteLockedTransitionPte(v4 - 4, v12, 17, 1) == 3 )
          --v7;
      }
      else if ( v8 != 768 )
      {
        MiReleasePageFileSpace((int)MiSystemPartition, v8, 1, v11);
      }
    }
  }
  if ( v5 != 17 )
    MiUnlockProtoPoolPage(v6, v5);
  return v7;
}
