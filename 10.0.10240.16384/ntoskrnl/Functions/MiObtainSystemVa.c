// MiObtainSystemVa 
 
int __fastcall MiObtainSystemVa(int a1, int a2)
{
  unsigned int v2; // r6
  int *v4; // r5
  int v5; // r8
  int v6; // r7
  int v7; // r0
  int v9; // r2
  char *v10; // r3
  int v11; // r2
  unsigned __int8 *v12; // r7
  unsigned int v14; // r2
  char v15[40]; // [sp+10h] [bp-28h] BYREF

  v2 = a2 & 0xBFFFFFFF;
  if ( (a2 & 0xBFFFFFFF) == 16 )
    v2 = 9;
  v4 = &MiState[v2];
  v5 = 0;
  v6 = 512;
  v7 = KeAcquireInStackQueuedSpinLock(&dword_6342BC, v15);
  if ( v4[2566] )
    return sub_5106B4(v7);
  v9 = (int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2;
  if ( byte_63505C < &byte_63505C[v9] && (v2 == 8 || v2 == 14 || v2 == 7) )
  {
    v6 = 512 - v9;
    v10 = &byte_63505C[512 - v9];
  }
  else
  {
    v10 = byte_63505C;
  }
  v11 = v6 - dword_633884;
  v12 = (unsigned __int8 *)&v10[dword_633884];
  if ( !v11 )
LABEL_26:
    JUMPOUT(0x5106C2);
  while ( *v12++ )
  {
    v5 = 0;
LABEL_13:
    if ( !--v11 )
      goto LABEL_26;
  }
  if ( ++v5 != a1 )
    goto LABEL_13;
  dword_635310 -= a1 << 22;
  if ( v12 > (unsigned __int8 *)&byte_63505C[(int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2] )
    dword_633890 -= a1 << 22;
  v4[2408] += a1;
  if ( dword_635310 < (unsigned int)dword_633888 )
    dword_633888 = dword_635310;
  v14 = v4[2408];
  if ( v14 > v4[2581] )
    v4[2581] = v14;
  for ( ; v5; --v5 )
    *--v12 = v2;
  KeReleaseInStackQueuedSpinLock(v15);
  MiReclaimSystemVa(0);
  return dword_63389C + ((v12 - (unsigned __int8 *)byte_63505C) << 22);
}
