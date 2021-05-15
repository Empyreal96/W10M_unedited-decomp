// MmAddVerifierSpecialThunks 
 
int __fastcall MmAddVerifierSpecialThunks(unsigned int a1, int a2, unsigned int a3)
{
  int v4; // r8
  int v6; // r4
  int v7; // r4
  unsigned int v8; // r6
  int v9; // r5
  int *v10; // r0
  int *v11; // lr
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int vars4; // [sp+1Ch] [bp+4h]

  v4 = a2;
  if ( (MiFlags & 1) == 0 )
    return -1073741637;
  v7 = a2;
  v8 = a3 >> 3;
  if ( !(a3 >> 3) )
    return -1073741583;
  v9 = MmAcquireLoadLock();
  v10 = MiLookupDataTableEntry(a1, 1);
  v11 = v10;
  if ( v10 )
  {
    v12 = v10[6];
    v13 = v11[8] + v12;
    if ( vars4 < v12 || vars4 >= v13 )
    {
      MmReleaseLoadLock(v9);
      return -1073741585;
    }
    v14 = 0;
    if ( v8 )
    {
      while ( 1 )
      {
        v15 = *(_DWORD *)(v7 + 4);
        if ( v15 < v12 || v15 >= v13 )
          break;
        ++v14;
        v7 += 8;
        if ( v14 >= v8 )
          goto LABEL_13;
      }
      v6 = -1073741584;
    }
    else
    {
LABEL_13:
      v6 = VfThunkAddSpecialDriverThunks(a1, v4, a3, v11);
    }
  }
  else
  {
    v6 = -1073741585;
  }
  MmReleaseLoadLock(v9);
  return v6;
}
